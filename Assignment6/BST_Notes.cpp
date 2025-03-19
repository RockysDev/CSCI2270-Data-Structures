Node* BST::deleteNode(Node*currnode, int value){
    if(currNode == NULL){
        return NULL;
    }
    else if(value <currNode.key){
        currNode.left = deleteNode(currNode.left, value);
    }
    else if(value > currNode.key){
        currNode.right = deleteNode(currnode.right)
    }
    else {
        if(currnode.left == NULL && currnode.right == NULL){
            // Delete node
        }
        else if(currNode.left == NULL){
            // create temp ptr and assign it to the current node
            // change the pointer to the right child
        }
        else if (currnode.right == NULL){
            // create temp ptr and assign it to the current node
            // change the pointer to the left child
        }
        else{
            // get the minimum value from the right subtree
            // call delete node recursively on the right of the current
        }
        return currNode
    }
}

getminvalueNode(node* currnode){
    if(currnode.left == NULL){
        return currNode
    }
    return getMinvalueNode(currnode.left)
}

Red and Black //trees
// each node has color, red or black
// each node has traits
    -color
-The root node is black