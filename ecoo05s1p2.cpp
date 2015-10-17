#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100

char data[80][80];

char input[MAX];

#ifdef getc
#undef getc
#endif
#define getc() (*(cur++))

#ifdef _DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) _=_
#endif

char _;
#define scan(x) for( x=getc() - '0', dprintf("x=%d\n",x); (_=getc())>='0' && (_<='9'); x = (x<<1)+(x<<3)+_-'0')dprintf("x=%d\n",x);;--cur;dprintf("Got %d\n",x);

int R, C;
int r, c, t;

void print() {
	int rs, re, cs, ce;
	for (int r = 0; r < 80; ++r)
		for (int c = 0; c < 80; ++c)
			if (data[r][c] != ' ')
				goto devil;
devil:;

	for (int i = 0; i < 24; ++i) {
		for (int j = 0; j < 78; ++j) {
			if (data[i][j])
				putchar(data[i][j]);
			else goto hell;
		}
		putchar(10);
	hell:;
	}
}

void parse(char* cur) {
	R = r = c = 0;
	r = 12;
	c = 39;
	while (*cur) {
		dprintf("[%d,%d] Processing '%c'\n",r, c, *cur);
		switch (*cur) {
		case '?':
			++cur;
			data[r][c] = getc();
			++c;
			break;
		case '<':
			++cur;
			switch (getc()) {
			case 'U':
				scan(t);
				r -= t;
				break;
			case 'D':
				scan(t);
				r += t;
				break;
			case 'L':
				scan(t);
				c -= t;
				break;
			case 'R':
				scan(t);
				c += t;
				break;
			case 'M':
				scan(t);
				_ = data[r][c - 1];
				for (int i = 0; i < t-1; ++i)
					data[r][c++] = _;
				break;
			}
			break;
		case '>':
			++cur;
			break;
		default:
			data[r][c] = *cur;
			cur++;
			++c;
			break;
		}
		//print();
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("DATA11.txt", "r", stdin);
#endif // DEBUG
	for (int Case = 0; Case < 5; ++Case) {
		memset(input, 0, sizeof(input));
		memset(data, ' ', sizeof(data));
		cin.getline(input, 1000);
		parse(input);
		print();
	}
}