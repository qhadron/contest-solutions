#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

char dat[1001][1001];
int N;
bool h, v, l, r;
#ifdef _DEBUG
fstream fin("input.txt");
#define cin fin
#endif 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
	cin >> N;
	cin.getline(dat[0], 1000);
	for (int i = 0; i < N; ++i)
		cin.getline(dat[i], 1001);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (dat[i][j] == '(') {
				if (dat[i][N - j - 1] != ')')
					h = true;
				if (dat[N - i - 1][j] != '(')
					v = true;
				l = true;
				r = true;
			}
			else if (dat[i][j] == ')') {
				if (dat[i][N - j - 1] != '(')
					h = true;
				if (dat[N - i - 1][j] != ')')
					v = true;
				l = true;
				r = true;
			}
			else if (dat[i][j] == '\\') {
				if (dat[i][N - j - 1] != '/')
					h = true;
				if (dat[N - i - 1][j] != '/')
					v = true;
				if (dat[j][i] != '\\')
					l = true;
				if (N - i - 1 == j)
					if (dat[N - j - 1][N - i - 1] != dat[i][j])
						r = true;
			}
			else if (dat[i][j] == '/') {
				if (dat[i][N - j - 1] != '\\')
					h = true;
				if (dat[N - i - 1][j] != '\\')
					v = true;
				if (dat[j][i] != '/')
					l = true;
				if (N - i - 1 == j)
					if (dat[N - j - 1][N - i - 1] != '/')
						r = true;
			}
			else {
				if (dat[i][N - j - 1] != dat[i][j])
					h = true;
				if (dat[N - i - 1][j] != dat[i][j])
					v = true;
				if (dat[j][i] != dat[i][j])
					l = true;
				if (dat[N - j - 1][N - i - 1] != dat[i][j])
						r = true;
			}

		}
	}
	cout << 4 - l - r - h - v << endl;
}