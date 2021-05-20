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
bool fileAdminCreate;
/*
============================================
            функции работы меню
============================================
*/

void GetChoiceMenuAdmin()
{
    system("cls");
    bool file = SearchFD();
    bool ok = false;
    int continueAnsw;
    if (!SearchFD() && !choiceCreateFD)
    {
        cout << "                             ===================================================" << endl;
        cout << "                                    Файл данных сотрудников не существует       " << endl;
        cout << "                             ===================================================" << endl;
        bool ok = false;
        while (ok == false)
        {
            int continueAnsw = getValueInt("    Создать файл данных? \n1 - Да\n2 - нет\n");
            if (continueAnsw == 1 || continueAnsw == 2)
            {
                if (continueAnsw == 1)
                {
                    if (CreateOrDeleteFD(true))
                    {
                        cout << "    Файл данных успешно создан" << endl;
                        fileCreate = true;
                        system("pause");
                        GetChoiceMenuAdmin();
                    }
                    else
                    {
                        cout << "    Ошибка при создании. Повторите попытку позже." << endl;
                        fileCreate = false;
                        system("pause");
                        GetChoiceMenuAdmin();
                    }
                    ok = true;
                }
                if (continueAnsw == 2)
                {
                    cout << "    Файл не будет создан." << endl;
                    choiceCreateFD = true;
                    fileCreate = false;
                    system("pause");
                    GetChoiceMenuAdmin();
                }
            }
            else
            {
                cout << "    Введите одно из указанных чисел.\n << endl";
            }
        }
    }
    else
    {
        if (!fileCreate)
        {
            cout << "                             ===================================================" << endl;
            cout << "                                    Файл данных сотрудников не существует       " << endl;
            cout << "                             ===================================================" << endl;
            DisplayMenuAdmin();
            int choice = getValueInt("    Введите числовое значение:");
            switch (choice)
            {
            case 1:
                GetChoiceWorkAtFileData();
                break;
            case 2:
                GetChoiceWorkAtProfile();
                break;
            case 3:
                cout << "    Выход!";
                exit(0);
            default:
                GetChoiceMenuAdmin();
                break;
            }
        
        }
        else
        {
            DisplayMenuAdmin();
            int choice = getValueInt("    Введите числовое значение:");
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
                cout << "                             ===================================================" << endl;
                cout << "                                        Просмотр всех записей в таблице         " << endl;
                cout << "                             ===================================================" << endl;
                printTable();
                if (availabilityWorker) {
                    while (ok == false)
                    {
                        continueAnsw = getValueInt("    Ваш действия?\n1 - Сортировка по имени\n2 - Сортировка по фамиии\n3 - Сортировка по отделу\n4 - Назад\n");
                        if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4)
                        {
                            switch (continueAnsw)
                            {
                            case 1:
                                system("cls");
                                cout << "    Сортировка по имени\n" << endl;
                                sortFN();
                                printTable();
                                continue;
                            case 2:
                                system("cls");
                                cout << "    Сортировка по фамиии\n" << endl;
                                sortLN();
                                printTable();
                                continue;
                            case 3:
                                system("cls");
                                cout << "    Сортировка по отделу\n" << endl;
                                sortDep();
                                printTable();
                                continue;
                            case 4:
                                GetChoiceMenuAdmin();
                                break;
                            default:
                                GetChoiceMenuAdmin();
                                break;
                            }
                        }
                        else
                        {
                            cout << "    Введите одно из указанных чисел.\n" << endl;
                        }
                    }
                }
                else
                {
                    system("pause");
                    GetChoiceMenuAdmin();
                }
                break;
            case 4:
                GetChoiceWorkAtProfile();
                break;
            case 5:
                cout << "    Выход!";
                exit(0);
            default:
                GetChoiceMenuAdmin();
                break;
            }
        }
        
    }
   
}

