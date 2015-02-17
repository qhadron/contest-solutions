//http://www.dmoj.ca/problem/dmopc14c4p6
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>

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
	__ = 0;
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
#define MAX 500001

int N;
int ldist[MAX], sdist[MAX], lnext[MAX], t, dist[MAX];

vector<int> adj[MAX];
int dfs1(int u, int p) {
	for (int i = 0,v; i < adj[u].size(); ++i) {
		v = adj[u][i];
		if (v == p) continue;
		t=dfs1(v, u) + 1;
		if (t > ldist[u]) {
			sdist[u] = ldist[u];
			ldist[u] = t;
			lnext[u] = v;
		}
		else if (t > sdist[u]) {
			sdist[u] = t;
		}
	}
	return ldist[u];
}

void dfs2(int u, int p) {
	for (int i = 0, v; i < adj[u].size(); ++i) {
		v = adj[u][i];
		if (v == p) continue;
		if (v == lnext[u]) {
			dist[v] = max(dist[u], sdist[u]) + 1;
		}
		else {
			dist[v] = max(dist[u], ldist[u]) + 1;
		}
		dfs2(v, u);
	}
	dist[u] = max(dist[u], ldist[u]);
}

int a, b;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(N);
	for (int i = 1; i < N; ++i) {
		scanp(a); scanp(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(1, 1);
	for (int i = 1; i <= N; ++i)
		dprintf("ldist[%d]=%d,sdist[%d]=%d,lnext[%d]=%d\n", i, ldist[i], i, sdist[i], i, lnext[i]);
	dfs2(1, 1);
	dist[1] = ldist[1];
	for (int i = 1; i <= N; ++i)
		printf("%d\n", ++dist[i]);
}

