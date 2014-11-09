#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
#define MAX 10001
#define other(n) (n)<<1
vector<pair<int, int> > adjlist[MAX];		//pair<node, capacity>

int M, N;	//number of lakes and rivers

int s, t, pre[MAX];	//source, sink

bool visited[MAX];

bool bfs(int s, int t) {
	queue<int> qu;
	memset(visited, false, sizeof(visited));
	memset(pre, -1, sizeof(pre));
	qu.push(s);
	visited[s] = true; pre[s] = s;
	for (int i = 0; i < adjlist[s].size(); ++i) {
		qu.push(adjlist[s][i].second);
	}
	while (!qu.empty()) {
		int p = qu.front(); qu.pop();
		for (int i = 0; i < adjlist[p].size(); ++i) {
			if (!visited[i] && adjlist[p][i].first != 0) {
				pre[i] = p; visited[p] = true;
				if (i == t) return true;
				qu.push(i);
			}
		}
	}
	return false;
}

int EK(int s, int t) {
	int maxflow = 0, d;
	while (bfs(s, t)) {
		d = INT_MAX;
		for (int i = t; i != s; i = pre[i]) {
			d = min(d, adjlist[pre[i]][i].first);
		}
		for (int i = t; i != s; i = pre[i]) {
			adjlist[pre[i]][i].first -= d;
			adjlist[i][pre[i]].first += d;
		}
		maxflow += d;
	}
	return maxflow;
}

int main() {
	cin >> M >> N;
	int  f;
	for (int i = 1; i <= M; ++i) {
		cin >> f;
		adjlist[i]
	}
}