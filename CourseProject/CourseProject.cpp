#include <Windows.h>
#include <string> //   для строк
#include <iostream> // файловый 
#include <iostream> // файловый 
#include <fstream> //  файловый 
#include <cstdlib> //  для использования функции exit()

using namespace std;
using std::string;



/*
============================================
            объекты программы
============================================
*/

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

/*
============================================
            объявление функций
============================================
*/
// проверка на наличие файла данных
bool SearchFD();
// создание и затирание файла данных
bool CreateOrDeleteFD(bool rewrote, bool createOrDelete);
// запись данных в файла профиля
string WorkProfileFD(Profile user, bool rePass, bool del);
// смена пароля имеющемуся пользователю
Profile setNewPass();
// сбор данных для пользователя
Profile GetNewProfileData();
// Функции выбора в меню
void GetChoiceMenuAdmin();
void GetChoiceWorkAtFileData();
void GetChoiceWorkAtRecords();
void GetChoiceWorkAtProfile();
void GetChoiceMenuManager();
void GetChoiceMenuUser();



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
            функции принта меню                     !!! переписать
============================================
*/

void DisplayMainMenu()
{
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
    cout << "4 - Работа с учетными записями\n";
    cout << "5 - Выход\n";
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

void DisplayWorkAtProfile()
{
    cout << "Меню работы с учетной записи\n";
    cout << "Пожалуйста укажите пункт\n";
    cout << "1 - Добавление учетной записи\n";
    cout << "2 - Редактирование учетной записи\n";
    cout << "3 - Удаление учетной записи\n";
    cout << "4 - Смена пароля учетной записи\n";
    cout << "5 - Назад\n";
    cout << "6 - Выход\n";
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

/*
============================================
            функции проверки
============================================
*/

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
            cout << "\033[2J\033[1;1H";
            string choiceLogin = getValueStr("Введите логин");
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

// проверка на наличие файла данных
bool SearchFD()
{
    ifstream fin("dataFile.txt", ios_base::in);
    if (!fin.is_open())
    {
        return false;
    }
    else
    {
        fin.close();
        return true;
    }
}

/*
============================================
      функции работы с файлом данных
============================================
*/

// создание и затирание файла данных
bool CreateOrDeleteFD(bool rewrote, bool createOrDelete)
{
    if (createOrDelete)
    {
        ofstream fout("dataFile.txt", ios_base::app);
        fout << "#"; 
        fout.close();
        return true;
    }
    else
    {
        if (remove("dataFile.txt") != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
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



int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    GetLogiAndPass();
}