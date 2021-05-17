#include <Windows.h>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "Profile.h"
#include "Header.h"

using namespace std;
using std::string;

// �������� ������ � ������
void GetLogiAndPass()
{
    bool ok = false;
    string fileLogin;
    string filePass;
    int profile = 0;
    int i = 1;
    while (ok == false)
    {
        if (i == 1)
        {
            system("cls");
            string choiceLogin = getValueStr("������� �����");
            string interimLogin = choiceLogin + ".txt";
            ifstream fin(interimLogin, ios_base::in);
            if (!fin.is_open()) // ���� ���� �� ������
            {
                cout << "������������ � ����� ������� �� ������!\n";
                int continueAnsw;
                bool okContin = false;
                while (okContin == false)
                {
                    continueAnsw = getValueInt("����������?\n1 - ��\n2 - ���\n");
                    if (continueAnsw == 1 || continueAnsw == 2)
                    {
                        okContin = true;
                    }
                    else
                    {
                        cout << "������� ���� �� ��������� �����.\n" << endl;
                    }
                }
                if (continueAnsw == 2)
                {
                    cout << "�������� ��������\n" << endl;
                    system("pause");
                    exit(0);
                }
            }
            else
            {
                string line;
                int j = 1;
                while (getline(fin, line))
                {
                    if (j == 1) { fileLogin = line; }
                    if (j == 2) { filePass = line; }
                    if (j == 3) { profile = stoi(line); }
                    j++;
                }
                fin.close();
                i = 2;
            }
        }
        if (i == 2)
        {
            system("cls");
            string choicePass = getValueStr("������� ������");
            if (choicePass == filePass)
            {
                ok = true;
            }
            else
            {
                cout << "������ ������. ��������� ����.\n"; // �������� �� ����
            }
        }
    }
    if (profile == 1) { GetChoiceMenuAdmin(); }
    if (profile == 2) { GetChoiceMenuManager(); }
    if (profile == 3) { GetChoiceMenuUser(); }
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
        cout << mess + "\n";
        string a;
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

/*
============================================
      ������� ������ � ��������������
============================================
*/

// ������ ������ � ����� �������
string WorkProfileFD(Profile user, bool rePass, bool del)
{
    ofstream fout;
    if (del)
    {
        string out;
        char* char_arr;
        user.name = user.name + ".txt";
        char_arr = &user.name[0];
        if (remove(char_arr) != 0)
        {
            out = "������ ��������. ���������� �������.\n";
        }
        else
        {
            if (user.level == 2)
            {
                out = "������ �������� " + user.name + "\n";
            }
            if (user.level == 3)
            {
                out = "������ ������������ " + user.name + "\n";
            }
        }
        return out;
    }
    else
    {
        if (rePass)
        {
            fout.open(user.name + ".txt", ios_base::trunc);
        }
        else
        {
            fout.open(user.name + ".txt", ios_base::app);
        }
        fout << user.name + "\n";
        fout << user.pass + "\n";
        fout << user.level;
        fout.close();
        string out;
        if (rePass)
        {
            if (user.level == 2)
            {
                out = "������� ������ ��������� " + user.name + "\n";
            }
            if (user.level == 3)
            {
                out = "������� ������ ������������ " + user.name + "\n";
            }
        }
        else
        {
            if (user.level == 2)
            {
                out = "������ �������� " + user.name + "\n";
            }
            if (user.level == 3)
            {
                out = "������ ������������ " + user.name + "\n";
            }
        }
        return out;
    }

}

// ����� ������ ���������� ������������                                                 �������� ����������� �������� ��� ������������� �������
Profile setNewPass()
{
    bool ok = false;
    Profile fileUser = Profile("", "", 0);
    while (ok == false)
    {
        cout << "\033[2J\033[1;1H";
        string choiceLogin = getValueStr("������� ����� ����������� �������");
        string interimLogin = choiceLogin + ".txt";
        ifstream fin(interimLogin, ios_base::in);
        if (!fin.is_open()) // ���� ���� �� ������
        {
            cout << "������������ � ����� ������� �� ������!\n";
        }
        else
        {
            string line;
            int j = 1;
            while (getline(fin, line))
            {
                if (j == 1) { fileUser.name = line; }
                if (j == 2) { fileUser.pass = line; }
                if (j == 3) { fileUser.level = stoi(line); }
                j++;
            }
            fin.close();
            ok = true;
        }
    }
    fileUser.pass = getValueStr("������� ������");
    return fileUser;
}

// ���� ������ ��� ������������
Profile GetNewProfileData()
{
    bool ok = false;
    Profile fileUser = Profile("", "", 0);
    fileUser.name = getValueStr("������� ��� �������");
    fileUser.pass = getValueStr("������� ������");
    fileUser.level = getValueInt("������� ������� �������:\n1 - �������������\n2 - ��������\n3 - ������������\n��� �����: ");
    return fileUser;
}
