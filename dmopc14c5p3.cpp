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

#define MAX 101

int dp[MAX], A[MAX], N, ans;

#define abs(x) ((x) < 0 ? -(x) : (x))

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	cin.sync_with_stdio(false);
#endif // _DEBUG
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = 1, j, cnt = 0; i <= N - 1; ++i) {
		cnt = 1;
		for (j = i + 1; j <= N && abs(A[j-1] - A[j]) <= 2; ++j)++cnt;
		if (ans < cnt) ans = cnt;// , dprintfn("%d=[%d,%d]", ans, i, j);
	}
	cout << ans << endl;
}
