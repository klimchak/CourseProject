#include <Windows.h>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "Profile.h"
#include "Header.h"
#include <stdio.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include "tabulate/table.hpp"
using namespace tabulate;

#if __cplusplus >= 201703L
#include <variant>
using std::variant;
#else
#include "tabulate/variant_lite.hpp"
using nonstd::variant;
#endif
using Row_t = std::vector<variant<std::string, const char*, Table>>;

using namespace std;
using std::string;

struct Education
{
    string nameEdComp;
    string spacialization;
    int yearEndEducation;
};

struct workAt
{
    string dateStartWork;
    string department;
    string position;
    string workTelNumber;
    string dateStopWork;
};

struct worker
{
    string firstName;
    string lastName;
    string patronymic;
    string birtday;
    Education educationWorker;
    string martStatus;
    string homeTelNumber;
    workAt workerPosition;
};

vector<worker> allWolker;
bool availabilityWorker;

// =====================================================
//         сортировка
// =====================================================
// компараторы
bool comparareLastName(const worker lhs, const worker rhs) {
    return lhs.lastName > rhs.lastName;
}
bool comparareFirstName(const worker lhs, const worker rhs) {
    return lhs.firstName > rhs.firstName;
}
bool comparareDepartment(const worker lhs, const worker rhs) {
    return lhs.workerPosition.department > rhs.workerPosition.department;
}
// сортировка по фамилии
void sortLN() {
    sort(allWolker.begin(), allWolker.end(), comparareLastName);
}
// сортировка по имени
void sortFN() {
    sort(allWolker.begin(), allWolker.end(), comparareFirstName);
}
// сортировка по отделу
void sortDep() {
    sort(allWolker.begin(), allWolker.end(), comparareDepartment);
}

