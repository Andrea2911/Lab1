// Lab 1:       War Eagle Chat System
// File:        Menu.cpp
// Description: Class implementation of the Menu class.

#include "Menu.h"

using namespace std;

//Function:     displayMenu
//Description:  Displays the menu for the War Eagle Chat system, giving
//              the user eight different options for how to proceed.
void Menu::displayMenu() {
    cout << string(10, ' ') << "=========================================================== " << endl
         << string(10, ' ') << "|             Welcome to War Eagle Chat System!            |" << endl
         << string(10, ' ') << "=========================================================== " << endl;

    string userChoice; //the user's input
    char choiceChar; //the user's input as one character
    // Take user input, if valid input is given perform the requested operation and continue this
    // loop until the user inputs 'q' for quit, at which point the program gracefully ends.
    do {
        cout << "Create new user(n), Post (p), Wall page (w), Home page (h), Add friend (f), Follow hashtag (t), Change"
             << endl << "user (c), Quit (q) " << endl
             << "Enter option: ";
        getline(cin, userChoice);
        cout << endl;
        //If the usesuesr doesn't give any input.
        if (userChoice.length() < 1) {
            cout << "No input was given, please choose one of the above options" << endl << endl;
            continue;
        }
        choiceChar = userChoice.at(0);
        //If the user attempts to do anything other than create a user of quit when no users have been created.
        if (userList.size() == 0 && choiceChar != 'n' && choiceChar != 'q') {
            cout << "No users have been created." << endl << endl;
            continue;
        }
        //If there is only one user and the user gives an input that requires multiple users.
        if (userList.size() == 1 && (choiceChar == 'c' || choiceChar == 'f')){
            cout << "Only one user has been created, please choose a different option." << endl << endl;
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
            case 'q':
                quit();
                break;
            default:
                cout << "Invalid input! Try again." << endl << endl;
                break;
        }

    }while(choiceChar != 'q');
}

//Function:     createUser
//Description:  Creates a new user, using the username the user enters.
//              The user is welcomed to the chat system and is added to the
//              list of users.
void Menu::createUser() {
    string candidateUser; //The potential new user
    bool validUser = false; //The potential user is assumed to be invalid until proven otherwise.
    while (!validUser) {
        cout << "Please enter user name: ";
        cin >> candidateUser;
        cin.ignore();
        cout << endl;
        //If the candidate User is already a created user, prompt the user for a different username
        //until a valid one is given.
        if (userList.find(User(candidateUser)) != userList.end()) {
            cout << "Username " + candidateUser + " is already taken. Choose a different username." << endl << endl;
            continue;
        }
        validUser = true;
    }
    User newUser(candidateUser);
    currentUser = newUser; //Make the candidate user the current user
    currentUser.addFriend(currentUser.getUsername()); //Make the current user a friend to himself
    userList.insert(currentUser); //Add the new user to the list of users
    string banner = "Welcome to War Eagle Chat System, " + currentUser.getUsername() + "!";
    createWelcome(banner);

}

// Function:    postMessage
//Description:  Allows a user to post a multiline message.  To end the message,
//              the user enters "#$". The message is appended to the message buffer
//              in the form "(*user*)message".
void Menu::postMessage() {
    cout << "Enter message:" << endl;
    string message = "(*" + currentUser.getUsername() + "*)"; //The username is stored in the message buffer
    string line = "";
    while (true) {
        getline(cin, line);
        if ((line.compare("#$") == 0)) {
            messageBuffer += message;
            break;
        }
        message += line + "\n";
    }
    cout << endl;
    cout << string(100, '=') << endl;
}

