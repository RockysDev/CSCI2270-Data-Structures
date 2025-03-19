#include <iostream>
#include <fstream>
#include <string>

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

int main(int argc, char* argv[]){
    // 2 b
    // cout << l << argv[0] <<" --- " << argv[1] << " --- " << argv[2] << endl;

    string filename = argv[1];

    float arr[100];
    int count = 0;

    ifstream in_file;
    in_file.open(filename);
    
    if(in_file.fail()){
        cout << "Failed to open the file." << endl;
        return 0;
    }
    
    string value;

    while(!in_file.eof()){
        getline(in_file, value, '\r');
        // cout << value << endl;
        float insert = stof(value);
        addToArrayAsc(arr, count, insert);
        count++;
        for(int i=0;i<count;i++){
            if(i!=count-1){
                cout << arr[i] << ",";
            }
            else{
                cout << arr[i] << endl;
            }
        }
    }
    in_file.close();
    return 0;
}