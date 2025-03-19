#include <iostream>
using namespace std;

int main(){
    current = head;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next; // this is pointing at the next
        //nodes memory address
    }
    node *first = new node();
    for(current = head; current != nullptr;current = current->next){
        cout << "bla";
        // nullptr could have to be 0
    }
}
