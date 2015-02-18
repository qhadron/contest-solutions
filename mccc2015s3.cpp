#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
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
#define MAX 100001

typedef pair<int, int> ii;

double cross(ii a, ii b, ii c) {
	return (a.first - c.first) * (b.second - c.second) - (a.second - c.second) * (b.first - c.first);
}

struct Line {
	ii a, b;
	Line(){};
	Line(ii A, ii B) : a(A), b(B){};
	bool intersects(const Line& other) {
		return (
			min(a.first, b.first) <= max(other.a.first, other.b.first) &&
			min(a.second, b.second) <= max(other.a.second, other.b.second) &&
			min(other.a.first, other.b.first) <= max(a.first, b.first) &&
			min(other.a.second, other.b.second) <= max(a.second, b.second) &&	//bounding rectangle
			cross(a, b, other.a) * cross(a, b, other.b) < 0 &&	//check side
			cross(other.a, other.b, a) * cross(other.a, other.b, b) < 0
			);
	}
	bool intersects(const ii& other) {
		return (min(a.first, b.first) <= other.first	&&
			min(a.second, b.second) <= other.second	&&
			other.first <= max(a.first, b.first) &&
			other.second <= max(a.second, b.second) &&	//bounding rectangle
			//cross(a, b, other) == 0					//check co-linear
			(b.second - a.second) * (other.first - b.first) == (other.second - b.second) * (b.first - a.first)
			);
	}
};

int N, res;
vector<ii> points;
int idx[MAX];
ii u, v;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0, a, b; i < N; ++i) {
		cin >> a >> b;
		points.push_back(make_pair(a, b));
		idx[i] = i;
	}
	sort(points.begin(), points.end());
	set<long long> used;
	vector<Line> lines;
	do {
		lines.clear();
		Line cur;
		bool flag = true;
		long long config = 0, rconfig = 0;
		int lline = -1, line, next;
		for (int i = 0; i < N; ++i) {
			next = (i + 1) % N;
			u = points[i];
			v = points[next]; 
			config *= 10;
			config += idx[next];
			long long c = 1;
			for (int j = 0; j <=i; ++j)
				c *= 10;
			rconfig += idx[next] * c;
			if (u.first == v.first)
				line = 1;
			else if (u.second == v.second)
				line = 2;
			else
				line = 0;
			if (line&&line == lline) {
				flag = false;
			}
			lline = line;
			if (flag)
			if (i != N - 1) {
				for (int j = 0; j < lines.size(); ++j)
					if (lines[j].intersects(v)) {
						flag = false;
					}
			}
			cur = Line(u, v);
			if (flag)
			for (int j = 0; j < lines.size(); ++j)
				if (cur.intersects(lines[j])) {
					flag = false;
				}
			lines.push_back(cur);
		}
		if (used.find(config) == used.end())
			res += flag;
		used.insert(config), used.insert(rconfig);
	} while (next_permutation(points.begin() + 1, points.end()) && next_permutation(idx,idx+N));
	cout << res << endl;
}