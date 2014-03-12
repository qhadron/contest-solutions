#include <iostream>
#include <string>

using namespace std;
#define MAX 101

int N;

struct VAL {
	int data[4][MAX];
	int pos[MAX];
	VAL(int N) {
		for (int i = 1; i <= N; i++) {
			data[1][N-i+1]=i;
			pos[i]=0;
			for (int j = 2; j <= 3; j++) {
				data[j][i-1]=MAX;
			}
		}
		pos[1]=N;
	}
	void mov(int src, int dest) {
		if (data[dest][pos[dest]] < data[src][pos[src]]) cout <<"(invalid):";
		cout << "Moved " << data[src][pos[src]] << " from " << src << " to " << dest << endl;
		data[dest][++pos[dest]]=data[src][pos[src]--];
	}
	
	string pad(int n, string& s) {
		for (int i = 0; i < ((n-s.size())>>1) ; ++i) {
			s=s+" ",s=" "+s;
		}
		return s;
	}
	
	string get(int n) {
		n=(n<<1)+1;
		string s = "";
		while (n--) {
			s+="*";
		}
		return s;
	}
	
	void print() {
		int maxwidth=(N<<1)+3;
		for (int j = N; j >= N; --j) {
			for (int i = 1; i <= 3; ++i) {
				if (j > pos[i]) {
					cout << pad(maxwidth,string("|"));
				} else {
					cout << pad(maxwidth,get(data[i][j]));
				}
			}
			cout << endl;
		}
	
	}
};

VAL v(0);

void dfs(int n,int src, int dest, int temp) {
	if (n==1) {
		v.mov(src,dest);
	} else {
		dfs(n-1,src,temp,dest);
		v.mov(src,dest);
		dfs(n-1,temp,dest,src);
	}
}
int main(void) {
	cin >> N;
	v=VAL(N);
	system("CLEAR");
	v.print();
	return 0;
	dfs(N,1,3,2);
}