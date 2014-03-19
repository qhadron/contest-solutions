#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 101

bool adj[MAX][MAX],visited[MAX];

int N,cnt,e;

set<vector<int> > paths;

/**
    Algorithm:
    1.use dfs to find every path
    2.add to set if path cycle
    3.count size of set
*/

void check(int n, vector<int> path, int start) {
    path.push_back(n);
    for (int i = 1; i <= N; i++) {
        if (adj[n][i]) {
            if (i==start&&path.size()>2) {
                sort(path.begin(),path.end());
                paths.insert(path);
                continue;
            }
            if (find(path.begin(),path.end(),i)==path.end())
                check(i,path,start);
        }
    }
};

inline bool get(int& x) {
    char c = getchar();
    while (c<'0'&&(c=getchar()));
    for (x=c-'0';(c=getchar())>='0';x=(x<<1)+(x<<3)+c-'0');
    return true;
}

vector<int> * temp;

int main(void) {
    puts("Enter the number of vertices:");
    get(N);
    puts("Enter the number of edges:");
    get(e);
    puts("Enter the edges:");
    for (int x,y; e--;adj[x][y]=adj[y][x]=true) {
        get(x);
        get(y);
    }
    for (int i = 1; i <= N; i++) {
        temp = new vector<int>;
        check(i,*temp,i);
        delete temp;
    }
    printf("The number of cycles is %d\n",paths.size());
    for (auto it = paths.begin(); it!=paths.end(); ++it) {
        for (int i = 0; i < it->size(); i++) {
            cout << (*it)[i] <<  ((i!=it->size()-1)?"->":"\n");
        }
    }
}

