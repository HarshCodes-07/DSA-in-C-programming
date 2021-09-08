//Reverse a Dynamic Array
#include<stdio.h>
int main(){
int n;
printf("Enter the size of the array : ");
scanf("%d",&n);
int *a=(int *)malloc(n*sizeof(int));
int *b=(int *)malloc(n*sizeof(int));
printf("\nEnter %d numbers : ",n);
for(int i=0;i<n;i++)
    scanf("%d",a+i);
for(int i=0;i<n;i++)
    *(b+i)=*(a+n-i-1);
for(int i=0;i<n;i++)
    *(a+i)=*(b+i);
for(int i=0;i<n;i++)
    printf("%d ",*(a+i));
return 0;
}
