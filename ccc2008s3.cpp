#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <queue>
using namespace std;
char _;
#define scanp(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
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

#define MAX 50
int T, R, C;
char maze[MAX][MAX];
int vis[MAX][MAX];
int bfs(int sr, int sc) {
	queue<ii> q;
	memset(vis, 0, sizeof(vis));
	q.push(make_pair(sr, sc));
	int r, c;
	vis[sr][sc] = 1;
	while (!q.empty()) {
		r = q.front().first, c = q.front().second; q.pop();
		dprintfn("At (%d,%d):%c", c+1, r+1, maze[r][c]);
		if (r == R - 1 && c == C - 1)
			break;
		if (maze[r][c] == '+' || maze[r][c] == '-') {
			if (c + 1 < C) {
				if (!vis[r][c + 1])
					q.push(make_pair(r, c + 1)),
					vis[r][c + 1] = vis[r][c] + 1;
			}
			if (c - 1 >= 0) {
				if (!vis[r][c - 1])
					q.push(make_pair(r, c - 1)),
					vis[r][c - 1] = vis[r][c] + 1;
			}
		}
		if (maze[r][c] == '|' || maze[r][c] == '+') {
			if (r + 1 < R) {
				if (!vis[r + 1][c])
					q.push(make_pair(r + 1, c)),
					vis[r + 1][c] = vis[r][c] + 1;
			}
			if (r - 1 >= 0) {
				if (!vis[r - 1][c])
					q.push(make_pair(r - 1, c)),
					vis[r - 1][c] = vis[r][c] + 1;
			}
		}
	}
	return (vis[R - 1][C - 1]&&maze[R-1][C-1]!='*') ? vis[R - 1][C - 1] : -1;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(T);
	while (T--) {
		scanf("%d%d ", &R, &C);
		for (int i = 0; i < R; ++i) {
			scanf("%s",maze[i]);
		}
		for (int i = 0; i < R; ++i) {
			dprintfn("%s", maze[i]);
		}
		printf("%d\n", bfs(0, 0));
	}
}
