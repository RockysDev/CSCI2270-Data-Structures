#include "EmployeeTree.hpp"

EmployeeTree::EmployeeTree() {
    root = NULL;
}

void bstDestruct(EmployeeNode* currNode){
    if(currNode != NULL){
        bstDestruct(currNode->left);
        bstDestruct(currNode->right);
        delete currNode;
    }
}

EmployeeTree::~EmployeeTree(){
    if(root != NULL){
        bstDestruct(root);
    }
}

void postOrderTraversal(EmployeeNode* currNode){
    if(currNode == NULL){
        return;
    }
    postOrderTraversal(currNode->left);
    cout << currNode->empId << ", " << currNode->empName << endl;
    postOrderTraversal(currNode->right);
}


void EmployeeTree::printEmployeeDirectory() {
    //TODO
    if(root == nullptr){
        cout << "Tree is Empty. Cannot print." << endl;
        return;
    }
    postOrderTraversal(root);
}

void addNodeHelper(EmployeeNode* currNode, int empId, string empName, int empLevel, string empPhone, int empJoiningYear){
    if(currNode == NULL){
        return;
    }
    else{
        if(currNode->empId > empId){
            if(currNode->left == NULL){
                EmployeeNode* temp = new EmployeeNode;
                temp->empId = empId;
                temp->empName = empName;
                temp->empLevel = empLevel;
                temp->empJoiningYear = empJoiningYear;
                temp->empPhone = empPhone;
                temp->left = temp->right = NULL;
                currNode->left = temp;
            }
            else{
                addNodeHelper(currNode->left, empId, empName, empLevel, empPhone, empJoiningYear);
            }
        }
        else if(currNode->empId < empId){
            if(currNode->right == NULL){
                EmployeeNode* temp = new EmployeeNode;
                temp->empId = empId;
                temp->empName = empName;
                temp->empLevel = empLevel;
                temp->empJoiningYear = empJoiningYear;
                temp->empPhone = empPhone;
                temp->left = temp->right = NULL;
                currNode->right = temp;
            }
            else{
                addNodeHelper(currNode->right, empId, empName, empLevel, empPhone, empJoiningYear);
            }
        }
    }
}


void EmployeeTree::addEmployee(int empId, string empName, int empLevel, string empPhone, int empJoiningYear){
    if(root == NULL){
        EmployeeNode* temp = new EmployeeNode;
        temp->empId = empId;
        temp->empName = empName;
        temp->empLevel = empLevel;
        temp->empJoiningYear = empJoiningYear;
        temp->empPhone = empPhone;
        temp->left = temp->right = NULL;
        root = temp;
    }
    else{
        addNodeHelper(root, empId,empName, empLevel, empPhone, empJoiningYear);
    }
}

void findEmployeeHelper(EmployeeNode* currNode, int empId, bool &found){
    if(empId == currNode->empId){
        cout << "Employee Information" << endl;
        cout << "====================" << endl;
        cout << "ID     : " << currNode->empId << endl;
        cout << "Name   : " << currNode->empName << endl;
        cout << "Level  : " << currNode->empLevel << endl;
        cout << "Phone  : " << currNode->empPhone << endl;
        cout << "Joined : " << currNode->empJoiningYear << endl;
        found = true;
        return;

    }
    else{
        if(currNode->empId > empId){
            if(currNode->left != NULL){
                findEmployeeHelper(currNode->left, empId, found);
            }
        }
        else if(currNode->empId < empId){
            if(currNode->right != NULL){
                findEmployeeHelper(currNode->right, empId, found);
            }
        }
    }
}

void EmployeeTree::findEmployee(int empId){
   if(root == NULL){
        // cout << "1" << endl;
       cout << "Employee not found." << endl;
       return;
   }
   bool printed = false;
   findEmployeeHelper(root, empId, printed);
    if(printed == false){
        // cout << "2" << endl;
        cout << "Employee not found." << endl;
        return;
    }
}

void queryEmployeesHelper(EmployeeNode* currNode, int level, int year, bool &found){
    if(currNode->empLevel >= level && currNode->empJoiningYear > year){
        cout << "====================" << endl;
        cout << "ID     : " << currNode->empId << endl;
        cout << "Level  : " << currNode->empLevel << endl;
        cout << "Joined : " << currNode->empJoiningYear << endl;
        found = true;
    }
    if(currNode->left != NULL){
        queryEmployeesHelper(currNode->left, level, year, found);
    }
    if(currNode->right != NULL){
        queryEmployeesHelper(currNode->right, level, year, found);
    }
}

void EmployeeTree::queryEmployees(int level, int year)
{
    cout << "Employees who joined after " << year << " and are at least at level " << level << ":" << endl;
    // Preorder root left right
    if(root == NULL){
        cout << "Tree is Empty. Cannot query employees directory" << endl;
        return;
    }
    bool printed = false;
    queryEmployeesHelper(root, level, year, printed);
    if(printed == false){
        // cout << "2" << endl;
        cout << "Employee not found." << endl;
        return;
    }
}


void printLevelNodesHelper(EmployeeNode* currNode, int count, int level){
    if(currNode == NULL){
        return;
    }
    if(count == level){
        cout << currNode->empId << ", " << currNode->empName << endl;
        return;
    }
    else{ 
        count++;
        printLevelNodesHelper(currNode->left, count, level);
        printLevelNodesHelper(currNode->right, count, level);
    }
}

void EmployeeTree::printLevelNodes(int node_level){
    EmployeeNode* temp = root;
    int numLevels = 0;
    while(temp->right != NULL){
        numLevels+=1;
        temp = temp->right;
    }
    numLevels+=1;
    if(node_level > numLevels){
        return;
    }
    if(root != NULL){
        printLevelNodesHelper(root, 0, node_level);
    }
}


void getKthLowestEmployeeIDHelper(EmployeeNode* currNode, int &k, int &result){
    if(currNode != nullptr){
        getKthLowestEmployeeIDHelper(currNode->left, k, result);
        if(k == 1){
            result = currNode->empId;
            k=0;
            return;
        }
        k--; // Keeps going all the way to left then right
        getKthLowestEmployeeIDHelper(currNode->right, k, result);
    }
}

int EmployeeTree::getKthLowestEmployeeID(int k){
    int result = 0;
    // int result = int getKthLowestEmployeeIDHelper(root, result, k);
    getKthLowestEmployeeIDHelper(root, k, result);
    return result;
}