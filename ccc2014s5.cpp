#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pii;

pair<int, pii> dist[2001 * 2002];
#ifdef _DEBUG
#define dvar(x) printf("%s:%d\n",#x,x);
#else
#define dvar(...)
#endif

#define INF 100000000


int N, dp[2001], dp2[2001];
int x[2001], y[2001], cnt;

int cdist(int a, int b) {
    int dx = x[a] - x[b], dy = y[a] - y[b];
    return dx * dx + dy * dy;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }

    for(int i = 0; i < N; ++i) {
        for(int j = i + 1, temp; j <= N; ++j) {
            temp = cdist(i, j);
            dist[cnt++] = make_pair(temp, make_pair(i, j));
        }
    }
    sort(dist, dist + cnt);
    pii cur;
    set<int> Set;
    for(int i = 0; i < cnt;) {
        Set.clear();
        do {
            cur = dist[i].second;
            if(cur.first == 0) {
                dp2[cur.first] = max(dp2[cur.first], dp[cur.second]);
            } else {
                dp2[cur.first] = max(dp2[cur.first], dp[cur.second] + 1);
                dp2[cur.second] = max(dp2[cur.second], dp[cur.first] + 1);
            }
            Set.insert(cur.first);
            if(cur.first) {
                Set.insert(cur.second);
            }
            i += 1;
        } while(i < cnt && dist[i - 1].first == dist[i].first);
        for(auto it = Set.begin(); it != Set.end(); ++it) {
            dp[*it] = dp2[*it];
        }
    }
    printf("%d\n", dp[0] + 1);
}

/**
longest increasing subsequence

dp with sort:
1. get all dist, sort, and store with info about [start][dest]
for l=0; l < ind; l=r+1 //move past the found positions
{
    while (next dist) == dist(l)
        r++
    store the points to get from curpoint to nextpoint
    store the curnum+1 to dp[nextpoint]
}
*/
