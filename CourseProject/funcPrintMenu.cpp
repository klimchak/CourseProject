#include <Windows.h>
#include <iostream>
#include "Header.h"

using namespace std;
extern bool fileCreate;
/*
============================================
            ������� ������ ����             
============================================
*/

void DisplayMenuAdmin()
{
    if (!fileCreate)
    {
        cout << "=================================================\n";
        cout << "              ���� ��������������\n";
        cout << "=================================================\n";
        cout << "\n";
        cout << "    ���������� ������� �����\n";
        cout << "    1 - ������ � ������� ������\n";
        cout << "    2 - ������ � �������� ��������\n";
        cout << "    3 - �����\n";
        cout << "    ��� �����: ";
    }
    else
    {
        cout << "=================================================\n";
        cout << "              ���� ��������������\n";
        cout << "=================================================\n";
        cout << "\n";
        cout << "    ���������� ������� �����\n";
        cout << "    1 - ������ � ������ ������\n";
        cout << "    2 - ������ � �������� � ����� ������\n";
        cout << "    3 - �������� ���� ������� � �������\n";
        cout << "    4 - ������ � �������� ��������\n";
        cout << "    5 - �����\n";
        cout << "    ��� �����: ";
    }

}

void DisplayWorkAtFileData()
{
    cout << "=========================================================\n";
    cout << "              ���� ������ � ������� ������\n";
    cout << "=========================================================\n";
    cout << "\n";
    cout << "    ���������� ������� �����\n";
    cout << "    1 - ������� ���� ������ �����������\n";
    cout << "    2 - ������� ���� ������ �����������\n";
    cout << "    3 - �����\n";
    cout << "    4 - �����\n";
    cout << "    ��� �����: ";
}

void DisplayWorkAtRecords()
{
    cout << "=================================================\n";
    cout << "              ���� ������ � ��������\n";
    cout << "=================================================\n";
    cout << "\n";
    cout << "    ���������� ������� �����\n";
    cout << "    1 - ���������� ������\n";
    cout << "    2 - �������������� ������\n";
    cout << "    3 - �������� ������\n";
    cout << "    4 - �������� ���� ������� � �������\n";
    cout << "    5 - ����������� �������� ���� ������� � �������\n";
    cout << "    6 - ����� �������\n";
    cout << "    7 - �����\n";
    cout << "    8 - �����\n";
    cout << "    ��� �����: ";
}

void DisplayWorkAtProfile()
{
    cout << "=====================================================\n";
    cout << "              ���� ������ � �������� ��������\n";
    cout << "=====================================================\n";
    cout << "\n";
    cout << "    ���������� ������� �����\n";
    cout << "    1 - ���������� ������� ������\n";
    cout << "    2 - �������������� ������� ������\n";
    cout << "    3 - �������� ������� ������\n";
    cout << "    4 - ����� ������ ������� ������\n";
    cout << "    5 - �����\n";
    cout << "    6 - �����\n";
    cout << "    ��� �����: ";
}

void DisplayMenuManager()
{
    cout << "==========================================\n";
    cout << "              ���� ���������\n";
    cout << "==========================================\n";
    cout << "\n";
    cout << "    ���������� ������� �����\n";
    cout << "    1 - ���������� ������\n";
    cout << "    2 - �������������� ������\n";
    cout << "    3 - �������� ������\n";
    cout << "    4 - �������� ���� ������� � �������\n";
    cout << "    5 - ����������� �������� ���� ������� � �������\n";
    cout << "    6 - ����� �������\n";
    cout << "    7 - �����\n";
    cout << "    ��� �����: ";
}

void DisplayMenuUser()
{
    cout << "===========================================\n";
    cout << "              ���� ������������\n";
    cout << "===========================================\n";
    cout << "\n";
    cout << "    ���������� ������� �����\n";
    cout << "    1 - �������� ���� ������� � �������\n";
    cout << "    2 - ����������� �������� ���� ������� � �������\n";
    cout << "    3 - ����� �������\n";
    cout << "    4 - �����\n";
    cout << "    ��� �����: ";
}

