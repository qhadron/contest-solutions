#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 1001
#define scan(x) while ((x=getchar())<'0'); for (x-='0'; (_=getchar())>='0' && _ <= '9';  x = (x<<1) + (x<<3) +_-'0');
char _;
typedef int data_t;

static const int INF = (data_t) 1e8;
int N, M, T, ans;
data_t dist[MAX][MAX];
int main (){
    scan(N);scan(M);scan(T);
    //scanf("%d %d %d",&N, &M, &T);
    for (int i = 0; i < N; i++,dist[i][i] = 0)
        for (int j = 0; j < N; j++)
            dist[i][j] = INF;
    for (int i =0,x,y, w; i < M; i++) {
        scan(x);scan(y);scan(w);
        //scanf("%d %d %d", &x , &y, &w);
        dist[x-1][y-1] = (data_t)w;
    }
    for (int k = 0; k < N; k++)
        for (int i = 0; i <N ;i++)
            for (int j = 0; j< N; j++)
                if (dist[i][k] != INF &&  dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j],(data_t)(dist[i][k] + dist[k][j]));
    for (int i = 0; i < N; i++) {
        ans  = max(ans,dist[i][T-1] + dist[T-1][i]);
    }
    printf("%d\n",ans);
}
/*
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

out: 10
*/
