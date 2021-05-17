#include <Windows.h>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "Profile.h"
#include "Header.h"

using namespace std;
using std::string;

// проверка пароля и логина
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
            string choiceLogin = getValueStr("Введите логин");
            string interimLogin = choiceLogin + ".txt";
            ifstream fin(interimLogin, ios_base::in);
            if (!fin.is_open()) // если файл не открыт
            {
                cout << "Пользователь с таким логином не найден!\n";
                int continueAnsw;
                bool okContin = false;
                while (okContin == false)
                {
                    continueAnsw = getValueInt("Продолжаем?\n1 - Да\n2 - нет\n");
                    if (continueAnsw == 1 || continueAnsw == 2)
                    {
                        okContin = true;
                    }
                    else
                    {
                        cout << "Введите одно из указанных чисел.\n" << endl;
                    }
                }
                if (continueAnsw == 2)
                {
                    cout << "Операция прервана\n" << endl;
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
            string choicePass = getValueStr("Введите пароль");
            if (choicePass == filePass)
            {
                ok = true;
            }
            else
            {
                cout << "Ошибка пароля. Повторите ввод.\n"; // сообщить об этом
            }
        }
    }
    if (profile == 1) { GetChoiceMenuAdmin(); }
    if (profile == 2) { GetChoiceMenuManager(); }
    if (profile == 3) { GetChoiceMenuUser(); }
}

/*
============================================
   функции получения значения с клавиатуры
============================================
*/

int getValueInt(string mess)
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << mess + "\n";
        int a;
        std::cin >> a;

        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

string getValueStr(string mess)
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << mess + "\n";
        string a;
        std::cin >> a;

        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

/*
============================================
      функции работы с пользователями
============================================
*/

// запись данных в файла профиля
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
            out = "Ошибка удаления. Попробуйте вручную.\n";
        }
        else
        {
            if (user.level == 2)
            {
                out = "Удален менеджер " + user.name + "\n";
            }
            if (user.level == 3)
            {
                out = "Удален пользователь " + user.name + "\n";
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
                out = "Изменен пароль менеджера " + user.name + "\n";
            }
            if (user.level == 3)
            {
                out = "Изменен пароль пользователя " + user.name + "\n";
            }
        }
        else
        {
            if (user.level == 2)
            {
                out = "Создан менеджер " + user.name + "\n";
            }
            if (user.level == 3)
            {
                out = "Создан пользователь " + user.name + "\n";
            }
        }
        return out;
    }

}

// смена пароля имеющемуся пользователю                                                 добавить возможность возврата при отсутствующем профиле
Profile setNewPass()
{
    bool ok = false;
    Profile fileUser = Profile("", "", 0);
    while (ok == false)
    {
        cout << "\033[2J\033[1;1H";
        string choiceLogin = getValueStr("Введите логин изменяемого объекта");
        string interimLogin = choiceLogin + ".txt";
        ifstream fin(interimLogin, ios_base::in);
        if (!fin.is_open()) // если файл не открыт
        {
            cout << "Пользователь с таким логином не найден!\n";
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
    fileUser.pass = getValueStr("Введите пароль");
    return fileUser;
}

// сбор данных для пользователя
Profile GetNewProfileData()
{
    bool ok = false;
    Profile fileUser = Profile("", "", 0);
    fileUser.name = getValueStr("Введите имя объекта");
    fileUser.pass = getValueStr("Введите пароль");
    fileUser.level = getValueInt("Введите уровень доступа:\n1 - Администратор\n2 - Менеджер\n3 - Пользователь\nВаш выбор: ");
    return fileUser;
}
