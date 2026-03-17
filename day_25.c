// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;
    int value, i;

    printf("Enter %d elements:\n", n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&value);

        newNode =(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL)        
        {
            head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

int countOccurrence(struct Node *head, int key)
{
    int count = 0;

    while(head != NULL)
    {
        if(head->data == key)
        {
            count++;
        }
        head = head->next;
    }
    return count;
}

int main()
{
    int n, key, result;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = createList(n);

    printf("Enter element to be counted: ");
    scanf("%d",&key);

    result=countOccurrence(head, key);

    printf("Number of occurrences of %d is: %d\n", key, result);

    return 0;
}