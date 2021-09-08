//Count and print elements between a and b
#include<stdio.h>
int main(){
int n;
printf("Enter the size of the array : ");
scanf("%d",&n);
int *a=(int *)malloc(n*sizeof(int));
printf("\nEnter %d numbers : ",n);
for(int i=0;i<n;i++)
    scanf("%d",a+i);
int x,y;
printf("\nEnter x and y : ");
scanf("%d %d",&x,&y);
int count =0,start=0,end=0;;
for(int i=0;i<n;i++){
    if(*(a+i)>x&&*(a+i)<y){
        count++;
        printf("%d ",*(a+i));
    }
}
printf("\n%d is count",count);
for(int i=start;i<=end;i++){

}
return 0;
}
