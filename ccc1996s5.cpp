#include <cstdio>
#include <algorithm>

using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define scanp(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _;

#define MAX 100001
int T, N;
int X[MAX], Y[MAX];

//returns position of first number smaller than t
int bs(int t) {
	int m,l=0,r=N;
	while (l < r) {
		m = l + r >> 1;
		if (t > Y[m])
			r = m;
		else
			l = m + 1;
	}
	return r;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanp(T);
	while (T--) {
		scanf("%d",&N);
		for (int i = 0; i < N; ++i)
			scanp(X[i]);
		for (int i = 0; i < N; ++i)
			scanp(Y[i]);
		int m = 0;
		for (int i = 0, pos; i < N; ++i) {
			if (Y[pos = bs(X[i]) - 1] >= X[i])
				m = max(m, pos - i);
			while (i < N&&X[i] == X[i + 1])++i;	//skip repeated elements
		}
		printf("The maximum distance is %d\n", m);
	}
}
