#include <cstring>
#include <iostream>
#include <set>
using namespace std;

#define p(x) cout << x << " " ;
#define SIZE 1992009
int main() {
    set<long> primes;
    bool isPrime[SIZE];
    memset(isPrime,true,sizeof(isPrime));

    long n;
    for (long i = 2; i < SIZE; i++) {
        if (isPrime[i-2]) {
            n=2;
            primes.insert(i);
            while (n*i<SIZE) {
                isPrime[n*i-2] = false;
                n++;
            }
        }
    }
    cout << "donePrimes" << endl;
    int maxcnt = 0,cnt;
    int a,b;
    const set<long>::iterator END = primes.end();
    set<long>::iterator it;

    for (int i= -1000; i <=1000; i++) {
                        if (i % 10 == 0) {
                cout << i << endl;
            }
        for (int j = -1000; j < 1000; j++) {
            cnt = 0;
            for (int k = 0; k < j -2; k++) {
                if (primes.find(k*k+i*k+j)!=END) {
                    cnt ++;
                } else {
                    if (cnt>maxcnt) {
                    a = i;
                    b = j;
                    maxcnt = cnt;
                }
                    break;
                }
            }
        }
    }
    int test = 0;
    for (int i= 0; i<39;i++)
        if (primes.find(i*i+i+41) != END) {
            test++;
        }
    cout << test << endl;
    cout <<"["<<maxcnt<<"]"<<" "<< a << "*" << b << "=" << a*b << endl;
}
