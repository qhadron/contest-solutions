#include <iostream>

#define FOR(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define p(x)
using namespace std;

int main() {
    int c[3];
    bool t[3][100];
    int cost = 0;
    cin >> c[0] >> c[1] >> c[2];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 100; j++)
            t[i][j]=false;
    for (int i = 0; i < 3; i++) {
        int x,y;
        cin >> x >> y;
        for (int j = x; j < y; j++)
            t[i][j] = true;
    }
    for (int i = 0; i < 100; i++) {
        int cnt = 0;
        for (int j = 0; j < 3; j++)
            cnt += (t[j][i])?1:0;
        if (cnt > 0)
        cost += cnt * c[cnt-1];
        p(cost)
    }
    cout << cost << endl;
}
