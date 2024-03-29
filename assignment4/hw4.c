// name: Connor Clancy
// email: clancy.co@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 50
#define RAND_RANGE 100

int main(){

  int source[LIMIT]; // array to hold input data values
  int dest[LIMIT];   // array to hold sorted data values
                     // use dest only if you are using two arrays
  bool valid[LIMIT]; // array that indicates which input values are valid

  int i;             // loop variable
  int j;             // loop variable
  int smallest;      // current smallest element

  //seed random numbers
  srand((unsigned)time(NULL));

  //initialize valid array - at begining the full array is valid
  for (i=0; i<LIMIT; i++) {
    valid[i] = true;
  }

  //initialize source array with random numbers from 0..RAND_RANGE
  for (i=0; i<LIMIT; i++) {
    source[i] = rand() % RAND_RANGE;
  }

  //print out source array in rows of 20 elements
  printf("Source array:\n");
  for (i=0; i < ((LIMIT/20)+1); i++) {
    for (j=0; j<20; j++) {
      if (i*20+j < LIMIT) {
	printf("%.2d ",source[i*20+j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  //selection sort
  for (i=0; i<LIMIT; i++) {

    // set variables 
    smallest = RAND_RANGE + 1;
    int temp_index = -1;

    // iterate every element in the list to find smallest 
    for (j=0; j<LIMIT; j++) {

        // store the smallest current element and its index
        if(source[j] < smallest) {
            smallest = source[j];
            temp_index = j;
        }

    }

    // after identifying smallest current element, write to
    // the destination list and set the index in the original list 
    // out of range for iteration. 
    dest[i] = smallest;
    source[temp_index] = RAND_RANGE + 1;  
  }
  
  //print out sorted array in rows of 10
  printf("Destination array:\n");
  
  // iterate over every element in the destination list 
  for (i=0; i<LIMIT; i++) {

      // print out each element with a trailing space
      printf("%d ", dest[i]);

      // if there are 10 elements in the row, start a new line
      if((i + 1) % 10 == 0) {
          printf("\n");
      }
  }
  
  return 0;
}
