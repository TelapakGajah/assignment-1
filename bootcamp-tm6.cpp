#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  int score;
  Node *next; // pointer ke node selanjutnya
} *head, *tail; // head: node pertama, tail: node terakhir

Node *createNode(int score) {
  Node *newNode = (Node*)malloc(sizeof(Node)); // alokasi memory
  newNode->score = score;
  newNode->next = NULL; // awalnya tidak memiliki node selanjutnya
  return newNode;
}

void sortList() {  
        //Node current will point to head  
        struct Node *current = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                    if(current->score < index->score) {  
                        temp = current->score;  
                        current->score = index->score;  
                        index->score = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
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

void printLinkedList(struct Node *curr){
  while(curr) { // selama curr bukan NULL
    printf("%d -> ", curr->score); // print data
    curr = curr->next; // curr akan berjalan ke node selanjutnya
  }
    printf("NULL\n");
}



 int main(){
    pushHead(5);
    pushHead(4);
    pushHead(3);
    pushHead(2);
    pushHead(1);
    printf("Before:\n");
    printLinkedList(head);
    printf("After:\n");
    sortList();
    printLinkedList(head);
     return 0;
 }
