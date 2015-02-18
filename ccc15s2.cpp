#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

#define MAX 1000001

int N,M,ans;
typedef pair<int, int> ii;
int J[MAX];
vector<ii> A;
ii cur;
char temp;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> temp;
		if (temp == 'S') 
			J[i] = 1;
		else if (temp == 'M')
			J[i] = 2;
		else
			J[i] = 3;
	}
	for (int i = 0; i < M; ++i) {
		cin >> temp;
		if (temp == 'S')
			cur.first = 1;
		else if (temp == 'M')
			cur.first = 2;
		else
			cur.first = 3;
		cin >> cur.second;
		if (cur.second <= N && J[cur.second] >= cur.first) {
			J[cur.second] = 0;
			ans += 1;
		}
	}
	cout << ans << endl; 
}