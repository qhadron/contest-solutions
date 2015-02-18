#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

#ifdef _DEBUG
#define dprintf(...) printf(__VA_ARGS__),putchar(10)
#else
#define dprintf(...)
#endif
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

#define MAX 2001
#define INF 0x3f3f3f3f
int K, N, M, dist[MAX], hull[MAX],s, t;
vector<iii> adj[MAX];
bool vis[MAX];
int dijkstra() {
	priority_queue<ii, vector<ii>, greater<ii> > q;
	memset(dist, INF, sizeof(dist));
	dist[s] = 0;
	hull[s] = K;
	q.push(ii(0, s));
	int u, v, w, h;
	while (!q.empty()) {
		u = q.top().second; q.pop();
		//if (vis[u]) continue;
		if (!hull[u]) continue;
		//vis[u] = true;
		dprintf("At %d, dist[%d] = %d, h[%d] = %d", u, u, dist[u], u, hull[u]);
		for (int i = 0; i < adj[u].size(); ++i) {
			v = adj[u][i].first.second;
			w = adj[u][i].first.first;
			h = adj[u][i].second;
			if (dist[v] > dist[u] + w) {
				if (hull[u] > h) {
					hull[v] = hull[u] - h;
					dist[v] = dist[u] + w;
					dprintf("U:dist[%d]=%d", v, dist[v]);
					q.push(ii(dist[v], v));
				}
			}
		}
	}
	return vis[t] ? dist[t]:-1;
}

int main() {
#ifdef _DEBUG
	freopen("input2.txt", "r", stdin);
#endif
	cin >> K >> N >> M;
	for (int i = 0,a,b,t,h; i < M; ++i) {
		cin >> a >> b >> t >> h;
		adj[a].push_back(iii(ii(t, b), h));
		adj[b].push_back(iii(ii(t, a), h));
	}
	cin >> s >> t;
	cout << dijkstra() << endl;
}