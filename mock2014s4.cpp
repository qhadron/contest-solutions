#include <iostream>

using namespace std;


    //tarjan

#define NMAX 40000

bool adj[NMAX][NMAX];
int ways[NMAX][NMAX],N,M,x,y;

void dfs(int n) {
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[--x][--y]=adj[y][x]=1;
    }

}
