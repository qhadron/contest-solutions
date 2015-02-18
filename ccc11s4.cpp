#include<iostream>

using namespace std;

#define MAX 8

struct BOARD {
    int p[MAX];//patient
    int d[MAX];//donor
};
int diff;

BOARD init,b;
int take(int d, int p) {
    int sum=0;
    while (b.d[d]&&b.p[p]) {
        sum++;
        b.d[d]--;
        b.p[p]--;
    }
    return sum;
}

int check() {
    int sum = 0;
    //ordered in terms of type
    //o-
    sum+=take(0,0);
    //o+
    sum+=take(1,1);
    sum+=take(0,1);
    //a-
    sum+=take(2,2);
    sum+=take(0,2);
    //b-
    sum+=take(4,4);
    sum+=take(0,4);
    //a+
    sum+=take(3,3);
    sum+=take(2,3);
    //b+
    sum+=take(5,5);
    sum+=take(4,5);

    sum+=take(1,3);
    sum+=take(1,5);
    sum+=take(0,3);
    sum+=take(0,5);
    //ab-
    sum+=take(6,6);
    sum+=take(4,6);
    sum+=take(2,6);
    sum+=take(0,6);
    //ab+
    for (int i  = 0; i < 8; i++)
        sum+=take(i,7);
    return sum;
}

int check2() {
    int sum = 0;
    //ordered in terms of +/-
    //o-
    sum+=take(0,0);
    //o+
    sum+=take(1,1);
    sum+=take(0,1);
    //a-
    sum+=take(2,2);
    sum+=take(0,2);
        //b-
    sum+=take(4,4);
    sum+=take(0,4);
     //a+
    sum+=take(3,3);
    sum+=take(1,3);
    //b+
    sum+=take(5,5);
    sum+=take(1,5);

    sum+=take(2,3);
    sum+=take(0,3);
    sum+=take(4,5);
    sum+=take(0,5);
    //ab-
    sum+=take(6,6);
    sum+=take(4,6);
    sum+=take(2,6);
    sum+=take(0,6);
    //ab+
    for (int i  = 0; i < 8; i++)
        sum+=take(i,7);
    return sum;
}


int main () {
    for(int i = 0; i < 8; i++) {
        cin >> init.d[i];
    }
        for(int i = 0; i < 8; i++) {
        cin >> init.p[i];
    }
    b=init;
    int a = check();
    b=init;
    int y = check2();
    cout << max(a,y) << endl;
}

