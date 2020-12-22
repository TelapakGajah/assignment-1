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

void removeDuplicates(struct Node* head) 
{ 
    /* Pointer to traverse the linked list */
    struct Node* curr = head; 
  
    /* Pointer to store the next pointer of a node to be deleted*/
    struct Node* next_next;  
    
    /* do nothing if the list is empty */
    if (curr == NULL)  
       return;  
  
    /* Traverse the list till last node */
    while (curr->next != NULL)  
    { 
       /* Compare current node with next node */
       if (curr->score == curr->next->score)  
       { 
           /* The sequence of steps is important*/               
           next_next = curr->next->next; 
           free(curr->next); 
           curr->next = next_next;   
       } 
       else /* This is tricky: only advance if no deletion */
       { 
          curr = curr->next;  
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

int main(){
    pushHead(10);
    pushHead(22);
    pushHead(22);
    pushHead(46);
    pushHead(46);
    printf("Sebelum dihapus duplicatenya\n");
    printLinkedList(head);
    removeDuplicates(head);
    printf("Setelah dihapus duplicatenya\n");
    printLinkedList(head);
    return 0;
}
