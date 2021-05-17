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
            ���������� �������
============================================
*/
// �������� �� ������� ����� ������
bool SearchFD();
// �������� � ��������� ����� ������
bool CreateOrDeleteFD(bool rewrote, bool createOrDelete);
// ������ ������ � ����� �������
string WorkProfileFD(Profile user, bool rePass, bool del);
// ����� ������ ���������� ������������
Profile setNewPass();
// ���� ������ ��� ������������
Profile GetNewProfileData();
// ������� ������ � ����
void GetChoiceMenuAdmin();
void GetChoiceWorkAtFileData();
void GetChoiceWorkAtRecords();
void GetChoiceWorkAtProfile();
void GetChoiceMenuManager();
void GetChoiceMenuUser();
// ������� ������ ����
void DisplayMainMenu();
void DisplayMenuAdmin();
void DisplayWorkAtFileData();
void DisplayWorkAtRecords();
void DisplayWorkAtProfile();
void DisplayMenuManager();
void DisplayMenuUser();
// ������� ��������� �������� � ����������
int getValueInt(string mess);
string getValueStr(string mess);
// �������� ������ � ������
void GetLogiAndPass();
// �������� �� ������� ����� ������
bool SearchFD();
// �������� � ��������� ����� ������
bool CreateOrDeleteFD(bool createOrDelete);
// ��������� ������ ������ ���������
worker CreateWorker();
// ������ ������ ������ ��������� � ���� ������
bool creatRecordInFD();
// ����� ������� ����� ������
void printTable();


#endif