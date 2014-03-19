#include <cstdio>
#include <utility>

using namespace std;

int main() {

}

/**
longest increasing subsequence

dp with sort:
1. get all dist, sort, and store with info about [start][dest]
for l=0; l < ind; l=r+1 //move past the found positions
{
    while (next dist) == dist(l)
        r++
    store the points to get from curpoint to nextpoint
    store the curnum+1 to dp[nextpoint]
}
*/
