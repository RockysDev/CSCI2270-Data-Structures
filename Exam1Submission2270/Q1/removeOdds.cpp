#include <iostream>
#include "removeOdds.hpp"

using namespace std;

/* DO NOT MODIFY */
int countOdds(int array[], int size){
    int nOdds = 0;

    for(int i=0; i<size; i++){
        if(array[i]%2 != 0) 
            nOdds++;
    }

    return nOdds;
}

/* Complete this function but do not modify the parameters or add new ones */
void removeOddsValue(int *&arrayPtr, int &size)
{
   if(size == 0){ // return if empty
       return;
   }
   int numEven = size - countOdds(arrayPtr, size); // find num even by subtracting the size of array from numOdds
   int *evenArr = new int[numEven]; // new array of correct size;

   int j = 0; 

   for(int i=0;i<size;i++){ // for each num in arrayptr
       if(arrayPtr[i]%2 == 0){ // if arrayptr index is even
            evenArr[j] = arrayPtr[i]; // taking arrayptr index and saving in evenArr
            j++;
       }
   }
   size = j; // setting the size of arrayPtr to the new size
    // Deleting and freeing the memory of arrayPtr
   delete [] arrayPtr; 
   arrayPtr = nullptr; // free memory

   arrayPtr = new int[numEven];
   arrayPtr = evenArr; // making arrayPtr the new array with only evens

}
/* You are welcome to add helper functions */