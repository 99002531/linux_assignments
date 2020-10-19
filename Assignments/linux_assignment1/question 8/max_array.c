

#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
// Size of array 
#define max 1000
  
// Max number of thread 
#define Th_max 10 
  
// Array 
int a[max] = {};
int i;
// Array to store max of threads 
int max_num[Th_max] = { 0 }; 
int thread_no = 0; 
  
// Function to find maximum 
void maximum(void* arg) 
{ 
    int i, num = thread_no++; 
    int maxs = 0; 
  
    for (i = num * (max / 10); i < (num + 1) * (max / 10); i++) { 
        if (a[i] > maxs) 
            maxs = a[i]; 	
    } 
  
    max_num[num] = maxs; 
} 
  
// Driver code 
int main() 
{ 
    for(i=0;i<max;i++)
    {
	a[i]=i;
   } 
    int maxs = 0; 
    int i; 
    pthread_t threads[Th_max]; 
  
    // creating 10 threads 
    for (i = 0; i < Th_max; i++) 
        pthread_create(&threads[i], NULL, 
                       maximum, (void*)NULL); 
  
    // joining 10threads i.e. waiting for 
    // all 10 threads to complete 
    for (i = 0; i < Th_max; i++) 
        pthread_join(threads[i], NULL); 
  
    // Finding max element in an array 
    // by individual threads 
    for (i = 0; i < Th_max; i++) { 
        if (max_num[i] > maxs) 
            maxs = max_num[i]; 
    } 
  
    printf("Maximum Element is : %d", maxs); 
  
    return 0; 
} 

