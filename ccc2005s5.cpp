#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define MAX 100001

/*
More precisely, r is one greater than the number of games whose score exceeds that of the game just ended.

Algorithm:
	1. remap a score to the position in the sorted list of scores after the final game has been played.
		so that all "scores" will be in [1,T]
	
	2. Go through the new "scores" turn by turn
		rank = 1 + sum (number of ranks that are lower than current rank)
			 = 1 + sum (number of games with rank 0, number of games with rank 1 ... )
			 = 1 + freqTo(total rank)
		update the scores by adding 1 to the number of scores with total rank i
*/

int T;
int tree[MAX];				//stores sum frequency (number of people who got rank[i])
int freq[MAX];				//freq[i] is which total rank turn i got
pair<int,int> score[MAX];	//pair<score,turn>
double totalRanks;

int freqTo(int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		//printf("tree[%d] = %d\n", i, tree[i]);
		i -= (i & -i);
	}
	return sum;
}

void update(int i, int val){
	while( i <= T ) {
		tree[i] += val;
		i += (i & -i);
	}
}

int main() {
	cin >> T;
	for (int i = 1, temp; i <= T; ++i) {
		cin >> temp;
		score[i] = make_pair(temp,i);
	}
	sort(score+1,score+T+1, greater<pair<int,int> >());
	for (int i = 1; i <= T; ++i) {
		freq[score[i].second] = i;
	}
	
	
	for (int i = 1; i <= T; ++i) {
		int rank = 1 + freqTo(freq[i]);
		totalRanks += rank;
		update(freq[i], 1);
	}
	printf("%.2f",totalRanks/T);
}