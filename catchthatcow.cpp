#include<iostream>
#include <queue>
#include <cstring>
using namespace std;

int steps [(int)1e5];

int main() {
    memset(steps,-1,sizeof(steps)); // set all the values in steps to -1 ( ie unvisited )
    int x, y;						//start, end respectively
    queue<int> qu;					//the queue, which stores the coords to visit
    cin >> x >> y;
    qu.push(x);						//push starting point to queue
    steps[x] = 0;					//set the number of steps at the starting point to 0
	
	//continue until everything that can be visited is visited
    while (!qu.empty()) {
	
        int c = qu.front();qu.pop(); //current pos = first element in queue
		
        for (int i = -1; i < 2; i++) { // lazy for loop, basically i is the change in coords, and it goes from -1 to 1,
								       // but since 0 is already visited, it doesn't matter
            if (steps[c+i]==-1){		//check if the coord is unvisited ( unvisited things have a value of -1)
                qu.push(c+i);			//add the new coordinate to the queue
                steps[c+i]=steps[c]+1;	// the number of steps it takes to get to the new coordinate is the current number of steps + 1
            }
        }
        if (steps[c*2]==-1) {			// checks the teleporting case
            qu.push(c*2);
            steps[c*2] = steps[c]+1;
        }
		
        if (c == y) 					//stop if we are at the cow
            break;
    }

    cout << steps[y] << endl;

}
