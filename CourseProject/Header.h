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
            ���������� �������
============================================
*/
// �������� �� ������� ����� ������
bool SearchFD();
// ��������� ����� ������
bool CreateOrDeleteAdminFile();
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
void DisplayMenuAdmin();
void DisplayWorkAtFileData();
void DisplayWorkAtRecords();
void DisplayWorkAtProfile();
void DisplayMenuManager();
void DisplayMenuUser();
// ������� ��������� �������� � ����������
// ��������� �������� int
int getValueInt(string mess);
// ��������� �������� string
string getValueStr(string mess);
// �������� ������ � ������
void GetLogiAndPass();
// �������� �� ������� ����� ������
bool SearchFD();
// �������� � ��������� ����� ������
bool CreateOrDeleteFD(bool createOrDelete);
// ���� �������� �� ���������
worker aggregationWorkerData();
// ������ ������ ������ ��������� � ���� ������ (���������� �����)
bool creatRecordInFD(bool atMemory);
// ����� ������� ����� ������
void printTable();
// ����� ������� ����� ������ ����������
void printTableAbbr();
// ����� ��������� � ����� �������
void searchAndPrintTable(int change);
// ������� ������ � ������
bool search(string query, string fundStr);
// ��������� ������ ���������� � ������
void getAllWorkerFD();
// �������� ������ ��������� � ������ � ���������� � ����
bool deleteWirkerInMemory();
// ��������� ������ ��������� � ������ � ���������� � ����
bool changeWirkerInMemory();
//����������
// ���������� last name
bool comparareLastName(const worker lhs, const worker rhs);
// ���������� first name
bool comparareFirstName(const worker lhs, const worker rhs);
// ���������� patronymic
bool comparareDepartment(const worker lhs, const worker rhs);
// ������� ����������
void sortLN();
void sortFN();
void sortDep();
#endif