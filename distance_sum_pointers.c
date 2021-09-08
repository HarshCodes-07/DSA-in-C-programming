s// Distance sum using pointer
#include <stdio.h>
struct Distance {
   int km;
   int m;
} a, b, c;
c *sum(struct Distance a,struct Distance b);
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
   struct Distance *p=sum(a,b);
   c=p;
   printf("\nSum of distances = %d km and %d m",c.km, c.m);
   return 0;
}
c *sum(struct Distance a,struct Distance b)
{
    struct Distance* p;
    c.km=a.km+b.km;
    c.m=a.m+b.m;
    int km=c.m/1000;
    int m=c.m%1000;
    c.km+=km;
    c.m=m;
    p=c;
    return p;
};
