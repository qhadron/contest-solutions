#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define scan(x) while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');
char _;

typedef long long ll;

struct seg
{
    int x,y1,y2,val;
    bool flag;//first(1) or last(0)
    seg(){};
    seg(int a, int b, int c, ll d, bool fl) {
        x=a,y1=b,y2=c,val=d,flag=fl;
    }
} point [3001];
int n,c,t,indy,len,ind,val,segy[3001],x1,y1,x2,y2,st,ed;
ll ans,line[3001];

int findy(int x) { // binary search
    int l = 1, h=len;
    while (l<h) {
        int mid=(l+h)>>1;
        if (segy[mid]>=x) h=mid;
        else l=mid+1;
    }
    return l;
}

bool cmp(seg p1, seg p2) {
    return p1.x<p2.x;
}

int main() {
    scan(n);scan(t);
    indy=ind=1;//index
    for (int i = 0; i < n ; i++) {
        scan(x1)
        scan(y1)
        scan(x2)
        scan(y2)
        scan(val)
        point[ind++]=seg(x1,y2,y2,val,true);
        point[ind++]=seg(x2,y1,y2,val,false);
        segy[indy++]=y1;
        segy[indy++]=y2;
    }
    sort (point+1,point+ind,cmp);
    sort (segy+1,segy+indy);
    len=unique(segy+1,segy+indy)-(segy+1);
    for (int i = 1; i < ind; i++) {
        for (int j = 1; j < len; j++) {
            if (line[j]>=t)
                ans+=(ll)(segy[j+1]-segy[j])*(point[i].x-point[i-1].x);
        }
        if (point[i].flag)
            c=point[i].val;
        else
            c=-point[i].val;
            st=findy(point[i].y1); ed=findy(point[i].y2);
        for (int j=st;j<ed;j++)line[j]+=c;
    }
    printf("%lld",ans);
}



/**
question:
    lay glass to get to a tint factor (T)
    overlapping glasses add their tint factors
    glass given by top-left coord and bot-right coord

solution:
    sweep line algorithm:
        sort the y values, removing duplicates
        loop {
        1.imagine a line sweeping from left to right
            if meet a glass
                add 1 to tint from top to bot
            else if leave glass
                sub 1 from tint from top to bot
        2. if greater or equal to T, add 1 to total
        }end loop
*/
