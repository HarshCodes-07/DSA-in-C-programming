#include <stdio.h>
int main()
{
    int i,n;
    printf("Enter the size : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d Elements : ",n);
    for (i = 0; i < n; i++)
        scanf("%d",&arr[i]);
        int max=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                int x=j-i;
                if(x>max){
                    max=x;
                }
            }
        }
    }
    printf("\n%d",max);
}
