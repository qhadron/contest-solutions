#include <iostream>
#include <cstdio>
using namespace std;

#define int unsigned int

//holds the corrosponding power of 5
const int f[]= {0,1,5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,1220703125};

bool dfs (int m, int x, int y)
{
    if (x<f[m]||x>=4*f[m]) return false; //false if on left or right side
    else if (y<f[m]) return true;        //true if y < 1/5 of grid size
    if (m==1&&x==2&&y==1) return true;   //hard code the base case for m = 1

    if (x>=2*f[m]&&x<3*f[m]&&y>=f[m]&&y<2*f[m])//true if in middle column
        return true;
    //check to see if inside the fractal
    if (x>=f[m]&&x<2*f[m]&&y>=f[m]&&y<2*f[m]) //left
        return dfs(m-1,x-f[m],y-f[m]);
    if (x>=3*f[m]&&x<4*f[m]&&y>=f[m]&&y<2*f[m]) // right
        return dfs(m-1,x-3*f[m],y-f[m]);
    if (x>=2*f[m]&&x<3*f[m]&&y>=2*f[m]&&y<3*f[m]) //middle
        return dfs(m-1,x-2*f[m],y-2*f[m]);
    return false;
}
int n,m,x,y;
#undef int
#ifdef DEBUG
void print(int mag) {
    for (int y = f[mag+1]-1; y >=0; y--)
    {
        for (int x = 0; x < f[mag+1]; x++)
        {
            cout << ((dfs(mag,x,y)?"*":"-"));
        }
        cout << endl;
    }
}
#endif // DEBUG

int main()
{
    cin >> n;
    while (n--) {
        cin >> m >> x >> y;
        cout << ((dfs(m,x,y)?"crystal":"empty")) << endl;
    }
}