void GetChoiceWorkAtFileData()
{
    system("cls");
    if (!fileCreate)
    {
        cout << "                             ===================================================" << endl;
        cout << "                                    Файл данных сотрудников не существует       " << endl;
        cout << "                             ===================================================" << endl;
    }
    DisplayWorkAtFileData();
    int choice = getValueInt("    Введите числовое значение:");
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                        Создать файл данных сотрудника          " << endl;
        cout << "                             ===================================================" << endl;
        if (CreateOrDeleteFD(true))
        {
            cout << "    Файл данных успешно создан" << endl;
            fileCreate = true;
            system("pause");
            GetChoiceMenuAdmin();
        }
        else
        {
            cout << "    Ошибка при создании. Повторите попытку позже." << endl;
            fileCreate = false;
            system("pause");
            GetChoiceMenuAdmin();
        }
        break;
    case 2:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                       Удалить файл данных сотрудников          " << endl;
        cout << "                             ===================================================" << endl;
        if (CreateOrDeleteFD(false))
        {
            cout << "    Файл данных успешно удален" << endl;
            choiceCreateFD = true;
            fileCreate = false;
            system("pause");
            GetChoiceMenuAdmin();
        }
        else
        {
            cout << "    Ошибка при удалении. Повторите попытку позже." << endl;
            fileCreate = true;
            system("pause");
            GetChoiceMenuAdmin();
        }
        break;
    case 3:
        GetChoiceMenuAdmin();
        break;
    case 4:
        cout << "    Выход!";
        exit(0);
    default:
        GetChoiceWorkAtFileData();
        break;
    }
}

void GetChoiceWorkAtRecords()
{
    system("cls");
    DisplayWorkAtRecords();
    int choice = getValueInt("    Введите числовое значение:");
    bool ok = false;
    int continueAnsw;
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                             Добавление записи                  " << endl;
        cout << "                             ===================================================" << endl;
        if (creatRecordInFD(false))
        {
            getAllWorkerFD();
            cout << "    Запись успешно добавлена" << endl;
            getAllWorkerFD();
            system("pause");
            GetChoiceWorkAtRecords();
        }
        else
        {
            cout << "    Запись успешно добавлена" << endl;
            system("pause");
            GetChoiceWorkAtRecords();
        }
        break;
    case 2:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                             Редактирование записи              " << endl;
        cout << "                             ===================================================" << endl;
        if (changeWirkerInMemory())
        {
            cout << "    Данные работника изменены" << endl;
            system("pause");
            GetChoiceWorkAtRecords();
        }
        else
        {
            cout << "    Ошибка. Данные не изменены." << endl;
            system("pause");
            GetChoiceWorkAtRecords();
        }
        break;
    case 3:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                               Удаление записи                  " << endl;
        cout << "                             ===================================================" << endl;
        if (deleteWirkerInMemory())
        {
            cout << "    Работник удалён." << endl;
            system("pause");
            GetChoiceWorkAtRecords();
        }
        else
        {
            cout << "    Ошибка. Данные не изменены." << endl;
            system("pause");
            GetChoiceWorkAtRecords();
        }
        break;
    case 4:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                        Просмотр всех записей в таблице         " << endl;
        cout << "                             ===================================================" << endl;
        printTable();
        if (availabilityWorker) {
            while (ok == false)
            {
                continueAnsw = getValueInt("    Ваш действия?\n1 - Сортировка по имени\n2 - Сортировка по фамиии\n3 - Сортировка по отделу\n4 - Назад\n");
                if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4)
                {
                    switch (continueAnsw)
                    {
                    case 1:
                        system("cls");
                        cout << "    Сортировка по имени\n" << endl;
                        sortFN();
                        printTable();
                        continue;
                    case 2:
                        system("cls");
                        cout << "    Сортировка по фамиии\n" << endl;
                        sortLN();
                        printTable();
                        continue;
                    case 3:
                        system("cls");
                        cout << "    Сортировка по отделу\n" << endl;
                        sortDep();
                        printTable();
                        continue;
                    case 4:
                        GetChoiceWorkAtRecords();
                        break;
                    default:
                        GetChoiceWorkAtRecords();
                        break;
                    }
                }
                else
                {
                    cout << "    Введите одно из указанных чисел.\n" << endl;
                }
            }
        }
        else
        {
            system("pause");
            GetChoiceWorkAtRecords();
        }
        break;
    case 5:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                            Сокращенный просмотр                " << endl;
        cout << "                                           всех записей в таблице               " << endl;
        cout << "                             ===================================================" << endl;
        printTableAbbr();
        if (availabilityWorker) {
            while (ok == false)
            {
                continueAnsw = getValueInt("    Ваш действия?\n1 - Сортировка по имени\n2 - Сортировка по фамиии\n3 - Сортировка по отделу\n4 - Назад\n");
                if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4)
                {
                    switch (continueAnsw)
                    {
                    case 1:
                        system("cls");
                        cout << "    Сортировка по имени\n" << endl;
                        sortFN();
                        printTableAbbr();
                        continue;
                    case 2:
                        system("cls");
                        cout << "    Сортировка по фамиии\n" << endl;
                        sortLN();
                        printTableAbbr();
                        continue;
                    case 3:
                        system("cls");
                        cout << "    Сортировка по отделу\n" << endl;
                        sortDep();
                        printTableAbbr();
                        continue;
                    case 4:
                        GetChoiceWorkAtRecords();
                        break;
                    default:
                        GetChoiceWorkAtRecords();
                        break;
                    }
                }
                else
                {
                    cout << "    Введите одно из указанных чисел.\n" << endl;
                }
            }
        }
        else
        {
            system("pause");
            GetChoiceWorkAtRecords();
        }
        break;
    case 6:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                                Поиск записей                   " << endl;
        cout << "                                              и вывод в таблицу                 " << endl;
        cout << "                             ===================================================" << endl;
        while (ok == false)
        {
            continueAnsw = getValueInt("\nВарианты поиска?\n1 - по фамилии\n2 - по имени\n3 - по отчетсву\n4 - по отделу\n5 - Назад\n6 - Выход\n");
            if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4 || continueAnsw == 5)
            {
                ok = true;
            }
            else
            {
                cout << "Введите одно из указанных чисел.\n";
            }
        }
        if (continueAnsw == 5)
        {
            GetChoiceMenuAdmin();
        }
        if (continueAnsw == 6)
        {
            cout << "    Выход!";
            exit(0);
        }
        searchAndPrintTable(continueAnsw);
        system("pause");
        GetChoiceWorkAtRecords();
        break;
    case 7:
        GetChoiceMenuAdmin();
        break;
    case 8:
        cout << "    Выход!";
        exit(0);
    default:
        GetChoiceWorkAtRecords();
        break;
    }
}

