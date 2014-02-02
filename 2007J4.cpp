#include <iostream>
#include <string>

using namespace std;

int ac[26],acnt,bcnt,bc[26];
int main()
{
    string a,b;
    cout << "Enter first phrase>";
    getline(cin,a);
    cout << "Enter second phrase>";
    getline(cin,b);
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i]==' ')
            continue;
        ac[a[i]-'A']++;
        acnt++;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i]==' ') continue;
        bc[b[i]-'A']++;
        bcnt++;
    }
    if (acnt==bcnt)
        for (int i = 0; i < 26; i++)
        {
            if (ac[i]!=bc[i])
            {
                cout<<"Is not an anagram.\n";
                return 0;
            }
        }
    else
    {
        cout<<"Is not an anagram.\n";
        return 0;
    }
    cout<<"Is an anagram.\n";
}
