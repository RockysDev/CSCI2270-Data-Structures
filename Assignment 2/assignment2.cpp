#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct wordRecord{
    string word;
    int count;
};

void getCommonWords(const char *commonWordFileName, string* commonWords)
{
    string line;
    ifstream inWords;
    inWords.open(commonWordFileName);
    if(inWords.fail()){
        cout << "Failed to open " << commonWordFileName << endl;
    }
    for(int i=0;i<50;i++){
        getline(inWords, line);
        commonWords[i] = line;
    }
    inWords.close();
    return;
}

bool isCommonWord(string word, string* commonWords)
{
    for(int i=0;i<50;i++){
        if(commonWords[i] == word){
            return true;
        }

    }
    return false;
}

int getTotalNumberUncommonWords(wordRecord* distinctWords, int length)
{
    int total = 0;
    for(int i=0;i<length;i++){
        total += distinctWords[i].count;

    }
    return total;
}

void sortArray(wordRecord* distinctWords, int length)
{
    wordRecord swap;
        for(int i=0;i<length-1;i++){
            for(int j=i+1;j<length;j++){
                if(distinctWords[i].count<distinctWords[j].count){

                    swap = distinctWords[j];
                    distinctWords[j] = distinctWords[i];
                    distinctWords[i] = swap;
                }
                else if(distinctWords[i].count == distinctWords[j].count){
                    if(distinctWords[i].word>distinctWords[j].word){
                        swap = distinctWords[j];
                        distinctWords[j] = distinctWords[i];
                        distinctWords[i] = swap;
                    }
                }
            }
        }
    return;
}

void printNFromM(wordRecord* distinctWords, int M, int N, int totalNumWords)
{
    float prob;
    for(int i=M;i<M+N;i++){
        prob = float(distinctWords[i].count) / float(totalNumWords);
        cout << setprecision(5) << fixed;
        cout << prob << " - " << distinctWords[i].word << endl;
    }
}

int split(string stringSplit, char delimiter, string array[], int arraySize){
    int splits = 0, z = 0, wordCount = 0;
    int subLength;
    string sub;
    stringSplit += ",";
    for (int i = 0; i < stringSplit.length(); i++){
        subLength++;
        if(stringSplit[i] == delimiter){
            sub = stringSplit.substr(z, subLength - 1);
            array[wordCount] = sub;
            wordCount++;
            z = i + 1;
            subLength = 0;
        }
    }
    return wordCount;
}

//g++ Problem1 -std=c++11 -o Problem1
//./Problem1 greatgatsby commonwords.txt 0 5

wordRecord* resize(wordRecord* arrayPtr, int &capacity)
{
	// TODO increase the capacity by two times
	int newCapacity = 2 * capacity;
    cout<<"Resizing from "<<capacity<<" to "<<newCapacity<<endl;

	// TODO dynamically allocate an array of size newCapacity
	wordRecord *newArray = new wordRecord[newCapacity];

	for(int i=0;i<capacity;i++){
		newArray[i] = arrayPtr[i];
	}

	delete[] arrayPtr;

	capacity = newCapacity;

	// TODO return the newArray
	return newArray;
}
//g++ Problem1 -std=c++11 -o Problem1
//./Assignment2 greatgatsby.txt commonWords.txt 0 10

int main(int argc, char* argv[])
{
	if(argc != 5)
	{
		return -1;
	}
    string commonWords[50];
    getCommonWords((char*)argv[2], commonWords);
    // for(int m=0;m<50;m++){
    //     cout << commonWords[m] << endl;
    // }
	ifstream data;
	data.open(argv[1]);

	int capacity = 100;
	wordRecord *arrayPtr;
	arrayPtr = new wordRecord[capacity];
	int numOfElement = 0;
    int newCapacity;
    int numResize = 0;
    string singleWord;
	if(data.is_open())
	{
		while(data >> singleWord)
		{
		    // cout << singleWord << endl;
            if(numOfElement == capacity)
			{
			    // cout << "needs to be resized" << endl;
				newCapacity = 2 * capacity;
                wordRecord *newArray = new wordRecord[newCapacity];

                for(int i=0;i<capacity;i++){
                    newArray[i] = arrayPtr[i];
                }
                delete[] arrayPtr;
                arrayPtr = nullptr; // for safety
                arrayPtr = newArray;
                capacity = newCapacity;
                numResize++;
                // cout << "it has been resized" << endl;
			}
            if(!isCommonWord(singleWord, commonWords)){
                // cout << "is not a commmon word" << endl;
                bool added = false;
                for(int p=0;p<numOfElement;p++){
                    if(singleWord == arrayPtr[p].word){ //if(singleWord == arrayPtr[p].word){
                        arrayPtr[p].count++;
                        added = true;
                         // arrayPtr[p].count++;
                    }
                }
                if(!added){
                    arrayPtr[numOfElement].word = singleWord;
                    arrayPtr[numOfElement].count = 1;
                    numOfElement++;
                }
            }
		}
        data.close();
	}
    else{
        cout << "Could not open the book file" << endl;
    }
    sortArray(arrayPtr, numOfElement);
    cout << "Array doubled: " << numResize << endl;
    cout << "Distinct uncommon words: " << numOfElement << endl;
    int totality = getTotalNumberUncommonWords(arrayPtr, numOfElement);
    cout << "Total uncommon words: " << totality << endl;
    cout << "Probability of next " << argv[4] << " words from rank " << argv[3] << endl;
    cout << "---------------------------------------" << endl;
    printNFromM(arrayPtr, stoi(argv[3]), stoi(argv[4]), totality);
}