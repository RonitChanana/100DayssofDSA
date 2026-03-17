// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

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

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

struct Node* deleteKey(struct Node *head, int key)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    if(temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return head;

    prev->next = temp->next;
    free(temp);

    return head;
}

void printList(struct Node *head)
{
    printf("Linked List after deletion:\n");

    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = createList(n);

    printf("Enter element to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}