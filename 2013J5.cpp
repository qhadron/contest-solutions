#include <iostream>
#include <vector>

using namespace std;

struct GAME {
    bool games[4][4];
    int points[4];
};
GAME game;
int t,g,a,b,c,d,played[4];

bool isMax(int p[]) {
    for (int i = 0; i < 4; i++) {
        if (i != t)
            if (p[t]<=p[i])
                return false;
    }
    return true;
}

int r(GAME G) {
    int total=0;
    for (int i = 0 ; i < 3; i++) {
        for (int j = i+1; j < 4; j++) {
            if (!G.games[i][j]){
                G.games[i][j]=true;

                G.points[i]+=3;
                total+=r(G);
                G.points[i]-=3;

                G.points[j]+=3;
                total+=r(G);
                G.points[j]-=3;

                G.points[i]+=1;
                G.points[j]+=1;
                total+=r(G);
                return total;
            }
        }
    }
    return isMax(G.points);
}

int main () {
    cin >> t >> g;
    t--;
    for (int i = g; i--;) {
        cin >> a >> b >> c >> d;
        played[--a]++;
        played[--b]++;
        game.games[a][b]=game.games[b][a]=true;
        if (c!=d)
            game.points[(c>d)?a:b]+=3;
        else {
            game.points[a]++;
            game.points[b]++;
        }
    }
    #ifdef DEBUG
    for (int i = 0; i<4;i++){
        cout << game.points[i] << " ";
    }

    cout << endl;
    #endif
    cout << r(game) << endl;
}