// делитель строки
vector<string> split(const string& s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

// запись данных нового работника в файл данных (перезапись файла)
bool creatRecordInFD(bool atMemory)
{
    if (atMemory)
    {
        vector<string> allString;
        
        for (worker wk : allWolker)
        {
            string outStrInterim = "";
            outStrInterim = outStrInterim + "#" + wk.lastName
                            + "#" + wk.firstName
                            + "#" + wk.patronymic
                            + "#" + wk.birtday
                            + "#" + wk.educationWorker.nameEdComp
                            + "#" + wk.educationWorker.spacialization
                            + "#" + to_string(wk.educationWorker.yearEndEducation)
                            + "#" + wk.martStatus
                            + "#" + wk.homeTelNumber
                            + "#" + wk.workerPosition.dateStartWork
                            + "#" + wk.workerPosition.department
                            + "#" + wk.workerPosition.position
                            + "#" + wk.workerPosition.workTelNumber
                            + "#" + wk.workerPosition.dateStopWork;
            allString.push_back(outStrInterim);
        }
        std::ofstream out("dataFile.txt", std::ios::trunc);
        if (out.is_open())
        {
            for (string strInFile : allString)
            {
                out << strInFile << std::endl;
            }
            
        }
        out.close();
        return true;
    }
    else
    {
        worker newWorker = aggregationWorkerData();
        string outStr = "";
        outStr = outStr + "#" + newWorker.lastName
            + "#" + newWorker.firstName
            + "#" + newWorker.patronymic
            + "#" + newWorker.birtday
            + "#" + newWorker.educationWorker.nameEdComp
            + "#" + newWorker.educationWorker.spacialization
            + "#" + to_string(newWorker.educationWorker.yearEndEducation)
            + "#" + newWorker.martStatus
            + "#" + newWorker.homeTelNumber
            + "#" + newWorker.workerPosition.dateStartWork
            + "#" + newWorker.workerPosition.department
            + "#" + newWorker.workerPosition.position
            + "#" + newWorker.workerPosition.workTelNumber
            + "#" + newWorker.workerPosition.dateStopWork;
        std::ofstream out("dataFile.txt", std::ios::app);
        if (out.is_open())
        {
            out << outStr << std::endl;
        }
        out.close();
        return true;
    }
    
}

// принт таблицы файла данных
void printTable()
{
    if (allWolker.size() > 0)
    {
        Table workers;
        workers.add_row(Row_t{ "Фамилия", "Имя", "Отчество", "Дата рождения", "Сем. положение \n" "Дом. телефон", 
                                "Образование:\n- оконченное УО;\n- специализация\n- год окончания", "Дата приёма", 
                                "Сведения о найме:\n- отдел,\n- должность,\n- рабочий телефон", "Дата увольнения"});
        for (size_t i = 0; i < allWolker.size(); i++)
        {            
            workers.add_row(Row_t{ allWolker[i].lastName, allWolker[i].firstName, allWolker[i].patronymic, allWolker[i].birtday, 
                                    allWolker[i].martStatus + "\n" + allWolker[i].homeTelNumber, allWolker[i].educationWorker.nameEdComp + "\n" + allWolker[i].educationWorker.spacialization + "\n" + 
                                    to_string(allWolker[i].educationWorker.yearEndEducation) , allWolker[i].workerPosition.dateStartWork, allWolker[i].workerPosition.department + "\n" + 
                                    allWolker[i].workerPosition.position + "\n" + allWolker[i].workerPosition.workTelNumber, allWolker[i].workerPosition.dateStopWork });
        }
        workers.add_row(Row_t{ "Итого сотрудников: ", to_string(allWolker.size()), "", "", "", "", "", "", "" });
        workers.column(0).format().font_align(FontAlign::center);
        workers.column(1).format().font_align(FontAlign::center);
        workers.column(2).format().font_align(FontAlign::center);
        workers.column(3).format().font_align(FontAlign::center);
        workers.column(6).format().font_align(FontAlign::center);
        workers.column(8).format().font_align(FontAlign::center);
        int a = allWolker.size() + 1;
        for (size_t i = 0; i < 9; ++i) {
            workers[0][i].format().font_color(Color::yellow).font_style({ FontStyle::bold });
            workers[a][i].format().font_color(Color::green).font_style({ FontStyle::bold });
        }
        std::cout << workers << "\n\n";
    }
    else
    {
        cout << "                                                   " << endl;
        cout << "              Записей не обнаружено.               " << endl;
        cout << "                                                   " << endl;
    }
}

// принт таблицы файла данных сокращенно
void printTableAbbr()
{
    if (allWolker.size() > 0)
    {
        Table workers;
        workers.add_row(Row_t{ "Фамилия", "Имя", "Отчество", "Дата рождения", "Сем. положение \n" "Дом. телефон",  
                                "Сведения о найме:\n- отдел,\n- должность,\n- рабочий телефон"});
        for (size_t i = 0; i < allWolker.size(); i++)
        {            
            workers.add_row(Row_t{ allWolker[i].lastName, allWolker[i].firstName, allWolker[i].patronymic, allWolker[i].birtday, 
                                    allWolker[i].martStatus + "\n" + allWolker[i].homeTelNumber,  allWolker[i].workerPosition.department + "\n" + 
                                    allWolker[i].workerPosition.position + "\n" + allWolker[i].workerPosition.workTelNumber });
        }
        workers.add_row(Row_t{ "Итого сотрудников: ", to_string(allWolker.size()), "", "", "",  "" });
        workers.column(0).format().font_align(FontAlign::center);
        workers.column(1).format().font_align(FontAlign::center);
        workers.column(2).format().font_align(FontAlign::center);
        workers.column(3).format().font_align(FontAlign::center);
        int a = allWolker.size() + 1;
        for (size_t i = 0; i < 6; ++i) {
            workers[0][i].format().font_color(Color::yellow).font_style({ FontStyle::bold });
            workers[a][i].format().font_color(Color::green).font_style({ FontStyle::bold });
        }
        std::cout << workers << "\n\n";
    }
    else
    {
        cout << "                                                   " << endl;
        cout << "              Записей не обнаружено.               " << endl;
        cout << "                                                   " << endl;
    }
}

// функция поиска в строке
bool search(string query, string fundStr) {
    string queryDest;
    queryDest.resize(query.size());
    string fundStrDest;
    fundStrDest.resize(fundStr.size());
    transform(query.begin(), query.end(), queryDest.begin(), ::tolower);
    transform(fundStr.begin(), fundStr.end(), fundStrDest.begin(), ::tolower);
    size_t pos = fundStrDest.find(queryDest);
    if (pos != string::npos)
        return true;
    else
        return false;
}

// поиск работника и принт таблицы
void searchAndPrintTable(int change)
{
    if (allWolker.size() > 0)
    {
        bool ok = false;
        string query;
        vector<worker> searchWorkers;
        int continueAnsw;
        switch (change)
        {
        case 1:
            query = getValueStr("    Введите фамилию работника");
            break;
        case 2:
            query = getValueStr("    Введите имя работника");
            break;
        case 3:
            query = getValueStr("    Введите отчетсво работника");
            break;
        case 4:
            query = getValueStr("    Введите отдел");
            break;
        }
        for (size_t i = 0; i < allWolker.size(); i++)
        {
            if (change == 1 && search(query, allWolker[i].lastName))
            {
                searchWorkers.push_back(allWolker[i]);
            }
            if (change == 2 && search(query, allWolker[i].firstName))
            {
                searchWorkers.push_back(allWolker[i]);
            }
            if (change == 3 && search(query, allWolker[i].patronymic))
            {
                searchWorkers.push_back(allWolker[i]);
            }
            if (change == 4 && search(query, allWolker[i].workerPosition.department))
            {
                searchWorkers.push_back(allWolker[i]);
            }
        }
        if (searchWorkers.size() > 0)
        {
            Table workers;
            workers.add_row(Row_t{ "Фамилия", "Имя", "Отчество", "Дата рождения", "Сем. положение \n" "Дом. телефон",
                                    "Образование:\n- оконченное УО;\n- специализация\n- год окончания", "Дата приёма",
                                    "Сведения о найме:\n- отдел,\n- должность,\n- рабочий телефон", "Дата увольнения" });
            for (size_t i = 0; i < searchWorkers.size(); i++)
            {
                workers.add_row(Row_t{ searchWorkers[i].lastName, searchWorkers[i].firstName, searchWorkers[i].patronymic, searchWorkers[i].birtday,
                                        searchWorkers[i].martStatus + "\n" + searchWorkers[i].homeTelNumber, searchWorkers[i].educationWorker.nameEdComp + "\n" + searchWorkers[i].educationWorker.spacialization + "\n" +
                                        to_string(searchWorkers[i].educationWorker.yearEndEducation) , searchWorkers[i].workerPosition.dateStartWork, searchWorkers[i].workerPosition.department + "\n" +
                                        searchWorkers[i].workerPosition.position + "\n" + searchWorkers[i].workerPosition.workTelNumber, searchWorkers[i].workerPosition.dateStopWork });
            }
            workers.add_row(Row_t{ "Найдено сотрудников: ", to_string(searchWorkers.size()), "", "", "", "", "", "", "" });
            workers.column(0).format().font_align(FontAlign::center);
            workers.column(1).format().font_align(FontAlign::center);
            workers.column(2).format().font_align(FontAlign::center);
            workers.column(3).format().font_align(FontAlign::center);
            workers.column(6).format().font_align(FontAlign::center);
            workers.column(8).format().font_align(FontAlign::center);
            int a = searchWorkers.size() + 1;
            for (size_t i = 0; i < 9; ++i) {
                workers[0][i].format().font_color(Color::yellow).font_style({ FontStyle::bold });
                workers[a][i].format().font_color(Color::green).font_style({ FontStyle::bold });
            }
            std::cout << workers << "\n\n";
            searchWorkers.clear();
        }
        else
        {
            cout << "                                                   " << endl;
            cout << "              Записей не обнаружено.               " << endl;
            cout << "                                                   " << endl;
        }        
    }
    else
    {
        cout << "                                                   " << endl;
        cout << "              Записей не обнаружено.               " << endl;
        cout << "                                                   " << endl;
    }
}

// получение данных работников в память
void getAllWorkerFD()
{
    int amountOfWorker = 0;
    ifstream fin("dataFile.txt", ios_base::in);
    string line;
    vector<string> strs;
    if (!fin.is_open())
    {
        cout << "not" << endl;
        availabilityWorker = false;
    }
    else
    {
        allWolker.clear();
        while (getline(fin, line))
        {
            amountOfWorker++;
            strs.push_back(line);
        }
        for (string u : strs)
        {
            vector<string> workerVect = split(u, '#');
            worker interimWorker;
            for (size_t i = 0; i < workerVect.size(); i++)
            {
                switch (i)
                {
                case 1:
                    interimWorker.lastName = workerVect[i];
                    break;
                case 2:
                    interimWorker.firstName = workerVect[i];
                    break;
                case 3:
                    interimWorker.patronymic = workerVect[i];
                    break;
                case 4:
                    interimWorker.birtday = workerVect[i];
                    break;
                case 5:
                    interimWorker.educationWorker.nameEdComp = workerVect[i];
                    break;
                case 6:
                    interimWorker.educationWorker.spacialization = workerVect[i];
                    break;
                case 7:
                    interimWorker.educationWorker.yearEndEducation = stoi(workerVect[i]);
                    break;
                case 8:
                    interimWorker.martStatus = workerVect[i];
                    break;
                case 9:
                    interimWorker.homeTelNumber = workerVect[i];
                    break;
                case 10:
                    interimWorker.workerPosition.dateStartWork = workerVect[i];
                    break;
                case 11:
                    interimWorker.workerPosition.department = workerVect[i];
                    break;
                case 12:
                    interimWorker.workerPosition.position = workerVect[i];
                    break; 
                case 13:
                    interimWorker.workerPosition.workTelNumber = workerVect[i];
                    break; 
                case 14:
                    interimWorker.workerPosition.dateStopWork = workerVect[i];
                    break;              
                }
            }
            allWolker.push_back(interimWorker);
            if (allWolker.size() > 0)
            {
                availabilityWorker = true;
            }
            else
            {
                availabilityWorker = false;
            }
        }
    }
}

// изменение данных работника в памяти и перезапись в файл
bool changeWirkerInMemory()
{
    string searchWorkerLN = getValueStr("    Введите фамилию работника");
    string searchWorkerFN = getValueStr("    Введите имя работника");
    int indexWorker = -1;
    for (size_t i = 0; i < allWolker.size(); i++)
    {
        if (allWolker[i].firstName == searchWorkerFN)
        {
            if (allWolker[i].lastName == searchWorkerLN)
            {
                indexWorker = i;
            }
        }
        
    }
    if (indexWorker < 0)
    {
        return false;
    }
    worker newWorker = aggregationWorkerData();
    allWolker[indexWorker] = newWorker;
    if (creatRecordInFD(true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// удаление данных работника в памяти и перезапись в файл
bool deleteWirkerInMemory()
{
    string searchWorkerLN = getValueStr("    Введите фамилию работника");
    string searchWorkerFN = getValueStr("    Введите имя работника");
    int indexWorker = -1;
    auto iter = allWolker.cbegin();
    for (size_t i = 0; i < allWolker.size(); i++)
    {
        if (allWolker[i].firstName == searchWorkerFN)
        {
            if (allWolker[i].lastName == searchWorkerLN)
            {
                indexWorker = i;
            }
        }

    }
    if (indexWorker < 0)
    {
        return false;
    }
    allWolker.erase(iter + indexWorker);
    if (creatRecordInFD(true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// сбор сведений по работнику
worker aggregationWorkerData() {
    worker newWorker;
    newWorker.firstName = getValueStr("    Введите имя");
    newWorker.lastName = getValueStr("    Введите фамилию");
    newWorker.patronymic = getValueStr("    Введите отчество");
    newWorker.birtday = getValueStr("    Введите дату рождения в формате мм-дд-гггг : ");
    newWorker.educationWorker.nameEdComp = getValueStr("    Введите наименование УО");
    newWorker.educationWorker.spacialization = getValueStr("    Введите специализацию");
    newWorker.educationWorker.yearEndEducation = getValueInt("    Введите год окончания УО");
    newWorker.martStatus = getValueStr("    Укажите семейное положение");
    char* intStr;
    string intStrLine = getValueStr("    Введите номер в формате 121234567");
    intStr = &intStrLine[0];
    string intStrEnd = "";
    intStrEnd = intStrEnd + "+375(" + intStr[0] + intStr[1] + ")" + intStr[2] + intStr[3] + intStr[4] + "-" + intStr[5] + intStr[6] + "-" + intStr[7] + intStr[8];;
    newWorker.homeTelNumber = intStrEnd;
    newWorker.workerPosition.dateStartWork = getValueStr("    Введите дату прриема на работу в формате мм-дд-гггг : ");
    newWorker.workerPosition.department = getValueStr("    Введите название отдела : ");
    newWorker.workerPosition.position = getValueStr("    Введите должность : ");
    char* intStr2;
    string intStrLine2 = getValueStr("    Введите номер в формате 121234567");
    intStr2 = &intStrLine2[0];
    string intStrEnd2 = "";
    intStrEnd2 = intStrEnd2 + "+375(" + intStr2[0] + intStr2[1] + ")" + intStr2[2] + intStr2[3] + intStr2[4] + "-" + intStr2[5] + intStr2[6] + "-" + intStr2[7] + intStr2[8];;
    newWorker.workerPosition.workTelNumber = intStrEnd2;
    newWorker.workerPosition.dateStopWork = getValueStr("    Введите дату увольнения в формате мм-дд-гггг : ");
    return newWorker;
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
        if (!availabilityWorker)
        {
            getAllWorkerFD();
        }
        return true;
    }
}

// создание и удаление файла данных
bool CreateOrDeleteFD(bool createOrDelete)
{
    if (createOrDelete)
    {
        ofstream fout("dataFile.txt", ios_base::app);
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
            allWolker.clear();
            return true;
        }
    }
}

// проеверка файла админа
bool CreateOrDeleteAdminFile()
{
    ifstream fin("admin.txt", ios_base::in);
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