void GetChoiceWorkAtProfile()
{
    system("cls");
    if (!fileCreate)
    {
        cout << "                             ===================================================" << endl;
        cout << "                                    Файл данных сотрудников не существует       " << endl;
        cout << "                             ===================================================" << endl;
    }
    DisplayWorkAtProfile();
    int choice = getValueInt("    Введите числовое значение:");
    Profile newUser = Profile("", "", 0);
    Profile interimProfile = Profile("", "", 0);
    string out;
    string oldUserName;
    int continueAnsw;
    bool ok = false;
    ifstream fin;
    switch (choice)   
    {
    case 1:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                        Добавление новой учетной записи         " << endl;
        cout << "                             ===================================================" << endl;
        newUser = GetNewProfileData();
        if (newUser.level > 3)
        {
            cout << "    Указан неверный уровень учетной записи.\n" << endl;
            system("pause");
            GetChoiceWorkAtProfile();
        }
        fin.open(newUser.name + ".txt", ios_base::in);
        if (!fin.is_open()) // если файл не открыт
        {
            while (ok == false)
            {
                continueAnsw = getValueInt("    Продолжаем?\n1 - Да\n2 - нет\n");
                if (continueAnsw == 1 || continueAnsw == 2)
                {
                    ok = true;
                }
                else
                {
                    cout << "    Введите одно из указанных чисел.\n" << endl;
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
                cout << "    Операция прервана\n" << endl;
                GetChoiceWorkAtProfile();
            }
            ok = false;
            break;
        }
        else
        {
            fin.close();
            cout << "    Пользователь с таким логином существует.\n";
            system("pause");
            GetChoiceWorkAtProfile();
            ok = false;
            break;
        }
        
    case 2:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                        Редактирование учетной записи           " << endl;
        cout << "                             ===================================================" << endl;
        newUser.name = getValueStr("    Введите имя учетной записи, которую желаете изменить");
        fin.open(newUser.name + ".txt", ios_base::in);
        if (!fin.is_open()) // если файл не открыт
        {
            cout << "    Пользователь с таким логином не найден.\n";
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
                continueAnsw = getValueInt("    Продолжаем?\n1 - Да\n2 - нет\n");
                if (continueAnsw == 1 || continueAnsw == 2)
                {
                    ok = true;
                }
                else
                {
                    cout << "    Введите одно из указанных чисел.\n";
                }
            }
            if (continueAnsw == 1)
            {
                cout << "    Введите новые данные учетной записи\n";
                interimProfile = GetNewProfileData();
                out = WorkProfileFD(interimProfile, true, false);
                cout << "    Учетная запись изменена\n";
                if (newUser.name != interimProfile.name)
                {
                    WorkProfileFD(newUser, false, true);
                }
                system("pause");
                GetChoiceWorkAtProfile();
            }
            if (continueAnsw == 2)
            {
                cout << "    Операция прервана\n";
                GetChoiceWorkAtProfile();
            }
            ok = false;
            break;
        }
    case 3:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                           Удаление учетной записи              " << endl;
        cout << "                             ===================================================" << endl;
        ok = false;
        while (ok == false)
        {
            system("pause");
            oldUserName = getValueStr("    Введите логин удаляемого объекта");
            string interimFN = oldUserName + ".txt";
            ifstream finn(interimFN, ios_base::in);
            if (!finn.is_open()) // если файл не открыт
            {
                cout << "    Пользователь с таким логином не найден!\n";
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
            cout << "    Операция прервана\n";
            GetChoiceWorkAtProfile();
        }

        break;
    case 4:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                          Смена пароля учетной записи           " << endl;
        cout << "                             ===================================================" << endl;
        out = WorkProfileFD(setNewPass(), true, false);
        cout << "    пароль изменен \n";
        system("pause");
        GetChoiceWorkAtProfile();
        break;
    case 5:
        GetChoiceMenuAdmin();
        break;
    case 6:
        cout << "    Выход!\n";
        exit(0);
    default:
        GetChoiceWorkAtProfile();
        break;
    }
}

void GetChoiceMenuManager()
{
    system("cls");
    if (!fileCreate)
    {
        cout << "                             ===================================================" << endl;
        cout << "                                    Файл данных сотрудников не существует       " << endl;
        cout << "                             ===================================================" << endl;
        system("pause");
        cout << "    Выход!\n";
        exit(0);
    }
    DisplayMenuManager();
    int choice = getValueInt("    Введите числовое значение:");
    bool ok = false;
    int continueAnsw;
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                             Добавление записи                  " << endl;
        cout << "                             ===================================================" << endl;
        if (creatRecordInFD(false))
        {
            getAllWorkerFD();
            cout << "    Запись успешно добавлена" << endl;
            getAllWorkerFD();
            system("pause");
            GetChoiceMenuManager();
        }
        else
        {
            cout << "    Запись успешно добавлена" << endl;
            system("pause");
            GetChoiceMenuManager();
        }
        break;
    case 2:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                             Редактирование записи              " << endl;
        cout << "                             ===================================================" << endl;
        if (changeWirkerInMemory())
        {
            cout << "    Данные работника изменены" << endl;
            system("pause");
            GetChoiceMenuManager();
        }
        else
        {
            cout << "    Ошибка. Данные не изменены." << endl;
            system("pause");
            GetChoiceMenuManager();
        }
        break;
    case 3:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                               Удаление записи                  " << endl;
        cout << "                             ===================================================" << endl;
        if (deleteWirkerInMemory())
        {
            cout << "    Работник удалён." << endl;
            system("pause");
            GetChoiceMenuManager();
        }
        else
        {
            cout << "    Ошибка. Данные не изменены." << endl;
            system("pause");
            GetChoiceMenuManager();
        }
        break;
    case 4:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                        Просмотр всех записей в таблице         " << endl;
        cout << "                             ===================================================" << endl;
        printTable();
        if (availabilityWorker) {
            while (ok == false)
            {
                continueAnsw = getValueInt("    Ваш действия?\n1 - Сортировка по имени\n2 - Сортировка по фамиии\n3 - Сортировка по отделу\n4 - Назад\n");
                if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4)
                {
                    switch (continueAnsw)
                    {
                    case 1:
                        system("cls");
                        cout << "    Сортировка по имени\n" << endl;
                        sortFN();
                        printTable();
                        continue;
                    case 2:
                        system("cls");
                        cout << "    Сортировка по фамиии\n" << endl;
                        sortLN();
                        printTable();
                        continue;
                    case 3:
                        system("cls");
                        cout << "    Сортировка по отделу\n" << endl;
                        sortDep();
                        printTable();
                        continue;
                    case 4:
                        GetChoiceMenuManager();
                        break;
                    default:
                        GetChoiceMenuManager();
                        break;
                    }
                }
                else
                {
                    cout << "    Введите одно из указанных чисел.\n" << endl;
                }
            }
        }
        else
        {
            system("pause");
            GetChoiceMenuManager();
        }
        break;
    case 5:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                            Сокращенный просмотр                " << endl;
        cout << "                                           всех записей в таблице               " << endl;
        cout << "                             ===================================================" << endl;
        printTableAbbr();
        if (availabilityWorker) {
            while (ok == false)
            {
                continueAnsw = getValueInt("    Ваш действия?\n1 - Сортировка по имени\n2 - Сортировка по фамиии\n3 - Сортировка по отделу\n4 - Назад\n");
                if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4)
                {
                    switch (continueAnsw)
                    {
                    case 1:
                        system("cls");
                        cout << "    Сортировка по имени\n" << endl;
                        sortFN();
                        printTableAbbr();
                        continue;
                    case 2:
                        system("cls");
                        cout << "    Сортировка по фамиии\n" << endl;
                        sortLN();
                        printTableAbbr();
                        continue;
                    case 3:
                        system("cls");
                        cout << "    Сортировка по отделу\n" << endl;
                        sortDep();
                        printTableAbbr();
                        continue;
                    case 4:
                        GetChoiceMenuManager();
                        break;
                    default:
                        GetChoiceMenuManager();
                        break;
                    }
                }
                else
                {
                    cout << "    Введите одно из указанных чисел.\n" << endl;
                }
            }
        }
        else
        {
            system("pause");
            GetChoiceMenuManager();
        }
        break;
    case 6:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                                Поиск записей                   " << endl;
        cout << "                                              и вывод в таблицу                 " << endl;
        cout << "                             ===================================================" << endl;
        while (ok == false)
        {
            continueAnsw = getValueInt("\nВарианты поиска?\n1 - по фамилии\n2 - по имени\n3 - по отчетсву\n4 - по отделу\n5 - Назад\n6 - Выход\n");
            if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4 || continueAnsw == 5)
            {
                ok = true;
            }
            else
            {
                cout << "Введите одно из указанных чисел.\n";
            }
        }
        if (continueAnsw == 5)
        {
            GetChoiceMenuManager();
        }
        if (continueAnsw == 6)
        {
            cout << "    Выход!";
            exit(0);
        }
        searchAndPrintTable(continueAnsw);
        system("pause");
        GetChoiceMenuManager();
        break;
    case 7:
        cout << "    Выход!";
        exit(0);
    default:
        GetChoiceMenuManager();
        break;
    }
}

