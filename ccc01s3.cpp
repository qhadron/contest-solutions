#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#else
#define dvar(...)
#endif

bool adj[26][26];

vector<string> paths;
string s;

void floyd(int a, int b) {
    memset(adj, 0, sizeof(adj));
    for(int i = 0; i < paths.size(); ++i) {
        int x = paths[i][0] - 'A', y = paths[i][1] - 'A';
        adj[x][y] = adj[y][x] = true;
    }
    adj[a][b] = adj[b][a] = false;

    for(int k = 0; k < 26; ++k)
        for(int i = 0; i < 26; ++i)
            for(int j = 0; j < 26; ++j)
                if(adj[i][k] && adj[k][j]) {
                    adj[i][j] = adj[j][i] = true;
                }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG
    while(true) {
        getline(cin, s);
        if(s == "**") {
            break;
        }
        paths.push_back(s);
    }
    int cnt = 0;
    for(int i = 0; i < paths.size(); ++i) {
        int a = paths[i][0] - 'A', b = paths[i][1] - 'A';
        floyd(a, b);
        if(!adj[0][1]) {
            cout << paths[i] << endl;
            ++cnt;
        }
    }
    printf("There are %d disconnecting roads.", cnt);
}
