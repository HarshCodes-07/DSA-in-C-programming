// Read and input an array of size n using malloc
#include<stdio.h>
int main(){
    int *a;
    int n,x,y;
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
        printf("Enter the number of x and y : ");
        scanf("%d %d",&x,&y);
        int min=1000000,temp=min,j;
        for (int i = 0; i < n; i++) {
            if(a[i]==x){
            temp=0;
            for(j=i+1;j<n;j++){
                if(a[j]!=y)
                    temp++;
                else break;
            }
            if(a[j]==y&&temp<=min)
                min=temp;
            }
        }
        printf("\nThe Minimum distance is : %d ",min+1);
    }
    return 0;
}