void GetChoiceMenuUser()
{
    system("cls");
    if (!fileCreate || !availabilityWorker)
    {
        cout << "                             ===================================================" << endl;
        cout << "                                    Файл данных сотрудников не существует       " << endl;
        cout << "                                          или записей не обнаружено             " << endl;
        cout << "                             ===================================================" << endl;
        system("pause");
        cout << "    Выход!\n";
        exit(0);
    }
    DisplayMenuUser();
    int choice = getValueInt("    Введите числовое значение:");
    bool ok = false;
    int continueAnsw;
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                        Просмотр всех записей в таблице         " << endl;
        cout << "                             ===================================================" << endl;
        printTable();
        if (availabilityWorker) {
            while (ok == false)
            {
                continueAnsw = getValueInt("    Ваш действия?\n1 - Сортировка по имени\n2 - Сортировка по фамиии\n3 - Сортировка по отделу\n4 - Назад\n");
                if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4)
                {
                    switch (continueAnsw)
                    {
                    case 1:
                        system("cls");
                        cout << "    Сортировка по имени\n" << endl;
                        sortFN();
                        printTable();
                        continue;
                    case 2:
                        system("cls");
                        cout << "    Сортировка по фамиии\n" << endl;
                        sortLN();
                        printTable();
                        continue;
                    case 3:
                        system("cls");
                        cout << "    Сортировка по отделу\n" << endl;
                        sortDep();
                        printTable();
                        continue;
                    case 4:
                        GetChoiceMenuUser();
                        break;
                    default:
                        GetChoiceMenuUser();
                        break;
                    }
                }
                else
                {
                    cout << "    Введите одно из указанных чисел.\n" << endl;
                }
            }
        }
        else
        {
            system("pause");
            GetChoiceMenuUser();
        }
        break;
    case 2:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                            Сокращенный просмотр                " << endl;
        cout << "                                           всех записей в таблице               " << endl;
        cout << "                             ===================================================" << endl;
        printTableAbbr();
        if (availabilityWorker) {
            while (ok == false)
            {
                continueAnsw = getValueInt("    Ваш действия?\n1 - Сортировка по имени\n2 - Сортировка по фамиии\n3 - Сортировка по отделу\n4 - Назад\n");
                if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4)
                {
                    switch (continueAnsw)
                    {
                    case 1:
                        system("cls");
                        cout << "    Сортировка по имени\n" << endl;
                        sortFN();
                        printTableAbbr();
                        continue;
                    case 2:
                        system("cls");
                        cout << "    Сортировка по фамиии\n" << endl;
                        sortLN();
                        printTableAbbr();
                        continue;
                    case 3:
                        system("cls");
                        cout << "    Сортировка по отделу\n" << endl;
                        sortDep();
                        printTableAbbr();
                        continue;
                    case 4:
                        GetChoiceMenuUser();
                        break;
                    default:
                        GetChoiceMenuUser();
                        break;
                    }
                }
                else
                {
                    cout << "    Введите одно из указанных чисел.\n" << endl;
                }
            }
        }
        else
        {
            system("pause");
            GetChoiceMenuUser();
        }
        break;
    case 3:
        system("cls");
        cout << "                             ===================================================" << endl;
        cout << "                                                Поиск записей                   " << endl;
        cout << "                                              и вывод в таблицу                 " << endl;
        cout << "                             ===================================================" << endl;
        while (ok == false)
        {
            continueAnsw = getValueInt("\nВарианты поиска?\n1 - по фамилии\n2 - по имени\n3 - по отчетсву\n4 - по отделу\n5 - Назад\n6 - Выход\n");
            if (continueAnsw == 1 || continueAnsw == 2 || continueAnsw == 3 || continueAnsw == 4 || continueAnsw == 5)
            {
                ok = true;
            }
            else
            {
                cout << "Введите одно из указанных чисел.\n";
            }
        }
        if (continueAnsw == 5)
        {
            GetChoiceMenuUser();
        }
        if (continueAnsw == 6)
        {
            cout << "    Выход!";
            exit(0);
        }
        searchAndPrintTable(continueAnsw);
        system("pause");
        GetChoiceMenuUser();
        break;
    case 4:
        cout << "    Выход!";
        exit(0);
    default:
        GetChoiceMenuUser();
        break;
    }

}

