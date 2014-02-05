#include <iostream>

using namespace std;
#define MAX 100000
#define _DEBUG
int cars[MAX],W[MAX],n,w,a;
int main ()
{
    cin >> w;
    cin >> n;
    for  (int i = 0; i < n; i++)
    {
        cin >> a;
        cars[i]=a;
    }
    a=0;
    if (cars[0]>w);
    else {
        W[0]=cars[0];
        a+=1;
        for (int i = 1; i < n; i++) {
            W[i]=cars[i]+W[i-1]-((i>=4)?(cars[i-4]):0);
            if (W[i]>w) break; else a++;
        }
    }
    //for (int i = 0; i < n; i++) if (W[i]>w)break;else cout << W[i] << endl;
    cout << a << endl;
}
