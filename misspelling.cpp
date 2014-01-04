#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        int x;
        char a;
        string s,s1="";
        cin >> x;
        //cin >> a;
        getline(cin,s);
        //cout << s << endl;
        //x--;
        for (int i = 1; i < s.length();i++)
        {
            if (i!=x)
                s1 += s[i];
        }
        cnt++;
        cout << cnt << " " << s1 << endl;
    }

}
