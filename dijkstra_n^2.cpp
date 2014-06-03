#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 100
int main()
{
    int adj[MAX][MAX];
    int N, M;
    cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			adj[i][j] = 0xffff;
    for (int x,y,w; M--;) {
        cin >> x >> y >> w;
        adj[x][y] = adj[y][x] = w;
    }
    int cur = 0, end = N-1, next, m;
    int dist[MAX], prev[MAX], visited[MAX];
    for (int i = 0; i < N; i++) visited[i] = 0 & (dist[i] = prev[i] = 0xffff);
	dist[0] = 0;
	int __cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        m = 0xffff;
		visited[cur] = true;
		cout << cur << ":\n";
		for (int j = 0; j < N; j++) {
			if (visited[j]) continue;
            if (dist[cur] + adj[cur][j] < dist[j]) {
                dist[j] = dist[cur] + adj[cur][j];
				prev[j] = cur;
			}
			if (dist[j] < m) {
				m = dist[j];
				next = j;
				cout << "Considering " << j << endl;
			}
			__cnt++;
        }
		if (cur == next) break;
		cur = next;
		cout << endl;
	}
	cout << endl;
	string out [MAX];
	for (int i = 0,j = 0,cnt = 0; j < N ;j++,cnt = 0) {
		i = j;
		if (prev[i] != 0xffff)
			out[j] += to_string(i);
		while ((i=prev[i]) != 0xffff) {
			out[j] = "->" + out[j];
			out[j] = to_string(i) + out[j];
		}
	}
	sort(out,out+N);
	stable_sort(out,out+N,[](const string& a, const string& b){return a.size() > b.size();});
	for (int i = 0,flag = 1; i < N; i++, flag = 1) {
		cout << out[i] << endl;
	}
    for (int i = 0; i < N; i++) {
        cout << dist[i] <<  " "; 
    }
	cout << "\ncnt:"<<__cnt<<endl;
    return 0;
}


/*
src: http://usna.edu/Users/cs/roche/courses/s12si335/u06/ex2color.png
5
8
0 2 6
0 3 3
0 1 6
2 4 1
2 3 5
3 4 4
1 4 4 
1 3 2

output: 0 5 6 3 7


src: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

output: 0 4 12 19 21 11 9 8 14
*/