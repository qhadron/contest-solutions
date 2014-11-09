#include <iostream>

using namespace std;

#define MAX 10000

int n,a;
char c[MAX],C;
int main() {
    cin >> n;
    for (int i = 0; i<n;i++)
        cin >> c[i];
    for (int i = 0; i<n;i++)
        cin>>C,a+=(C==c[i]);
    cout << a << endl;

}
