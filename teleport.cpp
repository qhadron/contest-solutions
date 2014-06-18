//finds the number of spanning trees given a graph

#include <iostream>
#include <vector>		//vector
#include <cstring> 		//memset

using namespace std;

int N, M;
int r[10001], p[10001];				//rank, parent for disjoint set

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
				//do nothing
			}
			else
				join(i,adjlist[i][j]);
	//resuse array r
	memset(r,0,sizeof(r));
	for(int i = 1; i <= N; ++i) {
		r[find(i)]=1;
	}
	int result = 0;
	for (int i = 1; i <= N; ++i)
		result += r[i];
	cout << ((result==1)?0:result) << endl;
}