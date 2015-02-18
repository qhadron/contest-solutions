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
int T, N;
int st[100001],inst[100001];
int t,t2, cur, x, flag;
int main() {
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif // _DEBUG
    scan(T);
    while(T--) {
        t = t2 = flag = 0;
        cur = 1;
        scan(N);
        for (int i = 0; i < N; ++i) {
            scan(x);
            inst[++t2]=x;
        }
        do {
            if (cur==N)
                break;
            x = inst[t2--];
            dvar(x);
            dvar(cur);
            dvar(t);
            while (st[t]==cur)
                --t,++cur;
            if(x != cur) {
                if (t!=0&&st[t]<x) {
                    flag=1;
                    break;
                } else {
                    st[++t]=x;
                    dvar(st[t]);
                }
            } else {
                dvar(x);
                ++cur;
            }
        } while (t2>0);

        if (flag)
            puts("N");
        else
            puts("Y");
    }
}
