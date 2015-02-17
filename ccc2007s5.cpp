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
#define MAX 30001
int T, N, K, W, dp[MAX][501], s[MAX], t, p;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(T);
	while (T--) {
		scanp(N); scanp(K); scanp(W);
		s[0] = 0;
		for (int i = 1; i <= N; ++i) {
			scanp(t);
			s[i] = s[i - 1] + t;
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= K; ++j) {
#ifdef _DEBUG
				p = (i > W) ? i - W : 0;
				t = (i > W ? dp[p][j - 1] : 0) + s[i] - (i > W ? s[p] : 0);
				if (t > dp[i - 1][j]) {
					dp[i][j] = t;
					dprintfn("Hit [%d,%d]->dp[%d][%d]=%d(+%d)", p + 1, i, i, j, dp[i][j], s[i] - s[p]);
				}
				else {
					dp[i][j] = dp[i - 1][j];
					dprintfn("dp[%d][%d]=dp[%d][%d]=%d", i, j, i - 1, j, dp[i][j]);
				}
#else
				if (i >= W) {
					p = i - W;
					dp[i][j] = max(dp[i-1][j], dp[p][j-1]+s[i]-s[p]);
				} else {
					dp[i][j] = dp[i-1][j];
				}
#endif
			}
		}
	printf("%d\n", dp[N][K]);
	}
}

