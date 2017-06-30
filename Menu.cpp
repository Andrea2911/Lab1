//
// Created by awalker on 6/30/17.
//

#include "Menu.h"

using namespace std;

//Menu::Menu() {
//    currentUser = User("no");
//}

//Function:     displayMenu
//Description:  Displays the menu for the War Eagle Chat system, giving
//              the user eight different options for how to proceed.
void Menu::displayMenu() {
    cout << string(10, ' ') << "=========================================================== " << endl
         << string(10, ' ') << "|             Welcome to War Eagle Chat System!            |" << endl
         << string(10, ' ') << "=========================================================== " << endl;

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
            cout << "No users have been created." << endl << endl;
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
                if (userList.size() == 1) {
                    cout << "You cannot switch users, only one user has been created." << endl << endl;
                    continue;
                }
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
        string banner = "Welcome to War Eagle Chat System, " + currentUser.getUsername() + "!";
        createWelcome(banner);
    }
}

// Function:    postMessage
//Description:  Allows a user to post a multiline message.  To end the message,
//              the user enters "#$". The message is appended to the message buffer
//              in the form "(*user*)message".
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
    string singleMessage;
    std::vector<string> userMessages;
    string banner = currentUser.getUsername() + "'s Wall Page";
    createWelcome(banner);
    string bufferCopy = messageBuffer;
    WallPage wall;
    wall.createWallPage(bufferCopy, currentUser, userMessages);

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
            singleMessage = user + " >\n" + singleMessage;

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
    cout << string(100, '=') << endl;
}

//Function:     addFriends
//Description:  Prompts the user for a friend's username.  If the username
//              is valid, a new friend is added to the current user's
//              friend list.  If the username is invalid, the user is continually
//              prompted until a valid username is entered.
void Menu::addFriends() {
    string candidateFriend;
    cout << "Enter friend's name: ";
    cin >> candidateFriend;
    cout << endl;
    cin.ignore();
    currentUser.addFriend(candidateFriend);
    cout << string(100, '=') << endl;
}

//Function:     switchUser
//Description:  Switches from the current user to a different user,
//              provided that the given username is valid.
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
    string banner = "Welcome back to War Eagle Chat System, " + currentUser.getUsername() + "!";
    createWelcome(banner);
}

//Function:     followHash
//Description:  Prompts the user for a hashtag topic to follow.  If the hashtag
//              did not exist, it is is added to the hashtag buffer.  The user is
//              added to the followers of the hashtag.
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
    cout << endl<< string(100, '=') << endl;
}

//Function:     quit
//Description:  Displays a closing message, and gracefully exits the program.
void Menu::quit() {
    cout << string(10, ' ') << string(59, '=') << endl
         << string(10, ' ') << "|         Thank you for using War Eagle Chat System        |" << endl
         << string(10, ' ') << string(59, '=') << endl;
}

//Function:     createWelcome
//Description:  Creates a welcome banner with unique to each task and
//              length of the current user's username.
void Menu::createWelcome(string banner) {
    banner = "|          " + banner + "          |";
    unsigned long bannerLength = banner.length();
    cout << string(10, ' ') << string(bannerLength, '=') << endl
         << string(10, ' ') << banner << endl
         << string(10, ' ') << string(bannerLength, '=') << endl << endl;
}