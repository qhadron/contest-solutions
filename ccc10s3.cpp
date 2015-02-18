#include<iostream>
#include<stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int h,k,maxi,start,temp;
int house[1001],hose[1001];

#define puts(...)


int dist(int a,int b)
{
    temp=a-b;
    if(temp<0)
        temp=-temp;
    if(temp>500000)
        return 1000000-temp;
    return temp;
}

bool A(int a,int b,int c)
{
    if(dist(house[a],hose[b])>c)
    {
        if(b>=k)
            return false;
        hose[b+1]=house[a]+c;
        if(hose[b+1]>=1000000)
            hose[b+1]-=1000000;
        return A(a,b+1,c);
    }
    temp=a+1;
    if(temp>h)
        temp-=h;
    if(temp==start)
        return true;
    return A(temp,b,c);
}

bool B(int b, int c) {
	for (int i = 0; i < h;i++){
		hose[1]=house[i+1]+c;
		start = i+1;
		if(hose[1]>1000000)hose[1]-=1000000;
		if(A(i+1,b,c))return true;
	}
	return false;
}

int main()
{
    cin>>h;
    cin>>house[1];
    for(int i=2; i<=h; i++)
    {
        scanf("%d",&house[i]);
    }
	sort(house+1, house+h+1);
	puts("here");
    cin>>k;
    int l=0,r=500000, ans=0;
    while(l<=r)
    {
	puts("here");
    	int m = l + r >> 1;
        if(B(1,m)){
			r = m-1;
	puts("here");
    		ans=m;
		}
        else l = m+1;
    puts("here");
    }

    cout<<ans<<endl;
}
