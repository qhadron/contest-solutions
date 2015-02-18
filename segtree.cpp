#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define scan(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _;
#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

struct segment {
	int left, right, mid, val;
	int lazy;	//lazy propagation 
};

#define MAX 100001

#define lc(x) (x<<1)
#define rc(x) (x<<1|1)

int N, M;
int data[MAX];
segment seg[3 * MAX];

inline int Min(int a, int b) {
	return (a < b) ? a : b;
}

int(*function)(int, int) = Min;

void _build(int cur, int l, int r){
	if (l > r)
		return;
	seg[cur].left = l;
	seg[cur].right = r;
	seg[cur].mid = (l + r) >> 1;
	if (l == r) {
		seg[cur].val = data[l];
		dprintfn("seg[%d,%d]=%d", seg[cur].left, seg[cur].right, seg[cur].val);
	}
	else {
		_build(lc(cur), l, seg[cur].mid);
		_build(rc(cur), seg[cur].mid + 1, r);
		seg[cur].val = function(seg[lc(cur)].val, seg[rc(cur)].val);
		dprintfn("seg[%d,%d]=%d", seg[cur].left, seg[cur].right, seg[cur].val);
	}
}

void build(int l, int r) {
	_build(1, l, r);
}

//change element [l,r] to val
void _update(int cur, int l, int r, int val) {
	if (l > r) return;
	if (seg[cur].lazy) {
		seg[cur].val += seg[cur].lazy;
		if (l != r) {
			seg[lc(cur)].lazy += seg[cur].lazy;
			seg[rc(cur)].lazy += seg[cur].lazy;
		}
		seg[cur].lazy = 0;
	}

	if (seg[cur].left >= l && seg[cur].right <= r) {
		seg[cur].val = val;
		dprintfn("Changed seg[%d,%d]=%d", seg[cur].left, seg[cur].right, seg[cur].val);
		return;
	}
	if (r <= seg[cur].mid) {
		dprintfn("[%d,%d] in left subtree of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		_update(lc(cur), l, r, val);
	}
	else if (l > seg[cur].mid) {
		dprintfn("[%d,%d] in right subtree of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		_update(rc(cur), l, r, val);
	}
	else {
		//never happens in this case
		dprintfn("[%d,%d] in both subtree of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		_update(lc(cur), l, seg[cur].mid, val);
		_update(rc(cur), seg[cur].mid + 1, r, val);
	}
	seg[cur].val = function(seg[lc(cur)].val, seg[rc(cur)].val);
	dprintfn("Changed seg[%d,%d]=%d", seg[cur].left, seg[cur].right, seg[cur].val);
}

void update(int l, int r, int val) {
	_update(1, l, r, val);
}

//add val to element in [l,r]
void _add_tree(int cur, int l, int r, int val) {
	if (l > r) return;
	if (seg[cur].lazy) {
		seg[cur].val += seg[cur].lazy;
		if (l != r) {
			seg[lc(cur)].lazy += seg[cur].lazy;
			seg[rc(cur)].lazy += seg[cur].lazy;
		}
		seg[cur].lazy = 0;
	}
	if (seg[cur].left >= l && seg[cur].right <= r) {
		seg[cur].val += val;
		if (seg[cur].left != seg[cur].right) {
			seg[lc(cur)].lazy += val;
			seg[rc(cur)].lazy += val;
		}
		dprintfn("Changed seg[%d,%d]=%d", seg[cur].left, seg[cur].right, seg[cur].val);
		return;
	}
	if (r <= seg[cur].mid) {
		dprintfn("[%d,%d] in left subtree of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		_add_tree(lc(cur), l, r, val);
	}
	else if (l > seg[cur].mid) {
		dprintfn("[%d,%d] in right subtree of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		_add_tree(rc(cur), l, r, val);
	}
	else {
		//never happens in this case
		dprintfn("[%d,%d] in both subtree of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		_add_tree(lc(cur), l, seg[cur].mid, val);
		_add_tree(rc(cur), seg[cur].mid + 1, r, val);
	}
	seg[cur].val = function(seg[lc(cur)].val, seg[rc(cur)].val);
	dprintfn("Changed seg[%d,%d]=%d", seg[cur].left, seg[cur].right, seg[cur].val);
}

void add_tree(int l, int r, int val) {
	_add_tree(1, l, r, val);
}

//query in range[l,r]
int _query(int cur, int l, int r) {
	if (l > r) {
		dprintfn("WTF?");
		return 10000000;
	}
	if (seg[cur].lazy) {
		seg[cur].val += seg[cur].lazy;
		if (l != r) {
			seg[lc(cur)].lazy += seg[cur].lazy;
			seg[rc(cur)].lazy += seg[cur].lazy;
		}
		seg[cur].lazy = 0;
	}
	if (seg[cur].left == l && seg[cur].right == r) {
		dprintfn("[%d,%d]->seg[%d,%d]=%d", l, r, seg[cur].left, seg[cur].right, seg[cur].val);
		if (seg[cur].val != -1)
			return seg[cur].val;
		else
			return seg[cur].val = function(_query(l, seg[cur].mid, lc(cur)), _query(seg[cur].mid + 1, r, rc(cur)));
	}
	if (r <= seg[cur].mid) {
		dprintfn("[%d,%d] in left subtree of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		return _query(lc(cur), l, r);
	}
	else if (l > seg[cur].mid) {
		dprintfn("[%d,%d] in right subtree of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		return _query(rc(cur), l, r);
	}
	else {
		dprintfn("[%d,%d] in both subtrees of [%d,%d]", l, r, seg[cur].left, seg[cur].right);
		return function(_query(lc(cur), l, seg[cur].mid), _query(rc(cur), seg[cur].mid + 1, r));
	}
}

int query(int l, int r) {
	return _query(1, l, r);
}

int main() {
#if defined _DEBUG || defined NDEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanf("%d%d", &N, &M);
	for (int i = 0, temp; i < N; ++i) {
		scanf("%d", &temp);
		data[i] = temp;
	}
	build(0, N - 1);
	char c;
	int a, b;
	for (int i = 0; i < M; ++i) {
		scanf(" %c %d %d", &c, &a, &b);
		dprintfn("\n\nread %c %d %d", c, a, b);
		if (c == 'Q') {
			printf("%d\n", query(a, b));
		}
		else if (c == 'M') {
			add_tree(a, a, -query(a,a));
			add_tree(a, a, b);
		}
	}
}
