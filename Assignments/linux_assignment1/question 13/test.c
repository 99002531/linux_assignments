#include<stdio.h>
#include "bitmask.h"
#include "mystring.h"
#include "myutils.h"


char string1[45]="ngjerngj";
char string2[]="rohith";
char string3[]="pandith";
int main()
{
  printf("Length of the string is %d\n",len("he is good boy"));
 printf("string comapre of %s and %s is %d\n",string1,string2,cmp(string1,string2));
  printf("string concate of  %s\n",cat(string2,string3));
  printf("string copy is %s\n",cpy(string,string1));
  printf("factorial of 5 is %d\n",factorial(5));
  printf("Number 5 is %s\n",(isprime(5)?"prime":"Not prime"));
  printf("Number is 12321 %s\n",(ispallindrome(12321)?"pallindrome":"Not a pallindrome"));
  printf("sum of 3,2,2 and 4 is %d\n",sum(3,2,3,4));
  printf("set 5th bit of 45 is  %d\n",setbit(45,5));
  printf("clear 5th bit of 45 is %d\n",clearbit(45,5));
  printf("flip 5th bit of 45 %d\n",flipbit(45,5));
  printf("Is 5th bit of 45  is set %s\n",(querybit(45,5)?"set":"not set"));
  return 0;
}	
