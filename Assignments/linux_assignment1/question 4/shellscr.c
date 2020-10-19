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
int main()
{
    int child1;
    int status,cont;
    char str[5];
    while(cont)
    {
        printf("Enter the Command: ");
        gets(str);
        child1 = fork();
        if(child1==0)
        {
            execlp(str,str,NULL);
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
    
}