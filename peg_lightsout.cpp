#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define scanp(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _, __;
static inline void scan(int& x) {
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

#define  MAXN 17	
#define INF 0x6fffffff

int R, C;
char data[MAXN][MAXN];
char temp[MAXN][MAXN];
int m = INF;

inline void tap(int r, int c) {
	for (int x = -1; x < 2; ++x) for (int y = -1; y < 2; ++y)
		if ((x == 0 && y == 0) || x != y && x + y != 0 && r + x >= 0 && c + y >= 0 && r + x < R&&c + y < C)
			temp[x + r][y + c] ^= 1;
}

int sim(int r, int state) {
	if (r > R) return INF;
	int cnt = 0, s1 = 0, cc;
	for (cc = 0; cc < C; ++cc) {
		if (!(state&(1 << cc)))
			continue;
		else ++cnt;
		tap(r, cc);
	}
	if (r == R - 1) {
		for (int i = 0; i < C; ++i)
			if (temp[r][i])
				return INF;
		return cnt;
	}
	for (int i = 0; i < C; ++i)
		if (temp[r][i])
			s1 |= 1 << i;
	return cnt + sim(r + 1, s1);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	while (scanf("%d%d", &R, &C)>0)
	{
		m = INF;
		for (int i = 0; i < R; ++i)
			cin >> data[i];
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				data[i][j] = (data[i][j] == '1') ? 1 : 0;
		memcpy(temp, data, sizeof(data));
		int lim = 1 << C, res;
		for (int i = 0; i < lim; ++i) {
			memcpy(temp, data, sizeof(data));
			res = sim(0, i);
			m = min(m, res);
			if (!m)
				break;	//minimal solution
		}
		printf("%d\n", (m < INF) ? m : -1);
	}
}
