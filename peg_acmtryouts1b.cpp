//http://wcipeg.com/problems/desc/acmtryouts1b

#include <cstdio>
#include <cstring>  //memset
#include <vector>
using namespace std;

int gcd(int a, int b) {
    return b==0?a:a>b?gcd(b,a%b):gcd(a,b%a);
}

int lcm(int a, int b) {
    return a / gcd(a,b) * b;
}


int s[5],h[5],a[5];
int T,N;
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while (T--) {
        //memset(num,0,sizeof(num));
        scanf("%d",&N);
        for (int j = 0; j < N; ++j) {
            int x, y, hour;
            scanf("%d %d %d",&x,&y,&hour);
            a[j] = x;
            s[j] = x+y;
            h[j] = hour;
        }
        int lim = s[0];
        for (int i = 1; i < N; ++i)
            lim = lcm(lim,s[i]);
        vector<int> num(lim+24,0);
        for (int j = 0; j < N; ++j)
            for (int i = h[j], cnt = 0; i < lim + h[j]; ++i,++cnt) {
                    if (i%s[j] < a[j])
                        num[cnt]++;
            }
        bool flag = false;
        for (int i = 0; i < lim; ++i) {
            if (num[i]==0) {
                printf("%d\n",i);
                flag = true;
                break;
            }
        }
        if (!flag)
            puts("Foxen are too powerful");
    }
}
