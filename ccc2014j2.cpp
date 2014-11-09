#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    char c;
    cin >> n;
    int a,b;
    while (n--) {
        cin >> c;
        if (c=='A')
            a++;
        if (c=='B')
            b++;
    }
    cout << ((a>b)?"A":(b>a)?"B":"tie") << endl;

}
