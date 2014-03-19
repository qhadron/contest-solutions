#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100
int R,C,N,s[10];

int curcol;

struct row {
    int data[MAX];
};

    bool cmp(const row& l, const row& Right) {
        return (l.data[curcol]<Right.data[curcol]);
    }
row r[100];
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> r[i].data[j];
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 0; i < N; i++){
        curcol=s[i]-1;
        stable_sort(r,(r+R),cmp);
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << r[i].data[j] << " ";
        cout << endl;
    }
}
/*
4 3
6 2 1
9 1 3
9 2 1
6 1 1
2
2
1
*/
