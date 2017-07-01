//
// Created by awalker on 6/27/17.
//

#include "User.h"

using namespace std;

User::User(string username) {
    name = username;
}

string User::getUsername() {
    return name;
}

void User::addFriend(string newFriend) {
    if (!isFriend(newFriend)) {
        friends.insert(newFriend);
    }
}

bool User::isFriend(string username) {
    return friends.find(username) != friends.end();
}

bool User::operator<(const User& right) const {
    return name < right.name;
}

string User::findFollowedHashtags(std::string hashBuffer, string username) {
    string currentItem;
    string currentHashList;
    string followedHashes;
    while (hashBuffer.length() > 0) {
        unsigned long hashIndex = hashBuffer.find("#");
        if (hashIndex != std::string::npos) {
            unsigned long followersEnd = hashBuffer.find("#", hashIndex + 1);
            if (followersEnd == std::string::npos) {
                followersEnd = hashBuffer.length();
            }
            currentHashList = hashBuffer.substr(hashIndex, followersEnd - hashIndex);
            stringstream s(currentHashList);
            string hash;
            for (; s >> currentItem;) {
                if (currentItem.find("#") != std::string::npos) {
                    hash = currentItem;
                } else if (currentItem.compare(username) == 0) {
                    followedHashes += hash + " ";
                }

            }
            hashBuffer = hashBuffer.substr(followersEnd, std::string::npos);
        }
    }
    return followedHashes;
}