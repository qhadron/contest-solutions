#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
/***
	TODO:
		1. Implement operators +=,-=,*=,/=
		2. Implement operator modulo (optional?)
		3. Implement function power(int exponent);
		3. Test and check for bugs
*/
using namespace std;

#define MAX 2000

class BigDecimal {
private:
	char msd=-1;
	char sign;
	char digits[MAX];
public:
	int operator[] (int index);
	BigDecimal& operator= (BigDecimal& other);
	BigDecimal& operator+= (const BigDecimal& other);
	BigDecimal& operator-= (const BigDecimal& other);
	BigDecimal& operator*= (const BigDecimal& other);
	BigDecimal& operator/= (const BigDecimal& other);
	
	BigDecimal& operator+= (long other);
	BigDecimal& operator-= (long other);
	BigDecimal& operator*= (long other);
	BigDecimal& operator/= (long other);
	
	bool operator==(const BigDecimal& other);
	bool operator>(const BigDecimal& other);
	bool operator<(const BigDecimal& other);

	bool setValue(long n);
	bool setValue(string s);
	
	inline int getSign() {return sign;};
	inline void setSign(int s) { sign=(s>0)?1:-1;};
	inline void negate() { sign=(sign>0)?-1:1; };
	size_t size();
	
	BigDecimal();
	BigDecimal(long n);
	BigDecimal(string s);
};

BigDecimal operator- (BigDecimal number) {
	number.negate();
	return number;
}
BigDecimal operator+ (BigDecimal a, BigDecimal& b) {
	return (a+=b);
}
BigDecimal operator- (BigDecimal a, BigDecimal& b) {
	return (a-=b);
}
BigDecimal operator* (BigDecimal a, BigDecimal& b) {
	return (a*=b);
}
BigDecimal operator/ (BigDecimal a, BigDecimal& b) {
	return (a/=b);
}
BigDecimal operator/ (const long& a, BigDecimal b) {
	return (b-=a);
}
BigDecimal operator* (const long& a, BigDecimal b) {
	return (b*=a);
}
BigDecimal operator+ (const long& a, BigDecimal b) {
	return (b+=a);
}
BigDecimal operator- (const long& a, BigDecimal b) {
	return (b-=a);
}

bool BigDecimal::setValue(long n) {
	sign=(n<0)?-1:1;
	msd=-1;
	while (n) {
		digits[++msd]=n%10;
		n/=10;
	}
	return true;
}
bool BigDecimal::setValue(string s) {
	if (s.size()==0) return false;
	for (int i = s.size()-1; i != 0; i--) {
		digits[++msd]=(char)(s[i]-'0');
	}
	if (s[0]=='-') sign=-1; 
	else digits[++msd]=(char)(s[0]-'0');
	return true;
}
BigDecimal::BigDecimal() {
	memset(digits,0,sizeof(digits));
}
BigDecimal::BigDecimal(long n) {
	BigDecimal();
	setValue(n);
}
BigDecimal::BigDecimal(string s) {
	BigDecimal();
	setValue(s);
}
int BigDecimal::operator[] (int index) {
	return (int)digits[msd-index];
}
BigDecimal& BigDecimal::operator= (BigDecimal& other) {
	if (&other!=this) {
		memcpy(digits,other.digits,other.size()-1);
		sign=other.sign;
	}
	return *this;
}
bool BigDecimal::operator==(const BigDecimal& other) {
	if (this->msd!=other.msd) return false;
	if (this->sign!=other.sign) return false;
	for (int i = 0; i < msd; i++){
		if (digits[i] != other.digits[i])
			return false;
	}
	return true;
}
bool BigDecimal::operator>(const BigDecimal& other) {
	if (sign!=other.sign)
		return (sign>other.sign);
	if(msd!=other.msd)
		return (msd>other.msd);
	for (int i = msd; i != -1; --i)
		if (digits[i]!=other.digits[i])
			return (digits[i]>other.digits[i]);
	return false; // they are equal
}
bool BigDecimal::operator<(const BigDecimal& other) {
	if (sign!=other.sign)
		return (sign<other.sign);
	if(msd!=other.msd)
		return (msd<other.msd);
	for (int i = msd; i != -1; --i)
		if (digits[i]!=other.digits[i])
			return (digits[i]<other.digits[i]);
	return false; // they are equal
}
BigDecimal& BigDecimal::operator+= (const BigDecimal& other) {
	if (other.sign==1)
		for (int i = 0; i != (msd+1); i++) {
			digits[i]+=other.digits[i];
			while (digits[i]>9) {
				digits[i]-=10;
				if (i+1>msd) msd++;
				digits[i+1]++;
			}
		}
	else {
		*this -= (-other);
	}
	return *this;
}
BigDecimal& BigDecimal::operator-= (const BigDecimal& other) {
	if ((*this)==(other)) setValue(0);
	if ((*this)<other) {
		*this=other-(*this);
		negate();
	} else if ((*this)>other) {
	
	}
}
BigDecimal& BigDecimal::operator*= (const BigDecimal& other) {

}
BigDecimal& BigDecimal::operator/= (const BigDecimal& other) {

}

BigDecimal& BigDecimal::operator+= (long other){};
BigDecimal& BigDecimal::operator-= (long other){};
BigDecimal& BigDecimal::operator*= (long other){};
BigDecimal& BigDecimal::operator/= (long other){};

size_t BigDecimal::size() {
		return msd+1;
}

ostream& operator<< (ostream& os, BigDecimal & obj) {
	if (obj.getSign() < 0) os << '-';
	for (int i = 0; i<obj.size(); i++) 
		os << ((char)('0'+obj[i]));
	return os;
}

istream& operator>> (istream& is, BigDecimal& obj) {
	string str;
	is >> str;
	obj.setValue(str);
	return is;
}

int main() {
	BigDecimal a(string("2147483649"));
	BigDecimal b = a;
	cout << b << endl;
	BigDecimal c;
	cin >> c;
	cout <<( (c>a)?"greater":"not greater" ) <<endl;
}