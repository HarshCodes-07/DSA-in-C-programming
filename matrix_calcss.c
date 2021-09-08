// Read and input a matrix of size m and n using malloc and
// a) Count no of non zero elements
// b) Find the sum of elements above leading diagnol
// c) Display element below minor diagnol
// d) Product of diagnol elements
#include<stdlib.h>
int main(){
    int *a;
    int m,n;
    printf("Enter the number of rows and columns : ");
    scanf("%d %d",&n,&m);
    printf("\nEnter %d elements : ",m*n);
    a=(int *)malloc(m*n*sizeof(int));
        int count =0,sum=0,prod=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",(a + i*n +j));
                if(*(a+i*n+j)!=0)
                    count++;
                if(j>i)
                    sum+=*(a+i*n+j);
                if(i==j)
                    prod*=*(a+i*n+j);
        }
        }
        printf("\nNo of Non Zero Elements are : %d",count);
        printf("\nThe Sum of Elements above leading diagnol are : %d ",sum);
        printf("\nThe elements below minor diagnol are : \n");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    if(j<i)
                        printf("%d ",*(a+i*n+j));
                    else printf(" ");
                }
            printf("\n");
        }
        printf("\nThe Product of the diagnol elements are : %d ",prod);
    return 0;
}
