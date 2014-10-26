//http://wcipeg.com/problems/desc/usaconov11g3


#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
#define MAX 250

#define MAXL 250		//number of left nodes
#define MAXR 250		//number of right nodes

struct Hallway {
    int x1, x2, y1, y2;
};

int N, L, R;
int pre[MAXR];
bool vis[MAXR];

vector<int> adjlist[MAXL];
vector<Hallway> row, column;

bool hungary(int x) {
    for(int i = 0; i < adjlist[x].size(); ++i) {
        int cur = adjlist[x][i];
        if(!vis[cur]) {
            vis[cur] = true;
            if(pre[cur] == -1 || hungary(pre[cur])) {
                pre[cur] = x;
                return true;
            }
        }
    }
    return false;
}

int maxmatching() {
    int cnt = 0;
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < L; ++i) {
        memset(vis, false, sizeof(vis));
        if(hungary(i)) {
            ++cnt;
        }
    }
    return cnt;
}

bool between(int x, int low, int high) {
    if(high < low) {
        swap(low, high);
    }
    return (low <= x && x <= high);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG

    cin >> N;
    for(int i = 0; i < N; ++i) {
        Hallway cur;
        cin >> cur.x1 >> cur.y1 >> cur.x2 >> cur.y2;
        if(cur.x1 == cur.x2) {
            column.push_back(cur);
        } else {
            row.push_back(cur);
        }
    }
    L = row.size();
    R = column.size();
    for(int i = 0; i < L; ++i) {
        Hallway r = row[i];
        for(int j = 0; j < R; ++j) {
            Hallway c = column[j];
            if(between(r.y1, c.y1, c.y2) && between(c.x1,r.x1,r.x2)) {
                adjlist[i].push_back(j);
            }
        }
    }
    cout << (N - maxmatching()) << endl;
}
