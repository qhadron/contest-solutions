#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define SIZE 201
#define INF 0x7ffff
typedef pair<int,int> pii;
typedef vector<pii> vpii;

vpii adjlist[SIZE];
bool cmp(pii& a, pii& b) {
    return a.second > b.second;
}
vpii PQ;
int n,CNT,dist[SIZE];
bool visited[SIZE];
int main() {
    do {
        cin >> n;
        if (n==0) break;
        CNT++;
        fill(dist,dist+SIZE,INF);
        for (int i =0,x,y,c; i < n; i++) {
            cin >> x >> y >> c;
            adjlist[x].push_back(make_pair(y,c));
            adjlist[y].push_back(make_pair(x,c));
        }
        for (int i = 0; i < adjlist[0].size(); i++)
            PQ.push_back(adjlist[0][i]);
        dist[0] = 0;
        #define parg PQ.begin(),PQ.end(), cmp
        make_heap(parg);
        while (!PQ.empty()) {
            pop_heap(parg);
            pii cur = PQ.front();
            PQ.pop_back();
            dist[cur.first] = cur.second;
            visited[cur.first] = true;
            for (int i = 0; i < adjlist[cur.first].size(); i++) {
                if (dist[i] == INF) {
                    PQ.push_back(make_pair(adjlist[cur.first][i].first, (dist[i] = min(dist[i],dist[cur.first] + adjlist[cur.first][i].second))));
                    push_heap(parg);
                }
            }
        }
        printf("Scenario #%d\n",CNT);
        printf("Frog Distance = %.3f\n",sqrt(dist[1]));
    }while (n!=0) ;
}
/*
3
17 4
19 4
18 5
*/
