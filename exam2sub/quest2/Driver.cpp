#include <iostream>
#include "BST.hpp"
using namespace std;

int main (int argc, char* argv[]){
  cout << "Creating tree" << endl;
  BST tree(8);

  tree.addNode(3); //left child to 8
  tree.addNode(1); //left child to 3
  tree.addNode(6); //right child to 3
  tree.addNode(4); //left child to 6
  tree.addNode(7); //right child to 6

  tree.addNode(10); //right child to 8
  tree.addNode(14); //right child of 10
  tree.addNode(13); // left child of 14

  cout << "----------------Testcase-1---------------" << endl;
  cout << "4 + x = 14" << endl;
  cout << endl;
  cout << "[GOT     ] ";
  tree.getNodeWithTargetSumAndLevel(4, 14);  
  cout << "[EXPECTED] 10 2" << endl;
  cout << endl;

  cout << "----------------Testcase-2---------------" << endl;
  cout << "9 + x = 22" << endl;
  cout << endl;
  cout << "[GOT     ] ";
  tree.getNodeWithTargetSumAndLevel(9, 22);
  cout << "[EXPECTED] Input key not found in BST" << endl;
  cout << endl;

  cout << "Creating tree with no duplicate nodes" << endl;
  BST tree2(8);

  tree2.addNode(3); //left child to 8
  tree2.addNode(1); //left child to 3
  tree2.addNode(6); //right child to 3
  tree2.addNode(4); //left child to 6
  tree2.addNode(7); //right child to 6

  tree2.addNode(10); //right child to 8
  tree2.addNode(14); //right child of 10
  tree2.addNode(13); // left child of 14

  cout << "----------------Testcase-3---------------" << endl;
  cout << "10 + x = 17" << endl;
  cout << endl;
  cout << "[GOT     ] ";
  tree2.getNodeWithTargetSumAndLevel(10, 17);
  cout << "[EXPECTED] 7 4" << endl;
  cout << endl;

  cout << "Creating tree with duplicate nodes" << endl;
  BST tree3(15);
  
  tree3.addNode(4); //left child to 15
  tree3.addNode(17); //right child to 15
  tree3.addNode(5); //right child to 4
  tree3.addNode(4); //left child to 5

  tree3.addNode(16); //left child to 17
  tree3.addNode(20); //right child to 17
  tree3.addNode(18); //left child to 20
  tree3.addNode(23); //right child to 20
  tree3.addNode(20); //left child to 23

  cout << "----------------Testcase-4---------------" << endl;
  cout << "5 + x = 9" << endl;
  cout << endl;
  cout << "[GOT     ] ";
  tree3.getNodeWithTargetSumAndLevel(5, 9);
  cout << "[EXPECTED] 4 4" << endl;
  cout << endl;

  cout << "----------------Testcase-5---------------" << endl;
  cout << "5 + x = 12" << endl;
  cout << endl;
  cout << "[GOT     ] ";
  tree3.getNodeWithTargetSumAndLevel(5, 12);
  cout << "[EXPECTED] There are no nodes that sum up to the target using the input key" << endl;
  cout << endl;

  return 0;
}