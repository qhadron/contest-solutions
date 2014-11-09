#include <iostream>

using namespace std;

#define MAX 25

int ways[MAX+1][MAX+1],R,C,n,x,y;
int main()
{
#ifdef PROFILE
	freopen("0.input.txt", "r", stdin);
#endif

    cin >> R >> C;
    cin >> n;
    while (n--) {
        cin >> y >> x;
        ways[x][y]=-1;
    }
    ways[1][1]=1;
    for (int i = 1; i <= C; i++) {
        for (int j = 1;  j <= R; j++) {
            if (ways[i][j]==-1) continue;
            ways[i][j]+=(ways[i-1][j]!=-1)?ways[i-1][j]:0;
            ways[i][j]+=(ways[i][j-1]!=-1)?ways[i][j-1]:0;
        }
    }
    #ifdef _DEBUG
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (ways[j][i]==-1)
                cout << 'x';
            else
                cout << ways[j][i];
            cout << " ";
        }
        cout << endl;
    }
    #endif
    cout << ways[C][R] << endl;

}
