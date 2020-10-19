#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd,nbytes,fd1,nbytes1;
	fd=open("sample.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(fd,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	
	fd1=open("alpha.txt",O_WRONLY|O_CREAT, 0666);
	
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}
	
	
	
	nbytes1=write(fd1,buf,strlen(buf));
	if(nbytes1<0)
	{
		perror("write");
		exit(2);
	}
	printf("written successfully,nbytes=%d\n",nbytes1);
	close(fd);
	close(fd1); 
	return 0;	//exit(0);
}
		






