#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

#define DEBUG false
using namespace std;

int main ()
{
    int t;
    string s ="";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int curnum,reversednum=0;
        string tempstring = "";
        cin >> curnum;

        while (curnum != 0)
        {
            if (curnum%2==0) {
                tempstring += "0";
            } else
                tempstring += "1";
            curnum /= 2;
        }
        if (DEBUG)
            cout << tempstring << endl;
        for (int i =0; i < tempstring.size(); i++) {
            int x = (tempstring[i]=='0')?0:1;
            reversednum += x * pow(2,tempstring.size()-i-1);
        }
        cout << reversednum << endl;
     }

}
