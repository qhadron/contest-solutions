#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#ifndef WIN32
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
typedef long long ll;

#define INF 0x3f3f3f3f
#define MAX 1000001
int N, M, a, b, c;
vector<ii> adj[MAX];
bool vis[MAX];
int prim(int s) {
	priority_queue<ii, vector<ii>, greater<ii> > q;
	memset(vis, false, sizeof(vis));
	int res = 0;
	int u, v, w;
	q.push(ii(0, s));
	while (!q.empty()) {
		u = q.top().second; w = q.top().first; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		res += w;
		for (int i = 0; i < adj[u].size(); ++i)
			if (!vis[adj[u][i].second]) 
				q.push(adj[u][i]);
	}
	return res;
}

/*
---input---
N M
edges etc...
*/
int main() {
#if defined _DEBUG | defined NDEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(N); scanp(M);
	while (M--) {
		scanp(a); scanp(b); scanp(c);
		adj[a].push_back(ii(c, b));
		adj[b].push_back(ii(c, a));
	}
	printf("%d\n", prim(0));
}
