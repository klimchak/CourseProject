#include "Header.h"
#include <Windows.h>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>

using namespace std;
using std::string;

// проверка пароля и логина
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
            cout << "    Введите логин:\n";
            cin >> choiceLogin;
            std::ifstream openFile(choiceLogin, std::ios::in | std::ios::binary | std::ios::app);
            if (!openFile.is_open()) // если файл не открыт
            {
                cout << "    Пользователь с таким логином не найден!\n";
                int continueAnsw;
                bool okContin = false;
                while (okContin == false)
                {
                    continueAnsw = getValueInt("    Продолжаем?\n1 - Да\n2 - нет\n");
                    if (continueAnsw == 1 || continueAnsw == 2)
                    {
                        okContin = true;
                    }
                    else
                    {
                        cout << "    Введите одно из указанных чисел.\n" << endl;
                    }
                }
                if (continueAnsw == 2)
                {
                    cout << "    Операция прервана\n" << endl;
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
            cout << "    Введите пароль:\n";
            cin >> choicePass;;
            if (strcmp(choicePass, searchProfile.password) == 0)
            {
                ok = true;
            }
            else
            {
                cout << "    Ошибка пароля. Повторите ввод.\n"; // сообщить об этом
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
        cout << mess << endl;
        std::string userStr;
        std::getline(std::cin >> std::ws, userStr);
        return userStr;
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
    string out; 
    string interString = (1, user.login);
    ofstream fs; 
    if (del)
    {
        if (remove(user.login) != 0)
        {
            out = "    Ошибка удаления. Попробуйте вручную.\n";
        }
        else
        {
            if (user.level == 1)
            {
                out = "    Удален администратор " + interString + "\n";
            }
            if (user.level == 2)
            {
                out = "    Удален менеджер " + interString + "\n";
            }
            if (user.level == 3)
            {
                out = "    Удален пользователь " + interString + "\n";
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
                out = "    Изменен пароль администратора " + interString + "\n";
            }
            if (user.level == 2)
            {
                out = "    Изменен пароль менеджера " + interString + "\n";
            }
            if (user.level == 3)
            {
                out = "    Изменен пароль пользователя " + interString + "\n";
            }
        }
        else
        {
            if (user.level == 2)
            {
                out = "    Создан администратор " + interString + "\n";
            }
            if (user.level == 2)
            {
                out = "    Создан менеджер " + interString + "\n";
            }
            if (user.level == 3)
            {
                out = "    Создан пользователь " + interString + "\n";
            }
        }
        return out;
    }

}

// смена пароля имеющемуся пользователю
Profile setNewPass()
{
    bool ok = false;
    Profile fileUser;
    while (ok == false)
    {
        system("cls");
        char choiceLogin[127];
        cout << "    Введите логин изменяемого объекта:\n";
        cin >> choiceLogin;
        ifstream openFile(choiceLogin, std::ios::in | std::ios::binary | std::ios::app);
        if (!openFile.is_open()) // если файл не открыт
        {
            cout << "    Пользователь с таким логином не найден!\n";
        }
        else
        {
            openFile.read((char*)&fileUser, sizeof(Profile));
            openFile.close();
            ok = true;
        }
    }
    cout << "    Введите новый пароль:\n";
    cin >> fileUser.password;
    return fileUser;
}

// сбор данных для пользователя
Profile GetNewProfileData()
{
    bool ok = false;
    Profile fileUser;
    cout << "    Введите имя объекта:\n";
    cin >> fileUser.login;
    cout << "    Введите пароль:\n";
    cin >> fileUser.password;
    int i = 1;
    while (true)
    {
        if (i > 1)
        {
            cout << "    Ошибка. Повторите ввод. Варианты для выбора:\n1 - Администратор\n2 - Менеджер\n3 - Пользователь\nВаш выбор:\n";
        }
        else
        {
            cout << "    Введите уровень доступа:\n1 - Администратор\n2 - Менеджер\n3 - Пользователь\nВаш выбор:\n";
        }
        
        cin >> fileUser.level;
        if (fileUser.level == 1 || fileUser.level == 2 || fileUser.level == 3)
        {
            break;
        }
    }
    return fileUser;
}
