#include <iostream>

using namespace std;

int P, U;
double a, b;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	ios::sync_with_stdio(false);
	cin >> P >> U >> a >> b;
	int res = 0;
	//loop through upvotes
	for (int u = 1; u < U; ++u) {
		for (int du = 1,d; du < U - u; ++du) {
			d = U - u - du;
			if (d > 0 && (2 * du + u - d == P)) {
				if ((double) u / du == a / b ||
					(double) du / u == a / b ||
					(double) d / du == a / b ||
					(double) du / d == a / b ||
					(double) u / d == a / b ||
					(double) d / u == a / b)
					++res;
			}
		}
	}
	cout << res << endl;
}