#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1001
int v[MAX],r[MAX];
int adj[MAX][MAX];
int c,d,dest[MAX];

typedef pair<int, int> ii;

bool cmp(const ii& x, const ii& y) {
    return adj[x.first][x.second] > adj[y.first][y.second];
}

vector <ii> vec;

void make(int x) {
    v[x] = x;
    r[x] = 0;
}

int f(int x) {
    return (v[x]==x)?x:x=f(v[x]);
}

void join(int x, int y) {
    if (r[x] > r[y])
        v[y] = x;
    else {
        v[x] = y;
        if (r[x]==r[y])r[y]++;
    }
}

bool indest(int x) {
    for (int i = 0; i < d; i++)
        if (dest[i]==x)
            return true;
    return false;
}

int kruskal(int start) {
    for (int i = 0; i < MAX; i++)
        make(i);
    int m = 0xffffff;
    for (auto i : vec) {

        if (adj[i.first][i.second]&&f(i.first)!=f(i.second)&&((indest(i.first)||indest(i.second)))) {
            //join(start,i.first);
            //join(start,i.second);
            //cout << adj[i.first][i.second] << endl;
            join(i.first,i.second);
            m = (adj[i.first][i.second] < m)?adj[i.first][i.second]:m;
        }
    }
    return m;
}

int main1() {
    int a;
    cin >> c >> a>> d;
    for (int i = 0,x,y; i < a; i++) {
        cin >> x >> y;
        cin >> adj[x][y];
        vec.push_back(make_pair(x,y));
    }
    for (int i = 0;  i < d; i++)
        cin >> dest[i];
    sort(vec.begin(),vec.end(),cmp);
    cout << kruskal(1) << endl;
    for (int i = 0; i < c; i++) {
        if (f(i)==f(dest[0]));
            //cout << i << " ";
    }
}
/*
5 7 3
1 2 20
1 3 50
1 4 70
1 5 90
2 3 30
3 4 40
4 5 60
2 4 5
*/
