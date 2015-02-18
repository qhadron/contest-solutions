//http://wcipeg.com/problems/desc/noi04p1

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include  <set>
using namespace std;

#define scan(x) do {while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0');} while(0)
char _;
#ifdef _DEBUG
#define dvar(x) cout << #x << ":" << x << endl
#define dprintf(...) printf(__VA_ARGS__)
#define dprintfn(...) printf(__VA_ARGS__),putchar('\n')
#else
#define dvar(...)
#define dprintf(...)
#define dprintfn(...)
#endif

#define MAX 100001

#define loc(x) ((x)-change+1)

int N, M, change;
itn BIT[MAX];

inline int lowbit(int x) {
    return x & (-x);
}

void update(int x, int val)[
for(int i = x; i < MAX; i += lowbit(i) {
    BIT[i] += val;
}
}

int sumTo(int x) {
    int sum;
    for(int i = x; i > 0; i -= lowbit(i)) {
        sum += BIT[i];
    }
    return sum;
}

int find (int x) {
    int ans = 0, cnt = 0;
    for (int i = 18; i >= 0; --i) {
		ans += (1<<i);
		if (ans > MAX || )
    }
}


int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG
    scanf("%d%d", &N, &M);
    char c;
    int x, left, people = 0;
    for(int _cur = 0; _cur < N; ++cur) {
        scanf("%c%d", &c, &x);
        if(c == 'I') {
            if(x >= M) {
                update(x + 1 - change, 1);
                people += 1;
            }
        } else if(c == 'A') {
            change += x;
        } else if(c == 'S') {
            change -= x;
            int temp += sumTo(loc(M-1));
            people -= temp;
            left += temp;
            for (int i = 1; i <= loc(M-1);i++)
				if (BIT[i])
					update(i,-BIT[i]);

            fill(BIT, BIT + M + change - 1, 0);
        } else if(c == 'F') {
            if(x > people) {
                puts("-1");
                continue;
            }
            int l = 1, r = MAX, m;
            cout << find (N - x + 1) + change << endl;
//            while(l < r) {
//                m = (l + r) >> 1;
//                int res = sumTo(m);
//                if(res < x) {
//                    l = m + 1;
//                } else if(res > x) {
//                    r = m - 1;
//                }
//                else {
//                    break;
//                }
//            }
        }
    }
}
