#include<stdio.h>
int main()
{
    int arr[100];
    int N, i;
    int * ptr = arr;

    printf("Enter size of array: ");
    scanf("%d", &N);

    printf("Enter elements in array:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }
    ptr = arr;
    printf("Array elements: ");
    printArray(arr,N);

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

