#include <iostream>
#include <vector>
#include <algorithm>

/*
3
1 2 3
2 3 4
3 4 5
5
1 1 1
2 2 2
4 3 2
4 3 3
4 4 4
*/

using namespace std;

struct S {
    int l[3];
    int v;
};

int main() {
    vector<S> in;
    vector<S> out;
    int n,m;
    cin >> n;
    for (int i  = 0 ; i < n; i++) {
        S s;
        cin >> s.l[0] >> s.l[1] >> s.l[2];
        s.v = s.l[0] * s.l[1] * s.l[2];
        sort(s.l,s.l+3);
        //cout << s.l[0] << endl;
        in.push_back(s);
    }
    cin >> m;
    while (m--) {
        S s;
        cin >> s.l[0] >> s.l[1] >> s.l[2];
        s.v = s.l[0] * s.l[1] * s.l[2];
        sort(s.l,s.l+3);
        out.push_back(s);
    }

    for (int i = 0; i < out.size(); i++) {
        S c = out[i];
        S t;
        int smallest = 9999999;
        int smallestindex = -1;
        for (int j = 0; j < in.size(); j++) {
            t = in[j];
           // if (c.v > t.v)
             //   break;
            if ((c.l[0]<=t.l[0]&&c.l[1]<=t.l[1]&&c.l[2]<=t.l[2])) {
                if (t.v < smallest) {
                    smallest = t.v;
                    smallestindex = j;
                }
            }
        }
        if (smallestindex !=-1)
            cout << smallest << endl;
        else
            cout << "Item does not fit." << endl;
    }

}
