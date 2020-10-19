#include <stdio.h>
#include <time.h>	// for clock_t, clock()
#include <unistd.h>	// for sleep()

#define BILLION  1000000000.0

/*
struct timespec{
time_t tv_sec;  //time in seconds
long tv_nsec;  //time in nano seconds
}
*/
int main()
{
	struct timespec start, end;

	clock_gettime(CLOCK_REALTIME, &start);

	// do some stuff here
	sleep(3);

	clock_gettime(CLOCK_REALTIME, &end);

	// time_spent = end - start
	double time_spent = (end.tv_sec - start.tv_sec) +
						(end.tv_nsec - start.tv_nsec) / BILLION;

	printf("Time elpased is %f seconds", time_spent);

	return 0;
}
