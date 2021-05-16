#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <iostream>

using namespace std;
using std::string;

class Profile
{
public:
    string name;
    string pass;
    int level;
    Profile(string nameCls, string passCls, int levelCls)
    {
        name = nameCls;
        pass = passCls;
        level = levelCls;
    }
};

#endif