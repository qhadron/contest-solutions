#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
    double x, y;
    void set(int u, int v) {
        x=u;
        y=v;
    }
};

double cross(point a,point b, point c)
{
    return (a.x-c.x) * (b.y-c.y) - (b.x-c.x) * (a.y - c.y);
}

bool intersect(point a1, point a2, point b1, point b2)
{
    return (min(a1.x, a2.x) <= max(b1.x, b2.x) &&
            min(a1.y, a2.y) <= max(b1.y, b2.y) &&
            min(b1.x, b2.x) <= max(a1.x, a2.x) &&
            min(b1.y, b2.y) <= max(a1.y, a2.y) &&       //check rectangle
            cross(a1,a2,b1) * cross(a1,a2,b2) <= 0 &&   //check if points on same side
            cross(b1,b2,a1) * cross(b1,b2,a2) <= 0);
}

int N,K;
int cnt;
point points[1000];
int main()
{
    int x, y;
    cin >> x >> y;
    point a1 {x,y};
    cin >> x >> y;
    point a2{x,y};
    cin >> K;
    for (int n = 0; n < K; n++)
    {
        cin >> N;
        for (int i =0; i < N; i++)
        {
            cin >> x >> y;
            points[i].set(x,y);
        }
        for (int i = 0; i < N; i++)
        {
            if (intersect(points[i],points[(i+1)%N],a1,a2))
            {
                c
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}
/*
0 0 3 3
1
4 1 2 2 2 2 1 1 1
*/
