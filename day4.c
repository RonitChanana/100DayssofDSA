#include <stdio.h>

int main()
{
    int n;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Two pointers
    int left = 0;
    int right = n - 1;

    printf("\nReversing process:\n");

    // Reverse using two-pointer approach
    while(left < right)
    {
        // Print swapping info
        printf("Swapping %d and %d\n", arr[left], arr[right]);

        // Swap
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move pointers
        left++;
        right--;
    }

    // Print reversed array
    printf("\nReversed array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
