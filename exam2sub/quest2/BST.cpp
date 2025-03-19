#include <iostream>
#include <limits>
#include "BST.hpp"

using namespace std;

/**
Create a node with key as data
**/
Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
parameterized constructor. It will create the root and put the data in the root.
**/
BST::BST(int data)
{
    root = createNode(data);
}

/**
Destructor
**/
BST::~BST(){
     destroyNode(root);
}

/**
getRoot
**/
Node* BST::getRoot(){
    return root;
}

/**
 This function will destroy the subtree rooted at currNode.
 **/
void BST::destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
}

/**
This function will add the data in the tree rooted at currNode.
**/
Node* BST::addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key <= data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}

/**
addNode
**/
void BST::addNode(int data)
{
    root = addNodeHelper(root, data);
}

/**
searchForKey
**/
Node* searchForKey(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchForKey(currNode->left, data);

    return searchForKey(currNode->right, data);
}


// ------ TODO ------
Node* displayLevelofNode(int &numlevels, Node* currNode, int target){
	// You can add parameters to this function as needed.
	// However, make sure you update the BST.hpp file.
    numlevels++;
    if(currNode == NULL)
        return NULL;

    if(currNode->key == target)
        return currNode;
        // need to check if left or right of curr node is also equal to target
        // for duplicates
        // couldn't finish in time :(

    if(currNode->key > target){
        // numlevels++;
        return displayLevelofNode(numlevels, currNode->left, target);
    }
    else{
        // numlevels++;
        return displayLevelofNode(numlevels, currNode->right, target);
    }

}

// ------ TODO ------
void BST::getNodeWithTargetSumAndLevel(int key1, int target){
   	Node *search = searchForKey(root, key1);
    if(search == NULL){
        cout << "Input key not found in BST" << endl;
        return;
    }
    int remainder = target - key1;
    Node *complement = searchForKey(root, remainder);
    if(complement == NULL){
        cout << "There are no nodes that sum up to the target using the input key" << endl;
        return;
    }
    // fix display
    int numLevels = 0;
    // cout << "1" << endl;
    // displayLevelofNode(numLevels, root, remainder);
    cout << complement->key << " " << numLevels << endl;


}




