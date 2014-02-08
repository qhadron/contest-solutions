#define BFS

#include <iostream>

#ifdef DFS
#include <stack>
#else
#include <queue>
#endif // STACK

#include <string>
#include <cstdio>
#include <set>
using namespace std;

#define MAX 8
#define NDEBUG
#ifndef NDEBUG
//#define DEBUG2 //used to debug coinstack
#define DEBUG1 // used to debug board (redirects output to log.txt)
#endif
#define abs(x) (((x)>0)?(x):(-(x)))
int N;
class COINSTACK
{
    int toploc;
    int coins[MAX];

private:

    COINSTACK(int top,int * vals)
    {
        toploc=top;
        for (int i = 0; i < MAX; i++) coins[i]=vals[i];
    }

public:

    COINSTACK()
    {
        for (int i = 0; i < MAX; i++) coins[i]=MAX+1;
        toploc=MAX-1;
    }

    COINSTACK(int n)
    {
        for (int i = 0; i < MAX; i++) coins[i]=MAX+1;
        coins[MAX-1]=n;
        toploc=MAX-2;
    }

    int top()
    {
        if(this->empty()) return MAX+1;
        return coins[toploc+1];
    }
    bool empty()
    {
        return (toploc+1>=MAX);
    }
    int pop()
    {
#ifdef DEBUG2
        if (toploc+1<MAX)
        {
            cout << "poped " << coins[++toploc] << endl;
            this -> print();
            return coins[toploc];
        }
        else
        {
            cout << "empty" << endl;
            return false;
        }
#else
        if (toploc+1<MAX)
        {
            return coins[++toploc];

        }
        else
        {
            return 0;
        }
#endif // DEBUG2
    }
    bool check(int n)
    {
        return (n<this->top());
    }
    bool push(int x)
    {
#ifdef DEBUG2
        cout << "pushing " << x ;
        if (x < this->top())
        {
            coins[toploc--]=x;
            cout << " succeeded" << endl;
            this -> print();
            return true;
        }
        else
        {
            cout << " failed" << endl;
            return false;
        }
#else
        if (x < (this -> top()))
        {
            coins[toploc--]=x;
            return true;
        }
        return false;
#endif // DEBUG2
    }
#ifdef DEBUG2
    void print()
    {
        cout << "Current stack: " ;
        for (int i = toploc+1; i < MAX; i++)
        {
            cout << coins[i] << ((i==MAX-1)?"\n":" ");
        }
    } // DEBUG2

#else
#ifdef DEBUG1
    void print()
    {
        if (this->empty()) cout << "empty\n";
        else
            for (int i = toploc+1; i < MAX; i++)
            {
                cout << coins[i] << ((i==MAX-1)?"\n":" ");
            }
    }
#endif // DEBUG1
#endif // DEBUG2

    COINSTACK clone()
    {
        return COINSTACK(toploc,coins);
    }

    string getConfig()
    {
        string s="";
        for (int i = toploc+1; i < MAX; i++)
        {
            s+=(char)(coins[i]+'0');
        }
        return s;
    }
};

class BOARD
{
public:
#ifdef DEBUG1
    string name;
#endif // DEBUG2

    COINSTACK s[MAX];
    int moves;
#ifdef DEBUG1
    BOARD(string Name)
    {
        moves=0;
        this->name=Name;
        for(int i =0; i < N; i++)s[i]=COINSTACK();
    };
    BOARD(COINSTACK c[],int m,string Name)
    {
        for (int i =0; i < N; i++)
        {
            s[i]=c[i].clone();
            moves=m;
        }
        this->name=Name;
    }
#else
    BOARD()
    {
        moves=0;
    };
    BOARD(COINSTACK c[],int m)
    {
        for (int i =0; i < N; i++)
        {
            s[i]=c[i].clone();
            moves=m;
        }
    }
    BOARD(string s)
    {
        moves=0;
    }
#endif
    bool check()
    {
        for (int i=0; i < N; i++)
        {
            if (s[i].top()!=(i+1))
                return false;
        }
#ifdef DEBUG2
        cout << name <<  " succeeded: ";
        this -> print();
#endif // DEBUGs
        return true;
    }
#ifdef DEBUG1
    BOARD clone(int x)
    {
        return BOARD(s,moves,name+'-'+(char)(x+'0'));//+name+(char)(name[name.size()-1]+1));
    }

