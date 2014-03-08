#include <iostream>
#include <set>
#include <cstring>

#define DEBUG1

#ifdef DEBUG
#include <bitset>
#define p(x) cout << bitset<8>((x)) << endl
#else
#define p(x)
#endif // DEBUG

using namespace std;

#define MAXR 30



int row[MAXR];
int L,R,t;
set<int> configs[MAXR];

int main() {
    cin >> R >> L;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < L; j++) {
            cin >> t;
            row[i]|=(t<<(L-j-1));
        }
    for (int i = 0; i < R; i++) {
        p(row[i]);
        configs[i].insert(row[i]);
    }

    for (int i = 1; i < R; i++) {
        for (set<int>::iterator top = configs[i-1].begin(); top!=configs[i-1].end();++top) {
            configs[i].insert((*top)^row[i]);
        }
    }

    cout << configs[R-1].size() << endl;
}
