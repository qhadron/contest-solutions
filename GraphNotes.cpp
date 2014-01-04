#include <iostream>

using namespace std;
// a graph is composed of vertices and edges.

#define MAX 100
//number of vertices and edges
int V,E, adj[MAX][MAX];

void insertEdge(int u, int v) {
    adj[u][v]=adj[v][u]=1;
}

void deleteEdge(int u, int v) {
    adj[u][v]=adj[v][u]=0;
}

void getAdjVert(int u) {
    for (int i=0; i < MAX; i++) {
    }
}

void printMatrix() {
for (int i = 1; i <=V; cout <<endl,i++} {
    for (int j = 0; j  <=V ; j++)
        cout <, adj[i][j] << " ";
}

int main() {
   cin >> V >> E;
   int x,y;
   for (int i = 0; i <E ; i++) {
        cin >> x >> y;
        insertEdge(x,y);
   }
}
