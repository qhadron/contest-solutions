#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define scan(x) while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0')
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

typedef unsigned long long ull;

struct Query {
    int order;
    int a, b,q;
    ull res;
    friend bool operator<(const Query& one, const Query& other) {
        return one.q>other.q;
    }
} qu[MAX];

struct Num {
    int pos, val;
    friend  bool operator<(const Num& a, const Num& b ) {
        return a.val > b.val;
    }
} nums[MAX];

bool comp(const Query& a,const  Query& b) {
    return a.order < b.order;
}

int N,Q;
ull tree[MAX];

inline int lowbit(int x) {
    return x&-x;
}

ull sumTo(int x) {
	ull sum = 0;
    for (int i = x; i > 0; i-= lowbit(i))
        sum+=tree[i];
	return sum;
}

void update(int x, int val){
	for (int i = x; i<=N; i+=lowbit(i))
        tree[i] += val;
}

ull sumFT(int st,int ed) {
	return sumTo(ed) - sumTo(st-1);
}

int main() {
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif // _DEBUG
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        nums[i].pos = i;
        cin >> nums[i].val;
    }
    cin >> Q;
    for (int i = 1; i <= Q; ++i) {
        cin >> qu[i].a >> qu[i].b >> qu[i].q;
        qu[i].order = i;
    }
    sort(nums+1,nums+N+1);
    sort(qu+1,qu+Q+1);
    for (int i = 1, cnt = 1; i <= Q; ++i) {
        dprintfn("Processing query with req %d",qu[i].q);
        while (cnt<=N&&nums[cnt].val >= qu[i].q) {
            update(nums[cnt].pos,nums[cnt].val);
            dprintfn("Inserted %d at %d",nums[cnt].val,nums[cnt].pos);
            cnt+=1;
        }
        qu[i].res=sumFT(qu[i].a+1,qu[i].b+1);
    }
    sort(qu+1,qu+Q+1,comp);
    for (int i = 1; i <= Q; ++i) {
        dprintfn("%d to %d with %d is %d",qu[i].a,qu[i].b,qu[i].q, qu[i].res);
        cout << qu[i].res << endl;
    }
}
