#include <iostream>
#include "removeOdds.hpp"

using namespace std;

int main()
{
	//*****************************************************
	// test case 1
	//*****************************************************
	int size = 6;
    int *arrayPtr = new int[size]{-7, 20, 14, 3, 5, 9};

    //TODO Complete this function
    removeOddsValue(arrayPtr, size);
    
    cout << "Testcase 1: Expected result: ";
    int arr[] = {20, 14};
	for(int i = 0; i < 1; i++){
		cout << arr[i] << ", ";
	}
    cout << arr[1] << endl;

    cout << "Your result: ";
    if(size == 0) cout << endl;
	else{
        for(int i = 0; i < size-1; i++){
            cout << arrayPtr[i] << ", ";
        }
        cout << arrayPtr[size-1] << endl;
        delete [] arrayPtr;
    }

	//*****************************************************
	// test case 2
	//*****************************************************
    size = 4;
    int *arrayPtr2 = new int[size]{-7, 2, 4, 9};

    removeOddsValue(arrayPtr2, size);
    
    cout << "Testcase 2: Expected result: ";
    int arr2[] = {2, 4};
	for(int i = 0; i < 1; i++){
		cout << arr2[i] << ", ";
	}
    cout << arr2[1] << endl;

    cout << "Your result: ";
    if(size == 0) cout << endl;
	else{
        for(int i = 0; i < size-1; i++){
            cout << arrayPtr2[i] << ", ";
        }
        cout << arrayPtr2[size-1] << endl;
        delete [] arrayPtr2;
    }

	//*****************************************************
	// test case 3
	//*****************************************************
    size = 0;
    int *arrayPtr3 = new int[size]{};
    removeOddsValue(arrayPtr3, size);
    
    cout << "Testcase 3: Expected result: ";
    cout << endl;


    cout << "Your result: ";
    if(size == 0) cout << endl;
	else{
        for(int i = 0; i < size-1; i++){
            cout << arrayPtr3[i] << ", ";
        }
        cout << arrayPtr3[size-1] << endl;
        delete [] arrayPtr3;
    }

	//*****************************************************
	// Add additional test cases here (e.g. edge cases)
	//*****************************************************
 
    return 0;
}
