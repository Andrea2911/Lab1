// Lab 1:       War Eagle Chat System
// File:        HomePage.h
// Description: Class definition of the HomePage class.

#ifndef HOMEPAGE_H
#define HOMEPAGE_H
#include "User.h"
#include <vector>
#include <string>
using namespace std;

class HomePage {
public:
    void createHomePage(string messageBuffer, string hashtags, User user, vector<string>& messages);
};


#endif //HOMEPAGE_H
