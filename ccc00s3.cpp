#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;

#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#else
#define dvar(...)
#endif

unordered_map<string, int> URL;
string webs[101];
vector<string> links[101];

bool adj[101][101];

int N, st, ed, curpos,x;
string str, s;

void floyd() {

    for (int i = 1; i <= N; ++i)
        for (string ss : links[i])
            if (x=URL[ss])
                adj[i][x]=1;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (adj[i][j])
                for (int k = 1; k <= N; ++k)
                    if (adj[j][k])
                        adj[i][k] = true;
}

int main() {
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif // _DEBUG
    scanf("%d\n", &N);
    for(int i = 0,cnt = 0; i < N; ++i) {
        getline(cin, str); //<Webpage>
        //insert page into map
        URL[str] = ++cnt;
        webs[cnt] = str;
        while(true) {
            curpos = 0;
            getline(cin, s);
            if(s == "</HTML>") {
                break;
            }
            while((st = s.find("<A HREF=\"",curpos)) != string::npos) {
                ed = s.find("\">",st);
                links[cnt].push_back(s.substr(st+9,ed-st-9));
                printf("Link from %s to %s\n",str.c_str(),links[cnt].back().c_str());
                curpos = ed+1;
            }
        }
    }
    floyd();
    cout << endl;
    while(true) {
        getline(cin,str);
        if (str == "The End")
            break;
        getline(cin,s);
        if (adj[URL[str]][URL[s]]) {
            cout << "Can surf ";
        } else {
            cout << "Can't surf ";
        }
        cout << "from " << str << " to " << s << endl;
    }
}
