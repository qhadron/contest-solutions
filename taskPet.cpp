#include <iostream>
using namespace std;
int main() {
    int cursum,maxsum=0,maxnum=0,tempnum;
    for (int i = 0; i < 5; i++) {
        cursum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> tempnum;
            cursum += tempnum;
        }
        if (maxsum < cursum) {
            maxsum = cursum;
            maxnum = i+1;
        }
    }
    cout << maxnum << " " << maxsum << endl;
}
