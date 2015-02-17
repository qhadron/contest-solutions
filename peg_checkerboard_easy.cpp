//http://wcipeg.com/problems/desc/cheasy

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 3001

inline int lastbit(int x) {
    return x&(-x);
}

inline bool isOdd(int x, int y) {
    return ((x + y) & 1);
}

int tree[MAX][MAX];

int M,N;

void update(int x, int y, int val) {
    for (int i = x; i <= M; i+=lastbit(i))
        for (int j = y; j <= N; j+=lastbit(j))
            tree[i][j] += val;
}

int sum(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i-=lastbit(i))
        for (int j = y; j > 0; j-=lastbit(j))
            res += tree[i][j];
    return res;
}

int sumTo(int x1, int y1, int x2, int y2) {
    return sum(x2,y2) - sum(x1-1,y2) - sum(x2,y1-1) + sum(x1-1,y1-1);
}

int main() {
    int r,c,x;
    cin >> M >> N;
    while(true) {
        cin >> r >> c >> x;
        if (r+c+x == 0)
            break;
        if (isOdd(r,c))
            update(r,c,x);
        else
            update(r,c,-x);
    }
    int r1,c1,r2,c2;
    while (scanf("%d %d %d %d",&r1,&c1,&r2,&c2)) {
        if (r1+c1+r2+c2==0)
            break;
        if (isOdd(r1,c1))
            cout << sumTo(r1,c1,r2,c2) << endl;
        else
            cout << -sumTo(r1,c1,r2,c2) << endl;
    }

}
