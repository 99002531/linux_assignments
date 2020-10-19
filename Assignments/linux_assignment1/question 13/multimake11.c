#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    int child1,child2,child3;
    int status;
    //printf("Parent PID %d\n",getpid());
    child1 = fork();

    if(child1==0)
    {
        execl("/usr/bin/gcc","gcc","-c","-Iinc","src/bitmask.c","src/myutils.c","src/mystring.c","test.c",NULL);
    }
    else if(child1<0)
    {
        perror("Error child1");
        exit(0);
    }
    else
    {
        printf("Inside child1\n");
        waitpid(child1,&status,0);
        child2 = fork();
    }
    if(child2==0)
    {
        
        execl("/usr/bin/gcc","gcc","-Iinc","bitmask.o","myutils.o","mystring.o","test.o","-o","test.out",NULL);
    }
    else if(child2<0)
    {
        perror("Error child2");
        exit(1);
    }    
    else
    {
        printf("Inside child2\n");
        waitpid(child2,&status,0);
        child3 = fork();
    }
    if(child3==0)
    {
        execl("test.out","test.out",NULL);
    }
    else if(child3<0)
    {
        perror("Error child3");
        exit(3);
    }    
    else
    {
        waitpid(child3,&status,0);
    }
    
    return 0;
}
