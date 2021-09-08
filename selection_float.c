#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter the size of Float array : ");
    scanf("%d",&n);
    float a[n];
    printf("\nEnter %d Elements : ",n);
    for(int i=0; i<n; i++)
        scanf("%f",&a[i]);
    for(int i=0; i<n; i++)
    {
        int minimum=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[minimum])
            {
                minimum=j;
            }
        }
        int temp=a[minimum];
        a[minimum]=a[i];
        a[i]=temp;
    }
    printf("\nAfter Sorting : \n");
    for(int i=0; i<n; i++)
    {
        printf("%f\t",a[i]);
    }
    return 0;
}
