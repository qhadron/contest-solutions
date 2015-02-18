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
typedef pair<int, ii> iii;	//weight, nodes
typedef long long ll;

#define INF 0x3f3f3f3f
#define MAX 101
int N, M, a, b, c, d;
int S[MAX], R[MAX];	//disjoint set, rank
int cost, danger;
priority_queue<iii, vector<iii>, greater<iii> > q;

inline int F(int x) {
	while (x != S[x])
		x = S[x] = S[S[x]];
	return x;
}

inline void U(int x, int y) {
	x = F(x), y = F(y);
	if (x != y) {
		if (R[x] > R[y]) {
			S[x] = S[y];
		}
		else {
			S[y] = S[x];
			if (R[x] == R[y])
				++R[y];
		}
	}
}


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(N);
	scanp(M);
	while (M--) {
		scanp(a); scanp(b); scanp(c); scanp(d);
		c += d * 1000;
		q.push(iii(c, ii(a, b)));
	}
	for (int i = 0; i <= N; ++i)
		S[i] = i;
	while (!q.empty()) {
		iii cur = q.top(); q.pop();
		if (F(cur.second.first) != F(cur.second.second)) {
			U(cur.second.first, cur.second.second);
			if (cur.first > 1000)
				++danger;
			cost += cur.first%1000;
		}
	}
	printf("%d %d\n", danger, cost);
}