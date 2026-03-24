// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20
#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x)
{
    if(size == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    pq[size] = x;
    size++;
}

void delete()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    printf("%d\n", pq[minIndex]);

    for(int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}


void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = pq[0];

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < min)
            min = pq[i];
    }

    printf("%d\n", min);
}

int main()
{
    int N;
    char op[10];
    int x;

    printf("Enter number of operations: ");
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(op[0] == 'i') 
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd') 
        {
            delete();
        }
        else if(op[0] == 'p') 
        {
            peek();
        }
    }

    return 0;
}