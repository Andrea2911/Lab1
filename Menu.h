//
// Created by awalker on 6/30/17.
//

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "User.h"
#include "WallPage.h"
using namespace std;

class Menu {
public:
    Menu() : currentUser("superuser") {}

    void displayMenu();
    void createUser();
    void postMessage();
    void displayWall();
    void displayHome();
    void addFriends();
    void switchUser();
    void followHash();
    void quit();

private:
    string messageBuffer;
    User currentUser;
    set<User> userList;
    string hashtagBuffer;
    void createWelcome(string banner);
};


#endif //LAB1_MENU_H
