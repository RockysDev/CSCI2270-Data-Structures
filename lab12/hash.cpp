// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    if(table[index] == NULL){ 
        return NULL;
    }
    else{
        node *temp = table[index]; // get node
        while(temp != NULL){ // iterate thru nodes next until we find key
            if(temp->key == key){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        node *insert = new node;
        insert->key = key;
        insert->next = NULL;
        int index = hashFunction(key);
        if(table[index] == NULL){
            table[index] = insert;
            return true;
        }
        else{
            node *temp = table[index]; // get node
            while(temp->next != NULL){ // iterate thru next next until we find empty next
                temp = temp->next;
            }
            temp->next = insert;
            return true;
        }

    }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }
}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        if(table[i]){
            node *temp = table[i];
            while(temp != NULL){
                cout << temp->key;
                if(temp->next != NULL){
                    cout << " -> "; 
                }
                temp = temp->next;
            }
        }
        //TODO
    }

 }
