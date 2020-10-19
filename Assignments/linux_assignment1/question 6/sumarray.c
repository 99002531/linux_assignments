
#include <stdio.h>
#include <pthread.h> 
#include <stdlib.h> 

#define MAX 1000
  
// maximum number of threads 
#define MAX_THREAD 10 
  

  
int a[MAX]={};
int sum[10] = { 0 }; 
int part = 0; 
  
void* sum_array(void* arg) 
{ 
  
    
    int thread_part = part++; 
  
    for (int i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++) 
        sum[thread_part] += a[i]; 
        //printf("%d",sum);
} 
  
// Driver Code 
int main() 
{ 	
   for(int i=1;i<=1000;i++)
   {
   	a[i]=i;
   }
  //printf("%d",a[999]);
   	
    pthread_t threads[MAX_THREAD]; 
  
    // Creating 10 threads 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i],NULL, sum_array,(void*)NULL); 
  
    // joining 10 threads i.e. waiting for all 10 threads to complete 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_join(threads[i], NULL); 
  
    // adding sum of all 10 parts 
    int total = 0; 
    for (int i = 0; i < MAX_THREAD; i++) 
        total+= sum[i]; 
  
    printf("sum is %d",total);
  
    return 0; 
} 
