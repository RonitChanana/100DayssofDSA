// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int main()
{
    char exp[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');   // convert char to int
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int b = pop();
            int a = pop();
            int result;

            if(exp[i] == '+')
                result = a + b;
            else if(exp[i] == '-')
                result = a - b;
            else if(exp[i] == '*')
                result = a * b;
            else if(exp[i] == '/')
                result = a / b;

            push(result);
        }

        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}