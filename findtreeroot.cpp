/**
* finds the root of a given tree
* input:
* two integers N ( number of Vertices) and M (number of edges)
* the next M lines:
* two integers x , y (1 <= x,y <= N) indicating a connection from x to y
*
*
* output:
* the index of the root of the tree, or -1 if the given graph is not a tree
*/

#include <iostream>
#include <vector>		//vector
#include <cstring> 		//memset
using namespace std;

int N, M;
int r[10001], p[10001];				//rank, parent

vector<int> adjlist[10001];
int parent[10001];

int find(int x) {
	if (p[x] == -1) p[x] = x;
	return x==p[x]?p[x]:(p[x] = find(p[x]));
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (r[x] > r[y]) {
        p[y] = x;
	}
    else {
        p[x] = y;
        if (r[x]==r[y])r[y]++;
    }
}


int dfs(int cur) {
	if (parent[cur])
		return dfs(parent[cur]);
	return cur;
}

int main() {
	memset(p,-1,sizeof(p));
	scanf("%d %d", &N, &M);
	if (N - M != 1) goto _end;	//wrong num of edges
	for (int i = 0,x,y; i < M; ++i) {
		scanf("%d %d", &x,&y);
		adjlist[x].push_back(y);
		if(parent[y] != 0) goto _end;	//node already has parent
			parent[y] = x;
	}
	//almost kruskal
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < adjlist[i].size(); ++j)
			if (find(i) == find(adjlist[i][j])) 
				goto _end;			//cycle
			else
				join(i,adjlist[i][j]);
	//find root
	cout << dfs(1) << endl;
	return 0;
	_end:
	cout << "-1" << endl;
}