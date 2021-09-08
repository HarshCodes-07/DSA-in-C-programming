#include <stdio.h>
#include <math.h>
  int isPerfect(int x)
    {
       int s = (int)sqrt(x);
       return (s*s == x);
     }
   int isFibonacci(int x)
      {
         return isPerfect(5*x*x + 4) ||
           isPerfect(5*x*x - 4);
     }
    int main(void)
    {
	 int n;
	 scanf("%d",&n);
	  if (n>0)
		{
		 printf("Is %d a Fibonacci number? %d",n, isFibonacci(n));
		}
		return 0;
   }
