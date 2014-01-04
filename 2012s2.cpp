#include <iostream>
#include <string>
using  namespace std;
int main()
{
    string str="1";

    while (str!="")
    {
        getline(cin,str);
        int sum = 0,temp;
        for (int i = 0; i < str.length(); i+=2)
        {
            temp=str[i]-48;
            switch(str[i+1])
            {
            case 'I':
                temp*=1;
                break;
            case 'V':
                temp *=5;
                break;
            case 'X':
                temp*=10;
                break;
            case 'L':
                temp*=50;
                break;
            case 'C':
                temp *= 100;
                break;
            case 'D':
                temp *= 500;
                break;
            case 'M':
                temp *= 1000;
                break;
            default:
                break;
            }
            sum += temp;
        }
        cout << sum << endl;
    }
}
