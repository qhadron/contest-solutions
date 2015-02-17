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

int S[MAX];	//disjoint set
int R[MAX];
int N, M, a, b, c;
typedef pair<int, ii > iii;
vector<ii> adj[MAX];
//make set
void MS(int x) {
	S[x] = x;
}
//find
int F(int x) {
	return (x != S[x]) ? S[x] = F(S[x]) : x;
}
//union by rank
void U(int x, int y) {
	x = F(x); y = F(y);
	if (x == y) return;
	if (R[x] > R[y])
		S[x] = S[y];
	else
		S[y] = S[x], R[y]+=R[x]==R[y];
}
int kruskal() {
	priority_queue<iii, vector<iii>, greater<iii> > q;
	int dist = 0;
	for (int i = 0; i <= N; ++i) {
		MS(i);
		for (ii edge : adj[i])
			q.push(iii(edge.first, ii(i, edge.second)));
	}
	while (!q.empty()) {
		iii cur = q.top(); q.pop();
		if (F(cur.second.first) != F(cur.second.second)) {
			dprintfn("Joined (%d,%d) w/ %f", cur.second.first, cur.second.second, cur.first);
			dist += cur.first;
			U(cur.second.first, cur.second.second);
		}
	}
	return dist;
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
	printf("%f\n", kruskal());
}
