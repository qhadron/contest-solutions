#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a[3],b[3];
    int x,y;
    cin >> x >> y;
    bool abigger;
    for (int i = 0 ; i < 3; i++)
    {
        a[i] = x % 10;
        x /= 10;
        b[i] = y % 10;
        y /= 10;
    }
    for (int i = 0; i < 3; i++){
        if (a[i] > b[i]) {
            abigger = true;
            break;
        }
        else if (a[i] < b[i]) {
            abigger = false;
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (abigger)
            cout << a[i];
        else
            cout << b[i];
    }
    cout <<  endl;
}
