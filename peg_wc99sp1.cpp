//http://wcipeg.com/problems/desc/wc99sp1

//Hungary algorithm

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAX 27

int SETS, A, E;
int adj[MAX][MAX];
int vis[MAX]; // stores if visited or not in dfs/bfs
int pre[MAX]; // stores the previous node

bool hungary(int x) {
	for (int i = 1; i <= E; ++i) {
		if (adj[x][i] && !vis[i]) {
			vis[i] = true;
			if (!pre[i] || hungary(pre[i])) {		//this edge is matching, see if previous node of i has another non-matching edge
				pre[i] = x;
				return true;
			}
		}
	}
	return false;		//nothing matches
}

int main() {
    cin >> SETS;
    for(int CASE = 0; CASE < SETS; ++CASE) {
        memset(adj, 0, sizeof(adj));
        memset(pre, 0, sizeof(pre));
        memset(vis,0,sizeof(vis));
        cin >> A >> E;
        cin.ignore();
        char u, v;
        while(true) {
            scanf("%c %c\n",&u,&v);
            if (u == '-')
                break;
            u= u -'a' + 1;
            v= v - 'A' + 1;
            adj[u][v] = 1;
        }
        cin.ignore(256,'\n');
        int cnt = 0;
        for (int i = 1; i <= A; ++i){
            memset(vis,0,sizeof(vis));
            if (hungary(i)) ++cnt;
        }
        if (A == cnt)
            puts("Will");
        else if (A == 0)
            puts("Neither");
        else
            puts("Ethan");
    }
}
