// Read and input a matrix of size m and n using malloc
#include<stdlib.h>
int main(){
    int *a;
    int m,n;
    printf("Enter the number of rows and columns : ");
    scanf("%d %d",&n,&m);
    a=(int *)malloc(m*n*sizeof(int));
    if(a==NULL){
        printf("Memory is zero");
    } else{
        int count =1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                *(a + i*n +j)= count++;
                }
        }
        printf("The elements of the array are : \n");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    printf("%d",*(a+i*n+j));
                }
            printf("\n");
        }
    }
    return 0;
}
