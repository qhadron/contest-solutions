#include <iostream>
#include <string>

using namespace std;

#define MAX 100
string str;
int n,s,t;
int main ()
{
    cin >> n;
    n++;
    while (n--){
    getline(cin,str);
        for (char c:str)
        s+=(c=='s'||c=='S')?1:0,t+=(c=='t'||c=='T');
    }
   cout << ((t>s)?"English":"French") << endl;
}
