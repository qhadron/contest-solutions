#include <iostream>
#include <thread>

const double PI = 3.141592653589793;

using namespace std;
typedef unsigned long long ulong;
typedef long double ldouble;

ldouble s;
#define NTHREADS 64
#define LIMIT 10000000000

#ifdef M1//use single thread or multi-thread
void sum(ulong start, ulong end) {
	ldouble x = start*2+1.0;
	char y = (start&1)?-1:1;
	while (start++<end)
		(s+=(y/x)),x+=2,y=-y;
	return;
}
#else
ldouble S[NTHREADS];
void sum_threads(int i, ulong start, ulong end) {
	ldouble x = start*2+1.0;
	char y = (start&1)?-1:1;
	while (start++<end)
		(S[i]+=(y/x)),x+=2,y=-y;
	s+=S[i];
}
thread threads[NTHREADS-1];
const ulong part=((ulong)LIMIT) / (ulong)NTHREADS;
#endif
int main(int argsc, char** argsv) {
	cout.precision(15);
	cout << PI << endl;
	#ifdef M1
	sum(0l,(ulong)LIMIT);
	cout << (4.0l)*s << endl;
	#else
	for (ulong i = 1; i < NTHREADS; i++)
		threads[i-1]=(thread(sum_threads,i,part*i,part*(i+1)));
	sum_threads(0,0,part);
	for (int i = 0; i < NTHREADS-1; i++) threads[i].join();
	cout << (4.0l)*s << endl;
	#endif
}