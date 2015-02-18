#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class PAIR {
public:
    int a,b,diff,sum;
    PAIR(int x, int y);
    void p();
};

PAIR::PAIR(int x, int y) {
    a=x;
    b=y;
    diff=abs(a-b);
    sum=a+b;
}

void PAIR::p() {
    cout << a << " " << b << " " << diff << " " << sum << endl;
}

vector<PAIR> getFactors(int n) {
    vector<PAIR> factors;
    for (int i = 1; i <= sqrt(n);i++){
        if (n%i==0){
            PAIR p (i,n/i);
            factors.push_back(p);
        }
    }
    return factors;
}

void dowork(){
    int n;
    cin >> n;
        vector<PAIR> pairs = getFactors(n);
        #ifdef DEBUG
        for (int i = 0; i < pairs.size(); i++)
            pairs[i].p();
        #endif
        for (int i  = 0; i < pairs.size()-1;i++) {
            for (int k = i; k < pairs.size();k++) {
                if (pairs[i].diff==pairs[k].sum){
                    cout<<n<<" is nasty"<<endl;
                    return;
                }
            }
        }
    cout<<n<<" is not nasty"<<endl;
}

int main() {
    int cnt;
    cin >> cnt;
    while (cnt--) {
        dowork();
    }

}
