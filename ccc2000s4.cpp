#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int D, C[50], N, dp[5281];

#define INF 0x3f3f3f3f
#ifndef WIN32
#ifdef getchar
#undef getchar
#endif
#define getchar getchar_unlocked
#endif
#define scanp(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _, __;

int main() {
	scanp(D); scanp(N);
	for (int i = 0; i < N; ++i)
		scanp(C[i]);
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	for (int d = 0; d < D; ++d) {
		for (int c = 0; c < N; ++c) {
			dp[d + C[c]] = min(dp[d + C[c]], dp[d] + 1);
		}
	}
	if (dp[D] == INF)
		puts("Roberta acknowledges defeat.");
	else
		printf("Roberta wins in %d strokes.\n", dp[D]);
}