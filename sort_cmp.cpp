#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define DEBUG

const double PI = 3.141592653589793;

using namespace std;


void print() {cout << endl;};
void print_space() {cout << endl;};
void print_line() {};

template <typename T, typename... Types>
void print ( const T& curArg, const Types&... args ) {
	cout << curArg;
	print(args...);
}

template <typename T, typename... Types>
void print_space ( const T& curArg, const Types&... args ) {
	cout << curArg << " ";
	print_space(args...);
}

template <typename T, typename... Types>
void print_line ( const T& curArg, const Types&... args ) {
	cout << curArg << endl;
	print_line(args...);
}

#if defined _VECTOR_
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); ) {
		out << *it;
		if (++it != v.end()) {
			cout << " ";
		}
	}
	return out;
}
#endif

//print array
template <typename T>
void print ( T* s, T* e) {
	--s;
	while (++s != e) {
		cout << (*s) << " ";
	}
	cout << endl;
}


//randint between [low,high]
int randint(int low, int high) {
	int divisor = RAND_MAX/((high-low)+1);
	int result;
	do {
		result = rand()/divisor;
	} while (result > (high-low));
	return result + low;
}

//return the median of the 3 iterators
template <class rai>
void med3 (rai first, rai mid, rai end) {
	if (*mid < *first) {
		iter_swap(mid,first);
	}
	if ( *(--end) < (*mid)) {
		iter_swap(end,mid);
		if (*mid < *first) {
			iter_swap(first,mid);
		}
	}
}

template <class rai>
void _qsort( rai start, rai end) {
	if (end - start < 2)
		return;
	rai m = start + ( end - start ) / 2;
	med3(start,m,end);
	rai l = start, r = end;
	while (l < m&&l!=r) {
		if (*l > *m)
		iter_swap(l,--r);
		else
		{
			++l;
		}
		
	}
	#ifdef DEBUG
	//print(start,end);
	#endif
	_qsort(start,m);
	_qsort(m,end);
}

//quicksort
template <class rai>
void qsort(rai start, rai end) {
	_qsort(start,end);
}

//insertion sort
template <class rai>
void isort( rai start, rai end) {
	rai i = start,t;
	while (++i != end) {
		t=i;
		while ( (t-1)>=start && (*t) < (*(t-1))) {
			iter_swap(t,t-1);
			--t;
		}
	}
}

template <typename T>
void merge( T* a, T* b, int left, int right, int end) {
	for (int x = left, y = right, i = left; i < end; ++i) {
		if (x < right && (y >= end || a[x] <= a[y])) {
			b[i]=a[x];
			++x;
		} else {
			b[i]=a[y];
			++y;
		}
	}
}

//mergesort
template <typename T>
void msort( T* start, T* end) {
	if (end - start < 2) return;
	int size = (end-start), *orig = start;
	T *temp = new T[size];
	for (int width = 1; width < size; width *= 2) {
		for (int i = 0; i < size; i+= width*2) {
			merge(start,temp,i, min(i+width,size),min(i+2*width,size));
		}
		swap(start,temp);
	}
	if (orig == start)
		delete [] temp;
	else 
		delete [] start;
}


#define SIZE 32768
#define CYCLES 1e4
int ia[SIZE],qa[SIZE],T[SIZE];

void randomize( ) {
	for (int i = 0; i < SIZE; ++i) {
		qa[i]=ia[i]=randint(0,SIZE);
	}
}

void random(int * s, int * e) {
	--s;
	while (++s!=e)
		(*s)=randint(0,1000);
}

void test() {
	random(T,T+SIZE);
	long it,qt,t;
	for (int i = 0; i < (int)CYCLES; ++i) {
		if (i&1023) random(T,T+SIZE);
		memcpy(ia,T,sizeof(T));
		memcpy(qa,T,sizeof(T));
		t = clock();
		qsort(ia,ia+SIZE);
		it += clock() - t;
		t =  clock();
		msort(qa,qa+SIZE);
		qt+= clock() -  t;
	}
	printf("%s took %.3fms on average.\n","Quick-sort",((double)it/CYCLES));
	printf("%s took %.3fms on average.\n","Merge-sort",((double)qt/CYCLES));
}

int main() {
	test();
	return 0;
	int a[]={9,8,7,6,5,4,2,1,3,0},b[10],c[10];
	do {
		print(a,a+10);
		cout <<endl;
		memcpy(b,a,sizeof(a));
		memcpy(c,a,sizeof(a));
		sort(b,b+10);
		cout << endl;
		msort(c,c+10);
		print(c,c+10);
		cout << endl;
		getchar();
	} while (next_permutation(a,a+10));
}