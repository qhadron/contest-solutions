#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 10000
class COM {
    public:
    string name;
    int score;
    inline bool operator<(const COM& l) {
        return true;
    }
    static inline bool cmp(const COM& l , const COM& r) {
        if (l.score==r.score) {
            return (l.name>r.name);
        } else {
            return (l.score<r.score);
        }
    }

};


int n,r,s,d;
string str;
COM c[MAX];
int main () {
    cin >> n;
    if (!n) return 0;
    for (int i = 0; i < n; i++) {
        cin >>str >> r >> s >> d;
        c[i]={str,(2*r+3*s+d)};
    }
    sort(c,c+n,COM::cmp);
    reverse(c,c+n);
    if (n==1)
        cout << c[0].name << endl;
    else
        cout << c[0].name << endl << c[1].name << endl;

}