// Function:    displayWall
// Description: Searches the message buffer for all of the user's own posts.
//              Those messages are then printed to the console in reverse
//              chronological order.  After two messages have been printed,
//              the user is asked if they want to see more messages.  If yes,
//              the rest of the user's messages are printed.  If no, no other
//              messages are printed.
void Menu::displayWall() {
    string singleMessage; //a single message from the message buffer
    std::vector<string> userMessages; //vector of a User's messages
    string banner = currentUser.getUsername() + "'s Wall Page";
    createWelcome(banner);
    string bufferCopy = messageBuffer; //copy of the messageBuffer
    WallPage wall; //instantiates a WallPage for the current user
    wall.createWallPage(bufferCopy, currentUser, userMessages); //finds the User's own messages

    int numDisplayed = 0; //current number of messages printed
    //iterate backwards over the User's messages to be printed in reverse chronological order.
    for (unsigned long i = userMessages.size() - 1; i != std::string::npos; i--) {
        // When two messages are printed prompt the user for more messages
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
    cout << string(100, '=') << endl;
}

// Function:    displayHome
// Description: Searches the message buffer for all of the user's own posts,
//              the user's friend's posts, and any posts with hashtags the user follows.
//              Those messages are then printed to the console in reverse
//              chronological order.  After two messages have been printed,
//              the user is asked if they want to see more messages.  If yes,
//              the rest of the messages are printed.  If no, no other
//              messages are printed.
void Menu::displayHome() {
    string singleMessage;
    std::vector<string> userMessages;
    string banner = currentUser.getUsername() + "'s Home Page";
    createWelcome(banner);
    string bufferCopy = messageBuffer;
    string hashes = currentUser.findFollowedHashtags(hashtagBuffer, currentUser.getUsername());
    HomePage home;
    home.createHomePage(bufferCopy, hashes, currentUser, userMessages);
//    while (bufferCopy.length() > 0) {
//        unsigned long userStart = bufferCopy.find("(*") + 2;
//        if (userStart != std::string::npos) {
//            unsigned long userEnd = bufferCopy.find("*)");
//            string user = bufferCopy.substr(userStart, userEnd - userStart);
//            unsigned long messageEnd = bufferCopy.find("(*", userEnd + 2);
//            if (messageEnd == std::string::npos) {
//                messageEnd = bufferCopy.length();
//            }
//            singleMessage = bufferCopy.substr(userEnd + 2, messageEnd - userEnd - 2);
//            singleMessage = user + " >\n" + singleMessage;
//
//            if (user == currentUser.getUsername()) {
//                userMessages.push_back(singleMessage);
//            }
//            else if (currentUser.isFriend(user)) {
//                userMessages.push_back(singleMessage);
//            }
//            else if (singleMessage.find("#") != std::string::npos) {
//                stringstream hashStream(hashes);
//                string hashtag;
//                for (; hashStream >> hashtag; ) {
//                    if (singleMessage.find(hashtag) != std::string::npos) {
//                        userMessages.push_back(singleMessage);
//                        break;
//                    }
//                }
//            }
//            bufferCopy = bufferCopy.substr(messageEnd, std::string::npos);
//        }
//
//    }

    int numDisplayed = 0; //current number of messages printed
    //iterate backwards of the messages relevant to the User and print them out
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
    cout << string(100, '=') << endl;
}

//Function:     addFriends
//Description:  Prompts the user for a friend's username.  If the username
//              is valid, a new friend is added to the current user's
//              friend list.  If the username is invalid, the user is continually
//              prompted until a valid username is entered.
void Menu::addFriends() {
    bool validUser = false; //assumed to be given an invalid user until proven otherwise
    string candidateFriend; //The possible friend to be added
    while (!validUser) {
        cout << "Enter friend's name: ";
        cin >> candidateFriend;
        cout << endl;
        cin.ignore();
        //Repeat if the user inputs an invalid User.
        if (userList.find(User(candidateFriend)) == userList.end()) {
            cout << candidateFriend + " is not a valid user." << endl << endl;
            continue;
        }
    validUser = true;
    }
    currentUser.addFriend(candidateFriend);
//    userList.erase(currentUser.getUsername());
//    userList.insert(currentUser);
    cout << string(100, '=') << endl;
}

//Function:     switchUser
//Description:  Switches from the current user to a different user,
//              provided that the given username is valid.
void Menu::switchUser() {
    userList.erase(currentUser.getUsername()); //currentUser is erased from and added back to the
    userList.insert(currentUser);              //list of users to reflect any changes made to the User
    bool realUser = false; //The inputted username is assumed invalid until proven otherwise.

    while (!realUser) {
        string candidateUser; //Possible user to be switched to.
        cout << "Enter user's name: ";
        cin >> candidateUser;
        cout << endl;
        cin.ignore();
        if (currentUser.getUsername() == candidateUser) {
            cout << candidateUser + " is already the current user." << endl << endl;
            continue;
        }

        set<User>::iterator iter = userList.find(candidateUser); // attempts to find the User in the user list.
        if (iter != userList.end()) {
            currentUser = *iter;
            realUser = true;
            continue;
        }
        cout << candidateUser + " has not been created, and is not a valid user." << endl << endl;
    }
    //new current user is welcomed back
    string banner = "Welcome back to War Eagle Chat System, " + currentUser.getUsername() + "!";
    createWelcome(banner);
}

//Function:     followHash
//Description:  Prompts the user for a hashtag topic to follow.  If the hashtag
//              did not exist, it is is added to the hashtag buffer.  The user is
//              added to the followers of the hashtag.
void Menu::followHash() {
    bool validHash = false; //hashtag is assumed to be invalid until proven otherwise
    string newHash; //potential new hashtag to be followed
    while (!validHash) {
        validHash = true;
        cout << "Enter hashtag topic: ";
        cin >> newHash;
        cin.ignore();
        cout << endl;
        //insures potential hashtag begins with '#'
        if (newHash.at(0) != '#') {
            validHash = false;
            cout << "Hashtag topics must begin with '#'" << endl << endl;
            continue;
        }
        //Checks that hashtag contains only letters
        string hashString = newHash.substr(1, std::string::npos);
        //for (char c : hashString) {
        for (int i = 0; i < hashString.size(); i++) {
            char c = hashString[i];
            if (!((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))) {
                validHash = false;
                cout << "Hashtag topics can only contain letters" << endl << endl;
                continue;
            }
        }
    }
    if (hashtagBuffer.find(newHash) == string::npos) {
        hashtagBuffer += " " + newHash + " " + currentUser.getUsername();
    }
    else {
        size_t index = hashtagBuffer.find(newHash);
        unsigned long hashSize = newHash.size();
        hashtagBuffer.insert(index + hashSize, " " + currentUser.getUsername());
    }
    cout << string(100, '=') << endl;
}

//Function:     quit
//Description:  Displays a closing message, and gracefully exits the program.
void Menu::quit() {
    cout << string(10, ' ') << string(59, '=') << endl
         << string(10, ' ') << "|         Thank you for using War Eagle Chat System        |" << endl
         << string(10, ' ') << string(59, '=') << endl;
}

//Function:     createWelcome
//Inputs:       The banner string, unique for each situation
//Description:  Creates a welcome banner with unique to each task and
//              length of the current user's username.
void Menu::createWelcome(string banner) {
    banner = "|          " + banner + "          |";
    unsigned long bannerLength = banner.length();
    cout << string(10, ' ') << string(bannerLength, '=') << endl
         << string(10, ' ') << banner << endl
         << string(10, ' ') << string(bannerLength, '=') << endl << endl;
}