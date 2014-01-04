#include <iostream>
#include <vector>
#include <queue>
/*
maze info
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/

using namespace std;

struct coords
{
    int x,y;
};

int maze[5][5];
int t[5][5];
vector<coords> v;

void bfs()
{
    queue<coords> qu;
    coords start;
    start.x=0;
    start.y=0;
    qu.push(start);
    while(!qu.empty())
    {
        coords c = qu.front();qu.pop();
        if (x<0||x>4||y<0||y>4)
            continue;
        if (t[x][y])
            continue;
        for (int i = -1; i <=1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i+j!=0&&i!=j&&!t[x+i][y+j]&&!maze[x+i][y+j])
                {
                    coords temp;
                    temp.x=x+i;
                    temp.y=y+j;
                    qu.push(temp);
                }
            }
        }
        if (c.x==4&&c.y==4)
        {
            break;
        }
    }


    bool dfs(int x, int y, int steps)
    {
        if (x<0||x>4||y<0||y>4)
            return false;
        if (t[x][y])
            return false;
        t[x][y]=1;
        if (x==4&&y==4)
        {
            coords c;
            c.x=x;
            c.y=y;
            v.push_back(c);
            return true;
        }
        for (int i = -1; i <=1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i+j!=0&&i!=j&&!t[x+i][y+j]&&!maze[x+i][y+j])
                {
                    if (dfs(x+i,y+j,steps+1))
                    {
                        coords c;
                        c.x=x+i;
                        c.y=y+j;
                        v.push_back(c);
                        return true;
                    }
                }
            }
        }

    }

    int main()
    {
        for (int i = 0; i<5 ; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> maze[i][j];
            }
        }

        dfs(0,0,0);
        for (int i = v.size()-1; i >-1; i--)
        {
            coords c = v[i];
            cout << "("<<c.x<<","<<c.y<<")"<<endl;
        }
    }
