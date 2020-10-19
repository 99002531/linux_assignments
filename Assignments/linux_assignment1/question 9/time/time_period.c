#include <stdio.h> 
#include <time.h> 
#include<unistd.h>
  
// driver code 
int main() 
{ 
    time_t s, val = 1; 
    struct tm* current_time; 
  
    // time in seconds 
    s = time(NULL); 
  
    // to get current time
    int i=10;
    while(1)
    { 
    current_time = localtime(&s); 
  
    // print time in minutes, 
    // hours and seconds 
    
    printf("%02d:%02d:%02d\n", 
           current_time->tm_hour, 
           current_time->tm_min, 
           current_time->tm_sec); 
    sleep(1);
    i--;
    }
  
    return 0; 
} 
