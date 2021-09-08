#include <stdio.h>
int main()
{
    int i,n;
    printf("Enter the size : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d Elements : ",n);
    for (i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    int nos[n];
    for(i=0; i<n; i++)
    {
        nos[i]=0;
    }
    for(i=0; i<n; i++)
    {
        nos[arr[i]-1]++;
    }
    int c=0;
    for(i=0; i<n; i++)
    {
        if(nos[i]!=1)
        {
            c=1;
        }
    }
    if(c==0)
    {
        printf("\nYES");
    }
    else
    {
        printf("\nNO");
    }
}
