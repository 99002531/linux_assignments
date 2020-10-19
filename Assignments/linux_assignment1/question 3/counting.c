#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int lc=0,wc=0,cc=0;
    int fptr;
    fptr = open("data.txt",O_RDONLY);

    if(fptr<0)
    {
        perror("File does not exists");
        exit(1);
    }
    int maxlen = 150;
    char buffer[maxlen];
    read(fptr,buffer,maxlen);
    for(int i=0;i<maxlen;i++)
    {
        if(buffer[i]== ' ')
        {
            wc=wc+1;
        }
        else if(buffer[i] == '\n')
        {
            lc=lc+1;
            wc=wc+1;
        }
        else if(buffer[i] != '\0')
        {
            cc=cc+1;
        }
        else
        {
            //lc=lc+1;
            //wc=wc+1;
            break;
        }
        
        
    }
    printf("%d\n",strlen(buffer));
    printf("\nNumber of lines = %d\n",lc);
    printf("Number of words = %d\n",wc);
    printf("Number of characters = %d\n",cc);
    close(fptr);
    return 0;
}
