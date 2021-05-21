#ifndef HEADER_H
#define HEADER_H

#include <Windows.h>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>

struct Education;
struct workAt;
struct worker;
struct Profile;

extern bool availabilityWorker;
extern int varSort;
/*
============================================
            объявление функций
============================================
*/
// проверка на наличие файла данных
bool SearchFD();
// проеверка файла админа
bool CreateOrDeleteAdminFile();
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
// функции принта меню
void DisplayMenuAdmin();
void DisplayWorkAtFileData();
void DisplayWorkAtRecords();
void DisplayWorkAtProfile();
void DisplayMenuManager();
void DisplayMenuUser();
// функции получения значения с клавиатуры
// получения значения int
int getValueInt(string mess);
// получения значения string
string getValueStr(string mess);
// проверка пароля и логина
void GetLogiAndPass();
// проверка на наличие файла данных
bool SearchFD();
// создание и затирание файла данных
bool CreateOrDeleteFD(bool createOrDelete);
// сбор сведений по работнику
worker aggregationWorkerData();
// запись данных нового работника в файл данных (перезапись файла)
bool creatRecordInFD(bool atMemory);
// принт таблицы файла данных
void printTable();
// принт таблицы файла данных сокращенно
void printTableAbbr();
// поиск работника и принт таблицы
void searchAndPrintTable(int change);
// функция поиска в строке
bool search(string query, string fundStr);
// получение данных работников в память
void getAllWorkerFD();
// удаление данных работника в памяти и перезапись в файл
bool deleteWirkerInMemory();
// изменение данных работника в памяти и перезапись в файл
bool changeWirkerInMemory();
//сортировка
// компаратор last name
bool comparareLastName(const worker lhs, const worker rhs);
// компаратор first name
bool comparareFirstName(const worker lhs, const worker rhs);
// компаратор patronymic
bool comparareDepartment(const worker lhs, const worker rhs);
// функция сортировки
void sortLN();
void sortFN();
void sortDep();
#endif