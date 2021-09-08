#include<stdio.h>
struct Day
{
    int yy;
    int mm;
    int dd;
    int joined;
};
int main()
{
    int n;
    printf("\nEnter the size or no of Days : ");
    scanf("%d",&n);
    struct Day a[n];
    printf("\nEnter %d Dates in dd mm yy format : ",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i].dd);
        scanf("%d",&a[i].mm);
        scanf("%d",&a[i].yy);
    }

    for(int i=0; i<n; i++)
    {
        int x=a[i].yy;
        x=x*100+a[i].mm;
        x=x*100+a[i].dd;
        a[i].joined=x;
    }
    for(int i=0; i<n-1; i++)
    {
        int ok=0;
        for(int j=0; j<n-1; j++)
        {
            if(a[j].joined>a[j+1].joined)
            {
                ok=1;
                struct Day temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(ok==0)
            break;
    }
    printf("\nAfter Sorting : \n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\n",a[i].dd,a[i].mm,a[i].yy);
    }
    return 0;
}
