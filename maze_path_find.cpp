#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int adj[5][5] = {
    {
        0,1,0,0,0
    },
    {
        0,1,0,1,0
    },
    {
        0,0,0,0,0
    },
    {
        0,1,1,1,0
    },
    {
        0,0,0,0,0
    }
};

vector<pair<int,int> > path;

bool t[5][5];

bool dfs(int x, int y) {
    t[x][y]=true;
    if (x==4&&y==4) {
       path.push_back(make_pair(x,y));
       return true;
    }
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
    if (i!=j&&i+j!=0&&x+i>=0&&x+i<5&&y+j>=0&&y+j<5) {
        if (adj[x+i][y+j]==0&&!t[x+i][y+j]) {
            if (dfs(x+i,y+j)) {
                path.push_back(make_pair(x,y));
                return true;
            }
        }
    }
    return false;
}

int main(void){
    dfs(0,0);
    for (int i = path.size()-1; i >= 0; --i) {
        cout << "(" << (path[i].first) << "," << (path[i].second) << ")" << endl;
    }
};
