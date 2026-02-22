// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j;
    printf("enter the string ");
    scanf("%s", str);

    i = 0;
    j = strlen(str) - 1;

    while(i < j)
    {
        if(str[i] != str[j])
        {
            printf("NO");
            return 0;
        }
        i++;
        j--;
    }

    printf("YES");
    return 0;
}