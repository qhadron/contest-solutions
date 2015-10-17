#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int N;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 1; i < N; i += 2)
		cout << i<<endl;
}