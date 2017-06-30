//
// Created by awalker on 6/30/17.
//

#ifndef WALLPAGE_H
#define WALLPAGE_H
#include "User.h"
#include <vector>
using namespace std;
class WallPage {
public:
   // WallPage(User newUser);
//    WallPage(User newUser) : user("superuser") {}
    void createWallPage(string messageBuffer, User user, vector<string>& messages);
//private:
//    User user;
};


#endif //LAB1_WALLPAGE_H
