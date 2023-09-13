//enter your email here
//enter your name here

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]){
    
    //length of the compressed string will be returned from the function

    
    
    //insert your code here
  // sprintf--convert int to char 
    
    
    
    
}
 
int main()
{
    char a[]="aaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    //a4b4c3d RLE
    printf("length of the compressed string:%d\n",r);
    return 0;
}
