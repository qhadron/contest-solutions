#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

#define scan(x) while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0')
char _;
#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#else
#define dvar(...)
#endif

int N,cnt;
string s;
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG
    cin >> N;
    cin >> s;
    for (int i = 0; i < s.size();) {
        if (s[i] == 'O')
            cnt += 1;
        while (s[i] == 'O')
            i+=1;
        if (s[i] != 'O')
            i+=1;
    }
    cout << cnt << endl;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'O')
            cout << s[i];
        else if (s[i]=='X'&&i!=0)
            cout << endl;
    }
}
