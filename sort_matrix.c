// Read and input a matrix and sort rown in ascending and column in descending
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
        //ROW SORTING
        for (int i = 0; i < m; i++) {
            for(int k=0;k<n;k++){
                for(int j=0;j<n-k-1;j++){
                    if(*(a+n*i+j)>*(a+n*i+j+1)){
                        int temp=*(a+n*i+j);
                        *(a+n*i+j)=*(a+n*i+j+1);
                        *(a+n*i+j+1)=temp;
                }
            }
        }
    }
    //COLUMN SORTING
    for (int i = 0; i < n; i++) {
            for(int k=0;k<m;k++){
                for(int j=0;j<m-k-1;j++){
                    if(*(a+n*j+i)<*(a+n*(j+1)+i)){
                    int temp=*(a+n*j+i);
                    *(a+n*j+i)=*(a+n*(j+1)+i);
                    *(a+n*(j+1)+i)=temp;
                }
            }
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
