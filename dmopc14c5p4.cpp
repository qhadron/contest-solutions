#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <functional>
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

typedef pair<double, int> ii;
typedef long long ll;

#define INF 0x3f3f3f3f
#define MAX 100001
int N, M, ans, w;
ii vals[MAX];
bool comp(const ii& a, const ii& b) {
	return a.second > b.second;
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	cin.sync_with_stdio(false);
	cin.tie(false);
#endif // _DEBUG
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> vals[i].first >> vals[i].second;
		vals[i].first /= vals[i].second;
	}
	sort(vals, vals + N);
	stable_sort(vals, vals + N, comp);
#ifdef _DEBUG
	for (int i = 0; i < N; ++i) cout << vals[i].first* vals[i].second << " " << vals[i].second << endl;
#endif	
	for (int i = 0; i < N; ++i) {
		if (w + vals[i].first * vals[i].second <= M) {
			w += vals[i].first * vals[i].second;
			ans += vals[i].second;
		}
	}
	cout << ans << endl;
}
