// Sum of two Complex Numbers
#include<stdio.h>
typedef struct complex{
    int real,imaginary;
}complex;
void sum(complex a,complex b);
int main(){
   struct complex a,b;
   printf("Enter real and imaginary of a\n");
   scanf("%d%d", &a.real, &a.imaginary);
   printf("Enter real and imaginary of b\n");
   scanf("%d%d", &b.real, &b.imaginary);
    sum(a,b);
}
void sum(complex a,complex b){
    struct complex c;
    c.real=a.real+b.real;
    c.imaginary=a.imaginary+b.imaginary;
    printf("Sum of the complex numbers: %d + %di", c.real, c.imaginary);
}
