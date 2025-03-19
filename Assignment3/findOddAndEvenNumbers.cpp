#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

void findOddAndEvenNumbers(int* numbers, int*& odd, int*& even, int length, int &numOdd, int&numEven)
{
    for(int i=0;i<length;i++){
        if(numbers[i] % 2 == 0){
            numEven++;
        }
        else{
            numOdd++;
        }
    }
    if(numEven == 0){
        even = NULL;
    }
    if(numOdd == 0){
        odd = NULL;
    }
    odd = new int[numOdd];
    even = new int[numEven];
    numOdd = 0;
    numEven = 0;
    for(int i=0;i<length;i++){
        if(numbers[i] % 2 == 0){
            even[numEven] = numbers[i];
            numEven++;
        }
        else{
            odd[numOdd] = numbers[i];
            numOdd++;
        }
    }
}

SocialMediaProfile* SocialMediaNetwork::searchForProfile(string profileName)
{
    // Complete the function
}