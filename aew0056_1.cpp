//
// Created by awalker on 6/27/17.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "User.h"

using namespace std;

class Menu {
public:
    Menu() : currentUser("superuser") {}
    string messageBuffer;
    User currentUser;
    set<User> userList;
    string hashtagBuffer;

    void displayMenu();
    void createUser();
    void postMessage();
    void displayWall();
    void displayHome();
    void addFriends();
    void switchUser();
    void followHash();
    void quit();

};

//class User {
//public:
//    User(string username);
//
//    string name;
//    set<string> friends;
//    set<string> followedHashtags;
//
//    string getUsername();
//    void addFriend(string newFriend);
//    bool isFriend(string username);
//    bool operator<(const User&) const;
//
//
//};

int main() {
    Menu menu;
    //set<User> userList2;
    menu.displayMenu();
    return 0;
}

//Menu::Menu() {
//    currentUser = User("no");
//}

void Menu::displayMenu() {
    cout << "=========================================================== " << endl
         << "|             Welcome to War Eagle Chat System!            |" << endl
         << "=========================================================== " << endl;

    string userChoice;
    char choiceChar;
    do {
       cout << "Create new user(n), Post (p), Wall page (w), Home page (h), Add friend (f), Follow hashtag (t), Change"
            << endl << "user (c), Quit (q) " << endl
            << "Enter option: ";
       getline(cin, userChoice);
       cout << endl;
       if (userChoice.length() < 1) {
           continue;
       }
       choiceChar = userChoice.at(0);
       if (userList.size() == 0 && choiceChar != 'n' && choiceChar != 'q') {
           continue;
       }
       switch (choiceChar) {
           case 'n':
               createUser();
               break;
           case 'p':
               postMessage();
               break;
           case 'w':
               displayWall();
               break;
           case 'h':
               displayHome();
               break;
           case 'f':
               addFriends();
               break;
           case 't':
               followHash();
               break;
           case 'c':
               switchUser();
               break;
           default:
               cout << "Invalid input! Try again.";
               break;
       }

    }while(choiceChar != 'q');
}

void Menu::createUser() {
    string candidateUser;
    cout << "Please enter user name: ";
    cin >> candidateUser;
    cin.ignore();
    cout << endl;
    if (userList.find(User(candidateUser)) != userList.end()) {
        cout << "Username " + candidateUser + " is already taken." << endl;
    }
    else {
        currentUser = candidateUser;
        User newUser(currentUser);
        userList.insert(newUser);
        newUser.addFriend(currentUser.getUsername());
        cout << "=========================================================== " << endl
             << "|        Welcome to War Eagle Chat System, " + currentUser.getUsername() + "!            |" << endl
             << "=========================================================== " << endl;
    }
}

void Menu::postMessage() {
    cout << "Enter message:" << endl;
    string message = "(*" + currentUser.getUsername() + "*)";
    string line = "";
    while (true) {
        getline(cin, line);
        if ((line.compare("#$") == 0)) {
            messageBuffer += message;
            break;
        }
        message += line + "\n";
    }
}

void Menu::displayWall() {
    string foundUser;
    string singleMessage;
    std::vector<string> userMessages;
    cout << "=========================================================== " << endl
         << "|       " + currentUser.getUsername() + "'s Wall Page        |" << endl
         << "=========================================================== " << endl << endl;
    string bufferCopy = messageBuffer;
    while (bufferCopy.length() > 0) {
        unsigned long userStart = bufferCopy.find("(*") + 2;
        if (userStart != std::string::npos) {
            unsigned long userEnd = bufferCopy.find("*)");
            string user = bufferCopy.substr(userStart, userEnd - userStart);
            unsigned long messageEnd = bufferCopy.find("(*", userEnd + 2);
            if (messageEnd == std::string::npos) {
                messageEnd = bufferCopy.length();
            }
            if (user == currentUser.getUsername()) {
                singleMessage = bufferCopy.substr(userEnd + 2, messageEnd - userEnd - 2);
                userMessages.push_back(singleMessage);
            }
            bufferCopy = bufferCopy.substr(messageEnd, std::string::npos);
        }

    }
    int numDisplayed = 0; //current number of messages printed
    for (unsigned long i = userMessages.size() - 1; i != std::string::npos; i--) {
        if (numDisplayed == 2) {
            cout << "                       More messages? (yes/no): ";
            string answer;
            getline(cin, answer);
            if (answer == "no" || answer == "No" || answer == "NO") {
                break;
            }
        }
        cout << userMessages.at(i) << endl;
        numDisplayed++;
    }
}

