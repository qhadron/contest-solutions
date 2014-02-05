#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t,c,e[100],cnt=0,cnt2=0;
    cin >> t >> c;
    while (c--)cin>>e[cnt++];
    sort(e,e+cnt);
    while(t&&--cnt)
        if (!(t<e[cnt2]))
            t-=e[cnt2++];
        else
            break;
    cout << cnt2 << endl;
}
