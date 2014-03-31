#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define MAX 1000
#define VT vector<pair<int,int> >

int data[MAX],N,sum;

vector<pair<int,int> >getmin(int start)
{
    int m = 2147483647;
    vector<pair<int,int> > v;
    for (int i = start+1, n = 0; i<2*N && n < 5; n++)
    {
        if (data[i]<m)
        {
            m = data[i];
        }
        i += 2;
    }
    if (m == 2147483647) return v;
    int cs = 0;
    for (int i = start; i < start+10; i++)
    {
        cs+=data[i];
        if (data[i]==m && (i%2 == 1))
            v.push_back(make_pair(cs,i));
    }
    return v;
}

int dfs(int pos, int cs)
{
    VT v = getmin(pos);
    int r = cs;
    cout << "At " << pos << "\tscore: " << cs << endl;
    if ((2*N-pos) < 10)
    {
        for (int i = pos; i < 2*N; i++)
            r += data[i];
    }
    else
    {
        for (int i = 0, t = 0; i < v.size(); i++)
        {
            t = dfs(v[i].second+1,cs+v[i].first-1-data[v[i].second]);
            r = (t > r)? t : r;
        }
    }
    cout << "Exit " << pos << " score: " << r << endl;
    return r;
}

int Dfs(int pos, int cs, int run) {
    if (pos >= 2*N) return cs;
    if (run == 9) return Dfs(pos + 1, cs - 1, 0);
    if (pos&1) {
        return max(Dfs(pos+1,cs-1,0),Dfs(pos+1,cs+data[pos],run+1));
    } else {
        return max(Dfs(pos+2,cs-1,0), Dfs(pos+1,cs+data[pos],run+1));
    }
}

char _;
void inline scan(int& x) {
    while ((x=getchar())<'0');
    for (x-='0'; (_=getchar()>'0'); x = (x<<1) + (x<<3) + _-'0');
}

int main(int argc, char* argv[])
{
    freopen("0.input.txt","r",stdin);
    scan(N);
    for (int i = 0; i < 2*N; i++)
    {
        scan(data[i]);
    }
    /*
    for (int i = 0; i < N; ) {
        pair<int,int> p = getmin(i);
        if (p.first == 2147483647){
            while (i < N)
                sum += data[i];
            break;
        }   //no min
        cout << "broken at:" << p.second << endl;
        for (int j = i; j < p.second; j++)
            sum+=data[j];
        sum-=1;
        i = p.second+1;
    }*/
    cout << Dfs(0,0,0) << endl;
}
/*
6
8 3
4 5
3 1
2 2
6 7
2 3
*/
/*
10
7 1
4 1
3 8
4 6
2 2
4 3
4 5
10 6
8 6
7 2
*/
