//TODO
//Implement subtraction

#include <cstdio>
#include <cstring>
#include <algorithm>

#ifdef _DEBUG
#define _debug(x) x;
#define dprintf(...) printf(__VA_ARGS__)
#else
#define _debug(...)
#define dprintf(...)
#endif

#define MAX 100000
#define ival(x) (x)-'0'
#define sval(x) (x)+'0'

using namespace std;
char a[2*MAX],b[2*MAX],c;
int sum,i,n,sa=1,sb=1,la,lb;
int getNum(char* str) {
    int n = 0, sgn;
    while((c=getchar())!='\n') {
        if (c=='-')
            n*=-1;
        else
            str[n++] = c;
    }
    //reverse
    for (int l = 0, r = n-1; l < r; ++l,--r) {
        c=str[l];
        str[l] = str[r];
        str[r] = c;
    }
    return n;
}

int main(int argsc, char** argsv) {
    _debug(freopen("input.txt","r",stdin))
    la = getNum(a);
    if (la < 0)
        la*=(sa=-1);
    lb = getNum(b);
    if (lb < 0)
        lb*=(sb=-1);
    dprintf("%s + %s = ",a, b);
    if (sa==sb)
    for (int carry=0;i<n||carry; ++i) {
        if (a[i] == 0)
            a[i]='0';
        if (b[i] == 0)
            b[i]='0';
        sum = ival(a[i]) + ival(b[i]) + carry;
        if (sum >= 10) {
            carry = 1;
            sum-=10;
        }
        else
            carry = 0;
        a[i] = sval(sum);
    }
    dprintf("%s\n",a);

    //reverse
    reverse(a,a+i);
    puts(a);
}
