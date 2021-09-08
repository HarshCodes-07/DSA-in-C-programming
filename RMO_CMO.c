#include<stdio.h>
int main(){
    int a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int BA;
    printf("\nEnter Base Address : ");
    scanf("%d",&BA);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]!=0){
                printf("\na[%d][%d] : ",i+1,j+1);
                printf("\nRMO : %d",(BA+sizeof(int)*(3*i+j)));
                printf("\nCMO : %d\n",(BA+sizeof(int)*(i+j*3)));
            }
        }
    }
}
