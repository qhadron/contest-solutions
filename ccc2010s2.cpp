#include <iostream>
#include <string>
#include <utility>

#define MAX 20

using namespace std;

pair<char,string> d[MAX];
int n;
char c;
string s,x;

string fix(string str) {
    int i = 0,t;
    while (i < n) {
        cout << str << endl;
        if (str.find(d[i].second)!=str.npos)
            str=str.replace(s.find(d[i].second),d[i].second.size(),2,d[i].first);
        else
            i++;
    }
    return str;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> x;
        d[i]=make_pair(c,x);
    }
    cin >> s;
    cout << s;
    cout << (fix(s)) << endl;
}
