#include "EmployeeDirectory.hpp"

// [HELPER FUNCTIONS]
char EmployeeDirectory::getLastInitial(string name) {
    int found_ix = name.find(' ');

    if (found_ix != string::npos)
        return name[found_ix + 1];

    return '\0';
}

void EmployeeDirectory::printEmployee(LLNode* n) {
    if (n == NULL) {
        cout << "LLNode is NULL." << endl;
    }
    else {
        cout << "Employee Information" << endl;
        cout << "====================" << endl;
        cout << "ID     : " << n->empId << endl;
        cout << "Name   : " << n->empName << endl;
        cout << "Level  : " << n->empLevel << endl;
        cout << "Phone  : " << n->empPhone << endl;
        cout << "Joined : " << n->empJoiningYear << endl;
    }
}


// [TO BE IMPLEMENTED]
// ----------------------------------------------------------------------------

EmployeeDirectory::EmployeeDirectory() {
    // TODO
    root = NULL;

}

// ----------------------------------------------------------------------------
void bstLLNodeDestruct(TreeNode* currNode){
    if(currNode != NULL){
        bstLLNodeDestruct(currNode->left);
        bstLLNodeDestruct(currNode->right);
        LLNode* currNext = currNode->head;
        LLNode* prev = NULL;
        while(currNext != NULL){
            prev = currNext;
            currNext = currNext->next;
            delete prev;
        }
        delete currNode;
    }
}

EmployeeDirectory::~EmployeeDirectory() {
    // TODO
    if(root != NULL){
        bstLLNodeDestruct(root);
    }
}

// ----------------------------------------------------------------------------

TreeNode* searchCharNodeHelper(char key, bool &found, TreeNode* currNode){
    if(currNode->lastInitial == key){
        found = true;
        return currNode;
    }
    else{
        if(currNode->lastInitial > key){
            if(currNode->left != NULL){
                searchCharNodeHelper(key, found, currNode->left);
            }
        }
        else if(currNode->lastInitial < key){
            if(currNode->right != NULL){
                searchCharNodeHelper(key, found, currNode->right);
            }
        }
    }
}

TreeNode* EmployeeDirectory::searchCharNode(char key) {
    // TODO
    if(root == NULL){
        // cout << "1" << endl;
       // cout << "Root is NULL" << endl;
       return NULL;
   }
   bool found = false;
   TreeNode* result = searchCharNodeHelper(key, found, root);
   if(found == false){
       return NULL;
   }
   return result;
}

// ----------------------------------------------------------------------------
void showEmployeeDirectoryHelper(TreeNode* currNode){
    if(currNode == NULL){
        return;
    }
    showEmployeeDirectoryHelper(currNode->left);
    if(currNode->parent == NULL){
        cout << "[Employees with lastInitial=" << currNode->lastInitial << ", parent= ]" << endl;
    }
    else{
        cout << "[Employees with lastInitial=" << currNode->lastInitial << ", parent=" << currNode->parent->lastInitial << "]" << endl;
    }
    if(currNode->head != NULL){
        LLNode* currLL = currNode->head;
        while(currLL != NULL){
            cout << "> " << currLL->empName<< ", " << currLL->empPhone << ", " << currLL->empId << endl;
            currLL = currLL->next;
        }
    }
    else{
        cout << "No employees found." << endl;
    }
    cout << "---------------------------------------" << endl;
    showEmployeeDirectoryHelper(currNode->right);
}

void EmployeeDirectory::showEmployeeDirectory() {
    // TODO
    if(root == NULL){
        return;
    }
    showEmployeeDirectoryHelper(root);
}

// ----------------------------------------------------------------------------

LLNode* EmployeeDirectory::searchEmployee(int empId, string empName) {
    // TODO
    char key = getLastInitial(empName); 
    TreeNode* temp = searchCharNode(key);
    if(root == NULL){
        return NULL;
    }
    if(temp != NULL){
        LLNode* traverse = temp->head;
        while(traverse != NULL){
            if(traverse->empId == empId){
                return traverse;
            }
            traverse = traverse->next;
        }
        return NULL;
    }
    else{
        return NULL;
    }
}

