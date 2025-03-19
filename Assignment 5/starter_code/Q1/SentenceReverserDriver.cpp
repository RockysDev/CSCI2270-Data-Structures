#include <iostream>
#include <cmath>
#include <iomanip>
#include "SentenceReverser.hpp"

using namespace std;

int main()
{
  // stack to hold the elements
  SentenceReverser stack;

  int numElement = 0; 
  string* inparr = new string[50];

  string word;
  cout << "Enter the sentences separated by '[' and ']' " << endl;

  while(true)
  {
    cout << "#> ";
    getline(cin, word);
    /* TODO
       1. Read input until you encounter a "end"
       2. store them in inparr
    */
  }

  /* TODO - If the inparr is empty then print "No sentences: Nothing to evaluate"
            else call the evaluate function
  */

  return 0;
}
