#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define scanp(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _, __;
static inline void scan(int& x) {
	while ((x = getchar()) < '-');
	if (x == '-')
		__ = 1, x = getchar();
	for (x -= '0'; (_ = getchar()) >= '0' && (_ <= '9'); x = (x << 1) + (x << 3) + _ - '0');
	if (__)
		x = -x;
}
#ifdef _DEBUG
#define dvar(x) cout << (#x) << ":" << (x) << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

#define MAX 32

int T, N;
char buf[50];
int dp[MAX][4][4][4][4][4][4];

bool go(int left, int a, int b, int c, int d, int e, int f) {
	int & cur = dp[left][a][b][c][d][e][f];
	if (cur != -1)
		return cur;
	if (left < 1)
		return cur = false;
	if (left >= 1 && a < 4)
		if (!go(left - 1, a + 1, b, c, d, e, f))
			return cur = true;
	if (left >= 1 && a < 4)
		if (!go(left - 1, a + 1, b, c, d, e, f))
			return cur = true;
	if (left >= 2 && b < 4)
		if (!go(left - 2, a, b + 1, c, d, e, f))
			return cur = true;
	if (left >= 3 && c < 4)
		if (!go(left - 3, a, b, c + 1, d, e, f))
			return cur = true;
	if (left >= 4 && d < 4)
		if (!go(left - 4, a, b, c, d + 1, e, f))
			return cur = true;
	if (left >= 5 && e < 4)
		if (!go(left - 5, a, b, c, d, e + 1, f))
			return cur = true;
	if (left >= 6 && f < 4)
		if (!go(left - 6, a, b, c, d, e, f + 1))
			return cur = true;
	return cur = false;
}

int a, b, c, d, e, f, Left;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(T);
	memset(dp, -1, sizeof(dp));
	while (T--) {
		gets(buf);
		dprintf("->%s\n", buf);
		Left = 31;
		a = b = c = d = e = f = 0;
		for (int i = 0; i < strlen(buf); ++i) {
			if (buf[i] == '1')
				++a, --Left;
			else if (buf[i] == '2')
				++b, Left -= 2;
			else if (buf[i] == '3')
				++c, Left -= 3;
			else if (buf[i] == '4')
				++d, Left -= 4;
			else if (buf[i] == '5')
				++e, Left -= 5;
			else if (buf[i] == '6')
				++f, Left -= 6;
		}
		if (strlen(buf) & 1)
			if (go(Left, a, b, c, d, e, f))
				puts("B");
			else
				puts("A");
		else
			if (go(Left, a, b, c, d, e, f))
				puts("A");
			else
				puts("B");
	}
}
