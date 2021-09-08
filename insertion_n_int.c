#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter the size of Integer array : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter %d Elements : ",n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<n; i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&key>a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("\nAfter Sorting : \n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
