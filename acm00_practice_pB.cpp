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

char c;
int t, buf[255];
char verdict[100];
int s, p;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	while ((c=getchar())!='-') {
		if (c == '-') break;
		cin >> t >> verdict;
		dprintf("%c %d %s\n", c, t, verdict);
		if (!strcmp(verdict,"correct")) {
			dprintfn("True");
			++s;
			p += buf[c] + t;
		}
		else
			buf[c] += 20;
		c = getchar();
	}
	printf("%d %d\n",s, p);
}
