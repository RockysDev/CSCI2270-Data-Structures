#include <iostream>
#include "LinkedList.hpp"
#include <cstddef>

using namespace std;

/* DO NOT MODIFY */
LinkedList::~LinkedList()
{
   Node *next;
   while(head != NULL)
   {
      next = head->next;
      delete head;
      head = next;
   }
}

/* DO NOT MODIFY */
void LinkedList::insertNode(int leftValue, int value) {
   Node* left = search(leftValue);
   Node* node = new Node(value);
   
   if (left == 0) { /* inserting a new head node */
      node->next = head;
      head = node;
   }
   else if (left->next == 0) { /* inserting a new tail node */
      left->next = node;
      if (head == 0) 
         head = node;
   }
   else { /* inserting a node in the middle */
      node->next = left->next;
      left->next = node;
   }
}

/* DO NOT MODIFY */
Node* LinkedList::search(int val) {
   Node* current = head;
   while (current != 0) {
      if (current->data == val)
         return current;
      current = current->next;
   }
   return 0;
}

/* DO NOT MODIFY */
void LinkedList::printList()
{
   Node *current = head;
   
   while (current != NULL)
   {
      cout << current->data << " ";
      current = current->next;
   }
}

/* Complete this function but do not add any function parameters */
void LinkedList::searchLastMoveMiddle()
{
   int count = 0;
   Node *temp = head;
   while (temp != NULL) // getting num in list
   {
      count++;
      temp = temp->next;
   }
   if(count == 1 || count == 2){ // if theres only one or two nodes
      return;
   }
   Node *tail = head;
   Node *tailPrev = NULL;
   while (tail->next != NULL) // getting tail of linked list and node before tail(tailPrev)
   {
      tailPrev = tail;
      tail = tail->next;
   }
   tailPrev->next = NULL; // setting node before tail next to NUll;
   Node *prev = head;

   int spot = count/2 + count%2; // this is finding the spot where tail should be
   // count /2 is giving the middle node number in the int form
   // adding count%2 is giving us whether it should be moved right if it's odd or not

   for(int i=0;i<spot;i++){
      prev = prev->next;
   }
   tail->next = prev->next; // tail is now middle node, setting its next to the original node's spots next
   prev->next = tail;
   return;
    // Your solution goes here
}
