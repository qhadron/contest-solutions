#include<iostream>
#include <vector>
using namespace std;

int main() {
vector<string> svec;
string s;
 do {

 cin >> s;
 svec.push_back(s);
 } while(s != "");
svec.pop_back();
 for (int i = svec.size()-1; i >=0; i--)
  cout << svec[i];
return 0;
}
