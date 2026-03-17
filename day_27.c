// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
// Problem: Find Intersection Point of Two Linked Lists
// Implement using linked list with dynamic memory allocation

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

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data =value;
        newNode->next =NULL;

        if(head == NULL)
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
    int count = 0;

    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

void findIntersection(struct Node *head1, struct Node *head2)
{
    int len1=length(head1);
    int len2=length(head2);

    int diff=abs(len1-len2);

    struct Node *temp1=head1;
    struct Node *temp2=head2;

    if(len1>len2)
    {
        for(int i=0; i<diff; i++)
            temp1 = temp1->next;
    }
    else
    {
        for(int i=0; i<diff; i++)
            temp2=temp2->next;
    }

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data == temp2->data)
        {
            printf("Intersection Node Value: %d\n", temp1->data);
            return;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("No Intersection\n");
}

int main()
{
    int n, m;

    printf("Enter number of nodes in first linked list: ");
    scanf("%d", &n);
    struct Node *head1 = createList(n);

    printf("Enter number of nodes in second linked list: ");
    scanf("%d", &m);
    struct Node *head2 = createList(m);

    printf("Finding intersection...\n");

    findIntersection(head1, head2);

    return 0;
}