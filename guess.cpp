/***
	guess a number from 1 to 2e9, depending on the output
		-- 'Higher' if guess was too low
		-- 'Lower' if guess was too high
		-- 'OK' if guess was spot on
	
	This implementation uses a binary search method, solves all cases in less than or equal to 32 steps
*/
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long ulong;
const ulong MAX = 2000000000;
ulong guess=1000000000,Max=2000000000,Min=1;
string s;

#define TEST

#ifdef TEST
#include <cstdio>
	ulong target = (ulong)(1e6);
	int cnt = 0;
	void test() {
		cnt++;
		if (guess<target)
			s="Higher";
		else if (guess>target)
			s="Lower";
		else
			s="OK";
	}
#endif
int main(int argsc, char**argsv) {
#ifdef TEST
	target=atoi(argsv[1]);
#endif
	while (true) {
		cout << guess << endl;
		
	#ifndef TEST
		cin >> s;
	#else
		test();
	#endif
		if (s=="Higher") {
			Min=guess;
			if ((guess+(guess>>1))>Max) {
				if(Max==MAX)
					guess=Max;
				else
					guess=(guess+Max)>>1;
			} else {
				guess+=(guess>>1);
			}
		} else if (s=="Lower") {
			Max=guess;
			if ((guess-(guess>>1))<Min) {
				guess=(guess+Min)>>1;
			} else {
				guess-=(guess>>1);
			}
		} else {
			break;
		}
	}
	#ifdef TEST
		return cnt;
	#endif
}