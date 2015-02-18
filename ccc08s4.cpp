#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 5

using namespace std;

int n,m;
int c[MAX][4];

bool check(int n) {
    return (n<=24&&m<n);
}


void f(vector<int> cards,int result) {
    if (cards.size()==1) {
        if (check(result+cards[0])) m=result+cards[0];
        if (check(result-cards[0])) m=result-cards[0];
        if (check(result*cards[0])) m=result*cards[0];
        if (result%cards[0]==0&&check(result/cards[0])) m=result/cards[0];
        return;
    }
    f(vector<int>(cards.begin()+1,cards.end()),result+cards[0]);
    f(vector<int>(cards.begin()+1,cards.end()),result-cards[0]);
    f(vector<int>(cards.begin()+1,cards.end()),result*cards[0]);
    if (result%cards[0]==0)
    f(vector<int>(cards.begin()+1,cards.end()),result/cards[0]);

}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i][0]>> c[i][1]>> c[i][2]>> c[i][3];
        m=0;
        sort(c[i],c[i]+4);
        do {
            f(vector<int>(c[i]+1,c[i]+4),c[i][0]);
        } while (next_permutation(c[i],c[i]+4));
        cout << m << endl;
    }

}


