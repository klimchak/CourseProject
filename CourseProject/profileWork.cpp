#include "Header.h"
#include <Windows.h>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>

using namespace std;
using std::string;

// �������� ������ � ������
void GetLogiAndPass()
{
    bool ok = false;
    char fileLogin[127];
    char filePass[127];
    int profile = 0;
    int i = 1;
    Profile searchProfile;
    while (ok == false)
    {
        if (i == 1)
        {
            system("cls");
            char choiceLogin[127];
            cout << "    ������� �����:\n";
            cin >> choiceLogin;
            std::ifstream openFile(choiceLogin, std::ios::in | std::ios::binary | std::ios::app);
            if (!openFile.is_open()) // ���� ���� �� ������
            {
                cout << "    ������������ � ����� ������� �� ������!\n";
                int continueAnsw;
                bool okContin = false;
                while (okContin == false)
                {
                    continueAnsw = getValueInt("    ����������?\n1 - ��\n2 - ���\n");
                    if (continueAnsw == 1 || continueAnsw == 2)
                    {
                        okContin = true;
                    }
                    else
                    {
                        cout << "    ������� ���� �� ��������� �����.\n" << endl;
                    }
                }
                if (continueAnsw == 2)
                {
                    cout << "    �������� ��������\n" << endl;
                    system("pause");
                    exit(0);
                }
            }
            else
            {
                openFile.read((char*)&searchProfile, sizeof(Profile));
                openFile.close();
                i = 2;
            }
        }
        if (i == 2)
        {
            system("cls");
            char choicePass[127];
            cout << "    ������� ������:\n";
            cin >> choicePass;;
            if (strcmp(choicePass, searchProfile.password) == 0)
            {
                ok = true;
            }
            else
            {
                cout << "    ������ ������. ��������� ����.\n"; // �������� �� ����
                system("pause");
            }
        }
    }
    if (searchProfile.level == 1) { GetChoiceMenuAdmin(); }
    if (searchProfile.level == 2) { GetChoiceMenuManager(); }
    if (searchProfile.level == 3) { GetChoiceMenuUser(); }
}

/*
============================================
   ������� ��������� �������� � ����������
============================================
*/

int getValueInt(string mess)
{
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        cout << mess + "\n";
        int a;
        std::cin >> a;

        if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
        {
            std::cin.clear(); // �� ���������� cin � '�������' ����� ������
            std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
        }
        else // ���� �� ������, �� ���������� a
            return a;
    }
}

string getValueStr(string mess)
{
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        cout << mess << endl;
        std::string userStr;
        std::getline(std::cin >> std::ws, userStr);
        return userStr;
    }
}

/*
============================================
      ������� ������ � ��������������
============================================
*/

// ������ ������ � ����� �������
string WorkProfileFD(Profile user, bool rePass, bool del)
{
    string out; 
    string interString = (1, user.login);
    ofstream fs; 
    if (del)
    {
        if (remove(user.login) != 0)
        {
            out = "    ������ ��������. ���������� �������.\n";
        }
        else
        {
            if (user.level == 1)
            {
                out = "    ������ ������������� " + interString + "\n";
            }
            if (user.level == 2)
            {
                out = "    ������ �������� " + interString + "\n";
            }
            if (user.level == 3)
            {
                out = "    ������ ������������ " + interString + "\n";
            }
        }
        return out;
    }
    else
    {
        if (rePass)
        {
            fs.open(user.login, std::ios::out | std::ios::binary | ios_base::trunc);
        }
        else
        {
            fs.open(user.login, std::ios::out | std::ios::binary | ios_base::app);
        }
        fs.write((char*)&user, sizeof(Profile));
        fs.close();
        if (rePass)
        {
            if (user.level == 2)
            {
                out = "    ������� ������ �������������� " + interString + "\n";
            }
            if (user.level == 2)
            {
                out = "    ������� ������ ��������� " + interString + "\n";
            }
            if (user.level == 3)
            {
                out = "    ������� ������ ������������ " + interString + "\n";
            }
        }
        else
        {
            if (user.level == 2)
            {
                out = "    ������ ������������� " + interString + "\n";
            }
            if (user.level == 2)
            {
                out = "    ������ �������� " + interString + "\n";
            }
            if (user.level == 3)
            {
                out = "    ������ ������������ " + interString + "\n";
            }
        }
        return out;
    }

}

// ����� ������ ���������� ������������
Profile setNewPass()
{
    bool ok = false;
    Profile fileUser;
    while (ok == false)
    {
        system("cls");
        char choiceLogin[127];
        cout << "    ������� ����� ����������� �������:\n";
        cin >> choiceLogin;
        ifstream openFile(choiceLogin, std::ios::in | std::ios::binary | std::ios::app);
        if (!openFile.is_open()) // ���� ���� �� ������
        {
            cout << "    ������������ � ����� ������� �� ������!\n";
        }
        else
        {
            openFile.read((char*)&fileUser, sizeof(Profile));
            openFile.close();
            ok = true;
        }
    }
    cout << "    ������� ����� ������:\n";
    cin >> fileUser.password;
    return fileUser;
}

// ���� ������ ��� ������������
Profile GetNewProfileData()
{
    bool ok = false;
    Profile fileUser;
    cout << "    ������� ��� �������:\n";
    cin >> fileUser.login;
    cout << "    ������� ������:\n";
    cin >> fileUser.password;
    int i = 1;
    while (true)
    {
        if (i > 1)
        {
            cout << "    ������. ��������� ����. �������� ��� ������:\n1 - �������������\n2 - ��������\n3 - ������������\n��� �����:\n";
        }
        else
        {
            cout << "    ������� ������� �������:\n1 - �������������\n2 - ��������\n3 - ������������\n��� �����:\n";
        }
        
        cin >> fileUser.level;
        if (fileUser.level == 1 || fileUser.level == 2 || fileUser.level == 3)
        {
            break;
        }
    }
    return fileUser;
}
