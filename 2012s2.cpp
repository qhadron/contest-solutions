#include <iostream>
#include <string>
#include <vector>
using  namespace std;
vector<int>vals;
vector<int>base;
int main()
{
    string str="1";

    //while (str!="")
    //{
        getline(cin,str);
        int sum = 0,temp;
        for (int i = 0; i < str.length(); i+=2)
        {
            temp=str[i]-'0';
            switch(str[i+1])
            {
            case 'I':
                temp*=1;
                base.push_back(1);
                break;
            case 'V':
                temp *=5;
                base.push_back(5);
                break;
            case 'X':
                temp*=10;
                base.push_back(10);
                break;
            case 'L':
                temp*=50;
                base.push_back(50);
                break;
            case 'C':
                temp *= 100;
                base.push_back(100);
                break;
            case 'D':
                temp *= 500;
                base.push_back(500);
                break;
            case 'M':
                temp *= 1000;
                base.push_back(1000);
                break;
            default:
                break;
            }
            vals.push_back(temp);
        }
        for (int i = 0; i <vals.size() ; i++) {
            if(base[i+1]>base[i]) {
                sum-=vals[i];
            }
            else {
                sum+=vals[i];
            }
        }
        cout << sum << endl;
    //}
}
