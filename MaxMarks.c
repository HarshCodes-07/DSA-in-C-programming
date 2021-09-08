#include<stdio.h>
int main(){
    int size=10;
    int arr[10];
    printf("Enter marks of 10 students : ");
    int max=0;
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("Maximum Marks : %d",max);
    return 0;
}
