//http://wcipeg.com/problems/desc/mockccc14s5

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;


#define MAX 100

int N, M, black[MAX], white[MAX], pre[MAX];
bool adj[MAX][MAX],vis[MAX];

int gcd(int a, int b) {
    if (b > a)
        return gcd(b,a);
    int t;
    while(b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

#define L N		//number of left nodes
#define R M		//number of right nodes

bool hungary(int x) {
    for(int i = 0; i < R; ++i) {
        if(adj[x][i] && !vis[i]) {
            vis[i] = true;
            if(pre[i] == -1 || hungary(pre[i])) {
                pre[i] = x;
                return true;
            }
        }
    }
    return false;
}

int maxmatching() {
	int cnt = 0;
	memset(pre,-1,sizeof(pre));
	for(int i = 0; i < L; ++i) {
		memset(vis, false, sizeof(vis));
		if(hungary(i)) {
			++cnt;
		}
	}
	return cnt;
}

int main() {
    #ifdef _DEBUG

    freopen("input.txt","r",stdin);
    #endif // DEBUG
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        scanf("%d ", &black[i]);
    }
    for(int i = 0; i < M; ++i) {
        scanf("%d", &white[i]);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (gcd(black[i],white[j]) > 1) {
                adj[i][j] = true;
                //printf("Connected (%d,%d)\n",black[i],white[j]);
            }
        }
    }
    cout << 2*maxmatching() << endl;
}
