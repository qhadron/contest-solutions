#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long D,H,M; //day, hour, minutes , respectively
long min;
int main(int argsc, char* argsv[]) {
	//freopen(argsv[1],"r",stdin);	//file input
	long double ratio = (86400.0 ) / (24 * 3600 + 37*60 + 22.663);	//ratio from earth to Martian
	while (cin >> D >> H >> M) {
		D-=1;		//time starts at day 1, but 0 sec...
		long min = ( M + 60 * ( H + 24 * D) ) * ratio;	//get number of Martian minutes
		M = min % 60;
		min/=60;
		H = min % 24;
		D = min/24;
		//formatted output (D + 1 because starts at day 1)
		cout <<"Day " << (D+1) << ", " << ((H<10)?"0":"\0") << H << ":" << ((M<10)?"0":"\0") << M << endl;
	}
}