// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, i;

    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &newNode->coef, &newNode->exp);

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

    printf("\nPolynomial is:\n");

    temp = head;

    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coef);

        else if(temp->exp == 1)
            printf("%dx", temp->coef);

        else
            printf("%dx^%d", temp->coef, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    printf("\n");

    return 0;
}