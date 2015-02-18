#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define MAX 1000001

int N, M, ans,fail=0x7fffffff;
typedef pair<int, int> ii;
int has[MAX];
ii P[MAX];
map<int,int> accepted;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> P[i].first;
		P[i].second = i+1;
	}
	sort(P, P + M);
	ans = 1;

	for (int i = 0; i < M; ++i) {
		if (P[i].second < fail && ans <= N && P[i].first >= ans) {
			//printf("%d->%d\n", P[i].first, ans);
			++ans;
		}
		else fail = P[i].second;
	}
	printf("f:%d\n", fail);
	
	cout << ans - 1<< endl;
}