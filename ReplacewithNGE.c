//Replace with nge
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
for(int i=0;i<n;i++){
        int nge=*(a+i);
    for(j=i+1;j<n;j++){
        if(*(a+j)>nge)
            {
                nge=*(a+j);
                break;
            }
    }
    *(a+i)=nge;
}
printf("\nAfter Replacing with NGE : ");
for(int i=0;i<n;i++)
    printf("%d ",*(a+i));
return 0;
}
