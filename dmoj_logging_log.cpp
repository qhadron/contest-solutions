#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define scan(x) while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0')
char _;
#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#else
#define dvar(...)
#endif

int N,cursum,D,x,cnt;

int main() {
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif // _DEBUG
    scan(D);
    while (D--) {
        cnt++;
        scan(N);
    cursum = 0;
        while (N--) {
            scan(x);
            cursum += x;
        }
        if (cursum)
        printf("Day %d: %d\n",cnt,cursum);
        else
            puts("Weekend");
    }
}
