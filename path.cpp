#include <iostream>

using namespace std;
#define MAX 10001

int N, M, A, B;
bool visited[MAX], adj[MAX][MAX];
bool dfs(int cur) {
	if (cur == B) return true;
	visited[cur] = true;
	for (int i = 1; i <= N; ++i)
		if (!visited[i] && adj[cur][i] && dfs(i))
			return true;
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0, x,y; i < M; ++i) {
		scanf("%d %d", &x, &y);
		adj[x][y] = true;
	}
	scanf("%d %d", &A, &B);
	cout << (dfs(A)?"yes":"no") << endl;
}