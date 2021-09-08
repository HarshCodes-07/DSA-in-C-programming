#include<stdio.h>
int main()
{
    int arr[100];
    int size;
    int *left = arr;
    int *right;
    printf("Enter size of array: ");
    scanf("%d", &size);
    right = &arr[size - 1];
    printf("Enter elements in array: ");
    while(left <= right)
    {
        scanf("%d", left++);
    }
    printf("\nArray before reverse: ");
    printArray(arr, size);
    left = arr;
    while(left < right)
    {
        *left    ^= *right;
        *right   ^= *left;
        *left    ^= *right;
        left++;
        right--;
    }


    printf("\nArray after reverse: ");
    printArray(arr, size);


    return 0;
}
void printArray(int *arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
}
