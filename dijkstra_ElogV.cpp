#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
#ifdef __GNUC__
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
#define INF 0x3f3f3f3f
#define MAX 1000001

vector<ii> adj[MAX];	//weight, target
int N, M, S, a, b, c;
int dist[MAX];
bool vis[MAX];
void dijkstra(int s) {
	priority_queue<ii, vector<ii>, greater<ii>> q;
	memset(dist, INF, sizeof(dist));
	memset(vis, false, sizeof(vis));
	dist[s] = 0;
	int u, v, w;
	q.push(make_pair(dist[s], s));
	while (!q.empty()) {
		u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		dprintfn("At %d", u);
		for (int i = 0; i < adj[u].size(); ++i) {
			v = adj[u][i].second;
			w = adj[u][i].first;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				q.push(ii(dist[v], v));
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
		//adj[b].push_back(make_pair(c, a));
	}
	dijkstra(S);
	for (int i = 0; i < N; ++i) {
		printf("dist[%d]=%d\n", i, dist[i]);
	}
}

