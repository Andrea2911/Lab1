//
// Created by awalker on 6/27/17.
//

#ifndef USER_H
#define USER_H

#include <set>
#include <string>

class User {
public:
    User(std::string username);

    std::string name;
    std::set<std::string> friends;
    std::set<std::string> followedHashtags;

    std::string getUsername();
    void addFriend(std::string newFriend);
    bool isFriend(std::string username);
    bool operator<(const User& right) const;
    std::string findFollowedHashtags(std::string hashBuffer, std::string username);

};


#endif //LAB1_USER_H
