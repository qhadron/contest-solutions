//http://wcipeg.com/problems/desc/acmtryouts1d

/*
	algorithm:
	1. connect all non T nodes with edge capacity of 1
	2. find max flow
	3. done
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

#ifdef _DEBUG
#define _debug(x) x;
#define dprintf(...) printf(__VA_ARGS__)
#else
#define _debug(...)
#define dprintf(...)
#endif

#define C(x,y) ((x)+(y)*7)

#define MAX 50

typedef pair<int, int> pos_t;

int T, H, W;
char grid[7][7];
int pre[MAX], r[MAX][MAX];
bool vis[MAX];

bool BFS(int s, int t) {
	queue<int> que;
	memset(pre,-1,sizeof(pre));
	memset(vis,false,sizeof(vis));
	pre[s] = s; vis[s] = true;
	que.push(s);
	while(!que.empty()) {
		int p = que.front(); que.pop();
		for (int i = 1; i <= MAX; ++i) {
			if (r[p][i] > 0 && !vis[i]) {	//still residue
				pre[i] = p; vis[i] = true;
				if (i == t) return true;
				que.push(i);
			}
		}
	}
	return false;
}

int EK(int s, int t) {
	int maxflow = 0, d;
	while(BFS(s,t)) {		//find shortest augmenting path from s to t
		d = INT_MAX;
		for (int i = t; i != s; i = pre[i]) {
			d=min(d,r[pre[i]][i]);	//back track to find the min number in residue network
		}
		for(int i = t; i != s; i = pre[i]) {
			r[pre[i]][i] -= d;		//decrease residue in positive direction
			r[i][pre[i]] += d; 		//increase residue in negative direction
		}
		maxflow += d;
	}
	return maxflow;
}

int main() {
    _debug(freopen("input.txt", "r", stdin);)
    scanf("%d", &T);
    while(T--) {
         memset(r,0,sizeof(r));

        scanf("%d %d", &H, &W);
        for(int i = 1; i <= H; ++i) {
            scanf("%s", grid[i] + 1);
        }
        _debug(
            for(int i = 1; i <= H; ++i)
            puts(grid[i]+1);
        )
        int farmer = -1, house = -1;
            for(int i = 1; i <= H; ++i)
                for(int j = 1; j <= W; ++j) {
                    _debug(printf("At (%d,%d)=%c looking for 'F'\n", i, j, grid[i][j]);)
                    if(grid[i][j] == 'F') {
                        _debug(printf("found F at (%d,%d)\n", i, j);)
                        farmer = C(i,j);
                    }
                    else if (grid[i][j] == 'H') {
                        dprintf("Found H at (%d, %d)\n", i, j);
                        house = C(i,j);
                    }
                    if (grid[i][j] != 'T') {
                        for (int dx = -1; dx < 2; ++dx) {
                            for (int dy = -1; dy < 2; ++dy) {
                                if (dx + dy != 0 && dx != dy&&i+dx>0&&i+dx<7&&j+dy>0&&j+dy<7) {
                                    if (grid[i+dx][j+dy] != 'T') {
                                        r[C(i,j)][C(i+dx,j+dy)] = 1;
                                    }
                                }
                            }
                        }
                    }
                }
        cout << EK(farmer,house) << endl;
    }

}

