#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

template <class rai>
void print(rai start, rai end) {
	--start;
	while (++start != end) {
		cout << (*start) << " ";
	}
	cout << endl;
}
template <typename T>
void merge(T* dest, T* a, T* b, T* end) {
	T* B = b, *D = dest, *A = a;
	while (a!=end) {
		#ifdef DEBUG_M
		cout << "a:" << *a << "\tb:" << *b << endl;
		#endif
		if (b == end) {
			while ( a!= B) {
				*dest = *a;
				++a;
				++dest;
			}
			break;
		}
		if (a==B) {
			while (b!=end) {
				*dest = *b;
				++b;
				++dest;
			}
			break;
		}
		if (*a < *b) {
			*dest = *a;
			++a;
			++dest;
		}
		else {
			*dest = *b;
			++b;
			++dest;
		}
	}
	while (A != end) {
		*A = *D;
		++D;
		++A;
	}
}


template <typename T>
void _msort(T* start, T* end, T* temp) {
	if (end - start < 2) return;
	T* m = start + ((end - start) >> 1);
	_msort(start, m, temp);
	_msort(m,end, temp);
	merge(temp,start,m,end);
}

template <typename T>
void msort(T* start, T* end) {
	T* temp = new T[(end-start)];
	_msort(start,end,temp);
	delete[] temp;
}

template <class rai>
void med3( rai left, rai mid , rai right) {
	if (*left > * mid)
		iter_swap(left,mid);
	if (*(--right) < *mid) {
		iter_swap(right,mid);
		if (*mid < *left)
			iter_swap(left,mid);
	}
}

template <class rai, typename T>
rai part(rai l, rai r, T pivot) {
	while (true) {
		while(*l < pivot)
			++l;
		--r;
		while (pivot < *r)
			--r;
		if (!(l < r))
			return l;
		iter_swap(l,r);
		++l;
	}		
}

template <class rai>
void qsort(rai start, rai end) {
	if (end - start < 2) return;
	
	rai m = start + ((end - start) >> 1);
	med3(start,m,end);
	#ifdef DEBUG_Q
		cout << "m: " << *m<< "\t";
		print(start,end);
	#endif
	rai pos = part(start,end,*m);
	qsort(start,pos);
	qsort(pos,end);
}

#define SIZE 10000
#define CYCLES 10000
#define F1 msort
#define F2 qsort

//randint between [low,high]
int randint(int low, int high) {
	int divisor = RAND_MAX/((high-low)+1);
	int result;
	do {
		result = rand()/divisor;
	} while (result > (high-low));
	return result + low;
}

void random(int * s, int * e) {
	--s;
	int size = (e - s);
	while (++s!=e)
		(*s)=randint(0,size);
}

bool check (int* src) {
	for (int i = 0; i < SIZE-1; ++i) {
		if (src[i] > src[i+1])
			return false;
	}
	return true;
}

template<class rai>
bool check(rai start, rai end) {
	--start;
	rai next = start+1;
	while (next != end) {
		if (*++start > *++next)
			return false;
	}
	return true;
}

void test(char* a, char* b) {
	int* T = new int[SIZE],* ia = new int[SIZE], *qa = new int[SIZE];
	random(T,T+SIZE);
	long it=0,qt=0,t=0;
	for (int i = 0; i < (int)CYCLES; ++i) {
		if (i&1023) random(T,T+SIZE);
		memcpy(ia,T,sizeof(T));
		memcpy(qa,T,sizeof(T));
		t = clock();
		F1(ia,ia+SIZE);
		it += clock() - t;
		if (!check(ia)) {
			cout << a << " failed" << endl;
			print(ia,ia+SIZE);
			break;
			};
		t =  clock();
		F2(qa,qa+SIZE);
		qt+= clock() -  t;
		if (!check(qa)) {
			cout << b << " failed" << endl;
			print(qa,qa+SIZE);
			break;
		};
	}
	printf("%s took %.3fms on average.\n",a,((double)it/CYCLES));
	printf("%s took %.3fms on average.\n",b,((double)qt/CYCLES));
	delete[] T, ia, qa;
}

int main(void) {
	srand(time(NULL));
	test("Merge sort","Quick sort");
}