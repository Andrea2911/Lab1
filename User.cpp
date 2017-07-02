// Lab 1:       War Eagle Chat System
// File:        User.cpp
// Description: Class implementation of the User class.


#include "User.h"

using namespace std;

// Function:    User constructor
// Description: Assigns the given username to the field name.
User::User(string username) {
    name = username;
}

// Function:    getUsername
// Outputs:     string with the user's name
// Description: Returns the username of a user.
string User::getUsername() {
    return name;
}

// Function:    addFriend
// Inputs:      The name of a friend.
// Description: Adds a new friend to the User's friend list.
void User::addFriend(string newFriend) {
    if (!isFriend(newFriend)) {
        friends.insert(newFriend);
    }
}

// Function:    isFriend
// Inputs:      Username of a possible friend
// Outputs:     True if the username is already a friend
// Description: Determines whether a given name is a friend of the User.
bool User::isFriend(string username) {
    return friends.find(username) != friends.end();
}

// Function:    operator<
// Description: Defines how User objects should be ordered, in this case by username.
bool User::operator<(const User& right) const {
    return name < right.name;
}

// Function:    findFollowedHashtags
// Description: Given a user and a hashtag buffer, determines which hashtags the User follows.
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