    BOARD clone (int x, int y)
    {
        return BOARD(s,moves,name+'|'+(char)(x+'0')+"->"+(char)(y+'0'));
    }

    void print1()
    {
        cout << ((name=="")?"Initial":(name+"|")) << " " << (this->getConfig()) <<endl;
        for (int i = 0; i < N ; i++)
        {
            cout << "stack " << (i+1) << ": ";
            s[i].print();
        }
        cout << "\n";
    }
    void print()
    {
        cout << ((name=="")?"Initial":(name+"|")) << "\t[" << (this->getConfig()) << "] : " << moves <<endl;
        for (int i = 0; i < N ; i++)
        {
            cout << ((s[i].empty())?"-":s[i].getConfig()) << "\t";
        }
        cout << "\n\n";
    }
#else
    BOARD clone()
    {
        return BOARD(s,moves);
    }
#endif
    string getConfig()
    {
        string str="";
        for (int i = 0; i < N; i++)
        {
            str+=s[i].getConfig()+"|";
        }
        return str;
    }
};


int main ()
{
#ifdef DEBUG1
    freopen("0.log.txt","w",stdout);
#endif // DEBUG1

#ifdef PROFILE
	freopen("0.input.txt", "r", stdin);
#endif
    while (cin >> N)
    {
        if (N==0)
            return 0;
#ifdef DFS
        stack<BOARD> qu;
#else
        queue<BOARD> qu;
#endif // DFS
#ifdef  DEBUG1
        int steps=0;
#endif // DEBUG1
        set<string> configs;
        int temp;
        BOARD initial("");
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            initial.s[i]=(COINSTACK(temp));
        }
        configs.insert(initial.getConfig());
        qu.push(initial);
        BOARD board("mystery"),t("temp");
        string str;
        if (!initial.check())
        {
            while (!qu.empty())
            {
#ifdef DFS
                board = qu.top();
                qu.pop();
#else
                board = qu.front();
                qu.pop();
#endif // DFS
                if (board.check())
                    break;
#ifdef DEBUG1
                board.print();
                int cnt = 0;
                steps++;
#endif // DEBUG1
                //i is the stack to push from, j is the stack to push onto
                for (int i = 0; i < N ; i++)
                {
                    if (board.s[i].empty()) continue;
                    for (int j = 0; j < N; j++)
                    {
                        if(i!=j&&((abs(i-j))==1))
                            if (board.s[j].check(board.s[i].top()))
                            {
#ifdef DEBUG1

                                t=(board.clone(i+1,j+1));
#else
                                t=(board.clone());
#endif
                                t.moves++;
                                t.s[j].push(t.s[i].pop());
                                str=t.getConfig();
                                if (configs.count(str)==0)
                                {
                                    configs.insert(str);
#ifdef DEBUG1
                                    //cout << "pushing " << t.name << " from " << board.name << " onto queue" << endl;
                                    //cout << "pushing [" << i+1 << "] to [" << j+1 << "]" << endl;
                                    //t.print();
                                    cnt++;
#endif // DEBUG1
                                    qu.push(t);
                                }
                            }
                    }
                }
#ifdef DEBUG1
                if (cnt==0) cout << "Backtracking..." << endl;
#endif // DEBUG1
            }
#ifdef DEBUG1
            cout << "-----------------------------------" << endl;
            cout << board.name << " succeeded in " << steps << " steps. \n moves: ";
#endif // DEBUG1
            if (board.check())
                cout << board.moves << endl;
            else
                cout << "IMMPOSSIBLE" << endl;
        }
        else
        {
            cout << 0 << endl;
        }
#ifdef DEBUG1
        cout << endl;
#endif // DEBUG1
    }
}
/*
3 1 2 3
3 1 3 2
3 2 1 3
3 2 3 1
3 3 1 2
3 3 2 1
0

4 4 3 1 2
4 4 3 2 1
4 4 1 2 3
0

*/
