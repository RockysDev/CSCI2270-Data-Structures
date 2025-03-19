/****************************************************************/
/*      ONLY COMPLETE THE FUNCTIONS OF SocialMediaNetwork Class */
/****************************************************************/
/*  DONOT change the class and main           */
/****************************************************************/

//#pragma once
#include <iostream>
#include <fstream>
using namespace std;
/*------ Contents of .hpp file. DONOT change-------*/
// SocialMediaProfile: node struct that will be stored in the SocialMediaNetwork
struct SocialMediaProfile
{
    string name;                 // name of the person
    string socialMediaStatus;    // status set by the profile
    int numberMessages;          // no. of messages in the inbox
    SocialMediaProfile *next;    // pointer to the next profile
    int totalFriends;            // number of friends of this profile

};

// class for storing and manipulating linked-list of social media profiles
class SocialMediaNetwork {
    private:
        SocialMediaProfile* head;  // pointer to head of linked list of profiles

    public:
        // You will need to define the below unfinished methods in SocialMediaNetwork.cpp
        SocialMediaNetwork();
        bool isEmpty();
        void addProfileInfo(SocialMediaProfile* previous, string profileName, int totalFriends, string status);
        void loadDefaultSetup();
        SocialMediaProfile* searchForProfile(string profileName);
        void transmitNumFriendsInfo(string receiverProfileName);
        void printNetwork();
};

//------------ hpp file ends------------------------------------------//


using namespace std;

/************************************************
    Definitions for main.cpp . DONOT change here
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Profile Info " << endl;
    cout << " 4. Add Profile " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
} 

int main(int argc, char* argv[])
{


    SocialMediaNetwork ProfileNet;
    int opt = 0; string s; string s1; string s2; string s3;

    while(opt != 5) {

        displayMenu();

        getline(cin, s);
        opt = stoi(s);

        switch(opt) {
            case 1: {
                ProfileNet.loadDefaultSetup();
                ProfileNet.printNetwork();
                break;
            }

            case 2: {
                ProfileNet.printNetwork();
                break;
            }

            case 3: {
                cout << "Enter name of the recipient to receive the message: "<< endl;
                getline(cin, s1);

                //cout << "Enter the message to send: " << endl;
                //getline(cin, s2);

                cout << endl;

                ProfileNet.transmitNumFriendsInfo(s1);

                break;
            }

            case 4: {
                cout << "Enter a new profile name: " << endl;
                getline(cin, s1);

                string numFriends;
                cout << "Enter number of friends: " << endl;
                getline(cin, numFriends);

                cout << "Enter the social media status: " << endl;
                getline(cin, s3);

                cout << "Enter the previous profile name (or First): " << endl;
                getline(cin, s2);
                
                while(!(s2 == "First" || ProfileNet.searchForProfile(s2))) {
                    cout << "INVALID(previous profile name)...Please enter a VALID profile name!" << endl;
                    getline(cin, s2);


                }

                if(s2 == "First") {
                    ProfileNet.addProfileInfo(NULL, s1, stoi(numFriends), s3);
                }
                else {
                    ProfileNet.addProfileInfo(ProfileNet.searchForProfile(s2), s1, stoi(numFriends), s3);
                }

                ProfileNet.printNetwork();
                break;
            }

            case 5: {
                cout << "Quitting..." << endl;
                break;
            }

        }
    }

    cout << "Goodbye!" << endl;

    return 0;
}


/************************************************
      Definitions from SocialMediaNetwork.cpp
      Complete the functions
************************************************/
SocialMediaNetwork::SocialMediaNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

bool SocialMediaNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}
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

void SocialMediaNetwork::loadDefaultSetup(){
    addProfileInfo(NULL,"Marshall",10,"“There is a great sandwich place on 24th.”");
    addProfileInfo(searchForProfile("Marshall"),"Lily",8,"I want to move to the suburbs.");
    addProfileInfo(searchForProfile("Lily"),"Ted",6,"Working on a building design right now.");
    addProfileInfo(searchForProfile("Ted"),"Robin",5,"The Canucks won today.");
    addProfileInfo(searchForProfile("Robin"),"Barney",4,"Suit up.");
    addProfileInfo(searchForProfile("Barney"),"Ranjit",15,"NYC is an interesting city.");
}

SocialMediaProfile* SocialMediaNetwork::searchForProfile(string profileName){
    SocialMediaProfile* ptr = head;
    while (ptr != NULL && ptr->name != profileName)
    {
        ptr = ptr->next;
    }
    return ptr;
}

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

void SocialMediaNetwork::printNetwork() {
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

