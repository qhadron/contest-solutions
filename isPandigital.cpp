#include <iostream>
#include <bitset>
#define DEBUGd
#ifdef DEBUG
	#define pbits cout <<"bits: " << bitset<sizeof(bits)*8>(bits) << endl;
	#define pmask cout <<"mask: " << bitset<sizeof(cnt)*8>((1<<cnt)-1)<<endl;
	#define pdiff cout <<"diff: " << bitset<sizeof(bits)*8>(bits^((1<<cnt)-1)) << endl; 
	#define print pbits pmask pdiff
	#define p(x) cout << (x) << endl;
#else
	#define pbits 
	#define pmask 
	#define pdiff 
	#define print 
	#define p(x) 
#endif
using namespace std;
typedef short byte;
bool checkPandig(int n) {
	byte bits=0,cnt=0;
	for (byte dig=n%10; n!=0;n/=10, dig=n%10,cnt++) {
		p(dig)
		if (--dig<0) return false;
		if (((bits)>>dig)&1){
			print
			p((bits)>>dig)
			return false;
		}
		bits|=(1<<dig);
	}
	print
	return (bits==((1<<cnt)-1));
}
int i,cnt;
int main(){
	#ifndef DEBUG
		while (++i<(int)1e4) {
			if (cnt+=checkPandig(i),checkPandig(i))
				cout<<i<<endl;
		}
		cout << "Total: " << cnt << endl;
	#else
		int x;
		while (cin >> x) {
			x=(checkPandig(x));
			cout << ((x)?"true":"false") << endl;
		}
	#endif
}

