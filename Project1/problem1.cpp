#include <iostream>
#include <array>
#include <fstream>


using namespace std;

int addToArrayAsc(float sortedArray[], int numElements, float newValue){
    float swap;
    sortedArray[numElements] = newValue;
    numElements++;
    for(int i=0;i<numElements-1;i++){
        for(int j=i+1;j<numElements;j++){
            if(sortedArray[i]>sortedArray[j]){
                swap = sortedArray[i];
                sortedArray[i] = sortedArray[j];
                sortedArray[j] = swap;
            }
        }
    }
    return numElements;
}
