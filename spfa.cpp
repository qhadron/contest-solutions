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

#include <vector>
#include <queue>

/*
N: # of nodes (first node is 0)
M: # of edges
*/

int N, M,a,b,c,S;

#define INF 0x3f3f3f3f
#define MAX 1001
typedef pair<int, int> ii;
vector<ii> adj[MAX]; //(weight,target)
int dist[MAX];
bool vis[MAX];	//stores whether vertex is in queue
void spfa(int s) {
	memset(vis, false, sizeof(vis));
	memset(dist, INF, sizeof(dist));
	queue<int> q;
	int u,v,w; 
	dist[s] = 0;
	q.push(s);
	while (!q.empty()) {
		u = q.front(); q.pop();
		vis[u] = false;
		for (int i = 0; i < adj[u].size(); ++i) {
			v = adj[u][i].second;
			w = adj[u][i].first;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				if (!vis[v])
					vis[v]=true,q.push(v);
			}
		}
	}
}
/*
---input---
N M S
edges etc...
*/
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(N); scanp(M); scanp(S);
	for (int i = 0; i < M; ++i) {
		scanp(a); scanp(b); scanp(c);
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}
	spfa(S);
	for (int i = 0; i < N; ++i) {
		printf("dist[%d]=%d\n", i, dist[i]);
	}
}
