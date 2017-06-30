//
// Created by awalker on 6/30/17.
//

#include "WallPage.h"

void WallPage::createWallPage(string messageBuffer, User user, vector<string>& messages) {
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

            if (username == user.getUsername()) {
                singleMessage = messageBuffer.substr(userEnd + 2, messageEnd - userEnd - 2);
                messages.push_back(singleMessage);
            }
            messageBuffer = messageBuffer.substr(messageEnd, std::string::npos);
        }
    }
}