#include <iostream>

using namespace std;

bool check(int year) {
    int digits=0,curdigit;
    while (year) {
            curdigit=year%10;
            year/=10;
            if (!(digits>>curdigit&1))
                digits=digits | 1 << curdigit;
            else {
                digits=0;
                break;
            }
    }
    return !(digits==0);
}

int main()
{
    int year;
    cin >> year;
    while (!check(++year));
    cout << year << endl;
}
