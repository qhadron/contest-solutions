//http://wcipeg.com/problems/desc/ioi0111
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 1025

int tree[MAX][MAX];
int S;


int freqTo(int x, int y) {
	int sum = 0, i = x;
	while (i > 0) {
		int j = y;
		while (j > 0) {
			sum += tree[i][j];
			j -= (j & -j);
		}
		i -= (i & -i);
	}
	return sum;
}

void update(int x, int y, int val){
	int i = x;
	while( i <= S ) {
		int j = y;
		while ( j <= S) {
			
			tree[i][j] += val;
		
			j += (j & -j);
		}
		i += (i & -i);
	}
} 

int main() {
	int command, x,y,a,l,b,r,t;
	while (true) {
		cin >> command;
		
		if (command == 0) {
			cin >> S;
		} else if ( command == 1) {
			cin >> x >> y >> a;
			
			update(x + 1,y + 1,a);
		} else if (command == 2) {
			cin >> l >> b >> r >> t;
			++l,++b,++r,++t;
			
			
			int sum = freqTo(r,t) - freqTo(l - 1 ,t) - freqTo(r,b - 1) + freqTo(l - 1 ,b - 1);
			cout << sum << endl;
		} else {
			break;
		}
	}
}