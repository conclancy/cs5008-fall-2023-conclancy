#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void longestCommonPrefix(char arr[][20], char res[20], int m){
    int index=0;
    int n=strlen(arr[0]);
    //traverse through all characters of first word
    for(int i=0;i<n;i++){
        char c=arr[0][i];
        bool flag=true;
    //for comparing c with the rest of strings
    //insert your code here
    
    
}
}
int main(){
    int i;
    char arr[5][20]={"aaabc","aaanv","aaamk","aaavf","aaacfb"};//input array
    int m=sizeof(arr)/sizeof(arr[0]);
    char res[20];//Array to store the longest common prefix 
    longestCommonPrefix(arr,res,m);
    printf("The Longest common prefix is ");
    for(i=0;i<strlen(res);i++){
        printf("%c",res[i]);
    }
    printf("\n");
    return 0;
}

