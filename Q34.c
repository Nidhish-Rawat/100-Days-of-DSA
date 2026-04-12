#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i = 0;
    int op1, op2, result;

    printf("enter postfix expression: ");
    scanf("%s", postfix);

    while(postfix[i] != '\0') {
        if(isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();

            if(postfix[i] == '+') result = op1 + op2;
            else if(postfix[i] == '-') result = op1 - op2;
            else if(postfix[i] == '*') result = op1 * op2;
            else if(postfix[i] == '/') result = op1 / op2;
            else if(postfix[i] == '^') {
                result = 1;
                for(int j = 0; j < op2; j++) result *= op1;
            }

            push(result);
        }
        i++;
    }

    printf("result: %d\n", pop());

    return 0;
}