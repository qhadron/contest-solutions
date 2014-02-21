#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n,curreading,readings[1000],l,sl;

#define abs(x) (((x)<0)?-(x):(x))

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> curreading;
        readings[curreading-1]++;
    }
    vector<int> most,smost;
    for (int i =0; i < 1000; i++) {
        l=(l>readings[i])?l:readings[i];
    }
    for (int i =0; i < 1000; i++) {
        sl=(sl<readings[i])?(readings[i]!=l)?readings[i]:sl:sl;
    }
    for (int i = 0; i < 1000; i++) {
        if (readings[i]==l) most.push_back(i);
        if (readings[i]==sl) smost.push_back(i);
    }
    if (most.size()==2) {
        cout << abs(most[0]-most[1]) << endl;
        return 0;
    } else if (most.size()==1) {
        l=0;sl=0;
        for (int i = 0; i < smost.size();i++) {
            l=(abs(most[0]-smost[i])>l)?abs(most[0]-smost[i]):l;
        }
        cout << l << endl;
    }
    else {
        l = 0;
        for (int i =0 ; i < most.size(); i++) {
            sl=abs(most[i]-most[(i+1) % most.size()]);
            l=(sl>l)?sl:l;
        }
        cout << l << endl;
    }
}
