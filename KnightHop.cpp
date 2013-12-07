#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct coords
{
    int x,y;
};

int main()
{
    queue<coords> qu;
    int grid[8][8];
    bool t[8][8];
    memset(grid,-1,sizeof(grid));
    memset(t,false,sizeof(t));
    coords c;
    int ex,ey;
    cin >> c.x>> c.y;
    c.x-=1;
    c.y-=1;
    qu.push(c);
    cin >> ex>> ey;
    grid[c.x][c.y]=0;
    while (!qu.empty())
    {
        coords cc = qu.front();
        qu.pop();

        if (cc.x < 0 || cc.x > 7 || cc.y < 0 || cc.y > 7) {
            continue;
        }
        int x = cc.x, y = cc.y;
        coords tc;

        for (int i = -2; i < 3; i++) {
            for (int j = -2; j < 3; j++) {
                if (i!=0&&j!=0&&i!=j&&i+j!=0) {
                    if (!(x+i<0||x+i>7||y+j<0||y+j>7)&&!t[x+i][y+j]) {
                            t[x+i][y+j]=true;
                    if (grid[x+i][y+j]>grid[x][y]||grid[x+i][y+j]==-1) {
                        //cout << x+i+1 << " " << y+j+1 << endl;
                        grid[cc.x+i][cc.y+j] = grid[cc.x][cc.y]+1;
                    }
                        tc.x = x+i;
                        tc.y = y+j;
                        qu.push(tc);
                    }
                }
            }
        }
    }
    cout << grid[ex-1][ey-1];

}
