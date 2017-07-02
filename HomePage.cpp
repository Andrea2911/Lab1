// Lab 1:       War Eagle Chat System
// File:        HomePage.cpp
// Description: Class implementation of the HomePage class.

#include "HomePage.h"

// Function:     createHomePage
// Description:  Finds the messages relevant to a user and modifies the parameter messages
//               to be used to display the User's HomePage.
void HomePage::createHomePage(string messageBuffer, string hashes, User user, vector<string> &userMessages) {
    string singleMessage;
    while (messageBuffer.length() > 0) {
        unsigned long userStart = messageBuffer.find("(*") + 2;
        if (userStart != std::string::npos) {
            unsigned long userEnd = messageBuffer.find("*)");
            string username = messageBuffer.substr(userStart, userEnd - userStart);
            unsigned long messageEnd = messageBuffer.find("(*", userEnd + 2);
            if (messageEnd == std::string::npos) {
                messageEnd = messageBuffer.length();
            }
            singleMessage = messageBuffer.substr(userEnd + 2, messageEnd - userEnd - 2);
            singleMessage = username + " >\n" + singleMessage;

            if (username == user.getUsername()) {
                userMessages.push_back(singleMessage);
            }
            else if (user.isFriend(username)) {
                userMessages.push_back(singleMessage);
            }
            else if (singleMessage.find("#") != std::string::npos) {
                stringstream hashStream(hashes);
                string hashtag;
                for (; hashStream >> hashtag; ) {
                    if (singleMessage.find(hashtag) != std::string::npos) {
                        userMessages.push_back(singleMessage);
                        break;
                    }
                }
            }
            messageBuffer = messageBuffer.substr(messageEnd, std::string::npos);
        }

    }

}