#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

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

#define MAXX 2501
#define MAXN 50*3

char buf;
ll arr[2][MAXX], dp[MAXN][MAXX];
ll opt;	//local optimal
int NC;	//node count
int X;

struct Node {
	Node *l = NULL, *r = NULL;
	int val = 0, idx;
	Node(int n) {
		idx = n;
	}
} *root;

#ifdef _DEBUG

void print(Node* cur) {
	if (cur->val != 0) {
		dprintf("%d", cur->val);
	}
	else {
		dprintf("(");
		if (cur->l == NULL)
			dprintfn("ERROR");
		print(cur->l);
		dprintf(" ");
		if (cur->r == NULL)
			dprintfn("ERROR");
		print(cur->r);
		dprintf(")");
	}
}
#else
void print(...){};
#endif // _DEBUG

Node* parse() {
	Node* cur = new Node(NC++);
	while ((buf = getchar()) == ' ');	//skip whitespace

	if (buf == '(') {
		cur->l = parse();
		buf = getchar();
		cur->r = parse();
		do {
			buf = getchar();
		} while (buf != ')');
	}
	else {
		ungetc(buf, stdin);
		scanf("%d", &cur->val);
	}
	return cur;
}

void dfs(Node* u) {
	if (u->val) {
		//leaf
		for (int i = 0; i <= X; ++i)
			dp[u->idx][i] = u->val + i;
		dprintfn("For leaf with %d: ", u->val);
		for (int i = 0; i <= X; ++i)
			dprintfn("[%d]=%d", i, dp[u->idx][i]);
	}
	else {
		//pre order traversal
		dfs(u->l);
		dfs(u->r);
		//left child
		dprintf("For "); print(u->l); dprintfn(" :");
		//i is # of nutrients used
		//j is # of nutrients used for increasing edge
		for (int i = 0; i <= X; ++i) {
			opt = 0;
			for (int j = 0; j <= i; ++j) {
				opt = max(opt, min((ll) (1 + j)*(1 + j), dp[u->l->idx][i - j]));
			}
			arr[0][i] = opt;
			dprintfn("[%d]=%d", i, arr[0][i]);
		}

		//right child
		dprintf("For "); print(u->r); dprintfn(" :");
		//i is # of nutrients used
		//j is # of nutrients used for increasing edge
		for (int i = 0; i <= X; ++i) {
			opt = 0;
			for (int j = 0; j <= i; ++j) {
				opt = max(opt, min((ll) (1 + j)*(1 + j), dp[u->r->idx][i - j]));
			}
			arr[1][i] = opt;
			dprintfn("[%d]=%d", i, arr[1][i]);
		}

		//i is # of nutrients sent
		//j is # of nutrients sent to left
		for (int i = 0; i <= X; ++i) {
			for (int j = 0; j <= i; ++j) {
				dp[u->idx][i] = max(dp[u->idx][i], arr[0][j] + arr[1][i - j]);
			}
		}
		dprintf("For "); print(u); dprintfn(" :");
		for (int i = 0; i <= X; ++i) {
			dprintfn("[%d]=%d", i, dp[u->idx][i]);
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	root = parse();
	scanf("%d", &X);
	dfs(root);
	printf("%lld\n", dp[root->idx][X]);
}
