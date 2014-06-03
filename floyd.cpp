#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 1001
static const int INF = (int) 1e8;
int dist[MAX][MAX], adj[MAX][MAX], N, M;

int main (){
    scanf("%d %d",&N,&M);
    for (int i = 0; i < N; i++,dist[i][i] = 0)
        for (int j = 0; j < N; j++)
            dist[i][j] = INF;
    for (int i =0,x,y, w; i < M; i++) {
        scanf("%d %d %d", &x , &y, &w);
        dist[x][y] = w;
    }
    for (int k = 0; k < N; k++)
        for (int i = 0; i <N ;i++)
            for (int j = 0; j< N; j++)
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
    for (int i = 0; i < N; i++,printf("\n"))
        for (int j = 0; j < N; j++)
            printf("%d ",dist[i][j]);
    printf("done!\n");
}
/*
5 9
0 1 10
0 2 3
1 3 2
1 2 1
2 1 4
2 3 8
2 4 2
3 4 7
4 3 9

out:
0 7 3 9 5
- 0 1 2 3
- 4 0 6 2
- - - 0 7
- - - 9 0
*/
