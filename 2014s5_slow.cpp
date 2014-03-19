#include <cstdio>

char _;
#define scan(x) while ((x=getchar())<'0') for (x-='0';(_=getchar())>='0';x=(x<<1)+(x<<3)+_-'0');

using namespace std;


int main() {

}


/**
O(n^3) complexity, gets 9/15

#define INF = infinity
adjmatrix:
    1   2    3    4   5
0  89  116  10   13  18
1 inf  5    53   40  29
2  5   inf  82   65  50
3 53   82   inf   1  4
4 40   65   1   inf  1
5 29   50   4     1  inf


dp holds the max amount
dp[0][INF] -> dp[1][89] , dp[2][116], dp[3][10],dp[4][13],dp[5][18]
dp[1][89] -> dp[3][10],dp[4][13],dp[5][18]
....
*/

