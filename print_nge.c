//Print all Next Greater Elements
#include<stdio.h>
int main(){
int n;
printf("Enter the size of the array : ");
scanf("%d",&n);
int *a=(int *)malloc(n*sizeof(int));
printf("\nEnter %d numbers : ",n);
for(int i=0;i<n;i++)
    scanf("%d",a+i);
for(int i=0;i<n;i++){
        int ok=0;
    for(int j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            int temp=*(a+j);
            *(a+j)=*(a+j+1);
            *(a+j+1)=temp;
            ok=1;
        }
    }
    if(ok==0)
        break;
}
printf("\nPrinting NGEs : \n");
for(int i=0;i<n-1;i++)
    printf("%d ----> %d\n",*(a+i),*(a+i+1));
return 0;
}
