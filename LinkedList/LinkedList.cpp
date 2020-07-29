#include <iostream>

struct Node {
  int key;
  Node * next;
  Node(int k){
    key = k;
    next = NULL;
  }
};

Node* insertBegin(Node* head, int k){
  Node* temp = new Node(k);
  temp->next = head;
  return temp;
}

Node* insertEnd(Node* head, int k){
  if(head== NULL) return new Node(k);
  Node *curr = head;
  while(curr->next != NULL){
    curr= curr->next;
  }
  curr->next = new Node(k);
  return head;
}
//1 2 3 4 5 6
Node* middleNode(Node* head){
  Node* fast = head;
  Node* slow = head;
  while(fast!= NULL && fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node* nthNodeFromEnd(Node* head,int n){
  Node* first= head;
  Node* second = head;
  while(n>0){
    first = first->next;
    n--;
  }
  while(first != NULL){
    first = first->next;
    second = second->next;
  }
  return second;
}
void printList(Node *head){
  // loop ->next until you reach head eq NULL
  while(head != NULL){
    std::cout <<head->key<<" ";
    head = head->next;
  }
}

Node* reverseList(Node* head){
  Node* curr = head;
  Node* prev = NULL;
  Node* next = NULL;
  while(curr!= NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int main() {
  Node* list ;
  // list = insertBegin(list, 24);
  // list = insertBegin(list, 36);
  list = insertEnd(list, 10);
  list = insertEnd(list, 20);
  list = insertEnd(list, 30);
  list = insertEnd(list, 40);
  list = insertEnd(list, 50);
  list = insertEnd(list, 60);
  std::cout <<middleNode(list)->key<<"  __ \n";
  std::cout <<nthNodeFromEnd(list, 3)->key<<"  __ \n";
  list = reverseList(list);
  printList(list);
}