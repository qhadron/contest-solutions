#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <thread>


using namespace std;

char _;


#define scan(x) do {while((x=getchar())<'0'); for (x-='0';(_=getchar())>='0';x=(x<<1)+(x<<3)+_-'0');}while(0)

template <typename T>
inline void readInt(T& x) {
	while ((x = getchar()) < '0');
	for (x -= '0'; (_ = getchar()) >= '0';)
		x = (x << 3) + (x << 1) + _ - '0';
}

#define MAX 1e7

template <typename T>
long double calcPi(T limit) {
	long double x = 1, y = 1, pi = 0;
	for (long i = 0; i < limit; ++i) {
		pi += y / x;
		y = -y;
		x += 2;
	}
	return 4.0L*pi;
}

int main(void) {
	printf("%.25Lf\n", calcPi(MAX));
}
