#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define scan(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _;
#ifdef _DEBUG
#define dvar(x) cout << (#x) << ":" << (x) << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

typedef long long ll;

#define MAX 1000001
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)

int N, M, L, a, b;
int res;

struct node {
	int l, r, val;
	bool lazy;
} seg[MAX * 3];

void build(int cur, int l, int r) {
	seg[cur].l = l;
	seg[cur].r = r;
	seg[cur].lazy = 0;
	if (l == r) {
		seg[cur].val = 1;
		return;
	}
	build(lc(cur), l, (l + r) / 2);
	build(rc(cur), (l + r)/2 + 1, r);
	seg[cur].val = seg[lc(cur)].val + seg[rc(cur)].val;
}

void push_down(int cur) {
	if (seg[cur].lazy) {
		seg[lc(cur)].lazy ^= 1;
		seg[rc(cur)].lazy ^= 1;
		seg[lc(cur)].val = seg[lc(cur)].r - seg[lc(cur)].l + 1 - seg[lc(cur)].val;
		seg[rc(cur)].val = seg[rc(cur)].r - seg[rc(cur)].l + 1 - seg[rc(cur)].val;
		seg[cur].lazy ^= 1;
	}
}

void _update(int cur, int l, int r) {
	if (seg[cur].l >= l && seg[cur].r <= r) {
		seg[cur].lazy ^= 1;
		seg[cur].val = seg[cur].r - seg[cur].l + 1 - seg[cur].val;
		return;
	}
	push_down(cur);
	int m = seg[cur].l + seg[cur].r >> 1;
	if (r <= m) _update(lc(cur), l, r);
	else if (l > m) _update(rc(cur), l, r);
	else _update(lc(cur), l, m), _update(rc(cur), m + 1, r);
	seg[cur].val = seg[lc(cur)].val + seg[rc(cur)].val;
}

void update(int l, int r) {
	_update(1, l, r);
}

int find_k(int cur, int k) {
	if (seg[cur].l == seg[cur].r)
		return seg[cur].l;
	push_down(cur);
	if (k <= seg[lc(cur)].val)
		return find_k(lc(cur), k);
	else
		return find_k(rc(cur), k - seg[lc(cur)].val);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scan(N);
	scan(M);
	scan(L);
	build(1,1,N);
	while (M--) {
		scan(a);
		scan(b);
		update(a, b);
		if (seg[1].val < L)
			puts("AC?");
		else
			printf("%d\n", find_k(1,L));
	}
}
