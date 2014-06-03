#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cstdio>
using namespace std;

typedef unsigned char uchar;

uchar data[22][22],mines[22][22];
uchar hintx[22*22],hinty[22*22];
uchar remaining[22][22];
int N,nhints ;
int dx[9] = {-1,0,1,-1,0,1,-1,0,1},dy[9] = {-1,-1,-1,0,0,0,1,1,1};

/**
*  add mines based on configuration
*   --pos holds whether to add(1) a mine
*   --n is the the current hint
*/
bool add(char pos[9],int n) {
    int x, y;   //holds the current hint position
    for (int i = 0; i < 9 ;i++) {
        if (pos[i]) {
            x = hintx[n]+dx[i]; y = hinty[n]+dy[i];
            if (x<1||x>N||y<1||y>N)
                return false;
            if (mines[y][x])
                return false;
            for (int j = 0,tx,ty; j < 9; j++) {
                ty = y+dy[j];
                tx = x+dx[j];
                if (!(tx<1||tx>N||ty<1||ty>N)&&remaining[ty][tx] < 1)
                    return false;
            }
        }
    }
    for (int i = 0; i < 9 ;i++) {
        if (pos[i]) {
            x = hintx[n]+dx[i]; y = hinty[n]+dy[i];
            mines[y][x] = true;
            for (int j = 0; j < 9; j++) {
                --remaining[y+dy[j]][x+dx[j]];
            }
        }
    }

    return true;
}

void remove(char pos[9], int n) {
    for (int i = 0; i < 9 ;i++) {
        if (pos[i]) {
            mines[hinty[n]+dy[i]][hintx[n]+dx[i]] = false;
            for (int j = 0; j < 9; j++) {
                ++remaining[hinty[n]+dy[i]+dy[j]][hintx[n]+dx[i]+dx[j]];
            }
        }
    }
}

bool dfs(int n) {
/*
cout << (int)hintx[n] <<" "<< (int)hinty[n] << "N:"<<n<<":\n";
         for (int i = 1; i <= N; i++,cout<<endl)
            for (int j = 1; j <=N; j++)
                cout << ((mines[i][j])?'M':'.');cout<<endl;*/
    char mine[9], val = data[hinty[n]][hintx[n]];
    if (remaining[hinty[n]][hintx[n]] == 0) return (n==nhints-1)||dfs(n+1);

    for (int i = 8,cnt = 0; i>=0; cnt++,i--) {
        mine[i] = (cnt < remaining[hinty[n]][hintx[n]]);
    }
    do {
        if(!add(mine,n)) continue;
        if (n==nhints-1) return true;
        if (dfs(n+1)) return true;
        remove(mine,n);
    } while(next_permutation(mine,mine+9));
    return false;
}

int main() {
    freopen("0.input.txt","r",stdin);
    freopen("0.log.txt","w",stdout);
    for (int testcases = 5; testcases--;) {
        memset(data,'-',sizeof(data));
        memset(mines,0,sizeof(mines));
        N=0;
        nhints = 0;
        for (int c, i = 0;(c=getchar())!='\n';) {
            data[1][++i] = c;
            ++N;
        }
        for (int i = 2; i <= N; i++) {
            cin >> (data[i]+1);
        }
        getchar();
        for (int i = 1; i <= N ;i++) {
            for (int j = 1; j <= N; j++) {
                bool shouldadd = false;
                if (isdigit(data[i][j])) {
                    data[i][j] -= '0';
                    shouldadd = true;
                }
                if (j==1||j==N) {
                    if (i==1||i==N) {
                        remaining[i][j] = min((uchar)4,data[i][j]);
                    } else {
                        remaining[i][j] = min((uchar)6,data[i][j]);
                    }
                } else {
                    if (i==1||i==N)
                        remaining[i][j] = min((uchar)6,data[i][j]);
                    else
                        remaining[i][j] = min((uchar)9,data[i][j]);
                }

                if (shouldadd) {
                    hintx[nhints] = j;
                    hinty[nhints++] = i;
                }
            }
        }
        /*
        for (int i = 1; i <= N; i++,cout<<endl)
            for (int j =1; j<=N; j++,cout<<" ")
                cout << (char)((data[i][j]!='-')?(data[i][j]+'0'):data[i][j]); cout << endl;
        for (int i = 1; i <= N; i++,cout<<endl)
            for (int j =1; j<=N; j++,cout<<" ")
                cout << (int)(remaining[i][j]);cout<<endl;*/
        dfs(0);
        for (int i = 1; i <= N; i++,cout<<endl)
            for (int j = 1; j <=N; j++)
                cout << ((mines[i][j])?'M':'.');
        cout << endl;
    }
}
/*
-4-1--
----5-
5-64--
-9--7-
--87-5
3--6--
2-20---33-
3-2---3---
-2----222-
-210---3-3
2-1--6-5-4
23--44---4
---5-42---
1-5--1-02-
----2-1--3
0-1-01-1--

MMM..M
.M...M
MMMMMM
MMM..M
MMMMMM
.MMMMM

.M...MMM.M
.M......M.
M........M
.....MM...
.M...M.MMM
M...MMM.MM
..MM......
.M.MM....M
..M......M
......M..M
*/
