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

vector<int> adj[1000];
int T,N,M;
int x, y;
int pre[1000];
int mark = 0;
bool dfs(int u) {
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (dfs)
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < 1000;++i)
			adj[i].clear();
		mark = 0;
		pre[]
		for (int i = 0; i < M; ++i) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}

}
