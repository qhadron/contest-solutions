#include <iostream>
#include <string>

using namespace std;

int n;
string row1[31],row2[31];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> row1[i];
    for (int i = 1; i <= n; i++) cin >> row2[i];
    if (n&1) {cout << "bad"; return 0;}
    for (int i = 1; i <= n; i++) {
        if (row1[i]==row2[i]) {cout << "bad" << endl; return 0;}
        for (int j = 1; j <= n;j++) {
            if (row1[j]==row2[i]) {
                if (row2[j]==row1[i]) break;
                else {cout << "bad"; return 0;}
            }
        }
    }
    cout <<"good" << endl;;
}
