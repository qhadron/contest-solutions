/**
* Checks for cycles in a (non-directed) graph
* input:
* two integers N ( number of Vertices) and M (number of edges)
* the next M lines:
* two integers x , y (1 <= x,y <= N) indicating a connection between x and y
*
* output:
* "yes" or "no"
*/

#include <iostream>
#include <vector>		//vector
#include <cstring> 		//memset

using namespace std;

int N, M;
int r[10001], p[10001];				//rank, parent

vector<int> adjlist[10001];


int find(int x) {
	if (p[x] == -1) p[x] = x;
	return (x==p[x])?p[x]:(p[x] = find(p[x]));
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


int main() {
	memset(p,-1,sizeof(p));
	scanf("%d %d", &N, &M);
	if (false && M >= N) {
		cout << "yes" << endl;
		return 0;
	}
	for (int i = 0,x,y; i < M; ++i) {
		scanf("%d %d", &x,&y);
		adjlist[x].push_back(y);
	}
	//almost kruskal
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < adjlist[i].size(); ++j)
			if (find(i) == find(adjlist[i][j]))  {
				cout << "yes" << endl;	//cycle
				return 0;
			}
			else
				join(i,adjlist[i][j]);
	cout << "no" << endl;
}