#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
//knapsack problem

ll N, T;
ll dp[100001];
ll A[2001][3], V[2001][3];
ll M, ans;

ll go(ll T) {
	for (int i = 0; i < N; ++i)
		for (int t = T; t >= 0; --t) {
			M = 0;
			for (int j = 0; j < 3; ++j)
				if (t >= A[i][j])
					M = max(M, dp[t - A[i][j]] + V[i][j]);
			dp[t] = max(dp[t], M);
		}

	return dp[T];
}

int main() {
	cin.sync_with_stdio(false);
	cin >> N;
	cin >> T;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> A[i][j] >> V[i][j];
	go(T);
	for (int t = 0; t < T; ++t)
		ans = max(ans, dp[T]);
	cout << ans << endl;
}