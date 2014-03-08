#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1000000

bool t[MAX+1],t1[MAX+1];

//stores who is taller than who
vector<int> taller[MAX+1];

int N,M,x,y,p,q;

#define T vector<int>

bool bfs(int start, int target) {
    queue<int> qu;
    qu.push(start);
    int cur;
    memset(t,false,sizeof(t));
    while (!qu.empty()) {
        cur=qu.front();qu.pop();
        if (cur == target)
            return true;
        for (T::iterator it = taller[cur].begin(); it != taller[cur].end(); ++it) {
            if (!t[(*it)])
                t[(*it)]=true,qu.push((*it));
        }
    }
    return false;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        taller[y].push_back(x);
    }
    cin >> p >> q;
    if (bfs(p,q))
        cout << "no" << endl;
    else if (bfs(q,p))
        cout << "yes" << endl;
    else
        cout << "unknown" << endl;
}

/*
10 3
8 4
3 8
4 2
3 2
*/

