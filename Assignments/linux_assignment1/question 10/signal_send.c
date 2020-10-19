#include  <stdio.h>
#include  <sys/types.h>
#include  <signal.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <stdlib.h>

void  main(void)
{

     char   c;
     int   i,pid;
                       

     while (1) {                       
          printf("Want to interrupt the other process or kill it (i or k)? \n");
          scanf("%c",&c);
          //printf("%c is ",c);
          printf("enter pid\n");
          scanf("%d",&pid);
          if (c == 'i' || c == 'I') {  
               kill(pid, SIGINT);
               printf("Sent a SIGINT signal\n");
               exit(0);
          }
          else if (c == 'k' || c == 'K') {
               printf("About to send a SIGKILL signal\n");
               kill(pid, SIGKILL);     
               printf("Done.....\n");
               exit(0);
          }
          else
               printf("Wrong keypress (%c).  Try again\n", c);
     }
}

