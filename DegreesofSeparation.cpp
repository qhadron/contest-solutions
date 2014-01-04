#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 50

using namespace std;

bool adjmatrix[MAX][MAX];

void f(int a, int b)
{
    adjmatrix[a][b] = adjmatrix[b][a] = true;
}

void unfriend(int a, int b)
{
    adjmatrix[a][b] = adjmatrix[b][a] = false;
}

int cntFriends(int a)
{
    int cnt = 0;
    for (int i = 0; i< MAX;
            i++)
    {
        if (adjmatrix[i][a])
            cnt++;
    }
    cout << cnt << endl;
    return cnt;
}



int ffriends(int a)
{
    list<int> ff;
    for (int i = 1; i < MAX; i++)
    {
        if (adjmatrix[a][i])
        {
            for (int j = 1; j < MAX; j++)
            {
                if (adjmatrix[i][j]&&j!=a&&!adjmatrix[a][j])
                    ff.push_back(j);
            }
        }
    }
    ff.sort();
    ff.unique();
    cout << ff.size();
    return ff.size();
}

int seperatoin(int x,int y)
{
    int steps[MAX];
    queue<int> qu;

    memset(steps,-1,sizeof(steps));
           qu.push(x);
           steps[x] = 0;
           while (!qu.empty())
{
    int curpos = qu.front();
        qu.pop();
        for (int j = 0; j < MAX; j++)
        {
            if (steps[j]==-1&&adjmatrix[curpos][j])
            {
                qu.push(j);
                steps[j]=steps[curpos]+1;
                if (j==y)
                    break;
            }
        }

    }
    if (steps[y]!=-1)
    cout << steps[y] << endl;
    else
        cout << "Not connected" << endl;
        return steps[y];

    }

int main()
{
    int head[] = {1,2,6,3,4,5,3,4,7,3,3,8,9,9,15,12,12,11,13,16,16,18};
    int tail[] = {6,6,7,6,6,6,4,5,8,5,15,9,10,12,13,13,11,10,14,18,17,17};

    for (int i = 0; i < sizeof(head)/sizeof(int); i++)
    {
        f(head[i],tail[i]);
    }
    char command;
    int x,y;

    cin >> command;
    while(command != 'q')
    {
        if (command == 'i')
        {
            cin >> x >> y;
            f(x,y);
        }
        if (command=='d')
        {
            cin >> x >> y;
            unfriend(x,y);
        }
        if (command == 'n')
        {
            cin >> x;
            cntFriends(x);
        }
        if (command == 'f')
        {
            cin >> x;
            ffriends(x);
        }
        if (command == 's')
        {
            cin >> x >> y;
            seperatoin(x,y);
        }
    }
}


