#include <iostream>
#define DEBUG1
using namespace std;

const double VALS[] = {1e2,5e2,1e3,5e3,1e4,2.5e4,5e4,1e5,5e5,1e6};

bool opened[10];
int n,offer,sum,a;

int main ()
{
    sum=0;
    cin >> n;
    for (int i= 0; i < n; i++) {
        cin>>a;
        opened[a-1]=1;
    }
    cin >> offer;
    for (int i = 0; i < 10; i++) {
        sum += (opened[i])?0:VALS[i];
    }
    #ifdef DEBUG
        cout << (sum/(10-n)) << " " << offer << endl;
    #endif // DEBUG
    cout << ((sum/(10-n)<offer)?"deal":"no deal") << endl;
}
