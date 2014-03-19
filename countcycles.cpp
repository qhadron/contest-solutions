#include <iostream>

using namespace std;

#define MAX 101
#define UNDIRECTED true


/* Test data
 * Answer: 9
	5 8
	1 2
	1 3
	1 4
	2 3
	2 4
	3 4
	1 5
	4 5
*/


/* Test data
 * Answer: 5
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/

bool path[MAX]; 		// included in current path
bool adj[MAX][MAX];		//adjacency matrix
bool included[MAX]; 	// used all options globally
bool exhausted[MAX]; 	//used all options locally

int cycles; 		//final result
int N; 			//number of vertices
int start; 		//starting point of dfs


/**
    Algorithm: (not optimized ( calculating max number of cycles etc )
    1. include current point in the path
    2. check available (connected and not completely exhausted)
    3. if check if in current path
        if true : check if starting point and increment the number of cycles by one iff length of path > 2
        if not  : start recursive call from vertex

        a.  after recursive call returns, the current vertex is completely explored with the current path, so mark it exhausted
        b.  if this is the starting point, then the point visited is completely explored for the current vertices and all cycles, so mark it included

    4. After everything finishes, reset local exhausted list, and remove node from path
*/

void dfs(int n) {
	path[n]=true;		//include current point in path
	//skip included points
	if (included[n]) {
		path[n]=false;
		return;
	}
	//check neighbours starting from start, as those before start will have been checked
	for (int i = start; i<=N; i++) {
		//if i is connected
		if (adj[n][i]&&i!=n) {
			if(included[i]||exhausted[i]) continue;		//skip those that are added globally or locally
			if (!path[i]) {
				dfs(i);			//dfs
				exhausted[i]=true;	//all options for branch 'i' in the current step is used,
									//but does not prevent the previous step from using it

                //when the starting point finishes exploring all paths for i, it has been globally exauhsted
                if (n==start)
                    included[i]=true;
			} else {
				if (i == start) {	//check if back to staring point
					//ignore 2 long cycles
					int cnt = 0;
					for (int j = 1; j <= N&&cnt<3; j++)
						cnt += path[j];
					if (cnt < 3) continue;
					#ifdef DEBUG
					for (int j = 1; j <= N; j++)
						cout << ((path[j])?(char)('0'+j):'\0') << " ";
					cout << "n:" << n <<  " start: " << start << endl;;
					#endif
					cycles+=1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) exhausted[i]=false; //reset the local list
	path[n]=false;	//remove node from path
}

//wrapper function
void count() {
	for (int i = 1; i <= N; i++) {
		start = i;						//set starting point
		for (int t = 1; t <= N; t++)
			included[t]=false||(t<i);	//reset vertices that are already included in every current possibility,because new vertex means new possibilities
										//however, the previous starting points must be exhausted
		dfs(i);
	}
}
/**
    Input:
    N - number of vertices
    E -number of edges
    (the following E lines:)
    x y ( x is connected to y (and vice versa, if undirected) )

*/
int main(void) {
	int x,y,e;
	cin >> N;
	cin >> e;
	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		if (UNDIRECTED) {
            adj[x][y]=adj[y][x]=true;
		} else {
            adj[x][y]=true;
		}
	}
	count();
	cout << "Number of cycles: " << cycles  << endl;
}

