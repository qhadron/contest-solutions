#include<iostream>
#include <queue>
#include <cstring>
using namespace std;

int steps [(int)1e5];

int main() {
    memset(steps,-1,sizeof(steps));
    int x, y;
    queue<int> qu;
    cin >> x >> y;
    qu.push(x);
    steps[x] = 0;
    while (!qu.empty()) {
            //curpos
        int c = qu.front();qu.pop();
        for (int i = -1; i < 2; i++) {
            if (steps[c+i]==-1){
                qu.push(c+i);
                steps[c+i]=steps[c]+1;
            }
        }
        if (steps[c*2]==-1) {
            qu.push(c*2);
            steps[c*2] = steps[c]+1;
        }
        if (c == y)
            break;
    }

    cout << steps[y] << endl;

}
