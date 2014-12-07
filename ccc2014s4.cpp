#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define dvar(x) cout << (#x) << ":" << (x) << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

struct seg {
	int x, y1, y2, t;
	bool operator< (const seg& other) {
		return x < other.x;
	}
};

#define MAX 3000

typedef long long ll;

int N, T, yvals[MAX], numy;
ll res, line[MAX];
vector<seg> segs;

//bs for x in segs
int bs(int x) {
	int l = 0, r = numy - 1, m;
	while (l < r) {
		m = (l + r) >> 1;
		if (x <= yvals[m])
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int main() {
#if defined _DEBUG || defined NDEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; ++i) {
		int l, t, r, b, ti;
		scanf("%d%d%d%d%d", &l, &t, &r, &b, &ti);
		
		segs.push_back({ l, t, b, ti });
		segs.push_back({ r, t, b, -ti });
		yvals[numy++] = t;
		yvals[numy++] = b;
	}
	//sort all segments
	sort(segs.begin(), segs.end());
	numy = unique(yvals, yvals + numy) - yvals;
	sort(yvals, yvals + numy);
	for (int i = 0; i < segs.size(); ++i) {
		if (i != 0)
		for (int j = 0; j < numy; ++j) {
			if (line[j] >= T) {
				dvar(line[j]);
				dprintfn("res+=(%d-%d)*(%d-%d)", yvals[j + 1], yvals[j], segs[i].x, segs[i - 1].x);
				res += (ll) (yvals[j+1] - yvals[j]) * (ll) (segs[i].x - segs[i - 1].x);
			}
		}
		int st = bs(segs[i].y1), ed = bs(segs[i].y2);
		dprintfn("Adding %d to [%d,%d]", segs[i].t, yvals[st], yvals[ed]);
		for (int j = st; j < ed; ++j)
			line[j] += segs[i].t;
	}
	cout << res << endl;
}