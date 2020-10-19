#include "myutils.h"
int factorial(int num)
{
  if(num==0)
    return 1;
  else if(num>=1)
    return num*factorial(num-1);
  else
    return 0;

}

int isprime(int num)
{ int flag,i;
  for(i=2;i<=num/2;i++)
  {
    if(num%i==0){
    flag=1;
    break;
  }
}

  if (num==1)
  return -1;
  else
  {
    if(flag==1)
    return 0;
    else
    return 1;
  }
  return 0;
}


int ispallindrome(int num)
{  int rev=0,rem,original;
    original=num;

  while(num!=0)
  {
    rem=num%10;
    rev=rev*10+rem;
    num/=10;
  }
  if(original==rev)
  return 1;
  else
  return 0;
}

int sum(int num,...) {

   va_list valist;
   int sum = 0;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      sum += va_arg(valist, int);
   }

   /* clean memory reserved for valist */
   va_end(valist);

   return sum;
}




