#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include <cstddef>

using namespace std;

int main()
{
	//*****************************************************
	// test case 1
	//*****************************************************
	int testll[] = {9, 8, 6, 4, 3};
	LinkedList ll;
	int n = 5;
	for(int i = 0; i<n; i++){
		ll.insertNode(0,testll[i]);
	}
	cout << "\n------------------------------------------\n";

	cout << "Test Case 1:" << endl; 
	cout << "original >> ";
	ll.printList();

	/* Call to searchLastMoveMiddle function  */
	ll.searchLastMoveMiddle();
	cout << "\nexpected >> 3 4 9 6 8" << endl;
	cout << "result   >> ";
	ll.printList();

	cout << "\n------------------------------------------\n";


	//*****************************************************
	// test case 2
	//*****************************************************
	int testll2[] = {7, 10, 6, 8, 4, 6, 21, 22};
	LinkedList ll2;
	n = 8;
	for(int i = 0; i<n; i++){
		ll2.insertNode(0,testll2[i]);
	}
	cout << "\n------------------------------------------\n";

	cout << "Test Case 2:" << endl; 
	cout << "original >> ";
	ll2.printList();

	/* Call to searchLastMoveMiddle function  */
	ll2.searchLastMoveMiddle();
	cout << "\nexpected >> 22 21 6 4 7 8 6 10" << endl;
	cout << "result   >> ";
	ll2.printList();

	cout << "\n------------------------------------------\n";\


	//*****************************************************
	// test case 3
	//*****************************************************
	int testll3[] = {5, 6};
	LinkedList ll3;
	n = 2;
	for(int i = 0; i<n; i++){
		ll3.insertNode(0,testll3[i]);
	}
	cout << "\n------------------------------------------\n";

	cout << "Test Case 3:" << endl; 
	cout << "original >> ";
	ll3.printList();

	/* Call to searchLastMoveMiddle function  */
	ll3.searchLastMoveMiddle();
	cout << "\nexpected >> 6 5" << endl;
	cout << "result   >> ";
	ll3.printList();

	cout << "\n------------------------------------------\n";


	//*****************************************************
	// Add additional test cases here (e.g. edge cases)
	//*****************************************************

	return 0;
}
