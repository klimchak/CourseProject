#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Profile.h"
#include "Header.h"

using namespace std;
using std::string;

/*
============================================
            функции второго уровня
============================================
*/

void GetChoiceMenuAdmin()
{
    system("cls");
    DisplayMenuAdmin();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        GetChoiceWorkAtFileData();
        break;
    case 2:
        GetChoiceWorkAtRecords();
        break;
    case 3:
        cout << "Просмотр всех записей в таблице";
        break;
    case 4:
        GetChoiceWorkAtProfile();
        break;
    case 5:
        cout << "Выход!";
        exit(0);
    }
}

void GetChoiceWorkAtFileData()
{
    system("cls");
    DisplayWorkAtFileData();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        cout << "Создать файл данных сотрудника";
        break;
    case 2:
        cout << "Создать файл данных отделов";
        break;
    case 3:
        cout << "Удалить файл данных сотрудников";
        break;
    case 4:
        cout << "Удалить файл данных отделов";
        break;
    case 5:
        GetChoiceMenuAdmin();
        break;
    case 6:
        cout << "Выход!";
        exit(0);
    }
}

void GetChoiceWorkAtRecords()
{
    system("cls");
    DisplayWorkAtRecords();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        cout << "Добавление записи";
        break;
    case 2:
        cout << "Редактирование записи";
        break;
    case 3:
        cout << "Удаление записи";
        break;
    case 4:
        cout << "Сортировка записей по имени";
        break;
    case 5:
        cout << "Сортировка записей по фамилии";
        break;
    case 6:
        cout << "Сортировка записей по оделу";
        break;
    case 7:
        cout << "Просмотр всех записей в таблице";
        break;
    case 8:
        GetChoiceMenuAdmin();
        break;
    case 9:
        cout << "Выход!";
        exit(0);
    }
}

void GetChoiceWorkAtProfile()
{
    system("cls");
    DisplayWorkAtProfile();
    int choice = getValueInt("Введите числовое значение:");
    Profile newUser = Profile("", "", 0);
    string out;
    string oldUserName;
    int continueAnsw;
    bool ok = false;
    ifstream fin;
    switch (choice)   
    {
    case 1:
        system("cls");
        cout << "Добавление новой учетной записи\n";
        newUser = GetNewProfileData();
        if (newUser.level > 3)
        {
            cout << "Указан неверный уровень учетной записи.\n";
            system("pause");
            GetChoiceWorkAtProfile();
        }
        fin.open(newUser.name + ".txt", ios_base::in);
        if (!fin.is_open()) // если файл не открыт
        {
            while (ok == false)
            {
                continueAnsw = getValueInt("Продолжаем?\n1 - Да\n2 - нет\n");
                if (continueAnsw == 1 || continueAnsw == 2)
                {
                    ok = true;
                }
                else
                {
                    cout << "Введите одно из указанных чисел.\n";
                }
            }
            if (continueAnsw == 1)
            {
                out = WorkProfileFD(newUser, false, false);
                cout << out;
                system("pause");
                GetChoiceWorkAtProfile();
            }
            if (continueAnsw == 2)
            {
                cout << "Операция прервана\n";
                GetChoiceWorkAtProfile();
            }
            ok = false;
            break;
        }
        else
        {
            fin.close();
            cout << "Пользователь с таким логином существует.\n";
            system("pause");
            GetChoiceWorkAtProfile();
            ok = false;
            break;
        }
        
    case 2:
        system("cls");
        cout << "Редактирование учетной записи\n";
        newUser.name = getValueStr("Введите имя учетной записи, которую желаете изменить");
        fin.open(newUser.name + ".txt", ios_base::in);
        if (!fin.is_open()) // если файл не открыт
        {
            cout << "Пользователь с таким логином не найден.\n";
            system("pause");
            GetChoiceWorkAtProfile();
            ok = false;
            break;
        }
        else
        {
            fin.close();
            ok = false;
            while (ok == false)
            {
                continueAnsw = getValueInt("Продолжаем?\n1 - Да\n2 - нет\n");
                if (continueAnsw == 1 || continueAnsw == 2)
                {
                    ok = true;
                }
                else
                {
                    cout << "Введите одно из указанных чисел.\n";
                }
            }
            if (continueAnsw == 1)
            {
                cout << "Введите новые данные учетной записи\n";
                out = WorkProfileFD(GetNewProfileData(), false, false);                                         // !!!!!!!!!!
                cout << "Учетная запись изменена\n";
                WorkProfileFD(newUser, false, true);
                system("pause");
                GetChoiceWorkAtProfile();
            }
            if (continueAnsw == 2)
            {
                cout << "Операция прервана\n";
                GetChoiceWorkAtProfile();
            }
            ok = false;
            break;
        }
    case 3:
        cout << "Удаление учетной записи\n";
        ok = false;
        while (ok == false)
        {
            cout << "\033[2J\033[1;1H";
            oldUserName = getValueStr("Введите логин удаляемого объекта");
            string interimFN = oldUserName + ".txt";
            ifstream finn(interimFN, ios_base::in);
            if (!finn.is_open()) // если файл не открыт
            {
                cout << "Пользователь с таким логином не найден!\n";
            }
            else
            {
                finn.close();
                ok = true;
            }
        }
        ok = false;
        while (ok == false)
        {
            continueAnsw = getValueInt("\nПродолжаем?\n1 - Да\n2 - нет\n");
            if (continueAnsw == 1 || continueAnsw == 2)
            {
                ok = true;
            }
            else
            {
                cout << "Введите одно из указанных чисел.\n";
            }
        }
        if (continueAnsw == 1)
        {
            newUser.name = oldUserName;
            out = WorkProfileFD(newUser, false, true);
            cout << out;
            system("pause");
            GetChoiceWorkAtProfile();
        }
        if (continueAnsw == 2)
        {
            cout << "Операция прервана\n";
            GetChoiceWorkAtProfile();
        }

        break;
    case 4:
        cout << "Смена пароля учетной записи\n";
        out = WorkProfileFD(setNewPass(), false, true);
        cout << "пароль изменен \n";
        system("pause");
        GetChoiceWorkAtProfile();
        break;
    case 5:
        GetChoiceMenuAdmin();
        break;
    case 6:
        cout << "Выход!\n";
        exit(0);
    }
}

void GetChoiceMenuManager()
{
    system("cls");
    DisplayMenuManager();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        cout << "Добавление записи";
        break;
    case 2:
        cout << "Редактирование записи";
        break;
    case 3:
        cout << "Удаление записи";
        break;
    case 4:
        cout << "Сортировка записей по имени";
        break;
    case 5:
        cout << "Сортировка записей по фамилии";
        break;
    case 6:
        cout << "Сортировка записей по оделу";
        break;
    case 7:
        cout << "Просмотр всех записей в таблице";
        break;
    case 8:
        cout << "Выход!";
        exit(0);
    }
}

void GetChoiceMenuUser()
{
    system("cls");
    DisplayMenuUser();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        cout << "Сортировка записей по имени";
        break;
    case 2:
        cout << "Сортировка записей по фамилии";
        break;
    case 3:
        cout << "Сортировка записей по оделу";
        break;
    case 4:
        cout << "Просмотр всех записей в таблице";
        break;
    case 5:
        cout << "Выход!";
        exit(0);
    }
}


int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    GetLogiAndPass();
}