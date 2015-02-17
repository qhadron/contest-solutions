#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#ifndef WIN32
#ifdef getchar
#undef getchar
#endif
#define getchar getchar_unlocked
#endif

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

int N, G,pre[501],dp[501];
string s;

struct group {
	int p, t, i;
	group(){};
	group(int a, int b, int c){ p = a; t = b; i = c; }
} g[501],sg(-1,-1,-1);

bool operator< (group& a, group& b) {
	return a.t < b.t;
}

vector<group> bg;
vector<int> order;

int dfs(int cur,int t) {
	if (cur >= bg.size())
		return 0 ;
	if (t >= bg[cur].t)
		return 0;
	if (dp[cur])
		return dp[cur];
	int a = dfs(cur + 1, t + 1) + bg[cur].t;
	int b = dfs(cur + 1, t);
	if (a > b) order.push_back(bg[cur].i+1);
	return dp[cur]=(a > b) ? a : b;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	//ios::sync_with_stdio(false);
	cin >> N;
	getline(cin, s);
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		if (s.find(" Princess ") != s.npos) {
			g[G].p += 1;
		}
		else {
			g[G].i = G;
			++G;
		}
	}
	g[G].i = G;
	++G;
	for (int i = 0; i < G; ++i) {
		cin >> g[i].t;
	}
	sort(g, g + G);
	for (int i = 0,t; i < G;) {
		bg.push_back(g[i]);
		t = g[i].t;
		while (g[i].t == t)
			++i;
	}
	dfs(0, 0);
	for (vector < int > ::reverse_iterator it = order.rbegin(); it != order.rend(); ++it) {
		cout << *it << endl;
	}
}