int main(int argc, char* argv[])
{
    // развернуть консоль
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
    // установка локали
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // проверка файла данных
    fileCreate = SearchFD();
    // проверка фала админа
    if (!CreateOrDeleteAdminFile())
    {
        int continueAnsw;
        bool ok = false;
        Profile admin = Profile("", "", 0);
        string out;
        while (ok == false)
        {
            system("cls");
            cout << "                             ===================================================" << endl;
            cout << "                                          Администратор не обнаружен            " << endl;
            cout << "                             ===================================================" << endl;
            continueAnsw = getValueInt("    Создать админа?\n1 - Да\n2 - нет\n");
            if (continueAnsw == 1 || continueAnsw == 2)
            {
                switch (continueAnsw)
                {
                case 1:
                    admin.name = "admin";
                    admin.pass = "pass";
                    admin.level = 1;
                    out = WorkProfileFD(admin, false, false);
                    cout << out;
                    cout << "\n    пароль для входа: pass\n";
                    system("pause");
                    ok = true;
                    break;
                case 2:
                    cout << "    Выход!\n";
                    exit(0);
                default:
                    cout << "    Выход!\n";
                    exit(0);
                }
            }
            else
            {
                cout << "    Введите одно из указанных чисел.\n" << endl;
            }
        }
    }
    // вход при наличии файла админа
    GetLogiAndPass();
}