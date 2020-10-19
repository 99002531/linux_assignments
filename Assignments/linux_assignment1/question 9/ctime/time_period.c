#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main()
{
    printf("\n\n\t\tThis program - to show use of ctime\n\n\n");

    time_t t;   // not a primitive datatype
    time(&t);
    int i=10;
     while(i)
     {
    printf("\nThis program has been writeen at (date and time): %s", ctime(&t));
    sleep(1);
    i--;
    }
    

    printf("\n\n\t\t\tend of the code !\n\n\n");
    return 0;
}
