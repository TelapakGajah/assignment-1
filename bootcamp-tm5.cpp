#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  char name[255];
  int score;
  Node *next; // pointer ke node selanjutnya
} *head, *tail; // head: node pertama, tail: node terakhir

Node *createNode(int score) {
  Node *newNode = (Node*)malloc(sizeof(Node)); // alokasi memory
  newNode->score = score;
  newNode->next = NULL; // awalnya tidak memiliki node selanjutnya
  return newNode;
}

void pushHead(int score) {
  // Kita mau pushHead A1 di linked list berikut:
  // A2 (head) -> B3 -> C4 (tail) -> NULL 

  // A1 (temp) -> NULL || Node *temp = createNode(name, score)
  // A1 (temp) -> A2 (head) -> B3 -> C4 (tail) -> NULL || temp->next = head
  // A1 (head) -> A2 -> B3 -> C4 (tail) -> NULL || head = temp

  Node *temp = createNode(score); // buat node baru

  if(!head) { // linked list kosong (0 node)
    head = tail = temp; // temp akan menjadi head dan tail
  } else { // >= 1 node
    temp->next = head; // node setelah temp adalah head
    head = temp; // head baru adalah temp
  }
}


 void printNthFromLast(struct Node *head, int n) 
{ 
  struct Node *main = head; 
  struct Node *ref = head; 
  
  int count = 0; 
  if(head != NULL) 
  { 
     while( count < n ) 
     { 
        if(ref == NULL) 
        { 
           printf("%d is greater than the no. of "
                    "nodes in list", n); 
           return; 
        } 
        ref = ref->next; 
        count++; 
     } /* End of while*/
      
     if(ref == NULL) 
     { 
        head = head->next; 
        if(head != NULL) 
         printf("Nodenya berada di %d ",main->score); 
     } 

     else
     { 
       while(ref != NULL) 
       { 
          main = main->next; 
          ref  = ref->next; 
       } 
        printf("Nodenya berada di %d ",main->score); 
     } 
  } 
} 


void printLinkedList(struct Node *curr){
  while(curr) { // selama curr bukan NULL
    printf("%d -> ", curr->score); // print data
    curr = curr->next; // curr akan berjalan ke node selanjutnya
  }
    printf("NULL\n");
}
int input;
int main(){
    pushHead(10);
    pushHead(22);
    pushHead(35);
    pushHead(46);
    pushHead(57);
    printLinkedList(head);
    puts("");
    printf("Masukkan angka yang ingin diprint (dari belakang)\n");
    scanf("%d",&input);
    printNthFromLast(head,input);




    return 0;
}
