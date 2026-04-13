// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct Node *temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main()
{
    int N, x;
    char op[20];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            dequeue();
        }
    }

    return 0;
}