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


void printMiddle(struct Node *head)  
{  
    struct Node *slow = head;  
    struct Node *fast = head;  
  
    if (head!=NULL)  
    {  
        while (fast != NULL && fast->next != NULL)  
        {  
            fast = fast->next->next;  
            slow = slow->next;  
        }  
        printf("The middle element is %d\n", slow->score);  
    }  
}  

int main(){
    pushHead(10);
    pushHead(22);
    pushHead(35);
    pushHead(46);
    pushHead(57);
    printMiddle(head);






    return 0;
}
