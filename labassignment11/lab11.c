//Enter your name here
//Enter your email here
//gcc -pthread lab11.c -o lab11
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t chopstick[5]; //lock variable

// Thread to be executed
void *philosopher(void *x) {
  //Treat variable x as a pointer to an int and then extract the value into n
  int* a=(int*)x;
  int n=*a; //dereferencing contents of a will be stored in n
  
  /*-----Insert your code here----*/
   
    
}


/*------------ Main Program---------*/
int main() {
  int i, val[5];
  pthread_t threads[5]; 
  
  // mutex initialize 
  for(i=0; i<5; i++) {
    pthread_mutex_init(&chopstick[i], NULL);
  }

  // pthread create
  for(i=0; i<5; i++) {
    val[i] = i;
    pthread_create(&threads[i], NULL, (void*)philosopher, &val[i]);
  }

  // wait until all threads are done 
  for(i=0; i<5; i++) {
    pthread_join(threads[i], NULL);
  }

  // destroy mutex
  for(i=0; i<5; i++) {
    pthread_mutex_destroy(&chopstick[i]);
  }

  return 0;
}
