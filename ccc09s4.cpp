#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 5000
#define min(y,x) ((x)<(y))?(x):(y)
#define INF 999999

int cost[MAX+1],m=INF,C[MAX+1][MAX+1],P[MAX+1],S[MAX+1],N,T,x,y,K,z,DEST,mi,cnt;
bool visited[MAX+1];

int search() {
	int smallest, cur;
	while (cnt<N) { //while not done
		smallest = INF;
		cur = 1;
		//find next city
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && S[i]<smallest)
				smallest = S[i], cur = i;
		}
		visited[cur] = true;
		cnt++;
		for (int i = 1; i <= N; i++) {
			if (C[cur][i] && !visited[i])
				if (S[i] > (S[cur] + C[cur][i]))
					S[i] = S[cur] + C[cur][i];
		}
	}
	for (int i = 1; i <= N; i++) {
		cost[i] = P[i] + S[i];
		if (m>cost[i]) {
			m = cost[i];
			mi = i;
		}
	}
	return m;
}

string s;

template <typename T>
inline void read(T& a) {
	while ((a = getchar() - '0') < 0); //skip non int values
	for (char c; (c = getchar() - '0') >= 0;) //read until space
		a = (a << 3) + (a << 1) + c;
}

int main() {
#ifdef PROFILE
	freopen("s4.5.in", "r", stdin);
#endif
	cin >> N >> T;
    for (int i = 0 ; i <= N; i++) {
        S[i]=INF;
        P[i]=INF;
    }
	cin.ignore();
	int pos;
    for ( int i = 0,temp; i < T; i++) {
		x = y = z = 0;
		read(x);
		read(y);
		read(z);
        C[x][y]=C[y][x]=z;
    }
	cin >> K;
	cin.ignore();
    for ( int i = 0; i < K; i++) {
		x = y = 0;
		read(x);
		read(y);
        P[x]=y;
    }
    cin >> DEST;
    //Dijkstra's Algorithm
    S[DEST]=0;
    
    cout << search() <<endl;
}

/*
3
3
1 2 4
2 3 2
1 3 3
3
1 14
2 8
3 3
1
*/
