// LinkedList.hpp - interface file (header file)
#ifndef LinkedList_H
#define LinkedList_H
#include <cstddef>

struct Node{
   int data;
   Node *next;
   Node(int v, Node *n=NULL){
       data = v;
       next = n;
   }
};

class LinkedList{
   private:
      Node *head;
      Node *search(int val);
   public:
      LinkedList(){head = NULL;};
      ~LinkedList();
      void insertNode(int leftVal, int newVal);
      // A new node is created and value is stored as its key.
	  // The new node is added after node containing leftValue.

      void printList();
      // Display the key values of the entire list, starting with
	  // first node and ending with last node.

      void searchLastMoveMiddle();
      // TODO
      // Move the last node to the middle of the linked-list as 
      // described in the problem write-up.
};

#endif