void Menu::displayHome() {
    string foundUser;
    string singleMessage;
    std::vector<string> userMessages;
    cout << "=========================================================== " << endl
         << "|       " + currentUser.getUsername() + "'s Home Page        |" << endl
         << "=========================================================== " << endl << endl;
    string bufferCopy = messageBuffer;
    string hashes = currentUser.findFollowedHashtags(hashtagBuffer, currentUser.getUsername());
    while (bufferCopy.length() > 0) {
        unsigned long userStart = bufferCopy.find("(*") + 2;
        if (userStart != std::string::npos) {
            unsigned long userEnd = bufferCopy.find("*)");
            string user = bufferCopy.substr(userStart, userEnd - userStart);
            unsigned long messageEnd = bufferCopy.find("(*", userEnd + 2);
            if (messageEnd == std::string::npos) {
                messageEnd = bufferCopy.length();
            }
            singleMessage = bufferCopy.substr(userEnd + 2, messageEnd - userEnd - 2);

            if (user == currentUser.getUsername()) {
                userMessages.push_back(singleMessage);
            }
            else if (currentUser.isFriend(user)) {
                userMessages.push_back(singleMessage);
            }
            else if (singleMessage.find("#") != std::string::npos) {
                stringstream hashStream(hashes);
                string hashtag;
                for (hashStream; hashStream >> hashtag; ) {
                    if (singleMessage.find(hashtag) != std::string::npos) {
                        userMessages.push_back(singleMessage);
                        break;
                    }
                }
            }
            bufferCopy = bufferCopy.substr(messageEnd, std::string::npos);
        }

    }
    int numDisplayed = 0; //current number of messages printed
    for (unsigned long i = userMessages.size() - 1; i != std::string::npos; i--) {
        if (numDisplayed == 2) {
            cout << "                       More messages? (yes/no): ";
            string answer;
            getline(cin, answer);
            if (answer == "no" || answer == "No" || answer == "NO") {
                break;
            }
        }
        cout << userMessages.at(i) << endl;
        numDisplayed++;
    }
}

void Menu::addFriends() {
    string candidateFriend;
    cout << "Enter friend's name: ";
    cin >> candidateFriend;
    cout << endl;
    cin.ignore();
    currentUser.addFriend(candidateFriend);
}

void Menu::switchUser() {
    bool realUser = false;
    while (!realUser) {
        string candidateUser;
        cout << "Enter user's name: ";
        cin >> candidateUser;
        cout << endl;
        cin.ignore();
        set<User>::iterator iter = userList.find(candidateUser);
        if (iter != userList.end()) {
            currentUser = *iter;
            realUser = true;
        }
    }
    cout << "=========================================================== " << endl
         << "|     Welcome back to War Eagle Chat System, " + currentUser.getUsername() + "!    |" << endl
         << "=========================================================== " << endl;

}

void Menu::followHash() {
    string newHash;
    cout << "Enter hashtag topic: ";
    cin >> newHash;
    cin.ignore();
    if (hashtagBuffer.find(newHash) == string::npos) {
        hashtagBuffer += " " + newHash + " " + currentUser.getUsername();
    }
    else {
        size_t index = hashtagBuffer.find(newHash);
        unsigned long hashSize = newHash.size();
        hashtagBuffer.insert(index + hashSize, " " + currentUser.getUsername());
    }
}

void Menu::quit() {

}

//User::User(string username) {
//    name = username;
//}
//
//string User::getUsername() {
//    return name;
//}
//
//void User::addFriend(string newFriend) {
//    if (!isFriend(newFriend)) {
//        friends.insert(newFriend);
//    }
//}
//
//bool User::isFriend(string username) {
//    return friends.find(username) != friends.end();
//}
//
//bool User::operator<(const User &right) const {
//    return name < right.name;
//}