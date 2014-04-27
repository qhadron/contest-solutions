#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int type[10] = {1,2,5,10,50,100,1000,10000,500000,1000000};
int main() {
    char c;
    int data[9];
    int cnt[10];
    for (int testcase = 0; testcase < 10; testcase++) {
        memset(data,0,sizeof(data));
        memset(cnt,0,sizeof(cnt));
        int qmark = 0;
        for (int i = 0; i < 9; i++) {
            while((c=getchar())=='\n');
            if (c=='?') {
                qmark++;
                continue;
            }
            cin >> data[i];
        }
        for (int i = 0; i < 9; i++) {
            if (data[i]) {
                int pos = 4;
                //binary search
                for (int s = 0, t = 8; type[pos]!=data[i];pos = (s+t) >> 1) {
                    if (type[pos]< data[i]) {
                        s = ++pos;;
                    } else {
                        t = --pos; ;
                    }
                }
                cnt[pos] ++;
            }
        }
        bool flag = false;
        for (int i = 0; i < 10; i++) {
            if (cnt[i]>2) {
                flag = true;
                cout << "$" << type[i];
                break;
            }
            if (cnt[i]+qmark > 2) {
                cout <<"$" <<  type[i] << " ";
                flag = true;
            }
        }
        if (!flag) cout << "No Prizes Possible" << endl;
        else cout << endl;
    }
}
/*
$10
$100
?
$10
$1
$50
$50
$1000
$1

$1
$2
$5
$10
$50
$100
$1000
$10000
?

*/
