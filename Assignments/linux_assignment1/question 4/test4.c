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
    int status,cont=1;
    char str[5];
    char mnstr[10];
    const char s[4] = " "; 
    char* tok; 
    //while(cont)
    //{
        strcat(mnstr,"\"");
        //puts(mnstr);
        printf("Enter the Command: ");
        gets(str);
        puts(str);
        for(int i=0;i<str[i]!='\0';i++)
        {
            puts("entering for loop");            
            if(!strcmp(str[i]," "))
            {  
                printf("%c",&str[i]);
                //strcat(mnstr,str[i]);
                //puts(mnstr);
            }
            else
            {
                strcat(mnstr,"\",\"");
                puts(mnstr);
            }    
        }
        puts(mnstr);
        if(child1==0)
        {
            char *arr[] = {"/usr/bin/",str,NULL};
            execvp("/usr/bin/",arr);
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
    //}
    
}