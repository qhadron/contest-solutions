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
    int i = 0,t,pos = 0;
	while (pos < str.length()) {
		i = 0;
		while (i < n) {
			t = str.find(d[i].second);
			if (t != str.npos && t == pos)
				str = str.replace(t, d[i].second.size(), 1, d[i].first), ++pos;
			else
				i++;
		}
	}
    return str;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif // _DEBUG
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> x;
        d[i]=make_pair(c,x);
    }
    cin >> s;
	cout << (fix(s)) << endl;
}
