#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    for (int s = 0; s < 5; s++)
    {
        int n;
        cin >> n;
        bool fish[n+1][n+1][n+1];
        memset(fish,false,sizeof(fish));
        int x,y,t,b;
        while (cin >> x && x != 0)
        {
            cin >>y >> t >> b;
            for (int i = b; i <=t; i++)
                fish[x][y][i] = true;
        }
        cin >> y >>t>> b;
        int cnt=-1;
        for (int level = 1; level <= n; level ++)
        {
            int tempcnt = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (fish[i][j][level])
                        tempcnt++;
                }
            }
            cnt = (tempcnt>cnt)?tempcnt:cnt;
        }
        cout << cnt << endl;

    }
}
