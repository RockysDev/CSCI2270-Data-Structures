#include <iostream>
#include <array>
#include <string>
#include <fstream>


using namespace std;



struct studentData {
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length){
    students[length].studentName = studentName;
    students[length].homework = homework;
    students[length].recitation = recitation;
    students[length].quiz = quiz;
    students[length].exam = exam;
    students[length].average = (homework + recitation + quiz + exam) / 4.0;
}

char calcLetter(double a){
    char grade;
    if(a >= 90){
        grade = 'A';
    }
    else if(a >= 80 && a <=89.9){
        grade = 'B';
    }
    else if(a >= 70 && a <=79.9){
        grade = 'C';
    }
    else if(a >= 60 && a <=69.9){
        grade = 'D';
    }
    else{
        grade = 'F';
    }
    return grade;
}

void printList(const studentData students[], int length){
    for(int i=0;i<length;i++){
        cout << students[i].studentName << " earned " << students[i].average << " which is a(n) " << calcLetter(students[i].average) << endl;
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

int getUpperBound(string letter){
    if(letter == "A"){
        return 100;
    }
    else if(letter == "B"){
        return 89;
    }
    else if(letter == "C"){
        return 79;
    }
    else{
        return 69;
    }
}

int getLowerBound(string letter){
    if(letter == "B"){
        return 80;
    }
    else if(letter == "C"){
        return 70;
    }
    else if(letter == "D"){
        return 60;
    }
    else{
        return 0;
    }
}

int main(int argc, char* argv[]){
    studentData students[10];
    string storage[50];
    ifstream input;
    ofstream output;
    string line;
    string filename = argv[1];
    string file_output = argv[2];
    string lowerBound = argv[3];
    string higherBound = argv[4];

    input.open(filename);
    if(input.fail()){
        cout << "Failed to open file" << endl;
    }
    int x = 0;
    int numStudents = 0;
    while(getline(input, line)){
        split(line, ',', storage, 5);
        addStudentData(students, storage[0], stoi(storage[1]), stoi(storage[2]), stoi(storage[3]), stoi(storage[4]), numStudents);
        numStudents++;
    }
    input.close();
    printList(students, numStudents);
    output.open(file_output);
    for(int i=0;i<numStudents;i++){
        if(students[i].average >= getLowerBound(lowerBound) && students[i].average <= getUpperBound(higherBound)){
            output << students[i].studentName << "," << students[i].average << "," << calcLetter(students[i].average) << endl;
        }
    }

}
