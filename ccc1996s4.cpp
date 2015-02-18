#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 1001 
int N, ans;
char a[MAX], b[MAX], c[MAX], d[MAX];

int fromRome(char* s) {
	if (strlen(s) <= 0)
		return 0;
	switch (*s) {
	case 'I':
		if (strlen(s) > 1 && (*(s + 1) == 'V' || *(s + 1) == 'X'))
			return -1 + fromRome(s + 1);
		return 1 + fromRome(s + 1);
	case 'V':
		return 5 + fromRome(++s);
	case 'X':
		if (strlen(s) > 1 && (*(s + 1) == 'L' || *(s + 1) == 'C'))
			return -10 + fromRome(s + 1);
		return 10 + fromRome(s + 1);
	case 'L':
		return 50 + fromRome(s + 1);
	case 'C':
		if (strlen(s) > 1 && (*(s + 1) == 'D' || *(s + 1) == 'M'))
			return -100 + fromRome(s + 1);
		return 100 + fromRome(s + 1);
	case 'D':
		return 500 + fromRome(s + 1);
	case 'M':
		return 1000 + fromRome(s + 1);
	default:
		return 0 + fromRome(s + 1);
	}
}

void toRome(char* s, int x) {
	if (x > 1000) {
		strcpy(s, "CONCORDIA CUM VERITATE");
		return;
	}
	int t, T;
	while (x) {
		//printf("x=%d\n", x);
		if (x == 1000) {
			*s = 'M';
			return;
		}
		else if (T = t = x / 100) {
			if (t >= 9) {
				*(s++) = 'C';
				*(s++) = 'M';
			}
			else if (t >= 5) {
				*(s++) = 'D';
				t -= 5;
				while (t--)
					*(s++) = 'C';
			}
			else if (t >= 4) {
				*(s++) = 'C';
				*(s++) = 'D';
			}
			else {
				while (t--)
					*(s++) = 'C';
			}
			x -= T * 100;
		}
		else if (T = t = x / 10) {
			if (t >= 9) {
				*(s++) = 'X';
				*(s++) = 'C';
			}
			else if (t >= 5) {
				*(s++) = 'L';
				t -= 5;
				while (t--)
					*(s++) = 'X';
			}
			else if (t >= 4) {
				*(s++) = 'X';
				*(s++) = 'L';
			}
			else {
				while (t--)
					*(s++) = 'X';
			}
			x -= T * 10;
		}
		else if (T = t = x / 1) {
			if (t >= 9) {
				*(s++) = 'I';
				*(s++) = 'X';
			}
			else if (t >= 5) {
				*(s++) = 'V';
				t -= 5;
				while (t--)
					*(s++) = 'I';
			}
			else if (t >= 4) {
				*(s++) = 'I';
				*(s++) = 'V';
			}
			else {
				while (t--)
					*(s++) = 'I';
			}
			x -= T * 1;
		}
		//printf("d=%s\n", d);
	}
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &N);
	while (N--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(c));
		scanf("%s", c);
		int i;
		for (i = 0; c[i] != '+'; ++i)
			a[i] = c[i];
		for (int j = 0; c[i] != '='; ++i, ++j)
			b[j] = c[i];
		//printf("a:%s->%d\nb:%s->%d\n", a, fromRome(a), b, fromRome(b));
		ans = fromRome(a) + fromRome(b);
		toRome(d, ans);
		printf("%s%s\n", c, d);
	}
}
