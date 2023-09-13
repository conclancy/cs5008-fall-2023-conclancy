//Insert your code and show the output to TAs
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 #define CHAR_SIZE 26
 
// Data structure to store a Trie node
typedef struct Trie
{
    int leafnode;             // 1 when the node is a leaf node,otherwise zero
    struct Trie* character[CHAR_SIZE]; //the branches for the size of a node is the size of the alphabet
}trienode;
 
// Function that create a new Trie node
trienode* newNode()
{
   trienode* node=(trienode*)malloc(sizeof(trienode));
   node->leafnode=0;
   int i;
   for(i=0;i<CHAR_SIZE;i++){
    node->character[i]=NULL;
   } 
   return node;
}
 
// Iterative function to insert a string into a Trie
void insert(trienode *head, char* str)
{
    
    
}


// Iterative function to search a string in a Trie. It returns 1
// if the string is found in the Trie; otherwise,returns 0.
int search(trienode* head, char* str)
{
    
}
    

int startswith(trienode* head,char *str)
{
    

}
void triefree(trienode *head)
{
    trienode *curr=head;
    if(curr!=NULL)
    {
        for(int i=0;i<CHAR_SIZE;i++)
        free(curr->character[i]);
        free(curr);
        
    }
}
    
    
// Trie implementation in C – Insertion, Searching and startswith
int main()
{
     trienode* head = newNode();
 
    insert(head, "car");
    printf("%d ", search(head, "abc"));       // print 1 if the word "car" is present
 
    insert(head, "cat");
    printf("%d ", search(head, "cat"));  // print 1 if the word "cat" is present
    printf("%d ",startswith(head,"ca"));
    
    insert(head, "do");
    printf("%d ", search(head, "do"));        // print 1 if the word "do" is present
    insert(head, "don");
    printf("%d \n", search(head, "don"));        //print 1 if don is present
    triefree(head);
    return 0;
}

    
    
    
    
    
   






 



    
    
    
    
    
   










    

