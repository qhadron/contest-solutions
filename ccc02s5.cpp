//http://wcipeg.com/problems/desc/ccc02s5
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#ifdef _DEBUG
#define printfn(...) printf(__VA_ARGS__); putchar(10);
#else
#define printfn(...)
#endif

#define MAX 1001
#define INF 1000000

bool hit[MAX];

int N, M, p, q;
double vx, vy;
int cnt, sol;
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG
    cin >> N >> M;
    cin >> p >> q;

    vx = (double)(N - p) / q * M;
    vy = (double)q / (N - p) * N;

    double curx = p, prex = -1;
    double cury = q, prey = -1;

    bool isRight = true;

    while(cnt < INF) {
        ++cnt;
        if(isRight) {
            printfn("hit at sid %.2f", cury);
            if(cury < 5 || (M - cury) < 5) {
                sol = cnt;
                printfn("Hit from sid");
                break;
            }
            cury += vy;
            while(cury > M) {
                cury -= M;
                isRight = false;
            }
            if (!isRight)
                continue;

        } else {

            curx += vx;
            printfn("hit at top %.2f", curx);
            while(curx > N) {
                isRight = true;
                curx -= N;
            }
            if (isRight)
                continue;
            if(curx < 5 || (N - curx) < 5) {
                sol = cnt;
                printfn("Hit from top");
                break;
            }
        }
    }
    if (sol)
        --sol;
    cout << sol << endl;
}
