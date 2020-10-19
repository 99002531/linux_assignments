#include <stdio.h>
#include <sys/time.h>   // for gettimeofday()
#include <unistd.h> 	// for sleep()

//use this structure in the sys/time.h
// struct timeval{
//long tv_sec;  for seconds
//long tv_usec; for micro seconds
//}
int main()
{
	struct timeval start, end;

	gettimeofday(&start, NULL);

	// do some stuff here
	sleep(5);

	gettimeofday(&end, NULL);

	long seconds = (end.tv_sec - start.tv_sec);
	long micro_seconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

	printf("Time elpased is %d seconds and %d microseconds\n", seconds, micro_seconds);

	return 0;
}
