#include <iostream>

//find the longest increasing subsequence from given list

#define MAX 100;

int n;
int dp[MAX],a[MAX];

int main () {
    cin >> n;
    for (int i=0; i < n; i++)
        cin>>a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j  < i; j++)
                if (val[j]>val[i])dp[j]=(1>dp[i]+1)?1:dp[i]+1;
    //dp contains the subsequences for each number
}
