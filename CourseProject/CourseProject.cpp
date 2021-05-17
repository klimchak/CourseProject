#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Profile.h"
#include "Header.h"

using namespace std;
using std::string;

bool choiceCreateFD = false;
bool fileCreate;
/*
============================================
            функции второго уровня
============================================
*/

void GetChoiceMenuAdmin()
{
    system("cls");
    bool file = SearchFD();
    if (!SearchFD() && !choiceCreateFD)
    {
        cout << "===================================================" << endl;
        cout << "       Файл данных сотрудников не существует       " << endl;
        cout << "===================================================" << endl;
        bool ok = false;
        while (ok == false)
        {
            int continueAnsw = getValueInt("Создать файл данных? \n1 - Да\n2 - нет\n");
            if (continueAnsw == 1 || continueAnsw == 2)
            {
                if (continueAnsw == 1)
                {
                    if (CreateOrDeleteFD(true))
                    {
                        cout << "Файл данных успешно создан" << endl;
                        fileCreate = true;
                        system("pause");
                        GetChoiceMenuAdmin();
                    }
                    else
                    {
                        cout << "Ошибка при создании. Повторите попытку позже." << endl;
                        fileCreate = false;
                        system("pause");
                        GetChoiceMenuAdmin();
                    }
                    ok = true;
                }
                if (continueAnsw == 2)
                {
                    cout << "Файл не будет создан." << endl;
                    choiceCreateFD = true;
                    fileCreate = false;
                    system("pause");
                    GetChoiceMenuAdmin();
                }
            }
            else
            {
                cout << "Введите одно из указанных чисел.\n << endl";
            }
        }
    }
    else
    {
        if (!fileCreate)
        {
            cout << "===================================================" << endl;
            cout << "       Файл данных сотрудников не существует       " << endl;
            cout << "===================================================" << endl;
        }
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
            system("cls");
            cout << "===================================================" << endl;
            cout << "           Просмотр всех записей в таблице         " << endl;
            cout << "===================================================" << endl;
            break;
        case 4:
            GetChoiceWorkAtProfile();
            break;
        case 5:
            cout << "Выход!";
            exit(0);
        }
    }
   
}

void GetChoiceWorkAtFileData()
{
    system("cls");
    if (!fileCreate)
    {
        cout << "===================================================" << endl;
        cout << "       Файл данных сотрудников не существует       " << endl;
        cout << "===================================================" << endl;
    }
    DisplayWorkAtFileData();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "===================================================" << endl;
        cout << "           Создать файл данных сотрудника          " << endl;
        cout << "===================================================" << endl;
        if (CreateOrDeleteFD(true))
        {
            cout << "Файл данных успешно создан" << endl;
            fileCreate = true;
            system("pause");
            GetChoiceMenuAdmin();
        }
        else
        {
            cout << "Ошибка при создании. Повторите попытку позже." << endl;
            fileCreate = false;
            system("pause");
            GetChoiceMenuAdmin();
        }
        break;
    case 2:
        system("cls");
        cout << "===================================================" << endl;
        cout << "          Удалить файл данных сотрудников          " << endl;
        cout << "===================================================" << endl;
        if (CreateOrDeleteFD(false))
        {
            cout << "Файл данных успешно удален" << endl;
            fileCreate = true;
            system("pause");
            GetChoiceMenuAdmin();
        }
        else
        {
            cout << "Ошибка при удалении. Повторите попытку позже." << endl;
            fileCreate = false;
            system("pause");
            GetChoiceMenuAdmin();
        }
        break;
    case 3:
        GetChoiceMenuAdmin();
        break;
    case 4:
        cout << "Выход!";
        exit(0);
    }
}

