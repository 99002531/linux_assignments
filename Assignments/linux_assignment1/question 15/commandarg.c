/*
Basic commands like
-ls
-pwd
-date
-cal
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <string.h> 
int main(int argc,char *argv[])
{
    int child1;
    int status,cont;
    //char str[5];
    if(argc==2)
    {
        child1 = fork();
        if(child1==0)
        {
            execlp(argv[1],argv[1],NULL);
        }
        else if(child1<0)
        {
            perror("Error child1");
            exit(0);
        }
        else
        {
            waitpid(child1,&status,0);
        }
   }
   else if(argc>2)
   {
       printf("Too many arguments given\n");
   }
   else
   {
       printf("One argument is expected\n");
   }
   return 0;
    
}