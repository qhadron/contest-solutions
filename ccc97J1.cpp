#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int n,nsub,nverb,nobj;
    string s;
    vector<string> sub,verb,obj;
    cin >> n;
    while (n--)
    {
        sub.clear();
        verb.clear();
        obj.clear();
        cin >> nsub >> nverb >> nobj;
        getline(cin,s); //remove garbage
        while (nsub--)
        {
            getline(cin,s);
            sub.push_back(s);
        }

        while (nverb--)
        {
            getline(cin,s);
            verb.push_back(s);
        }

        while (nobj--)
        {
            getline(cin,s);
            obj.push_back(s);
        }

        for (int i = 0; i < sub.size(); i++)
            for(int j = 0; j < verb.size(); j++)
                for(int k=0; k<obj.size(); k++)
                    cout<<sub[i]<<" "<<verb[j]<<" "<<obj[k]<<"."<<endl;
        cout<<endl;
    }
}
