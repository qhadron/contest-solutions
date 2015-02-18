#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 400001

vector<int> adj[MAX];
int N,x,y;
bool vis[MAX];
long long num, len, paths[MAX], dp[MAX];
// dp[i] = max length from i to children
// paths[i] = number of paths at i with length of dp[i]
// num = # of longest paths
// len = length of longest paths

void dfs(int cur) {
	vis[cur] = true;
	if (paths[cur] == 0)
		paths[cur] = 1;
	for (int next : adj[cur]) {
		if (vis[next])
			continue;
		dfs(next);
		x = dp[next] + 1;
		if (x + dp[cur] > len) {
			//new longest path
			len = x + dp[cur];	//update length
			num = paths[cur] * paths[next];	//update number
		}
		else if (x + dp[cur] == len) {
			//more longest paths found
			num += paths[cur] * paths[next];	//increment number
		}
		//update dp && paths
		if (dp[cur] < x) {
			//new length found
			dp[cur] = x;	//update dp
			paths[cur] = paths[next];	//update paths
		}
		else if (dp[cur] == x) {
			//same length
			paths[cur] += paths[next]; // increment paths
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	printf("%lld %lld\n", ++len, num);
}