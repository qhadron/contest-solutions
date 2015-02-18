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

#define MAX 31

int T;
int A, B, C, D;
int dp[MAX][MAX][MAX][MAX];

int go(int a, int b, int c, int d) {
	if (dp[a][b][c][d] != -1)
		return dp[a][b][c][d];
	if (a >= 2 && b >= 1 && d >= 2) {
		if (!go(a - 2, b - 1, c, d - 2))
			return dp[a][b][c][d] = true;
	}
	if (a >= 1 && b >= 1 && c >= 1 && d >= 1) {
		if (!go(a-1,b-1,c-1,d-1))
			return dp[a][b][c][d] = true;
	}
	if (c >= 2 && d >= 1) {
		if (!go(a , b , c - 2, d - 1))
			return dp[a][b][c][d] = true;
	}
	if (b >= 3) {
		if (!go(a, b - 3, c, d))
			return dp[a][b][c][d] = true;
	}
	if (a >= 1 && d >= 1) {
		if (!go(a - 1, b, c , d - 1))
			return dp[a][b][c][d] = true;
	}
	return dp[a][b][c][d] = false;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	memset(dp, -1, sizeof(dp));
	scanp(T);
	while (T--) {
		scanf("%d%d%d%d", &A, &B, &C, &D);
		if (go(A, B, C, D))
			puts("Patrick");
		else
			puts("Roland");
	}
}
