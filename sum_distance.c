// Distance sum
#include <stdio.h>
struct Distance {
   int km;
   int m;
} a, b, c;
struct Distance sum(struct Distance a,struct Distance b);
int main() {
   printf("Enter 1st distance\n");
   printf("Enter km: ");
   scanf("%d", &a.km);
   printf("Enter meter: ");
   scanf("%d", &a.m);
   printf("\nEnter 2nd distance\n");
   printf("Enter km: ");
   scanf("%d", &b.km);
   printf("Enter meter: ");
   scanf("%d", &b.m);
   c=sum(a,b);
   printf("\nSum of distances = %d km and %d m",c.km, c.m);
   return 0;
}
struct Distance sum(struct Distance a,struct Distance b)
{
    c.km=a.km+b.km;
    c.m=a.m+b.m;
    int km=c.m/1000;
    int m=c.m%1000;
    c.km+=km;
    c.m=m;
    return c;
};
