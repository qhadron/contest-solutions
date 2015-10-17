//http://www.codechef.com/JUNE15/problems/STDYTAB

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;
#ifndef WIN32
#ifdef getchar
#undef getchar
#endif
#define getchar getchar_unlocked
#endif
#define scanp(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _, __;
static inline void scan(int& x) {
	__ = 0;
	while ((x = getchar()) < '-');
	if (x == '-')
		__ = 1, x = getchar();
	for (x -= '0'; (_ = getchar()) >= '0' && (_ <= '9'); x = (x << 1) + (x << 3) + _ - '0');
	if (__)
		x = -x;
}
#ifdef _DEBUG
#define dvar(x) cout << (#x) << ":" << (x) << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

typedef pair<int, int> ii;
typedef long long ll;

#define INF 0x3f3f3f3f

#define MAX 2001

const int K = (int)1e9;
int N, M, T, dp[MAX][MAX];


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	cin.tie(0);
	ios::sync_with_stdio(false);
#endif // _DEBUG

	//dp [i][j] stores the number of ways to partition integer i into j-1 parts, order matters
	/*
		ex:
		dp[i][j] = 1					 (i==0||j==1)
				 = dp[i-1][j+1]+dp[i][j] otherwise
	*/
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	cin >> T;
	while (T--) {
		cin >> N >> M;
	}
}
