#include <iostream>

using namespace std;


int a,b,cnt;

typedef unsigned long long ulong;

int main() {
    cin >> a >> b;
    for (ulong i = 0,t; i < 22; i++)
        if ((t=i*i*i*i*i*i)>=a&&t<=b)
            cnt++;

    cout << cnt << endl;
}
