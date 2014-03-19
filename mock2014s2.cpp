#include <iostream>
using namespace std;

#define MAX 1000
int data[MAX],N,len;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin>>data[i];
    for (int i=0,t=0; i < N-1; i++) {
            t=0;
            if (data[i+1]<data[i])
            for (int j = 1; j + i < N;j++) {
                if (data[i+j]<data[i+j-1]) //descending part
                    t++;
                else {
                    for (int k = 1,l; k + j + i < N; k++) {
                        if (data[i+j+k]==data[i+j+k-1]) //equal
                            t++;
                        else {
                            t++;
                            k-=1;
                            l=0;
                            while ((i+j+k+l)<N&&data[i+j+k+l]>data[i+j+k+l-1])
                                t++,l++;
                            break;
                        }
                    }
                    break;
                }
            }
        len=(t>len)?t:len;
    }
    cout << len << endl;
}/*
12
21 5 4 10 8 4 3 6 12 17 4 17
*/
