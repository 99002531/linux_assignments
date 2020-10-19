#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int ret;
    printf("Parent PID %d\n",getpid());
    ret = fork();

    switch(ret)
    {
        case 0 :printf("child--welcome,pid=%d,ppid=%d\n",
			    getpid(),getppid());
                execl("/usr/bin/gcc","gcc","file2.c","-o","file2",NULL);
                execl("file2","file2",NULL);  
                break;
        case -1: perror("fork");
		         exit(1);
        default:printf("parent--hello,pid=%d,ppid=%d\n",
			    getpid(),getppid());
                break;                 
    }
    return 0;
}
