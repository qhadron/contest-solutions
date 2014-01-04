#include <iostream>

using namespace std;

    int score[5];
int main() {
    int temp;
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4; j++) {
        cin >> temp;
        score[i]+=temp;
    }
    int maxsum = 0;
    int maxnum = 0;
    for (int i = 0; i < 5; i++) {
        if (score[i]>maxsum) {
            maxsum = score[i];
            maxnum = i;
        }
    }
    cout << ++maxnum << " " << maxsum << endl;

}
