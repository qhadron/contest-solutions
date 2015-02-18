#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;
#ifndef WIN32
#ifdef getchar
#undef getchar
#endif
#define getchar getchar_unlocked
#endif
#define scanp(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _, __;
static inline void scan(int& x) {
	__ = 0;
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

typedef pair<int, int> ii;
typedef long long ll;

#define INF 0x3f3f3f3f
#define MAX 105

char map[MAX][MAX];
int dp[MAX][MAX];
int M, N;

int dirx [] = { 0, 0, 1 },
diry [] = { 1, -1, 0 };


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	while (scanf(" %d%d ", &M, &N) > 0 && (N | M)){
		memset(dp, 0, sizeof(dp));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < M; ++i)
			scanf("%s ", map[i]);
		for (int r = M - 2; r >= 0; --r) {
			if (map[r][0] != '*')
				dp[r][0] = dp[i + 1][0] + (map[r][0] != '.') ? map[r][0] - '0' : 0;
		}
		for (int c = 1; c < N; ++c) {
			for (int r = 0; r < M; ++r) {
				if (dp[r][c - 1] != '*') {
					dp[r][c] = dp[r][c - 1] + (map[r][c] != '.') ? map[r][c] - '0' : 0;
				}
			}
		}

		for (int i = 0; i < M; ++i, putchar(10))
			for (int j = 0; j < N; ++j) {
				dprintf("%d ", dp[i][j]);
			}
		printf("%d\n", dp[M - 1][N - 1]);
	}
}
