#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1001
#define pb(x) push_back(x)
#define DEBUG 0
const int INF = (int)1e8;

typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, less<pii> > PQ;
vector<pii> adjlist[MAX];
bool visited[MAX];
int N, M, a, b, CNT, T, w, len[MAX];
pii cur;
int main() {
    scanf("%d", &T);
    while (T--) {
        ++CNT;
        memset(visited, 0, sizeof(visited));
        memset(len,INF,sizeof(len));
        for (int i = 1; i <= N; i++) adjlist[i].clear();

        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &a, &b, & w);
            adjlist[a].pb(pii(w,b));
            adjlist[b].pb(pii(w,a));
        }
        PQ.push(pii(INF,1));
        while (!PQ.empty()) {
            cur = PQ.top();PQ.pop();
            if (visited[cur.second]) continue;
            #if DEBUG
            printf("At %d for %d, ans = %d\n", cur.second, cur.first, ans);
            #endif // DEBUG
            if (cur.second == N) break;
            visited[cur.second] = true;
            for (size_t i = 0; i < adjlist[cur.second].size(); i++) {
                int u = adjlist[cur.second][i].first,v = adjlist[cur.second][i].second;
                if (!visited[v] && len[cur.second] + u > len[v]) {
                    len[v] = len[cur.second] + u;
                    PQ.push(pii(len[v],u));
                    #if DEBUG
                    printf("Pushing %d for %d\n", adjlist[cur.second][i].second, adjlist[cur.second][i].first);
                    #endif // DEBUG
                }
            }
        }
        while (!PQ.empty())PQ.pop();
        printf("Scenario #%d\n%d",CNT,len[N]);
    }
    return 0;
}

