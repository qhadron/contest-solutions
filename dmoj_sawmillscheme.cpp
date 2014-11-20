#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

#define scan(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0);
char _;
#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

#define MAX 1000001

int N, M;
long double dp[MAX];
vector<int> adj[MAX];
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    scan(N);
    scan(M);
    for(int i = 0, x, y; i < M; ++i) {
        scan(x);
        scan(y);
        if(x < y) {
            adj[x].push_back(y);
        } else {
            adj[y].push_back(x);
        }
    }
    dp[1] = 1;
    for(int i = 1; i <= N; ++i) {
        for(auto next : adj[i]) {
            dp[next] += dp[i] / (long double)adj[i].size();
        }
    }

    cout.precision(15);
    for(int i = 1; i <= N; ++i) {
        if(adj[i].size() == 0) {
            cout << dp[i] << '\n';
        }
    }
    cout.flush();
}
