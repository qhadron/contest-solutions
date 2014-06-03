#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("0.input.txt","r",stdin);
    int N,x,y;
    for (int testcase = 10; testcase--;) {
        cin >> N;
        for (int i = 0,cnt =0; i < 5; i++,cnt=0) {
            cin >> x >> y;
            x--;y--;
            for (int j = 1; j<=N; j++)
            {
                if (N%j)continue;
                //x % 2 != 0 && y & 2 != 0
                if (!(((x/j)^(y/j))&1)) {
                    cnt++;
                }
            }
            cout << ((cnt&1)?'B':'G');
        }
        cout << endl;
    }
}

/*
10
5 1
5 2
5 3
5 4
5 5
*/
