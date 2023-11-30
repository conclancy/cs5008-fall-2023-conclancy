// Connor Clancy
// clancy.co@neu.edu
//gcc -pthread lab11.c -o lab11
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t chopstick[5]; //lock variable

// Thread to be executed
void *philosopher(void *x) {
  // Treat variable x as a pointer to an int and then extract the value into n
  int* a = (int*)x; //type cast address to integer type
  int n = *a; //dereferencing contents of a will be stored in n

  // thinking
  printf("Philosopher %d is thinking.\n", n + 1);

  // 1. acquire lock --> blocking, wait until the thread gets both chopsticks
  // lock left chopstick
  pthread_mutex_lock(&chopstick[n]);

  // lock right chopstick
  pthread_mutex_lock(&chopstick[(n + 1) % 5]);

  //---critical section---//

  // 2. eating
  // eating 
  // print a statement that the philosopher is eating
  printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d].\n", n + 1, n, (n + 1) % 5);
  
  // sleep(1 second)
  sleep(1);

  // print a statement that the philosopher is finished eating
  printf("Philosopher %d finished eating.\n", n + 1);

  // 3. unlock the chopsticks
  // unlock left chopstick
  pthread_mutex_unlock(&chopstick[n]);

  // unlock right chopstick
  pthread_mutex_unlock(&chopstick[(n + 1) % 5]);
   
  return NULL;
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
