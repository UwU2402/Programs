#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
bool isPalindrome(int arr[], int i, int j)
{
    while (i < j)
    {
        if (arr[i] != arr[j])
        {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}
int main()
{
    int n;
    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array's elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxLen = INT_MIN;
    int ansi = 0;
    int ansj = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (isPalindrome(arr, i, j) == true && (j - i + 1) > maxLen)
            {
                maxLen = j - i + 1;
                ansi = i;
                ansj = j;
            }
        }
    }

    for (int k = ansi; k <= ansj; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}
