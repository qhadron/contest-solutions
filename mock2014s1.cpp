#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s,pattern,rp;
int i,j;
int main() {
    getline(cin,s);
    getline(cin,pattern);
    rp=string(pattern.rbegin(),pattern.rend());
    i=s.find(rp,i);
    do {
        j=i++;
    } while ((i=s.find(rp,i))!=s.npos);
    reverse(pattern.begin(),pattern.end());
    cout << ((j)?(j+pattern.size()):-1) << endl;

}
