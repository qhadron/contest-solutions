#include <iostream>
#include <cstdio>		//file io
using namespace std;

char str[10];
int cnt;
int nk,nq,nr,nb,nn; 				//number of each of the pieces K, Q, R, B and N, respectively
int k[1],q[1],r[2],b[2],n[2];		//stores the location of the pieces
void dfs(int n) {
	if (n >= 8) {
		nk=nq=nr=nb=nn=0;
		for (int i = 0; i < 8; i++){
			if (str[i] == 'K')
				k[nk++]=i;
			else if (str[i] == 'Q')
				q[nq++]=i;
			else if (str[i] == 'R')
				r[nr++]=i;
			else if (str[i] == 'B')
				b[nb++]=i;
			else if (str[i] == 'N')
				n[nn++]=i;
		}
		if (nk==1 && nq==1 && nr==2 && nb==2 && nn==2) 			//check the number of pieces
			if (r[0]<k[0]&&k[0]<r[1]&&((b[0]&1) != (b[1]&1)))	//check positions of pieces
				cnt++;
		return;
	}

	if (str[n]=='_') {
		//dfs each possibility
		str[n]='K';
		dfs(n+1);
		str[n]='Q';
		dfs(n+1);
		str[n]='R';
		dfs(n+1);
		str[n]='B';
		dfs(n+1);
		str[n]='N';
		dfs(n+1);
		str[n]='_'; //backtrack
	} else {
		dfs(n+1);
	}
}

int main() {
	//freopen("0.input.txt","r",stdin);	//file input
	while (cin.getline(str,9)) {
		cnt = 0;
		dfs(0);
		cout << cnt << endl;
	}
}

/*
Test Data:

NR____RN
___BB___
_R____R_
___KQ___
___QK___
NBRK____
__Q___B_
__Q___NN
_RKR____
RKRBN__Q
________

Output:
8
60
72
32
32
12
40
6
18
1
960
*/
