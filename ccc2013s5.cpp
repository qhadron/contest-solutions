#include <iostream>

#define MAX 1000000

#define DEBUG1
using namespace std;

/***
    f - the smallest factor of N greater than 1
    n - backup of N
    x - backup of n/f

    algorithm: be as greedy as possible while subtracting to get minimum cost
***/


int N,cost,f,n,x;
int main()
{
    cin >> N;
    n=N;
    cost=0;
    while (n>1) {
            #ifdef DEBUG
        cout << n << ":" << cost << endl;
    #endif
        f=1;
        while(n%++f);
        if(f<n&&n%f==0) {
            x=n/f;
            n-=x;
            cost+=n/x;
        }else {
            n-=1;
            cost+=n;
        }
    }

    cout << cost << endl;
}
