#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    char* s = "";
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        cout << x*y-1 << endl;
    }
}
