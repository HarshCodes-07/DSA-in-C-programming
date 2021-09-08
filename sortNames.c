#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    printf("\nEnter the size of names array : ");
    scanf("%d",&n);
    char a[n][20];
    printf("\nEnter %d Names : ",n);
    for(int i=0; i<n; i++)
        scanf("%s",&a[i]);
    for(int i=0; i<n; i++)
    {
        int minimum=i;
        for(int j=i+1; j<n; j++)
        {
            if(strcmp(a[j],a[minimum])<0)
            {
                minimum=j;
            }
        }
        char temp[20];
        strcpy(temp,a[minimum]);
        strcpy(a[minimum],a[i]);
        strcpy(a[i],temp);
    }
    printf("\nAfter Sorting : \n");
    for(int i=0; i<n; i++)
    {
        printf("%s\t",a[i]);
    }
    return 0;
}
