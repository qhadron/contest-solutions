#include <iostream>
#include <vector>
#define p(x) cout << x << " ";
using namespace std;

int getf(int n) {
    int x = 1;
    while (n > 1){
        x *= n--;
    }
    return x;
}

bool check(vector<int> v,int n) {
    if (v.size()<=0)
        return true;
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i]==n)
        return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n, n!=0) {
        vector<int> v;
        while (check(v,n)) {
            int sum = 0;
            while (n > 0) {
                sum += getf(n%10);
                n/=10;
            }
            n = sum;
            //p(sum)
            v.push_back(sum);
        }

        cout << v.size() +1 << endl;

    }

}
