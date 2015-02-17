//http://wcipeg.com/problems/desc/ioi1311

#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#ifdef _DEBUG
#define dvar(x) cout << (#x) << ":" << (x) << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

using namespace std;
#define MAX 100001
#define max(x,y) (((x) > (y)) ? (x) : (y))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

vii adj[MAX];

int N, M, L, S;
int x, y, z;//tmp vars
bool searched[MAX];
long long ans, dp[MAX],tree[MAX];
ii ldist[MAX], sdist[MAX];	//longest, second longest dist
int best;
ll len;  //longest length

void dfs1(int cur, int parent) {
	searched[cur] = true;
	for (int i = 0; i < adj[cur].size(); ++i) {
		if (adj[cur][i].first == parent)
			continue;
		dfs1(adj[cur][i].first, cur);
		x = ldist[adj[cur][i].first].second + adj[cur][i].second;
		if (x > ldist[cur].second) {
			sdist[cur] = ldist[cur];
			ldist[cur] = { adj[cur][i].first, x };
		}
		else if (x > sdist[cur].second) {
			sdist[cur] = { adj[cur][i].first, x };
		}
	}
	dprintf("ldist[%d]: (%d,%d)->%d\nsdist[%d]: (%d,%d)->%d\n", cur, cur, ldist[cur].first, ldist[cur].second, cur, cur, sdist[cur].first, sdist[cur].second);
}


void dfs2(int cur, int parent) {
	for (ii edge : adj[cur]) {
		if (edge.first == parent) continue;
		if (edge.first == ldist[cur].first) {
			dp[edge.first] = max(dp[cur], sdist[cur].second) + edge.second;
			dprintfn("1:dp[%d]=%d", edge.first, dp[edge.first]);
		}
		else {
			dp[edge.first] = max(dp[cur], ldist[cur].second) + edge.second;
			dprintfn("2:dp[%d]=%d", edge.first, dp[edge.first]);
		}
		dfs2(edge.first, cur);
	}
	dp[cur] = max(dp[cur], ldist[cur].second);
	if (best<0||dp[cur] < dp[best])
		best = cur;
	dprintfn("dp[%d] = %d", cur,dp[cur]);
}

int main() {
#if defined _DEBUG || defined NDEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d%d", &N, &M, &L);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		adj[x].push_back({ y, z });
		adj[y].push_back({ x, z });
	}
	for (int i = 0; i < N; ++i) {
		if (searched[i]) continue;
		dprintfn("Searching in %d:", i);
		best = -1;
		dfs1(i,i);
		dfs2(i,i);
		dprintfn("->dp[%d]=%d",best,dp[best]);
		tree[S++] = dp[best];
		dprintfn("\n");
	}
	sort(tree, tree + S);
	if (S < 2)
		for (int i = 0; i < N; ++i)
			len = max(len, dp[i]);
	else
		len = tree[S - 1] + tree[S - 2] + L;
	if (S > 2)
		len = max(len, tree[S - 2] + tree[S - 3] + (L * 2));
	printf("%lld\n", len);
}