void GetChoiceWorkAtRecords()
{
    system("cls");
    if (!fileCreate)
    {
        cout << "===================================================" << endl;
        cout << "       Файл данных сотрудников не существует       " << endl;
        cout << "===================================================" << endl;
    }
    DisplayWorkAtRecords();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "===================================================" << endl;
        cout << "                Добавление записи                  " << endl;
        cout << "===================================================" << endl;
        if (creatRecordInFD())
        {
            cout << "Запись успешно добавлена" << endl;
            system("pause");
            GetChoiceWorkAtRecords();
        }
        else
        {
            cout << "Запись успешно добавлена" << endl;
            system("pause");
            GetChoiceWorkAtRecords();
        }
        break;
    case 2:
        system("cls");
        cout << "===================================================" << endl;
        cout << "                Редактирование записи              " << endl;
        cout << "===================================================" << endl;
        break;
    case 3:
        system("cls");
        cout << "===================================================" << endl;
        cout << "                  Удаление записи                  " << endl;
        cout << "===================================================" << endl;
        break;
    case 4:
        system("cls");
        cout << "===================================================" << endl;
        cout << "            Сортировка записей по имени            " << endl;
        cout << "===================================================" << endl;
        break;
    case 5:
        system("cls");
        cout << "===================================================" << endl;
        cout << "           Сортировка записей по фамилии           " << endl;
        cout << "===================================================" << endl;
        break;
    case 6:
        system("cls");
        cout << "===================================================" << endl;
        cout << "             Сортировка записей по оделу           " << endl;
        cout << "===================================================" << endl;
        break;
    case 7:
        system("cls");
        cout << "===================================================" << endl;
        cout << "           Просмотр всех записей в таблице         " << endl;
        cout << "===================================================" << endl;
        printTable();
        system("pause");
        GetChoiceWorkAtRecords();
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
    if (!fileCreate)
    {
        cout << "===================================================" << endl;
        cout << "       Файл данных сотрудников не существует       " << endl;
        cout << "===================================================" << endl;
    }
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
        cout << "===================================================" << endl;
        cout << "           Добавление новой учетной записи         " << endl;
        cout << "===================================================" << endl;
        newUser = GetNewProfileData();
        if (newUser.level > 3)
        {
            cout << "Указан неверный уровень учетной записи.\n" << endl;
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
                    cout << "Введите одно из указанных чисел.\n" << endl;
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
                cout << "Операция прервана\n" << endl;
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
        cout << "===================================================" << endl;
        cout << "           Редактирование учетной записи           " << endl;
        cout << "===================================================" << endl;
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
                out = WorkProfileFD(GetNewProfileData(), false, false);
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
        system("cls");
        cout << "===================================================" << endl;
        cout << "              Удаление учетной записи              " << endl;
        cout << "===================================================" << endl;
        ok = false;
        while (ok == false)
        {
            system("pause");
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
        system("cls");
        cout << "===================================================" << endl;
        cout << "             Смена пароля учетной записи           " << endl;
        cout << "===================================================" << endl;
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
    if (!fileCreate)
    {
        cout << "===================================================" << endl;
        cout << "       Файл данных сотрудников не существует       " << endl;
        cout << "===================================================" << endl;
        system("pause");
        cout << "Выход!\n";
        exit(0);
    }
    DisplayMenuManager();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "===================================================" << endl;
        cout << "                Добавление записи                  " << endl;
        cout << "===================================================" << endl;
        break;
    case 2:
        system("cls");
        cout << "===================================================" << endl;
        cout << "                Редактирование записи              " << endl;
        cout << "===================================================" << endl;
        break;
    case 3:
        system("cls");
        cout << "===================================================" << endl;
        cout << "                  Удаление записи                  " << endl;
        cout << "===================================================" << endl;
        break;
    case 4:
        system("cls");
        cout << "===================================================" << endl;
        cout << "            Сортировка записей по имени            " << endl;
        cout << "===================================================" << endl;
        break;
    case 5:
        system("cls");
        cout << "===================================================" << endl;
        cout << "           Сортировка записей по фамилии           " << endl;
        cout << "===================================================" << endl;
        break;
    case 6:
        system("cls");
        cout << "===================================================" << endl;
        cout << "             Сортировка записей по оделу           " << endl;
        cout << "===================================================" << endl;
        break;
    case 7:
        system("cls");
        cout << "===================================================" << endl;
        cout << "           Просмотр всех записей в таблице         " << endl;
        cout << "===================================================" << endl;
        break;
    case 8:
        cout << "Выход!";
        exit(0);
    }
}

void GetChoiceMenuUser()
{
    system("cls");
    if (!fileCreate)
    {
        cout << "===================================================" << endl;
        cout << "       Файл данных сотрудников не существует       " << endl;
        cout << "===================================================" << endl;
        system("pause");
        cout << "Выход!\n";
        exit(0);
    }
    DisplayMenuUser();
    int choice = getValueInt("Введите числовое значение:");
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "===================================================" << endl;
        cout << "            Сортировка записей по имени            " << endl;
        cout << "===================================================" << endl;
        break;
    case 2:
        system("cls");
        cout << "===================================================" << endl;
        cout << "           Сортировка записей по фамилии           " << endl;
        cout << "===================================================" << endl;
        break;
    case 3:
        system("cls");
        cout << "===================================================" << endl;
        cout << "             Сортировка записей по оделу           " << endl;
        cout << "===================================================" << endl;
        break;
    case 4:
        system("cls");
        cout << "===================================================" << endl;
        cout << "           Просмотр всех записей в таблице         " << endl;
        cout << "===================================================" << endl;
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
    fileCreate = SearchFD();
    GetLogiAndPass();
}