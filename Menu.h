// Lab 1:       War Eagle Chat System
// File:        Menu.h
// Description: Class definition of the Menu class.

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "User.h"
#include "WallPage.h"
#include "HomePage.h"

using namespace std;

// Class: Menu
// Description: This class creates a Menu object which represents
//              the menu of options for the  War Eagle Chat System.  This class
//              handles the user's inputs and displays the output requested
//              by the user.
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
