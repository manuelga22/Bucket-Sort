typedef struct node{
     char* string;
     struct node* next;
}node;

typedef struct bucket{
    int minInitial;
    int maxInitial;
    int numWords;
    node* chainHead;
} bucket;

void swap( node* a,  node* b) { 
    if(a->string ==NULL){
      return;
    }else if(b->string ==NULL){   
      return;
    }
    char *temp = a->string;
    a->string= b->string;
    b->string = temp;
} 
void sortStrings(node * start) {   
     int swapped, i; 
     node *ptr1; 
     node *lptr = NULL; 
  
    if (start == NULL) 
        return; 
  
    do{ 
        swapped = 0; 
        ptr1 = start; 
        while (ptr1->next != lptr) { 
            if (ptr1->string > ptr1->next->string) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped); 
} 

void bucketSort( bucket b[8] ){
    for (int i=0; i<8; i++) {
      if(b[i].chainHead != NULL){
        sortStrings(b[i].chainHead); 
      }       
    }
}

void setLast(node* n, char *str){  
    node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL){
        printf(" Memory can not be allocated.");
    }else{
        
        fnNode->string = str;     //Links the data part
        fnNode->next = NULL; 
        while(n->next != NULL)
            n = n->next;
        n->next = fnNode;  //Links the address part
        
    }
}


void printNodes(node* n){
  node *temp = n;
  if(temp ==NULL){
    printf("-");
  }
  while (temp != NULL){     
     printf("%c ", temp->string);
     temp = temp->next;
  }
  printf("\n");

}
void printBucket(bucket b[]){
 
  for (int i=0; i<8; i++) { 
    // printf(" %d ", b[i].numWords);
      printNodes(b[i].chainHead);
  }

}
