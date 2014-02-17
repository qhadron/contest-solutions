#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string s, result;
int x,y,n,r,c;
//r: num rows
//c: num cols
int main (void) {
    cout << "Start value:" << endl;
    cin >> x;
    cout << "End value:" << endl;
    cin >> y;
    n=x-y;
    if(n==0)
        cout << x << endl;s
    else {
        c=(n&1)?n/2:n/2+1;
        r=(int)sqrt(n)+1;
    }
}
