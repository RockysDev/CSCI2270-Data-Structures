#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node{
    int key;
    Node* left ;
    Node* right;
};

class BST{
    private:
        Node* root;
        Node* createNode(int data);

        Node* addNodeHelper(Node*, int);
		Node* displayLevelofNode(int numlevels, Node* curr, int target); // TODO
        void destroyNode(Node *);

    public:
        Node* getRoot();                // Returns the root of the tree;
        void addNode(int);              // function to insert a node in the tree.
        bool searchKey(int);            // function to search a data in the tree
        BST();                          // default constructor
        BST(int data);                  // parameterized constructor
        ~BST();                         // destructor
		
        void getNodeWithTargetSumAndLevel(int, int);  // TODO
};
#endif
