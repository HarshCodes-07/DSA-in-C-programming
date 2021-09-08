//Segregate 1s and 0s in array
#include<stdio.h>
int main(){
int n;
printf("Enter the size of the array : ");
scanf("%d",&n);
int *a=(int *)malloc(n*sizeof(int));
printf("\nEnter %d numbers : ",n);
for(int i=0;i<n;i++)
    scanf("%d",a+i);
int i = 0,j= n - 1;
while(i<j){
if(a[i] == 1){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    j--;
}
else
    i++;
}
printf("\nAfter Seperating : ");
for(int i=0;i<n;i++)
    printf("%d ",*(a+i));
return 0;
}
