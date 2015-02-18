#include <iostream>


using namespace std;

int n,x,y,a,d;

int main() {
    cin >> n;
    while (n--) {
        cin >> x >> y;
        if (x>y) a-=d;
        else if (y>x) d-=a;
    }
    cout << a << endl << d << endl;
}
