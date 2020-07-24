#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Bucket.h"
#define NUMBUCKS 8
#define MAX 50


int main(void){
   
    bucket list[NUMBUCKS] = {
        'a', 'b', 0, NULL,
        'c', 'c', 0, NULL,
        'd', 'f', 0, NULL,
        'f', 'k', 0, NULL,
        'l', 'o', 0, NULL,
        'p', 'r', 0, NULL,
        's', 's', 0, NULL,
        't', 'z', 0, NULL
     };

    FILE *fp = fopen("test.txt", "r"); 
       int ch = getc(fp); 
       node *b;
       char* word;
    while (ch != EOF)  {
       word = ch; 
       b = (struct node*)malloc(sizeof(struct node));
       b->string = word;
       b->next = NULL;
      if(ch >= 'a' && ch <= 'b'){
         if(list[0].chainHead==NULL ){ 
            list[0].chainHead = b;   
            list[0].numWords++;
         }else{         
            setLast( list[0].chainHead , word);
            list[0].numWords++;
         } 
      }else if(ch == 'c'){
         if(list[1].chainHead ==NULL){ 
            list[1].chainHead = b;  
            list[1].numWords++;
         }else{
           setLast(list[1].chainHead, word);
           list[1].numWords++;
         }  
      }else if(ch >= 'd' && ch <= 'f'){
         if(list[2].chainHead ==NULL){
            list[2].chainHead = b;  
            list[2].numWords++;
         }else{
            setLast( list[2].chainHead, word);
            list[2].numWords++;
         }  
      }else if(ch >= 'f' && ch <= 'k'){
         if(list[3].chainHead ==NULL){
            list[3].chainHead = b;  
            list[3].numWords++;
         }else{
            setLast( list[3].chainHead, word);
            list[3].numWords++;    
         }  
      }else if(ch >= 'l' && ch <= 'o'){
         if(list[4].chainHead ==NULL){ 
            list[4].chainHead = b;  
            list[4].numWords++;
         }else{
            setLast( list[4].chainHead, word);
            list[4].numWords++;
         }  
      }else if(ch >= 'p' && ch <= 'r'){
         if(list[5].chainHead ==NULL){
            list[5].chainHead = b;  
            list[5].numWords++;
         }else{
            setLast( list[5].chainHead, word);
            list[5].numWords++;
         }  
      }else if(ch =='s'){
         if(list[6].chainHead ==NULL){ 
            list[6].chainHead = b;  
            list[6].numWords++;
         }else{
            setLast( list[6].chainHead, word);
            list[6].numWords++;
         }  
      }else if(ch >= 't' && ch <= 'z'){
         if(list[7].chainHead ==NULL){ 
            list[7].chainHead = b;  
            list[7].numWords++;
         }else{
            setLast( list[7].chainHead, word);
            list[7].numWords++;
         }     
      }
         ch = getc(fp); 
    }  

     bucketSort(list);
    printBucket(list);
   
    

return 0;

}