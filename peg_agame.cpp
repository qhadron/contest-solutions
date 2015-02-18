//http://wcipeg.com/problems/desc/dp1p2
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
#ifdef _DEBUG
#define dvar(x) cout << (#x) << ":" << (x) << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

#define INF 0x3f3f3f3f
#define MAX 1001
int dp[MAX][MAX], coins[MAX], S[MAX], N;
inline int sum(int l, int r) {
	return S[r] - S[--l];
}
int go(int l, int r) {
	if (dp[l][r])
		return dp[l][r];
	return dp[l][r] = sum(l, r) - min(go(l + 1, r), go(l, r - 1));
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(N);
	for (int i = 0; i < N; ++i) {
		scanp(coins[i]);
		S[i] = (i?S[i - 1]:0) + coins[i];
		dp[i][i] = coins[i];
	}
	printf("%d\n", go(0, N - 1));
}
