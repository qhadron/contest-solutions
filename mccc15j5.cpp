#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

#define MAX 100001

ii B1[MAX], B2[MAX], P[MAX];

int N, M;
long long ans;
int find_first(int x, ii* arr, int l = 0, int r = N, bool first = true, bool neg=false) {
	int m;
	if (first){
		while (l < r) {
			m = l + r >> 1;
			if (x <= arr[m].first)
				r = m;
			else
				l = m + 1;
		}
			return neg||arr[l].first == x ? l : -1;
	}
	else  {
		while (l < r) {
			m = l + r >> 1;
			if (x <= arr[m].second)
				r = m;
			else
				l = m + 1;
		}
		return neg || arr[l].second == x ? l : -1;
	}
}

int find_last(int x, ii* arr, int l = 0, int r = N, bool first = true) {
	int m;
	if (first)
	while (l < r) {
		m = l + r >> 1;
		if (x < arr[m].first)
			r = m;
		else
			l = m + 1;
	}
	else
		while (l < r) {
			m = l + r >> 1;
			if (x < arr[m].second)
				r = m;
			else
				l = m + 1;
		}
	return l;
}

bool comp(const ii& a, const ii& b) {
	return a.second < b.second;
}
int a, b, x, y;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		B1[i].first = a; B1[i].second = b;
		B2[i].first = b; B2[i].second = a;
	}
	sort(B1, B1 + N, comp);
	sort(B2, B2 + N, comp);
	stable_sort(B1, B1 + N);
	stable_sort(B2, B2 + N);
	//cout << "B1:" << endl;
	//for (int i = 0; i < N; ++i)
	//	printf("[%d,%d]\n", B1[i].first, B1[i].second);
	//cout << "B2:" << endl;
	//for (int i = 0; i < N; ++i)
	//	printf("[%d,%d]\n", B2[i].first, B2[i].second);
	cin >> M;
	for (int i = 0; i < M; ++i)
		cin >> P[i].first >> P[i].second;
	for (int i = 0; i < M - 1; ++i) {
		//printf("[%d,%d]-[%d,%d]\n", P[i].first, P[i].second, P[i + 1].first, P[i + 1].second);
		if (P[i].first == P[i + 1].first) {
			//cout << "c1" << endl;
			a = find_first(P[i].first, B1);
			if (a < 0) continue;
			b = find_last(P[i].first, B1);
			x = find_first((P[i].second > P[i + 1].second) ? P[i + 1].second: P[i].second, B1, a, b, false, true);
			y = find_last((P[i].second < P[i + 1].second) ? P[i + 1].second : P[i].second, B1, a, b, false);
			//cout << a << " " << b << " " << x << " " << y << endl;
			ans += y - x;
			//cout << "y-1:" << B1[y - 1].first<<"," << B1[y - 1].second << endl;
		}
		else {
			//cout << "c2" << endl;
			a = find_first(P[i].second, B2);
			if (a < 0) continue;
			b = find_last(P[i].second, B2);
			x = find_first((P[i].first > P[i + 1].first) ? P[i + 1].first : P[i].first, B2, a, b, false, true);
			y = find_last((P[i].first > P[i + 1].first) ? P[i].first : P[i+1].first, B2, a, b, false);
			//cout << a << " " << b << " " << x << " " << y << endl;
			ans +=  y - x;
			//cout << "y-1:" << B2[y - 1].second << "," << B2[y - 1].first << endl;
			
		}
	}
	cout << ans << endl;
}