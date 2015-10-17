#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>

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

vector<int> adj[1000];
ll T, N, K;
int A, B, d;

bool go(int a, int b) {
	if (a == d || b == d) return true;

}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	cin >> T;
	while (T--) {
		cin >> A >> B >> d;
		if (A < B)
			swap(A, B);
		if (B==1 || (go(0, 0) &&
			!(!(A & 1) && !(B & 1) && d % 2 == 1) &&
			!((A - B) == 0 && d != 0)))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
