#include <iostream>

//#define DEBUG

#ifdef DEBUG
#include <bitset>
#endif // DEBUG
using namespace std;

#define MAX 33445533 //2^25
#ifdef DEBUG
#define p(x) for (int i = n; i > 0;) cout << (((x)&(1<<--i))?1:0); cout << endl;
#endif // DEBUG

int n,l[MAX],steps[MAX],f,e,x,c,temp,found;

void flip(int& l, int pos)
{
    if (l==0) return;
    int start,end;
    for (start=pos; start>=0;)if (!(l&(1<<--start))) break;
    for (end=pos; end<n;) if (!(l&(1<<++end))) break;
    start++;
    end--;
#ifdef DEBUG1
    cout << bitset<8>(l) << endl << bitset<8> (((1<<(end-start+1))-1)<<start) << endl;
#endif // DEBUG
    if (end-start+1>3)    //4 or more consequtive lights
    {
        l^=(((1<<(end-start+1))-1)<<start); //use a bitmask
    }
}

int main ()
{
    cin >> n;
	for (int i = 0, a; i < n; i++)
		(cin >> a), x = (x << 1) | a;// (a << (n - i - 1));
    steps[x]=0;
    c=1;
    l[(f=e=0)]=x;
    while (c&&!found)
    {
        c--;
        x=l[f++];
        if (x==0) break;
        #ifdef DEBUG
        cout << "x:";p(x)
        #endif // DEBUG
        for (int i = 0; i < n; i++)
        {
            if (!(x&(1<<i)))
            {
                temp=x|(1<<i);
                flip(temp,i);
                #ifdef DEBUG
                cout<<"t:"<<bitset<7>(temp) << endl;
                #endif
                if (!steps[temp])
                {
                    steps[temp]+=steps[x]+1;
                    if (temp==0) { found=1;break;}
                    l[++c,++e]=temp;
                }
            }
        }
		if (found) break;
    }
    cout << steps[0] << endl;
}
