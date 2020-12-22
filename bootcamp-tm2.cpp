#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  int score;
  Node *next; // pointer ke node selanjutnya
  int penanda;
} *head, *tail; // head: node pertama, tail: node terakhir

//buat newnode baru
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

bool detectLoop(struct Node* h)
{
    while (h != NULL) {
        // If this node is already traverse
        // it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (h->penanda == 1)
            return true;
 
        // If we are seeing the node for
        // the first time, mark its flag as 1
        h->penanda = 1;
 
        h = h->next;
    }
 
    return false;
}


int input;
int main(){
    pushHead(1);
    pushHead(2);
    pushHead(3);
    pushHead(4);
    pushHead(5);

    head->next->next->next->next = head;
    puts("Enter your number: ");
    scanf("%d",&input);
    if (detectLoop(head)==input){
        puts("Loop Detected");
    }
    else{
        puts("No Loop");
    }
    

    return 0;
}
