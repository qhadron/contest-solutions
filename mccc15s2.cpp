#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX 100001

int N,D[MAX],res,cur;
//3 3 3 2 2 1
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0,x; i < N; ++i) {
		cin >> x;
		++D[x];
	}
	sort(D, D + MAX, greater<int>());
	cout << D[0] << endl;
}