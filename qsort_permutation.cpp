#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//print the vector
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

typedef unsigned long long ul;

//count digits of x
int l(int x) {
	for (int cnt = 0; ; x/=10,cnt++) {
		if (!(x)) {
			return cnt;
		}
	}
	return -1;
}

namespace j {
	//swap values of a and b
	template <typename T>
	void _swap(T& a, T& b) {
		T c(a);
		a = b;
		b = c;
	}
	
	//swap a,b when they are iterators
	template <typename T>
	void swap (T a, T b) {
		_swap(*a,*b);
	}
	
	//reverse the interval [start,end)
	template <typename RandomAccessIterator> 
	void reverse (RandomAccessIterator start, RandomAccessIterator end){
		if (end-start < 2) return;
		while ((start!=end)&&(start!=--end)) {
			j::swap(start,end);
			++start;
		}
	}
}

//(quick) sort [start,end)
template <class RandomAccessIterator>
void qs(RandomAccessIterator start, RandomAccessIterator end) {
	if (end-start<2) return;
	RandomAccessIterator m = (start+((end-start) >> 1));
	j::swap(m,end-1);
	RandomAccessIterator t=start;
	for (RandomAccessIterator i = start; i != end; ++i) {
		if ((*i)<(*(end-1))) {
			j::swap(t,i);
			++t;
		}
	}
	j::swap(end-1,t);
	qs(start,t);
	qs(t+1,end);
}

//permute [start,end)
template <typename RandomAccessIterator>
bool next_permutation(RandomAccessIterator start, RandomAccessIterator end ) {
	RandomAccessIterator next = end,t,temp;
	if (start==end||start==--next) return false;
	
	while (start!=next) {
		temp=next;
		if (*(--next) < *(temp)) { //find largest index next such that a[next] < a[next+1]
			for(t=end;!(*next<(*--t)););	//find largest index t such that a[next] < a[t]
			j::swap(next,t);
			j::reverse(temp,end);
			return true;
		}
	}
	j::reverse(start,end);
	return false;
}

//prints all permutations of x
void premutate(ul x) {
	int n=l(x);
	char *c = new char[n];
	for (int i = 0; i < n; i++) {
		c[i]=x%10+'0';
		x/=10;
	}
	qs(c,c+n);
	do {
		for (int i = 0; i < n; i++) {
			cout << c[i] << ((i+1!=n)?" ":"\n");
		}
	} while(next_permutation(c,c+n));
}


int main() {
	vector<int> v ({3,4,2,1});
	qs(v.begin(),v.end());
	do {
		cout << v << endl;
	} while (next_permutation(v.begin(),v.end()));
}