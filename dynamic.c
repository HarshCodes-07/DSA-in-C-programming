#include<stdio.h>
#include<math.h>
int main(){
    int *i;
    float *j;
    *i=malloc(sizeof(int));
    *i=10;
    printf("%d",i);
    return 0;
}
