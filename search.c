//Search in a Dynamic Array
#include<stdio.h>
int main(){
int n;
printf("Enter the size of the array : ");
scanf("%d",&n);
int *a=(int *)malloc(n*sizeof(int));
printf("\nEnter %d numbers : ",n);
for(int i=0;i<n;i++)
    scanf("%d",a+i);
    int x;
printf("\nEnter the element to be searched : ");
scanf("%d",&x);
int index=0;
for(int i=0;i<n;i++)
    if(*(a+i)==x)
    {
        printf("The Element %d is at position %d.",x,i+1);

    }
return 0;
}
