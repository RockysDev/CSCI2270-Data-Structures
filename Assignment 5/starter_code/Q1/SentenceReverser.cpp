#include <iostream>
#include "SentenceReverser.hpp"

using namespace std;

SentenceReverser::SentenceReverser()
{
    stackHead = NULL;
    stackHead->word = "";
}

SentenceReverser::~SentenceReverser()
{
    //TODO
    Word *temp;
    while(!isEmpty()){
        temp = stackHead;
        stackHead = stackHead->next;
        delete temp;

    }
}

bool SentenceReverser::isEmpty()
{
	//TODO
    if(stackHead == NULL){
        return true;
    }
    else{
        return false;
    }
}

void SentenceReverser::push(string word)
{
    Word *temp = new Word;
    temp->word = word;
    if(isEmpty()){
        stackHead = temp;
        stackHead->next = nullptr;
    }
    else{
        temp->next = stackHead;
        stackHead = temp;
    }
}

string SentenceReverser::pop()
{
    //TODO
    if(stackHead != NULL){
        Word *temp = stackHead;
        string res = temp->word;
        stackHead = temp->next;
        delete temp;
        return res;
    }
    else{
        cout << "Stack empty, cannot pop a word." << endl;
        return "";
    }
}

Word* SentenceReverser::peek()
{
    if(stackHead != NULL){
        return stackHead;
    }
    
    else{
        cout << "Stack empty, cannot peek." << endl;
    }
}

void SentenceReverser::evaluate(string* s, int size)
{
    /*TODO: 1. Scan the array s from start
            2. Check for opening and closing brackets.
            3. Push each element on the stack till you encounter a "]"
            4. Then keep popping (& processing) from the stack till you get a "[".
            5. Handle the boundery cases as required.
            6. Read the writeup for more details. Another example is in Appendix 2.
    */
   int numBracketsOpen = 0;
   for(int i=0;i<size;i++){
       if(s[i] == "["){
           numBracketsOpen++;
       }
       if(s[i] == "]"){
           numBracketsOpen--;
       }
    }
    if(numBracketsOpen != 0){
        cout << "err: Invalid String" << endl;
    }

}

