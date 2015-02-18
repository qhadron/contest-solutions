#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>

#ifdef _DEBUG
#define dprintf(...) printf(__VA_ARGS__),putchar(10)
#else
#define dprintf(...)
#endif
using namespace std;

#define MAX 3002
#define INF 0x3f3f3f3f

int N,M,dp[MAX],O[MAX], temp;
vector<int> V;
int brute_force() {
	int len = V.size();
	for (int i = 0; i < len; ++i) dprintf("V[%d]=%d", i, V[i]);
	dp[0] = V[0];
	for (int i = 1; i < len; ++i) {
		if (i >= 2) {
			dp[i] = max(dp[i-1], V[i] + dp[i - 2]);
			dprintf("dp[%d]=dp[%d](%d)+%d=%d", i, i - 2, dp[i - 2], V[i], dp[i]);
		}
		else {
			dp[i] = max(dp[i - 1],V[i]);
			dprintf("dp[%d]=%d", i, dp[i]);
		}
	}
	return dp[len-1];
}

int main() {
#ifdef _DEBUG
	freopen("input3.txt", "r", stdin);
#endif

	cin >> N;
	for (int i = 0, t; i < N; ++i) {
		cin >> temp;
		V.push_back(temp);
	}
	cin >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> O[i];
	}
	if (M==0)
		cout << brute_force() << endl;
	else if (M == 1) {
		int m = 0, mi = 0;
		for (int i = 0; i < N; ++i) {
			V.insert(V.begin() + i, O[1]);
			m = max(m, brute_force());
			V.erase(V.begin() + i);
		}
		cout << m << endl;
	}
	else {
		int sum = 0;
		for (int i = 1; i <= M; ++i)
			V.push_back(O[i]);
		for (int i = 0; i < V.size(); ++i)
			sum += V[i];
		cout << sum/2 << endl;
	}
}