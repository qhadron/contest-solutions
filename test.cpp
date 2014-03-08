#include <cstdio>

using namespace std;

char _;

#define scan(x) while((x=getchar())<'0'); for (x-='0';(_=getchar())>='0';x=(x<<1)+(x<<3)+_-'0');

template <typename T>
void readInt(T& x) {
    while ((x=getchar())<'0');
    for (x-='0';(_=getchar())>='0';)
        x =(x<<3)+(x<<1) + _-'0';
}


int main(void){
    unsigned long long x;
    while (1) {
        scan(x);
        printf("a:%u\n",x);
        readInt(x);
        printf("b:%u\n",x);
    }

}
