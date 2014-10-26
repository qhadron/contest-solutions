//http://wcipeg.com/problems/desc/acmtryouts1a
#include <cstdio>
#include <cstring>

using namespace std;

char command[50];
int N;
int main() {
    scanf("%d",&N);
    getchar();
    while (N--) {
        gets(command);
        if (strlen(command)<4)
            puts("Foxen");
        else if (!strcmp("Foxen",command))
            break;
        else if (command[0] == 'R')
            puts("Paper");
        else if (command[0] == 'P')
            puts("Scissors");
        else
            puts("Rock");
    }
}
