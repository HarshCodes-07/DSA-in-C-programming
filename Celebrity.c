#include<stdio.h>
int main(){
    int n;
    printf("\nEnter no of people : ");
    scanf("%d",&n);
    int m[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("\nDoes %d Know %d ? Enter 1 for yes and 0 for no : ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
    int knows[n],knownBy[n];
    for(int i=0;i<n;i++){
        knows[i]=0;
        knownBy[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]==1){
                knows[i]++;
                knownBy[j]++;
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(knows[i]==0&&knownBy[i]==n-1){
            printf("\n%d is a celebrity",i+1);
            count=1;
            break;
        }
    }
    if(count==0)
        printf("\nNo Celebrity");
    return 0;
}
