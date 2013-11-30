/*
    input: n--the number of trains
           m--the number of rails
           (next n numbers) -- the order of carts
*/

#include <iostream>
#include <queue>
#include <string>
#ifdef DEBUG
#define p(x) cout << x << endl;
#else
#define p(x)
#endif
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    queue <int> q[m];
    queue <int> rec[m];
    int curbuff = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < q[curbuff].front()&&curbuff < m-1)
            curbuff++;
        q[curbuff].push(temp);
        p("line 20")
    }
    for (int curnum = 1; curnum <= n; curnum++)
    {
        bool found = false;
        int curcheck = 0;
        while (!found)
        {
            p("line 26")
            for (int i = 0; i < m; i++)
            {
                if (q[i].front()==curnum)
                {
                    rec[i].push(curnum);
                    q[i].pop();
                    found =  true;
                    break;
                }
            }
            if (!q[curcheck].empty())
            {
                q[(curcheck+1)%(m-1)].push(q[curcheck].front());
                q[curcheck].pop();
            }
            else if (curcheck < m)
                curcheck ++;
            else
            {
                cout << "not enough rails" << endl;
                return 0;
            }

        }
    }
    for (int i = 0; i < m; i++)
    {
        while(!rec[i].empty())
        {
            cout << rec[i].front();
            rec[i].pop();
        }
        cout << endl;
    }

}

int main2()
{
    int n,m;
    cin >> n >> m;
    queue<int> buffer[m];
    string s[m];
    for (int i = 0, temp = 0; i < n; i++)
    {
        cin >> temp;
        buffer[3].push(temp);
    }

    bool done = false;
    while(!done)
    {
        bool atfront = false;
        for (int num = 1; num <= n; num++)
        {
            int i;
            for (i =0; i < m; i++)
            {
                if (!buffer[i].empty())
                    if (buffer[i].front()==num)
                    {
                        atfront = true;
                        break;
                    }
            }
            if (atfront)
            {
//                s[i] += to_string(buffer[i].front());
                buffer[i].pop();
            }
            else
            {
                for (int j = 0; j < m-1; j++)
                {
                    if (false)
                        buffer[j].push(buffer[m].front());


                }
            }
        }

    }
}
