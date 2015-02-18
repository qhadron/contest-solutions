#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

#define INF 0xfffff

int c,r,d,x,y,tmp,weight = INF, dist[10001];
priority_queue<pair<int,int> > Q;
vector<pair<int, int> > adjlist[20001];
bool visited[10001],dest[10001];
pair<int,int> t1;
//pair stores cost, dest
void prim(int start) {
    Q.push(make_pair(INF,1));
    while (!Q.empty()) {
        t1 = Q.top();Q.pop();
        if (dest[t1.second]<t1.first||!visited[t1.second]) {
            visited[t1.second] = true; dist[t1.second]=t1.first;
            for (int i = 0; i < adjlist[t1.second].size(); i++) {
                if (!visited[adjlist[t1.second][i].second]) {
                    Q.push(adjlist[t1.second][i]);
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d",&c,&r,&d);
    for(int i=1; i<=r; i++){
        scanf("%d %d %d", &x, &y, &tmp);
        adjlist[x].push_back(make_pair(tmp, y));
        adjlist[y].push_back(make_pair(tmp, x));
    }
    for(int i=1; i<=d; i++){
        scanf("%d ", &tmp);
        dest[tmp] = true;
    }
    prim(1);
    for(int i=0; i<=c; i++)
        if(dest[i]) weight=min(weight, dist[i]);
    printf("%d\n", weight);
}
