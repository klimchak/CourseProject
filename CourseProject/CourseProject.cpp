#include <Windows.h>
#include <string> //   для строк
#include <iostream> // файловый 
#include <iostream> // файловый 
#include <fstream> //  файловый 
#include <cstdlib> //  для использования функции exit()

using namespace std;
using std::string;

int getValueInt()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        
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

string getValueStr()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        
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


int GetInput()
{
    int choice;
    cin >> choice;
    return choice;
}

void DisplayMainMenu()
{
    //cout << "\033[2J\033[1;1H";
    cout << "Окно входа\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Администратор\n";
    cout << "2 - Менеджер\n";
    cout << "3 - Пользователь\n";
    cout << "4 - Выход\n";
    cout << "Ваш выбор: ";
}

void DisplayMenuAdmin()
{
    cout << "Меню администратора\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Работа с файлами данных\n";
    cout << "2 - Работа с записями в файле данных\n";
    cout << "3 - Просмотр всех записей в таблице\n";
    cout << "4 - Работа с менеджерами\n";
    cout << "5 - Работа с пользователями\n";
    cout << "6 - Выход\n";
    cout << "Ваш выбор: ";
}

void DisplayWorkAtFileData()
{
    cout << "Меню работы с файлами данных\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Создать файл данных сотрудников\n";
    cout << "2 - Создать файл данных отделов\n";
    cout << "3 - Удалить файл данных сотрудников\n";
    cout << "4 - Удалить файл данных отделов\n";
    cout << "5 - Назад\n";
    cout << "6 - Выход\n";
    cout << "Ваш выбор: ";
}

void DisplayWorkAtRecords()
{
    cout << "Меню работы с записями\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Добавление записи\n";
    cout << "2 - Редактирование записи\n";
    cout << "3 - Удаление записи\n";
    cout << "4 - Сортировка записей по имени\n";
    cout << "5 - Сортировка записей по фамилии\n";
    cout << "6 - Сортировка записей по оделу\n";
    cout << "7 - Просмотр всех записей в таблице\n";
    cout << "8 - Назад\n";
    cout << "9 - Выход\n";
    cout << "Ваш выбор: ";
}

void DisplayWorkAtManagerProfile()
{
    cout << "Меню работы с менеджерами\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Добавление менеджера\n";
    cout << "2 - Редактирование менеджера\n";
    cout << "3 - Удаление менеджера\n";
    cout << "4 - Смена пароля менеджера\n";
    cout << "8 - Назад\n";
    cout << "9 - Выход\n";
    cout << "Ваш выбор: ";
}

void DisplayWorkAtUserProfile()
{
    cout << "Меню работы с пользователями\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Добавление пользователя\n";
    cout << "2 - Редактирование пользователя\n";
    cout << "3 - Удаление пользователя\n";
    cout << "4 - Смена пароля пользователя\n";
    cout << "8 - Назад\n";
    cout << "9 - Выход\n";
    cout << "Ваш выбор: ";
}

void DisplayMenuManager()
{
    cout << "Меню мменеджера\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Добавление записи\n";
    cout << "2 - Редактирование записи\n";
    cout << "3 - Удаление записи\n";
    cout << "4 - Сортировка записей по имени\n";
    cout << "5 - Сортировка записей по фамилии\n";
    cout << "6 - Сортировка записей по оделу\n";
    cout << "7 - Просмотр всех записей в таблице\n";
    cout << "5 - Выход\n";
    cout << "Ваш выбор: ";
}

void DisplayMenuUser()
{
    cout << "Меню пользователя\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Просмотр всех записей в таблице\n";
    cout << "2 - Сортировка записей по имени\n";
    cout << "3 - Сортировка записей по фамилии\n";
    cout << "4 - Сортировка записей по оделу\n";
    cout << "5 - Выход\n";
    cout << "Ваш выбор: ";
}

/// <summary>
/// функции второго уровня
/// </summary>

void GetChoiceMenuAdmin()
{
    int choice = 0;
    do
    {
        system("cls");
        DisplayMenuAdmin();
        choice = GetInput();
        switch (choice)
        {
        case 1:
            DisplayWorkAtFileData();
            break;
        case 2:
            DisplayWorkAtRecords();
            break;
        case 3:
            cout << "Просмотр всех записей в таблице";
            break;
        case 4:
            DisplayMenuManager();
            break;
        case 5:
            DisplayMenuUser();
            break;
        case 6:
            cout << "Выход!";
            break;
        default:
            break;
        }
    } while (choice != 3);
}

void GetChoiceWorkAtFileData()
{
    int choice = 0;
    do
    {
        system("cls");
        DisplayWorkAtFileData();
        choice = GetInput();
        switch (choice)
        {
        case 1:
            cout << "Создать файл данных сотрудников";
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
            break;
        default:
            break;
        }
    } while (choice != 3);
}

void GetChoiceWorkAtRecords()
{
    int choice = 0;
    do
    {
        system("cls");
        DisplayWorkAtRecords();
        choice = GetInput();
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
            break;
        default:
            break;
        }
    } while (choice != 3);
}

void GetChoiceWorkAtManagerProfile()
{
    int choice = 0;
    do
    {
        system("cls");
        DisplayWorkAtManagerProfile();
        choice = GetInput();
        switch (choice)
        {
        case 1:
            cout << "Добавление менеджера";
            break;
        case 2:
            cout << "Редактирование менеджера";
            break;
        case 3:
            cout << "Удаление менеджера";
            break;
        case 4:
            cout << "Смена пароля менеджера";
            break;
        case 5:
            GetChoiceMenuAdmin();
            break;
        case 6:
            cout << "Выход!";
            break;
        default:
            break;
        }
    } while (choice != 3);
}

void GetChoiceWorkAtUserProfile()
{
    int choice = 0;
    do
    {
        system("cls");
        DisplayWorkAtUserProfile();
        choice = GetInput();
        switch (choice)
        {
        case 1:
            cout << "Добавление пользователя";
            break;
        case 2:
            cout << "Редактирование пользователя";
            break;
        case 3:
            cout << "Удаление пользователя";
            break;
        case 4:
            cout << "Смена пароля пользователя";
            break;
        case 5:
            GetChoiceMenuAdmin();
            break;
        case 6:
            cout << "Выход!";
            break;
        default:
            break;
        }
    } while (choice != 3);
}

void GetChoiceMenuManager()
{
    int choice = 0;
    do
    {
        system("cls");
        DisplayMenuManager();
        choice = GetInput();
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
            break;
        default:
            break;
        }
    } while (choice != 3);
}

void GetChoiceMenuUser()
{
    int choice = 0;
    do
    {
        system("cls");
        DisplayMenuUser();
        choice = GetInput();
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
            break;
        default:
            break;
        }
    } while (choice != 3);
}

/// <summary>
/// функции проверки логина и пароля
/// </summary>

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
            cout << "\033[2J\033[1;1H";
            cout << "Введите логин:\n";
            string choiceLogin = getValueStr();
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
            cout << "\033[2J\033[1;1H";
            cout << "Введите пароль:\n";
            string choicePass = getValueStr();
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


/// <summary>
/// функция первого уровня
/// </summary>



int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    GetLogiAndPass();
}