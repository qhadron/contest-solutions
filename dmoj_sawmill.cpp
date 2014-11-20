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

#define MAX 50001
unsigned long long N,e[MAX],l[MAX];

unsigned long long res;

int main() {
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif // _DEBUG
    cin >> N;
    for (unsigned long long i = 0; i < N; ++i) {
        cin >> e[i];
    }
    for (unsigned long long i = 0; i < N; ++i) {
        cin >> l[i];
    }
    sort(e,e+N);
    sort(l,l+N);
    for (unsigned long long i = 0; i < N; ++i)
        res+=e[i]*l[N-i-1];
    cout << res << endl;
}
