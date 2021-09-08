// Read and input an array of size n using malloc
#include<stdio.h>
int main(){
    int *a;
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL){
        printf("Memory is zero");
    } else{
        printf("Enter the %d elements of the array : ",n);
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
        }
        printf("The elements of the array are: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", *a+i);
        }
    }
    return 0;
}
