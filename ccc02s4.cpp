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

int N, M;
char name[101][101];
int times[101];
int dp[101], pre[101];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(M);
	scanp(N);
	for (int i = 1; i <= N; ++i) {
		gets(name[i]); scanp(times[i]);
	}
	M = min(M, N);
	for (int i = 1; i <= N; ++i) {
		dp[i] = dp[i - 1] + times[i];
		pre[i] = i;
		for (int m = 1; m < M && (i - m - 1 >= 0); ++m) {
			int Max = 0;
			for (int j = 0; j <= m; ++j) {
				if (times[i - j] > Max)Max = times[i - j];

			}
			if (dp[i] > dp[i - m - 1] + Max) {
				pre[i] = i - m;
				dp[i] = dp[i - m - 1] + Max;
				dprintfn("dp[%s]=dp[%s]+%d,pre=%d", name[i],name[i-m-1], Max,pre[i]);
			}
		}

	}
	for (int i = 1; i <= N; ++i) {
		dprintfn("%s:%d-%d", name[i], dp[i], pre[i]);
	}
	for (int i = N; pre[i]; i = pre[i] - 1) {
		for (int j = pre[i]; j <= i; ++j)
			pre[j] = pre[i];
		dprintfn("pre[%d,%d]->%d", pre[i], i, pre[i]);
	}
	printf("Total Time: %d", dp[N]);
	int cur = -1;
	for (int i = 1; i <= N; ++i) {
		//dprintfn("Cur:%d,pre[%d]=%d", cur, i, pre[i]);
		if (pre[i] != cur) {
			putchar(10);
			cur = pre[i];
		}
		else
			putchar(' ');
		printf("%s",name[i]);
	}
	if (cur == pre[N])
		putchar(10);
}
