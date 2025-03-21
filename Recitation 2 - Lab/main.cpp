#include<iostream>
#include "swap.h"

using namespace std;
int main(int argc, char const *argv[])
{
  int foo[5] = {1, 2, 3, 4, 5};

  cout << "Addresses of elements:" << endl;
  //TODO Print the addresses of array elements

  cout << endl;

  cout << "Elements:" << endl;;
  //TODO Print all the elements using pointers

  cout << endl;

  int a,b;
  int f;
  int flag = 1;
  while(flag == 1){
    cout<<"Enter indices of elements you want to swap?"<<endl;
    cout<<"First index"<<endl;
    cin>>a;
    cout<<"Second index"<<endl;
    cin>>b;
    cout<<"Enter 0 for pass-by-value, 1 for pass-by-pointer"<<endl;
    cin>>f;

    switch (f) {
      case 0:
        // Pass by Value
        // Compare the resultant array with the array you get after passing by pointer
        cout << "Before swapping" << endl;
        for(int i = 0;i<5;i++){
          cout<<foo[i]<<" ";
        }
        cout<<endl;

        swap(foo[a],foo[b]);

        cout << "\nAfter swapping" << endl;
        for(int i = 0;i<5;i++){
          cout<<foo[i]<<" ";
        }
        cout<<endl;
        break;

      case 1:
        // Pass by pointer
        cout << "Before swapping" << endl;
        for(int i = 0;i<5;i++){
          cout<<foo[i]<<" ";
        }
        cout<<endl;

        // TODO complete the function in swap.cpp file
        swap_by_pointers(&foo[a],&foo[b]);

        cout << "\nAfter swapping" << endl;
        for(int i = 0;i<5;i++){
          cout<<foo[i]<<" ";
        }
        cout<<endl;
        break;

    }
    cout<<endl;
    cout << "Press 1 to continue else press 0"<<endl;
    cin>> flag;
  }

  cout << "Reversing the array";
  // Reverse your array
  // TODO complete the function in swap.cpp file
  reverse(foo,5);

  cout << "\nAfter reversing" << endl;
  for(int i = 0;i<5;i++){
    cout<<foo[i]<<" ";
  }
  cout<<endl;


  // GOLD problem
  // Cumulative sum of the array
  // TODO call this function cumulative_sum properly so that it passes the array 'foo'
  // and updates 'foo' with cumulative summation.
  // After this function call, you will get the updated array here
  // TODO complete the function declaration in swap.h file
  // TODO complete the function in swap.cpp file
  
  // cumulative_sum(<TODO>,5);

  cout << "\nAfter cumulative summation" << endl;
  for(int i = 0;i<5;i++){
    cout<<foo[i]<<" ";
  }
  cout<<endl;

  return 0;
}
