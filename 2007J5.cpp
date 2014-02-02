#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG1
/*
    case 1:
        1 500
        0
    out: 0

    case 2:
        970 1030
        0
    out: 1

    case 3:
        970 1040
        0
    out: 4

    case 4:
        970 1030
        1 4960
    out: 2


*/
using namespace std;
#define NUM 13
int MIN,MAX,N;
const int init[]= {0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};

vector <int> loc(init,init+sizeof(init)/sizeof(int));
int dfs(int cur)
{
#ifdef DEBUG
    cout << cur << " " ;
#endif
    if (cur>=NUM+N) return 1;
    int i = 1, cnt = 0;
    //if ()
    while (loc[cur+i]-loc[cur]<=MAX)
    {
        if (loc[cur+i]-loc[cur]>=MIN)
            cnt += dfs(cur+i);
        i+=1;
    }
    return cnt;
}

int main ()
{
    cin >> MIN >> MAX >> N;
    for (int i= 0; i < N; i++)
    {
        int a;
        cin >> a;
        loc.push_back(a);
    }
    sort(loc.begin(),loc.end());
#ifdef DEBUG
    int a = dfs(0);
    cout << "\n" << a << endl;
#else
    cout << dfs(0) << endl;
#endif // DEBUG
}
