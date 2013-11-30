/*
    implementation of stack
*/

#include <iostream>
using namespace std;

#define SIZE 100

int stack[SIZE], top = -1;

void push(int x) {
    stack[++top] = x;
}

bool empty() {
    return top < 0;
}

int pop() {
    return stack[top--];
}

int main() {
    for (int i = 1; i <= 10; i++)
        push(i);
    while (!empty())
        cout << pop() << " ";

}
