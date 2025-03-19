#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// int addToArrayAsc(float sortedArray[], int numElements, float newValue){
//     float swap;
//     sortedArray[numElements] = newValue;
//     numElements++;
//     for(int i=0;i<numElements-1;i++){
//         for(int j=i+1;j<numElements;j++){
//             if(sortedArray[i]>sortedArray[j]){
//                 swap = sortedArray[i];
//                 sortedArray[i] = sortedArray[j];
//                 sortedArray[j] = swap;
//             }
//         }
//     }
//     return numElements;
// }

struct studentData {
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

//correct
void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length){
    studentData student;
    student.studentName = studentName;
    student.homework = homework;
    student.recitation = recitation;
    student.quiz = quiz;
    student.exam = exam;
    student.average = (homework + recitation + quiz + exam) / 4.0;
    students[length] = student;
    return;
}

char calcLetter(double a){
    char grade;
    if(a >= 90){
        grade = 'A';
    }
    else if(a >= 80){
        grade = 'B';
    }
    else if(a >= 70){
        grade = 'C';
    }
    else if(a >= 60){
        grade = 'D';
    }
    else{
        grade = 'F';
    }
    return grade;
}

void printList(const studentData students[], int length){ // correct
    for(int i=0;i<length-1;i++){
        cout << students[i].studentName << " earned " << students[i].average << " which is a(n) " << calcLetter(students[i].average) << endl;
    }
    return;
}

// int split(string stringSplit, char delimiter, string array[], int arraySize){
//     int splits = 0, z = 0, wordCount = 0;
//     int subLength;
//     string sub;
//     stringSplit += ",";
//     for (int i = 0; i < stringSplit.length(); i++){
//         subLength++;
//         if(stringSplit[i] == delimiter){
//             sub = stringSplit.substr(z, subLength - 1);
//             array[wordCount] = sub;
//             wordCount++;
//             z = i + 1;
//             subLength = 0;
//         }
//     }
//     return wordCount;
// }

int getUpperBound(char letter){
    if(letter == 'A'){
        return 100;
    }
    else if(letter == 'B'){
        return 90;
    }
    else if(letter == 'C'){
        return 80;
    }
    else if(letter == 'D'){
        return 70;
    }
    else{
        return 60;
    }
    return 60;
}

int getLowerBound(char letter){
    if(letter == 'A'){
        return 90;
    }
    else if(letter == 'B'){
        return 80;
    }
    else if(letter == 'C'){
        return 70;
    }
    else if(letter == 'D'){
        return 60;
    }
    else{
        return 0;
    }
    return 0;
}

int main(int argc, char* argv[]){
    ifstream in_file;
    ofstream out_file;
    string filename = argv[1];
    string outFile = argv[2];
    char lowGrade = *argv[3];
    char highGrade = *argv[4];

    in_file.open(filename);
    out_file.open(outFile);

    int low = getLowerBound(lowGrade);
    int high = getUpperBound(highGrade);

    studentData students[15];
    // studentData newstu;
    // newstu.average
    int count = 0;

    string name, homework, rec, quiz, exam;

    //for each bozo read info and convert to ints if need
    while(!in_file.eof()){
        getline(in_file, name, ',');
        // cout << name << endl;
        getline(in_file, homework, ',');
        getline(in_file, rec, ',');
        getline(in_file, quiz, ',');
        getline(in_file, exam, '\n');

        int inthomework = stoi(homework);
        int intrec = stoi(rec);
        int intquiz = stoi(quiz);
        int intexam = stoi(exam);

        addStudentData(students, name, inthomework, intrec, intquiz, intexam, count);
        //increase size
        count++;
    }
    in_file.close();
    printList(students, count);
    //for each student write name, average, and their final grade
    for(int i=0;i<count-1;i++){
        if(students[i].average <= high && students[i].average >= low){
            out_file << students[i].studentName << ",";
            out_file << students[i].average << ",";
            out_file << calcLetter(students[i].average) << endl;
        }
    }
    out_file.close();
    return 0;
}

