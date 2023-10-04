//Connor Clancy
//connor.clancy@northeastern.edu

//To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int SIZE = 10;
    int arr[SIZE],temp;
    int count=0,i,j; /*count will have the total number of elements in the array*/
    
    /*read the file*/
    fp=fopen("Input.txt","r");

    if(fp==NULL){
        //if file returns NULL then can't open the file
    printf("\n Cannot open the file \n");
    exit(0);
    }
    
    // read file into an array 

    int index = 0;  

    printf("Read  values: ");

    while(fscanf(fp, "%d", &temp) == 1) {
	  printf("%d ", temp);
	  arr[index] = temp;
	  index += 1; 
    }  
    
    printf("\n\nArray values: "); 

    for (int i = 0; i<SIZE; i++) {
    	printf("%d ", arr[i]);
    }

    printf("\n");

    fclose(fp);

    // insertion sort logic 

    int n, m, key;

    for (n=1; n<SIZE; n++) {
	key = arr[n];
	m = n - 1; 

	while(m>=0 && arr[m] > key) {
	    arr[m + 1] = arr[m];
	    m = m - 1;
	}

	arr[m + 1] = key;
    }
    
    printf("\nSort  values: ");

    for (int x = 0; x<SIZE; x++) {
	printf("%d ", arr[x]);
    }

    printf("\n");

    // write output file

    FILE *fo;
    
    fo = fopen("sorted.txt", "w");

    if(fo == NULL) {
	printf("Error creating sorted file.");
	exit(0);
    }

    for (int f = 0; f<SIZE; f++) {
	fprintf(fo, "%d\n", arr[f]);
    }

    fclose(fo); 
    
    return 0;
}
