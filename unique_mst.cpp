//determines whether or not 

#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x7fffffff;
vector<ii> adj[101];
int N, M,x,y,z;
int T;
bool vis[101];
vector<ii*> used;
struct mcomp {
	bool operator() (ii* a, ii* b) {
		return a->first > b->first;
	}
};
long long prim(int start, bool mark) {
	priority_queue<ii*, vector<ii*>, mcomp > q;
	ii* cur;
	long long sum = 0;
	memset(vis, 0, sizeof(vis));
	cur = new ii;
	*cur = make_pair(0, start);
	q.push(cur);
	int pre = 0;
	while (!q.empty()) {
		cur = (q.top()); q.pop();
		if (vis[cur->second])
			continue;
		vis[cur->second] = true;
		if (mark&&cur->second != start) used.push_back(cur);// , printf("Used [%d,%d]\n", cur->first, cur->second);
		//printf("At %d\n", cur->second);
		sum += cur->first;
		for (int i = 0; i < adj[cur->second].size(); ++i) {
			ii edge = adj[cur->second][i];
			if (!vis[edge.second])
				q.push(&adj[cur->second][i]);
				//printf("Seen %d->%d,%d\n", cur->second, edge.second, edge.first);
		}
	}
	return sum;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		used.clear();
		for (int i = 0; i < N; ++i)adj[i].clear();
		for (int i = 0; i < M; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			adj[x].push_back(make_pair( z, y ));
			adj[y].push_back(make_pair( z, x ));
		}
		ll len = prim(1,true);
		ii tmp;
		bool flag = 0;
		for (int i = 0; i < used.size(); ++i) {
			//printf("Removing %d->%d\n", used[i]->first, used[i]->second);
#define edge (*used[i])
			int t = edge.first;
			edge.first = INF;
			if (flag = prim(1, false) == len) break;
			edge.first = t;
#undef edge
		}
		if (flag)
			puts("Not Unique!");
		else
			printf("%lld\n", len);
	}
}