#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define scan(x) while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0')
char _;
#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#else
#define dvar(...)
#endif

#define MAX 201
/*
    dp[i][j] is max score with interval from i to j
    dp[i][j] =  0                                       ; if j<=i+1
                max(dp[i][k] + dp[k][j] + ai + ak + aj  ; otherwise
*/

int arr[MAX], N;
bool removed[MAX];
int dp[MAX][MAX];

int dfs(int sum, int level) {
    int m = 0, mi = -1;
    for(int i = 1; i < N - 1; ++i) {
        if(!removed[i]) {
            removed[i] = true;
            int j = -1, k = -1, flag = 0;
            for(j = i - 1; j >= 0; --j)
                if(!removed[j]) {
                    flag = 1;
                    break;
                }
            if(!flag) {
                continue;
            }
            flag = 0;
            for(k = i + 1; k < N; ++k)
                if(!removed[k]) {
                    flag = 1;
                    break;
                }
            if(!flag) {
                continue;
            }
            int temp = dfs(sum, level + 1) + arr[i] + arr[j] + arr[k];
            if(temp > m) {
                mi = i;
                m = temp;
            }
            removed[i] = false;
        }
    }
    return sum + m;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG
    while(true) {
        scanf("%d", &N);
        if(!N) {
            break;
        }
        for(int i = 0; i < N; ++i) {
            scanf("%d", &arr[i]);
        }
        memset(removed, 0, sizeof(removed));
        memset(dp, 0, sizeof(dp));
        for(int len = 2; len < N; ++len) {
            for(int i = 0; i < N; ++i) {
                int j = i + len;
                if(j > N) {
                    break;
                }
                for(int k = i + 1; k < j; ++k)
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k] + dp[k][j] + arr[i] + arr[j] + arr[k]);
            }
        }
        cout << dp[0][N - 1] << endl;
    }
}
