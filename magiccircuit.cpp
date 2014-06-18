#include <iostream>

using namespace std;

#define MAX 1001

int adj[MAX][MAX],visited[MAX],N,M,X,Y, cnt;

bool dfs(int cur) {
	//printf("At %d\n" ,cur);
	if (cur == Y) return true;
	visited[cur] = true;
	for(int i = 1; i <= N; ++i)
		if (!visited[i] && adj[cur][i]) {
			//printf("Visiting %d from %d\n",i,cur);
			if (dfs(i) && cur != X) {
				
				visited[cur] = false;	//each level is responsible for popping itself off the stack
				return true;
			}
		}
	if (cur == X) return true;
	//printf("Cannot reach from %d\n", cur);
	++cnt;
	visited[cur] = false;
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> X >> Y;
		adj[X][Y] = true;
	}
	cin >> X >> Y;
	//printf("start: %d\t end: %d\n\n", X, Y);
	dfs(X);
	cout << cnt << endl;
}