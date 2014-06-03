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
static const int INF = (1<<20);

typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii> > PQ;
vector<pii> adjlist[MAX];

int N,visited[MAX], x[MAX], y[MAX], ans, CNT;
int jump[MAX];
pii cur;
int main() {
    do {
        scanf("%d", &N);
        if (N == 0) break;
        ++CNT;
        memset(visited, 0, sizeof(visited));
        memset(jump,INF,sizeof(jump));
        for (int i = 0; i < N; i++) adjlist[i].clear();
        for (int i = 0; i < N ;i++) {
            scanf("%d %d",&x[i],&y[i]);
        }
        for (int i = 0,t,tx,ty; i < N - 1 ;i++) {
            for (int j = i + 1; j < N; j++) {
                tx = x[j] - x[i];
                ty = y[j] - y[i];
                t = tx * tx + ty * ty;
                adjlist[i].pb(pii(t,j));
                adjlist[j].pb(pii(t,i));
            }
        }
        PQ.push(pii(INF,0));
        jump[0] = 0;
        while (!PQ.empty()) {
            cur = PQ.top();PQ.pop();
            #if DEBUG
            printf("At %d for %d\n", cur.second, cur.first);
            #endif // DEBUG
            if (cur.second == 1) break;
            if (visited[cur.second]) continue;
            visited[cur.second] = true;
            for (size_t i = 0; i < adjlist[cur.second].size(); i++) {
                int v = adjlist[cur.second][i].second, w = adjlist[cur.second][i].first;
                if (!visited[adjlist[v] && jump[cur.second] + w < jump[v]) {
                    jump[v] = jump[cur.second] + w;
                    PQ.push(pii(w,v));
                    #if DEBUG
                    DEBUG printf("Pushing %d for %d, ans = %d\n", adjlist[cur.second][i].second, adjlist[cur.second][i].first, ans);
                    #endif // DEBUG
                }
            }
        }
        while (!PQ.empty())PQ.pop();
        printf("Scenario #%d\n",CNT);
        printf("Frog Distance = %.3f\n\n",sqrt(jump[1]));
    } while (N != 0);

}