// ----------------------------------------------------------------------------

// char EmployeeDirectory::getLastInitial(string name) {
//     int found_ix = name.find(' ');

//     if (found_ix != string::npos)
//         return name[found_ix + 1];

//     return '\0';
// }

void EmployeeDirectory::insertEmployee(int empId, string empName, int empLevel, string empPhone, int empJoiningYear) {
    // TODO
    char key = getLastInitial(empName); 
    TreeNode* temp = searchCharNode(key); // find if tree node exists for last initial
    if(root == NULL){ // tree empty set new insert as root
        LLNode* newInsert = new LLNode(empId, empName, empLevel, empPhone, empJoiningYear);
        TreeNode* newNode = new TreeNode(key);
        newNode->head = newInsert;
        root = newNode;
        return;
    }
    if(temp == NULL){ // did not find tree node for LLNode
        // create new node
        LLNode* newInsert = new LLNode(empId, empName, empLevel, empPhone, empJoiningYear);
        TreeNode* newNode = new TreeNode(key);
        newNode->head = newInsert;
        TreeNode* temp = root;
        while(temp != NULL){ // finding spot for newInsert
            if(temp->lastInitial > key){
                if(temp->left == NULL){
                    newNode->parent = temp;
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    newNode->parent = temp;
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }
    else{ // found tree node
        LLNode* newInsert = new LLNode(empId, empName, empLevel, empPhone, empJoiningYear);
        LLNode* prev = NULL;
        LLNode* pres = temp->head;
        if(temp->head->empId > empId){ // if new insert belongs as head in tree node
            newInsert->next = temp->head;
            temp->head = newInsert;
            return;
        }
        else{
            while(pres != NULL){ // else find spot to insert LL
                if(pres->empId > empId){
                    prev->next = newInsert;
                    newInsert->next = pres;
                    return;
                }
                prev = pres;
                pres = pres->next;
            }
            if(pres == NULL){ // If new insert needs to be put last in linked list of tree
                prev->next = newInsert;
                newInsert->next = NULL;
                return;
            }
        }
    }
    return;
}

// ----------------------------------------------------------------------------

void EmployeeDirectory::removeEmployee(int empId, string empName) {
    char key = getLastInitial(empName); 
    TreeNode* temp = searchCharNode(key);
    if(root == NULL){
        cout << "Employee not found." << endl;
        return;
    }
    if(temp != NULL){ // if there is treeNode with employee last initial
        LLNode* front = temp->head;
        LLNode* prev = NULL;
        if(temp->head->empId == empId){
            temp->head = temp->head->next;
            // cout << "Deletion Successful" << endl;
            // cout << "1 " << endl;
            delete front;
            return;
        }
        while(front != NULL){
            if(front->empId == empId){
                prev->next = prev->next->next;
                // cout << "Deletion Successful" << endl;
                // cout << "2" << endl;
                delete front;
                return;
            }
            prev = front;
            front = front->next;
        }
        cout << "Employee not found." << endl;
    }
    else{
        cout << "Employee not found." << endl;
        return;
    }
}

// ----------------------------------------------------------------------------

void EmployeeDirectory::leftRotate(TreeNode* curr) {
    // TODO
    TreeNode* y = curr->right;
    if(root == NULL){
        return;
    }
    if(curr == root){
        root = y;
        y->parent = NULL;
        curr->right = y->left;
        y->left = curr;
        if(curr->right != NULL){
            curr->right->parent = curr;
        }
        curr->parent = y;
        return;
    }
    else{
        if(y->lastInitial < curr->parent->lastInitial){
            y->parent = curr->parent;
            curr->parent->left = y;
        }
        else{
            y->parent = curr->parent;
            curr->parent->right = y;
        }
    }
    curr->right = y->left;
    if(curr->right != NULL){
        curr->right->parent = curr;
    }
    curr->parent = y;
    y->left = curr;
}

// ----------------------------------------------------------------------------
