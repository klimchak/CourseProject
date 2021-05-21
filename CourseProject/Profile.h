/*#ifndef PROFILE_H
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


class info
{
private:


public:
    char name[128];
    char pass[128];
    int level;
    info()
        :name()
        , pass()
        , level(0)
    {
        memset(name, 0, sizeof name);
        memset(pass, 0, sizeof pass);
    }

    void input()
    {
        std::cout << "¬ведите логин логин:" << std::endl;
        std::cin.getline(name, 127);

        std::cout << "¬ведите паоль:" << std::endl;
        std::cin.getline(pass, 127);

        std::cout << "”кажите  age:" << std::endl;
        std::cin >> level;

        to_file();
    }

    void to_file()
    {
        std::ofstream fs("example.bin", std::ios::out | std::ios::binary | std::ios::app);
        fs.write(name, sizeof name);
        fs.write(pass, sizeof pass);
        fs.write(reinterpret_cast<const char*>(&age), sizeof age);
        fs.close();
    }
    void at_file()
    {
        std::ifstream fs("example.bin", std::ios::out | std::ios::binary | std::ios::app);
        fs.read(name, sizeof name);
        fs.read(surname, sizeof surname);
        fs.read(reinterpret_cast<char*>(&age), sizeof age);
        fs.close();
    }
    void show()
    {
        std::cout << "Your name:  " << name << std::endl;

        std::cout << "Your surname:  " << surname << std::endl;

        std::cout << "Your age:  " << age << std::endl;
    }

};


#endif*/