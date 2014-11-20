#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

#define scan(x) while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0')
char _;
#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#else
#define dvar(...)
#endif

#define MAX 1000000

int sums[MAX],N,Q,x,y;

unsigned long long res;

int main() {
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif // _DEBUG
    scan(N);
    for (int i = 0; i < N; ++i) {
        scan(x);
        sums[i] += x;
        if (i > 0)
            sums[i] += sums[i-1];
    }
    scan(Q);
    for (int i = 0; i < Q; ++i) {
        scan(x);
        scan(y);
        --x;
        res = 0;
        res += sums[y];
        if (x >= 0)
        res -= sums[x];
        cout << res << endl;
    }
}
