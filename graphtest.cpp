#include <iostream>
#include <queue>
#include <cstring>

#define DEBUG true

using namespace std;

//adjmatrix
bool adj[12][12];


void c(int a, int b)
{
    adj[a][b] = adj[b][a] = true;
}

void bfs (int a, int b)
{
    queue<int> qu;
    int steps[12];
    memset(steps,-1,sizeof(steps));
    steps[a] = 0;
    qu.push(a);
    while (!qu.empty())
    {
        int curpos = qu.front();
        if (DEBUG) cout << curpos << ":";
        qu.pop();

        for (int i = 1; i<=11; i++)
        {
            if (adj[curpos][i]&&steps[i]==-1)
            {
                cout << i << " ";
                qu.push(i);
                steps[i] = steps[curpos]+1;
            }
        }
        if (curpos == b)
            break;
        cout << endl;
    }
    if (DEBUG) cout << endl;
    if (steps[b]!=-1)
    cout <<"steps from " << a << " to " << b << " is " << steps[b] << endl;
    else
        cout << "No connection" << endl;
}


int main()
{
    memset (adj,false,sizeof(adj));
    int points[] = {1,11,1,2,1,3,1,11,2,3,2,1,2,4,3,11,3,5,3,1,3,2,3,4,4,3,4,2,5,3,5,6,5,7,5,8,6,5,6,11,6,10,7,5,7,10,8,9,8,5,9,8,9,10,10,6,10,7,11,3,11,1,11,6};
    //cout << sizeof(points) << endl;
    for (int i= 0; i < sizeof(points)/sizeof(int); i+=2)
    {
        //cout << points[i] << " " <<  points[i+1] << endl;
        c(points[i],points[i+1]);
    }
   cout << sizeof(adj)/sizeof(bool)<< endl;
    int x, y;
    while(cin >> x, x!=0){
    cin >> y;

    bfs(x,y);
    }
}
