#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <ctime>
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
typedef pair<int, ii> iii;
typedef long long ll;

#define INF 0x3f3f3f3f

#define MAX 500000

int N,L;
char S[MAX], T[MAX];
/*
1. Bob wins
2. alice wins
*/
int needed[255],has[255];
time_t start;
int check(int i, int j) {
	for (int ti = 0; ti < L && i < j; ++i, ++ti)
		if (S[i] != T[ti])
			return 0;
	return 1;
}

bool go(map<ii,bool> dp[2], int p, int i, int j) {
	if (j < i) return false;
	if (clock() - start > 1500) return false;
	ii choice = ii(i, j);
	if (dp[p].find(choice)!=dp[p].end())
		return dp[p][choice];
	dprintfn("%c i:%2d j:%2d",(p&1)?'A':'B', i, j);
	for (int i = 0; i < 255; ++i)
		if (has[i] < needed[i]) {
			return dp[p][choice] = (p == 0) ? true : false;
		}
	if (L == j - i) {
		//dprintfn("%d", (p == 1) ? check(i, j) : !check(i, j));
		return dp[p][choice] = (p==1) ? check(i, j) : !check(i, j);
	}
	bool res = false;
	has[S[i]]-=1;
	if (!go(dp,(p + 1) % 2, i + 1, j)) {	
		has[S[i]] += 1;
		return dp[p][choice] = true;
	}
	has[S[i]] += 1;
	has[S[j - 1]] -= 1;
	if (!go(dp,(p + 1) % 2, i, j - 1)) {
		has[S[j - 1]] += 1;
		return dp[p][choice] = true;
	}
	has[S[j - 1]] += 1;
	return dp[p][choice] = false;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	scanf("%d", &N);
	start = clock();
	while (N--) {
		scanf("%s %s", S, T);
		L = strlen(T);
		memset(has, 0, sizeof(has));
		memset(needed, 0, sizeof(needed));
		map<ii, bool> dp[2];
		dprintf("%s %s\n", S, T);
		for (int i = 0, l = strlen(S); i < l; ++i)
			has[S[i]]++;
		for (int i = 0; i < L; ++i)
			needed[T[i]]++;
		if (go(dp,0,0, strlen(S)))
			puts("Bob");
		else
			puts("Alice");
	}
}
