#include <iostream>
#include <string>

using namespace std;

int n,rem;
unsigned long x,y;
string s,b;
char g;

#define OUT

void subtract(string & a, int n, int pos) {
    if ((a[pos]-'0')<n) {
        a[pos]=a[pos]+10-n;
        subtract(a,1,pos-1);
    } else {
        a[pos]=a[pos]-n;
    }
}

int main() {
    cin >> n;
    getline(cin,s);
    while (n--) {
        getline(cin,s);
        b=string(s);
        while (s.size()>2) {
            x=s[s.size()-1]-'0';
            #ifdef OUT
            cout << s  << endl;
            #endif
            s=s.substr(0,s.size()-1);
            subtract(s,x,s.size()-1);
            while (s[0]=='0')
                s=s.substr(1);
        }
        #ifdef OUT
        cout << s << endl;
        #endif
        if (s=="11")
            cout << "The number "<<b<<" is divisible by 11." << endl << ((n==0)?"":"\n");
        else
            cout << "The number "<<b<<" is not divisible by 11." << endl << ((n==0)?"":"\n");
    }

}
