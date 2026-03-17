// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head=NULL, *temp=NULL, *newNode;
    int value;

    printf("Enter %d elements:\n", n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);

        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }

    return head;
}

int length(struct Node *head)
{
    int count=0;

    while(head!=NULL)
    {
        count++;
        head=head->next;
    }

    return count;
}

struct Node* rotateRight(struct Node *head,int k)
{
    if(head==NULL)
        return head;

    int n=length(head);

    k=k%n;

    if(k==0)
        return head;

    struct Node *temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=head;

    int steps=n-k;

    struct Node *newTail=head;

    for(int i=1;i<steps;i++)
        newTail=newTail->next;

    struct Node *newHead=newTail->next;

    newTail->next=NULL;

    return newHead;
}

void display(struct Node *head)
{
    printf("Linked List after rotation:\n");

    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main()
{
    int n,k;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    struct Node *head=createList(n);

    printf("Enter value of k (rotation): ");
    scanf("%d",&k);

    head=rotateRight(head,k);

    display(head);

    return 0;
}