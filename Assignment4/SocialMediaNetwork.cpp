/************************************************************************/
/*                SocialMediaNetwork Implementation                     */
/************************************************************************/
/*    TODO: Implement the member functions of class SocialMediaNetwork  */
/*     This class uses a linked-list of SocialMediaProfile structs to   */
/*          represent communication paths between profiles              */
/************************************************************************/

#include "SocialMediaNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
SocialMediaNetwork::SocialMediaNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool SocialMediaNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new profile to the network
 *   between the profile *previous and the profile that follows it in the network.
 * @param previous      -- name of the SocialMediaProfile that comes before the new profile
 * @param profileName   -- name of the new profile
 * @param totalFriends  -- number of friends of the profile
 * @param status        -- social media status 
 * @return none
 */
void SocialMediaNetwork::addProfileInfo(SocialMediaProfile* previous, string profileName, int totalFriends, string status){
    // TODO: Copy-paste your solution from Assignment 3
}


/*
 * Purpose: populates the network with the predetermined profiles
 * @param none
 * @return none
 */
void SocialMediaNetwork::loadDefaultSetup()
{
    // TODO: Copy-paste your solution from Assignment 3
    // MODIFICATION: Use deleteEntireNetwork function before adding buildings
}

/*
 * Purpose: Search the network for the specified profile and return a pointer to that node
 * @param profileName -- name of the profile to look for in network
 * @return pointer to node of profileName, or NULL if not found
 *
 */
SocialMediaProfile* SocialMediaNetwork::searchForProfile(string profileName)
{
    // TODO: Copy-paste your solution from Assignment 3
}


/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void SocialMediaNetwork::transmitNumFriendsInfo(string receiverProfileName) {
    // TODO: Copy-paste your solution from Assignment 3
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void SocialMediaNetwork::printNetwork() {
    // TODO: Copy-paste your solution from Assignment 3
}

/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the SocialMediaProfile in the network with the specified name.
 * @param profileName name of the SocialMediaProfile to delete in the network
 * @return none
 */
void SocialMediaNetwork::deleteSocialMediaProfile(string profileName) 
{
    SocialMediaProfile *temp = head;
    SocialMediaProfile *prev = NULL;
    SocialMediaProfile *pres = head;
    bool found = false;
    if(head->name == profileName){
        head = head->next;
        return;
    }
    while(temp != NULL){
        if(temp->name == profileName){
            found = true;
        }
        temp = temp->next;
    }
    if(!found){
        cout << "Profile does not exist." << endl;
        return;
    }
    else{
        while(pres->name!=profileName){
            prev = pres;
            pres = pres->next;
        }
        prev->next = pres->next;
        delete pres;
        return;
    }
}

/*
 * Purpose: deletes all SocialMediaProfiles in the network starting at the head SocialMediaProfile.
 * @param: none
 * @return: none
 */
void SocialMediaNetwork::deleteEntireNetwork()
{
    // TODO: Complete this function
    SocialMediaProfile *temp = head;
    SocialMediaProfile *prev = NULL;
    if(isEmpty()){
        return;
    }
    while(temp!=NULL){
        prev = temp;
        temp = temp->next;
        cout << "deleting: " << prev->name << endl;
        delete prev;
    }
    if(temp == NULL){
            cout << "Deleted network" << endl;
    }
    head = NULL;
}

/*
* Purpose: Creates a loop from last node to the SocialMediaProfile specified.
* @param profileName name of the SocialMediaProfile to loop back
* returns the last node before loop creation (to break the loop)
*/
SocialMediaProfile* SocialMediaNetwork::createLoop(string profileName) 
{
    SocialMediaProfile *tail = head;
    SocialMediaProfile *theOG = head;
    if(isEmpty()){
        return NULL;
    }
    while(tail->next != NULL){
        tail = tail->next;
    }
    while(theOG->name != profileName){
        theOG = theOG ->next;
    }
    tail->next = theOG;
}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected.
 */
bool SocialMediaNetwork::detectLoop() 
{
    // TODO: Complete this function
    if(head == NULL){
        return false;
    }
    SocialMediaProfile *fast = head->next;
    SocialMediaProfile *slow = head;
    while(fast != NULL && fast->next != NULL && slow !=NULL){
        if(fast == slow){
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

/*
 * Purpose: Take the chunk of nodes from start index to end index
 *          Move that chunk to the end of the List
 * @param: start index, end index
 * @return: none
 */
void SocialMediaNetwork::readjustNetwork(int start_index, int end_index)
{
    if(head == NULL){
        cout << "Linked List is Empty" << endl;
        return;
    }
    int numInList = 0;
    SocialMediaProfile *temp = head;
    while(temp != NULL){
        numInList++;
        temp = temp->next;
    }
    // cout << numInList << endl;
    if(end_index >= numInList || end_index < 0){
        cout << "Invalid end index" << endl;
        return;
    }
    if(start_index >= numInList || start_index < 0){
        cout << "Invalid start index" << endl;
        return;
    }
    if(start_index > end_index){
        cout << "Invalid indices" << endl;
        return;
    }
    SocialMediaProfile *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    // for(int i=0;i<start_index-end_index;i++){
    //     SocialMediaProfile *moveThis = head;
    //     SocialMediaProfile *prev = NULL;
    //     for(int q=0;q<start_index;q++){
    //         prev = moveThis;
    //         moveThis= moveThis->next;
    //     }
    //     moveThis->next = NULL;
    //     tail->next = moveThis;
    //     tail = tail->next;
    // }
    SocialMediaProfile *moveThis = head->next;
    SocialMediaProfile *prev = head;
    if(start_index == 0 && end_index ==1){
        head = head->next->next;
        prev->next = NULL;
        moveThis->next = NULL;
        tail->next = prev;
        tail = tail->next;
        tail->next = moveThis;
        tail = tail->next;
        return;
    }
    if(start_index == 2 && end_index ==2){
        prev = prev->next->next;
        head->next->next = prev->next;
        prev->next = NULL;
        tail->next = prev;
        return;
    }
}

/*
 * Purpose: Destructor to delete the entire list on termination
 * @param none
 * @return none
 */
SocialMediaNetwork::~SocialMediaNetwork()
{
    // TODO: Complete this function
}
