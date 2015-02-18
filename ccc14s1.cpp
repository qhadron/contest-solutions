
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define scan(x) while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0')
char _;
#ifdef _DEBUG
#define dvar(x) printf("%s:%d\n",#x,x);
#else
#define dvar(...)
#endif
int K, M, r;
bool F[101];
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG
    scan(K);
    scan(M);
    while(M--) {
        scan(r);
        for(int i = 1,cur=0, t = r; i <= K; ++i) {
            if(F[i]) {
                continue;
            }
            if(++cur == t) {
                F[i]=
                t += r;
            }
        }
    }
    for(int i = 1; i <= K; ++i)
        if(!F[i]) {
            printf("%d\n", i);
        }
}

