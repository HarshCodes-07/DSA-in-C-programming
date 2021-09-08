 // Read and input a matrix and interchange columns
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
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    scanf("%d",a+i*n+j);
                }
        }
        for (int i = 0; i < m; i++) {
            for(int j=0;j<n/2;j++){
                int temp = *(a + i*n +j);
                *(a + i*n +j) = *(a+i*n+ (n - j -1));
                *(a+i*n+ (n - j -1)) = temp;
            }
        }
        printf("The elements of the array are : \n");
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    printf("%d ",*(a+i*n+j));
                }
                printf("\n");
        }
    }
    return 0;
}
