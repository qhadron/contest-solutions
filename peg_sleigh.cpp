//http://wcipeg.com/problems/desc/sleigh
#include <cstdio>
#include <vector>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
char _;
#define scan(x) while((_=getchar())<'0'); for(x=_-'0';(_=getchar())>='0';x=(x<<1)+(x<<3)+_-'0')
vector<pair<int, int> > adj[100001];
int q[100001], d[100001];
int sum, N, m = -1, a, b, c, cc;
inline void bfs() {
	a = b = 0;
	q[b++] = 0;
	do {
		cc = q[a];
		for (int i = 0; i < adj[cc].size(); ++i)
			if (adj[cc][i].second&&d[adj[cc][i].second] == 0) {
				d[adj[cc][i].second] = d[cc] + adj[cc][i].first;
				if (m < d[adj[cc][i].second])
					m = d[adj[cc][i].second];
				q[b++] = adj[cc][i].second; //push
			}
	} while (++a < b);    //pop
}
int main() {
	scan(N);
	while (N--) {
		scan(a); scan(b); scan(c);
		sum += c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	bfs();
	printf("%d\n", (sum << 1) - m);
}