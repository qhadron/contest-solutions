#include <iostream>
#include <set>
using namespace std;

int N, x;
set<int> s;
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> x, s.insert(x);
	cout << s.size() << endl;
}