#include <iostream>

using namespace std;

//calculates a string expression with the 6 standard operators

#define DEBUG 0

int eval(string s) {
	#define getop(x) (x == ')')?rbracket:(x=='-')?minus:(x=='+')?plus:(x=='/')?div:(x=='*')?mul:(x=='(')?bracket:none
	#define getst(x) (x == rbracket)?')':(x==minus)?'-':(x==plus)?'+':(x==div)?'/':(x==mul)?'*':(x==bracket)?'(':'\0'
	#define work(a,b,c) (c==mul)?(a)*(b):(c==div)?(a)/(b):(c==plus)?(a)+(b):(a)-(b)
	#define print(x) cout << #x << ':';	for (int i = 0; i < x.size(); i++) cout << (x[i]) << " "; cout << endl
	#define print1(x) cout << #x << ':';	for (int i = 0; i < x.size(); i++) cout << (getst(x[i])) << " "; cout << endl
	#ifndef _STACK_
		#include <vector>
		#define push push_back
		#define pop pop_back
		#define top back
		#define stack vector
	#endif
	enum optype {
		none = 0,
		rbracket=1,
		minus=2,
		plus=3,
		div=4,
		mul=5,
		bracket=6
	};
	if (s.size() < 2)
		return (s.size())?s[0]-'0':0;
	stack<int> data,  op;
	int pos = 0,a,b,val,n;
	optype curop;
	do {
		if (isdigit(s[pos])) {
			val = n = 0;
			while ((pos+n)<s.size()&&isdigit(s[pos+n])) n++;
			for (int i = pos + n - 1, pow = 1; i >= pos; i--, pow = (pow << 3) + (pow << 1)) {
				val += pow * (s[i]-'0');
			}
			pos+=n-1;
			data.push(val);
		}
		else {
			curop = getop(s[pos]);
			if (!curop) continue;
			if (curop == rbracket) {
				while (op.top()!=bracket) {
					b = data.top();data.pop();
					a = data.top();data.pop();
					data.push(work(a,b,op.top()));
					op.pop();
				}
				op.pop();
			}
			else {
				while (op.size()&&op.top()!=bracket&& ((curop == mul && op.top() == div)||(curop == plus && op.top() == minus)||curop <= op.top())) {
					b = data.top();data.pop();
					a = data.top();data.pop();
					data.push(work(a,b,op.top()));
					op.pop();
				}
				if (curop == bracket)
					if (pos-1>=0 && (isdigit(s[pos-1]) || s[pos-1] == ')') )
						op.push(mul);
				op.push(curop);
			}
		}
#if DEBUG
		system("PAUSE");
		print(data);
		print1(op);
		cout << "curop:" << (getst(curop));
		cout << endl;
#endif
	} while (++pos < s.size());
#if DEBUG 
	cout << "-------------exited---------------" << endl;
#endif
	while  (!op.empty()) {
		if (op.top() == bracket || op.top() == rbracket) {
			op.pop(); 
			continue;
		}
		b = data.top();data.pop();
		a = data.top();data.pop();
		data.push(work(a,b,op.top()));
		op.pop();
#if DEBUG
			system("PAUSE");
			print(data);
			print1(op);
			cout << "curop:" << (getst(op.top())) << endl;
			cout << endl;
#endif
	}
#if DEBUG
	cout << "-----------done------------" << endl;
	print(data);
	cout << endl;
	cout << endl;
#endif 
	return data.top();
#ifndef _STACK_
	#undef push
	#undef pop
	#undef top
	#undef stack
#endif
	#undef getop
	#undef getst
	#undef work
	#undef print
	#undef print1
}

int main(void) {
	string s;
	while (getline(s,cin)) 
		cout << eval(s) << endl;
}