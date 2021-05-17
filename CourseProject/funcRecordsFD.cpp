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

// �������� ������
vector<string> split(const string& s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

// ��������� ������ ������ ���������
worker CreateWorker()
{
    worker newWorker;
    bool ok = false;
    int colStep = 7;
    int step = 0;
    while (step > colStep)
    {
        if (step == 0)
        {
            newWorker.firstName = getValueStr("������� ���");
            step++;
        }
        if (step == 1)
        {
            newWorker.lastName = getValueStr("������� �������");
            step++;
        }
        if (step == 2)
        {
            newWorker.patronymic = getValueStr("������� ��������");
            step++;
        }
        if (step == 3)
        {
            newWorker.birtday = getValueStr("������� ���� �������� � ������� ��-��-���� : ");
            step++;
        }
        if (step == 4)
        {
            newWorker.educationWorker.nameEdComp = getValueStr("������� ������������ ��");
            newWorker.educationWorker.spacialization = getValueStr("������� �������������");
            newWorker.educationWorker.yearEndEducation = getValueInt("������� ��� ��������� ��");
            step++;
        }
        if (step == 5)
        {
            newWorker.martStatus = getValueStr("������� �������� ���������");
            step++;
        }
        if (step == 6)
        {
            cout << "\n ������� ����� � ������� 121234567\n";
            char intStr[10];
            cin.getline(intStr, 10);
            string intStrEnd = "";
            intStrEnd = intStrEnd + "+375(" + intStr[0] + intStr[1] + ")" + intStr[2] + intStr[3] + intStr[4] + "-" + intStr[5] + intStr[6] + "-" + intStr[7] + intStr[8];;
            newWorker.homeTelNumber = intStrEnd;
            step++;
        }
        if (step == 7)
        {
            newWorker.workerPosition.dateStartWork = getValueStr("������� ���� ������� �� ������ � ������� ��-��-���� : ");
            newWorker.workerPosition.department = getValueStr("������� �������� ������ : ");
            newWorker.workerPosition.position = getValueStr("������� ��������� : ");
            cout << "\n ������� �������� ����� �������� � ������� 121234567\n";
            char intStr[10];
            cin.getline(intStr, 10);
            string intStrEnd = "";
            intStrEnd = intStrEnd + "+375(" + intStr[0] + intStr[1] + ")" + intStr[2] + intStr[3] + intStr[4] + "-" + intStr[5] + intStr[6] + "-" + intStr[7] + intStr[8];;
            newWorker.workerPosition.workTelNumber = intStrEnd;
            newWorker.workerPosition.dateStopWork = getValueStr("������� ���� ������� �� ������ � ������� ��-��-���� : ");
            step++;
        }
    }
    return newWorker;
}

// ������ ������ ������ ��������� � ���� ������
bool creatRecordInFD()
{
    worker newWorker;
    newWorker.firstName = getValueStr("������� ���");
    newWorker.lastName = getValueStr("������� �������");
    newWorker.patronymic = getValueStr("������� ��������");
    newWorker.birtday = getValueStr("������� ���� �������� � ������� ��-��-���� : ");
    newWorker.educationWorker.nameEdComp = getValueStr("������� ������������ ��");
    newWorker.educationWorker.spacialization = getValueStr("������� �������������");
    newWorker.educationWorker.yearEndEducation = getValueInt("������� ��� ��������� ��");
    newWorker.martStatus = getValueStr("������� �������� ���������");
    char* intStr;
    string intStrLine = getValueStr("������� ����� � ������� 121234567");
    intStr = &intStrLine[0];
    string intStrEnd = "";
    intStrEnd = intStrEnd + "+375(" + intStr[0] + intStr[1] + ")" + intStr[2] + intStr[3] + intStr[4] + "-" + intStr[5] + intStr[6] + "-" + intStr[7] + intStr[8];;
    newWorker.homeTelNumber = intStrEnd;
    newWorker.workerPosition.dateStartWork = getValueStr("������� ���� ������� �� ������ � ������� ��-��-���� : ");
    newWorker.workerPosition.department = getValueStr("������� �������� ������ : ");
    newWorker.workerPosition.position = getValueStr("������� ��������� : ");
    char* intStr2;
    string intStrLine2 = getValueStr("������� ����� � ������� 121234567");
    intStr2 = &intStrLine2[0];
    string intStrEnd2 = "";
    intStrEnd2 = intStrEnd2 + "+375(" + intStr2[0] + intStr2[1] + ")" + intStr2[2] + intStr2[3] + intStr2[4] + "-" + intStr2[5] + intStr2[6] + "-" + intStr2[7] + intStr2[8];;
    newWorker.workerPosition.workTelNumber = intStrEnd2;
    newWorker.workerPosition.dateStopWork = getValueStr("������� ���� ���������� � ������� ��-��-���� : ");
    string outStr = "";
    outStr = outStr + newWorker.lastName
        + "#" + newWorker.lastName
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

// ��������� ������ ����������



// ����� ������� ����� ������
void printTable()
{
    int amountOfWorker = 0;
    ifstream fin("dataFile.txt", ios_base::in);
    string line;
    vector<string> strs;

    if (!fin.is_open())
    {
        cout << "not" << endl;
    }
    else
    {
        while (getline(fin, line))
        {
            amountOfWorker++;
            strs.push_back(line);
        }

        for (string u : strs)
        {
            vector<string> workerVect = split(u, '#');
            worker interimWorker;
            for (int i = 0; i < workerVect.size(); i++)
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
        }
        cout << "�\t" << "�������\t" << "���\t" << "��������\t" << "���� ��������\t" << "��������� ���������\t\t" << "���. �������" << endl;
        cout << "==================================================================" << endl;
        for (int i = 0; i < allWolker.size(); i++)
        {
            cout << i + 1 << '\t' << allWolker[i].lastName << '\t' << allWolker[i].firstName
                << '\t' << allWolker[i].patronymic << '\t' << allWolker[i].birtday << '\t'
                << allWolker[i].martStatus << '/' << allWolker[i].homeTelNumber << '/' << endl;
        }
        
    }

}


// �������� �� ������� ����� ������
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

// �������� � �������� ����� ������
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
            return true;
        }
    }
}