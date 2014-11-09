//http://wcipeg.com/problems/desc/skyscrapers

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int wsky[100000],ssky[100000];
int M,N,C,MC;
int Min,Max;
bool shas[20000];

int main() {
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif // _DEBUG

    cin >> M >> N >> C >> MC;
    for (int i = 0; i < M; ++i)
        cin >> wsky[i];
    for (int i = 0; i < N; ++i) {
        cin >> ssky[i];
        shas[ssky[i]] = true;
    }

    sort(wsky,wsky+M);
    sort(ssky,ssky+N);

    //check impossible
    if (wsky[M-1] != ssky[N-1]) {
        cout << "Impossible" << endl;
        return 0;
    }
    //calculate min
    for (int i = 0; i < N; ++i) {
        Min += ssky[i];
    }
    for (int i = 0; i < M; ++i)
        if (!shas[wsky[i]])
            Min += wsky[i];

    cout << "Minimum: " << Min * C;

    //calculate max
    for (int i = 0,j =0; i < N; ++i) {
        for (j = 0; ssky[i] > wsky[j] && j < M; ++j) {
            Max += wsky[j];
        }
        Max+= (M - j) * ssky[i];
    }
    cout << ", maximum: " << Max * MC << endl;
}
