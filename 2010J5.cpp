#include <iostream>
#include <queue>

using namespace std;

int steps[8][8];

class coord {
    public:
        int x,y;
        coord(int a, int b) {x=a;y=b;}
        int step() {return steps[x][y];}
        void setstep(int v) {steps[x][y]=v;}
        bool check(int a,int b) {return (x+a>=0&&x+a<8&&b+y>=0&&y+b<8);}
        coord getnext(int a,int b) {return coord(x+a,y+b);}
        inline bool operator==(coord b) {return (x==b.x&&y==b.y);}
};

int main() {
    int sx,sy;
    cin >> sx >> sy;
    sx-=1;
    sy-=1;
    coord start(sx,sy);
    queue<coord> coords;
    coords.push(start);
    start.setstep(1);
    cin >> sx >> sy;
    sx-=1;
    sy-=1;
    coord End(sx,sy);
    while (!coords.empty()) {
        coord c = coords.front();coords.pop();
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (i!=j&&i+j!=0&&i&&j&&c.check(i,j)) {
                    coord n = c.getnext(i,j);
                    if (n.step()==0) {
                        n.setstep(c.step()+1);
                        if (n==End) break;
                        coords.push(n);
                    }
                }
            }
        }
    }

    cout << steps[sx][sy]-1 << endl;
}
