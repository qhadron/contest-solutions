#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const char c[] = "IOSHZXN";

int main()
{
    string word;
    cin >> word;
    for (int i = 0,found=0; i < word.size(); i++,found=0)
    {
        for (int j = 0; j < sizeof(c); j++)
        {
            if (word[i]==c[j])
            {
                //cout << word[i] <<  " " << c[j] << endl;

                found = 1;
            }
        }
        if (!found) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;


}
