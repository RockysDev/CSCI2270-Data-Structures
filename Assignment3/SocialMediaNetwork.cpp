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
    SocialMediaProfile* newProfile = new SocialMediaProfile;
    newProfile->name = profileName;
    newProfile->totalFriends = totalFriends;
    newProfile->socialMediaStatus = status;


    // if list is not empty, look for prev and append our node there
    if(previous == NULL){
        SocialMediaProfile* temphead = new SocialMediaProfile;
        temphead = head;
        head = newProfile;
        head->next = temphead;
        cout << "adding: " << profileName << " (HEAD)" << endl;
    }
    else{
        newProfile->next = previous->next;
        previous->next = newProfile;
        cout << "adding: " << profileName << " (prev: " << previous->name << ")" << endl;
    }
}


/*
 * Purpose: populates the network with the predetermined profiles
 * @param none
 * @return none
 */
void SocialMediaNetwork::loadDefaultSetup(){
    addProfileInfo(NULL,"Marshall",10,"“There is a great sandwich place on 24th.”");
    addProfileInfo(searchForProfile("Marshall"),"Lily",8,"I want to move to the suburbs.");
    addProfileInfo(searchForProfile("Lily"),"Ted",6,"Working on a building design right now.");
    addProfileInfo(searchForProfile("Ted"),"Robin",5,"The Canucks won today.");
    addProfileInfo(searchForProfile("Robin"),"Barney",4,"Suit up.");
    addProfileInfo(searchForProfile("Barney"),"Ranjit",15,"NYC is an interesting city.");
}

/*
 * Purpose: Search the network for the specified profile and return a pointer to that node
 * @param profileName -- name of the profile to look for in network
 * @return pointer to node of profileName, or NULL if not found
 *
 */
SocialMediaProfile* SocialMediaNetwork::searchForProfile(string profileName){
    SocialMediaProfile* ptr = head;
    while (ptr != NULL && ptr->name != profileName)
    {
        ptr = ptr->next;
    }
    return ptr;
}


/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void SocialMediaNetwork::transmitNumFriendsInfo(string receiverProfileName) {
    SocialMediaProfile* temp = head;
    bool found = false;
    if(temp == NULL){
        cout << "empty list" << endl;
        return;
    }
    while(temp!=NULL){
        if(temp->name == receiverProfileName){
            found = true;
        }
        temp = temp->next;
    }
    if(found == false){
        cout << "Profile not found" << endl;
        return;
    }
    SocialMediaProfile* temp2 = head;
    if(temp2->name == receiverProfileName){
        temp2->numberMessages++;
        cout << temp2->name << " [# messages received: " << temp2->numberMessages << "] received: " << temp2->name << " has " << temp2->totalFriends<< " friends." << endl;
    }
    else{
        while(temp2->name != receiverProfileName){
            temp2->numberMessages++;
            cout << temp2->name << " [# messages received: " << temp2->numberMessages << "] received: " << temp2->name << " has " << temp2->totalFriends<< " friends." << endl;
            if(temp2->next->name == receiverProfileName){
                temp2->next->numberMessages++;
                cout << temp2->next->name << " [# messages received: " << temp2->next->numberMessages << "] received: " << temp2->next->name << " has " << temp2->next->totalFriends<< " friends." << endl;
                return;
            }
            temp2 = temp2->next;
        }
    }
}
//cout << temp->name << " [# messages received: 1] received: " << temp->name << " has " << temp->totalFriends<< " friends." << endl;

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void SocialMediaNetwork::printNetwork(){
    SocialMediaProfile* temp = head;
    cout << "== CURRENT PATH ==" << endl;
    if(temp==NULL){
        cout << "nothing in path" << endl;
        cout << "===" << endl;
        return;
    }
    while(temp!=NULL){
        cout << temp->name << "(" << temp->totalFriends << ") -> ";
        if(temp->next==NULL){
            cout << "NULL" << endl;
        }
        temp = temp->next;
    }
    cout << "===" << endl;
}
