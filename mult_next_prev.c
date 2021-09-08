//Replace with multiplications of prev and next
#include<stdio.h>
int main(){
int n;
printf("Enter the size of the array : ");
scanf("%d",&n);
int *a=(int *)malloc(n*sizeof(int));

printf("\nEnter %d numbers : ",n);
for(int i=0;i<n;i++)
    scanf("%d",a+i);
    int j;
printf("\nAfter Replacing with multiples of prev and next : ");
for(int i=0;i<n;i++)
    if(i!=0 &&i!=n-1)
    printf("%d ",*(a+i-1)* *(a+i+1));
    else printf("%d ",*(a+i));
return 0;
}
