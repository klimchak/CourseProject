#ifndef HEADER_H
#define HEADER_H

#include <Windows.h>
#include <string>
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "Profile.h"


struct Education;

struct workAt;

struct worker;

/*
============================================
            объ€вление функций
============================================
*/
// проверка на наличие файла данных
bool SearchFD();
// создание и затирание файла данных
bool CreateOrDeleteFD(bool rewrote, bool createOrDelete);
// запись данных в файла профил€
string WorkProfileFD(Profile user, bool rePass, bool del);
// смена парол€ имеющемус€ пользователю
Profile setNewPass();
// сбор данных дл€ пользовател€
Profile GetNewProfileData();
// ‘ункции выбора в меню
void GetChoiceMenuAdmin();
void GetChoiceWorkAtFileData();
void GetChoiceWorkAtRecords();
void GetChoiceWorkAtProfile();
void GetChoiceMenuManager();
void GetChoiceMenuUser();
// функции принта меню
void DisplayMainMenu();
void DisplayMenuAdmin();
void DisplayWorkAtFileData();
void DisplayWorkAtRecords();
void DisplayWorkAtProfile();
void DisplayMenuManager();
void DisplayMenuUser();
// функции получени€ значени€ с клавиатуры
int getValueInt(string mess);
string getValueStr(string mess);
// проверка парол€ и логина
void GetLogiAndPass();
// проверка на наличие файла данных
bool SearchFD();
// создание и затирание файла данных
bool CreateOrDeleteFD(bool createOrDelete);
// получение данных нового работника
worker CreateWorker();
// запись данных нового работника в файл данных
bool creatRecordInFD();
// принт таблицы файла данных
void printTable();


#endif