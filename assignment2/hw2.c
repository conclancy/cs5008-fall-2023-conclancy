// name: Connor Clancy
// email: clancy.co@neu.edu

#include <stdio.h>   // stardard input/output library
#include <stdbool.h> // standard boolean library: bool, true, false

#define MAXSIZE 100

bool isEmpty (int* s, int t) {
	// returns true if t = -1
	if (s == NULL || t < 0) {
		return true; 
	} else {
		return false;
	}
}

bool isFull (int* s, int t) {
	// returns true if no more room in the stack
	if ((sizeof(s) / sizeof(s[0])) == MAXSIZE || t + 1 == MAXSIZE) {
		return true;
	} else {
		return false;
	}
}

void push(int v, int* s, int* tp) {
  // put v onto the top of the stack s unless it is already full

  // INSERT YOUR CODE HERE
}

int pop (int* s, int* tp) {
  // return the top entry in the stack unless stack is empty
  // update s and *tp -- requires top to be passed by reference!

  // INSERT YOUR CODE HERE
}

int main () {

  int stack1[MAXSIZE]; // array in which stack will live
  int top1 = -1;       // top valid location in stack, -1 == empty
  int stack2[MAXSIZE]; // array in which stack will live
  int top2 = -1;       // top valid location in stack, -1 == empty
  
  printf("pushing: 1, 2, 3, 4, 5 onto first stack\n");
  printf("pushing: 100, 200, 300, 400, 500 onto second stack\n\n");
  push(1, stack1, &top1);
  push(2, stack1, &top1);
  push(3, stack1, &top1);
  push(4, stack1, &top1);
  push(5, stack1, &top1);
  push(100, stack2, &top2);
  push(200, stack2, &top2);
  push(300, stack2, &top2);
  push(400, stack2, &top2);
  push(500, stack2, &top2);

  printf("popping alternating stacks:\n");
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  
  // TESTS TODO 

  printf("\n**Tests Begin Here**\n\n");
  printf("test 1 - expected 1:%d\n", isEmpty(stack1, top1));
  printf("test 2 - expected 0:%d\n", isEmpty(stack1, 1));
  printf("test 3 - expected 1:%d\n", isFull(stack1, 99));
  printf("test 4 - expected 0:%d\n", isFull(stack1, top1));


  return 0;
}
