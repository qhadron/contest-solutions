#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int chars[26];
    string s;
    int cnt =0;
    for (int n = 0; n < 5; n++)
    {
        getline(cin,s);
        cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            chars[i] = 0;
        }
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = toupper(s[i]);
            if (s[i]>64&&s[i]<91)
            {
                chars[s[i]-65]++;
                cnt++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (chars[i]>0)
            {
                cout << (char)(65+i);
                cout << '-';
                cout << chars[i];
                cnt-=chars[i];
                if (cnt !=0)
                    cout << ":";
                else
                    cout << endl;
            }
        }
    }
}


