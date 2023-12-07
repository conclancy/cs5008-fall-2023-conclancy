// Connor Clancy
// clancy.co@neu.edu

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]) {
  // length of the compressed string will be returned from the function
  int index = 0;

  // parse the string one character at a time 
  for(int i = 0; i < n; i++) {
    int count = 1; // every character appears at least once

    // while not the last character and the next character is the same
    while(i < n - 1 && arr[i] == arr[i + 1]) {
      count++; // count each successive occurence of the character
      i++; // move to the next character in the string
    }

    // store the current letter in the results graph and increment index
    res[index] = arr[i];
    index++;

    if(count > 1) {
      char countArr[n]; // placeholder array to keep count for sprintf
      sprintf(countArr, "%d", count); // convert count to string and store in array

      // iterate over results and record it to res[]S
      int len = strlen(countArr);
      for(int j = 0; j < len; j++) {
        res[index] = countArr[j];
        index++;
      }
    }
  }

  // print our the compressed string on the screen
  printf("compressed string: %s\n", res);

  // return the compressed string length
  return index;
}
 
int main() {
    char a[]="aaaabbbbcccd";
    char res[50];
    int r,n = strlen(a);//n is the size of input array

    r = compression(a,n,res);

    //a4b4c3d RLE
    printf("length of the compressed string:%d\n",r);
    return 0;
}
