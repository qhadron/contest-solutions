
//http://wcipeg.com/problems/desc/checker

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 3001

int tree[MAX][MAX];
int prev[MAX][MAX];
int M,N;
bool first;

inline int lowbit(int x) {return x&(-x);};
inline bool isOdd(int x, int y) {
    return ((x + y) & 1);
}

void update(int x, int y, int v) {
	for (int i = x; i <=M; i+=lowbit(i))
		for (int j = y; j <= N; j += lowbit(j))
			tree[i][j] += v;
}


int freqTo (int x, int y) {
	int res = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
                res += tree[i][j];
	return res;
}


int main() {
	int command, x,y,a,l,b,r,t;
	cin >> M >> N;
	while (true) {
		cin >> command;
		if ( command == 1) {
			cin >> x >> y >> a;
			if (isOdd(x,y)) {
                update(x ,y , a - prev[x][y]);
                prev[x][y] = a;
            } else {
                update(x,y, -a - prev[x][y]);
                prev[x][y] = -a;
            }
		} else if (command == 2) {
			cin >> l >> b >> r >> t;
            int sum = freqTo(r,t) - freqTo(l - 1 ,t) - freqTo(r,b - 1) + freqTo(l - 1 ,b - 1);
			//cout << "sum: ";
            if (!isOdd(l,b))
                sum = -sum;
			cout << sum << endl;
		} else {
			break;
		}
	}
}
