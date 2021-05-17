#include<iostream>
#include<windows.h> // для system("cls");
using namespace std;

struct Size
{
	int breast;
	int waist;
	int hips;
};

struct WonderfulWoman
{
	char name[64];
	int age;
	int height;
	int weight;
	Size volume;
	bool engKnowledge;
};

void showData(const WonderfulWoman Obj[], int amount);

int main()
{
	setlocale(LC_ALL, "rus");

	const int amountOfGirl = 7;
	WonderfulWoman Woman[amountOfGirl] = {};

	for (int i = 0; i < amountOfGirl; i++)
	{
		cout << "Имя: ";
		cin.getline(Woman[i].name, 32);
		cout << "Возраст: ";
		cin >> Woman[i].age;
		cout << "Рост: ";
		cin >> Woman[i].height;
		cout << "Вес: ";
		cin >> Woman[i].weight;
		cout << "Английский (1 - да, 0 - нет): ";
		cin >> Woman[i].engKnowledge;
		cout << "Объемы (грудь, талия, бедра): ";
		cin >> Woman[i].volume.breast;
		cin >> Woman[i].volume.waist;
		cin >> Woman[i].volume.hips;
		cin.get(); // считывает из потока Enter который пользователь нажимает после ввода возраста
		cout << endl;
	}

	showData(Woman, amountOfGirl);

	return 0;
}

void showData(const WonderfulWoman Obj[], int amount)
{
	system("cls"); // сработает только для windows
	cout << "№\t" << "Имя\t" << "Возраст\t" << "Рост\t" << "Вес\t" << "Объёмы\t\t" << "Английский" << endl;
	cout << "==================================================================" << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << i + 1 << '\t' << Obj[i].name << '\t' << Obj[i].age
			<< '\t' << Obj[i].height << '\t' << Obj[i].weight << '\t'
			<< Obj[i].volume.breast << '/' << Obj[i].volume.waist << '/' << Obj[i].volume.hips
			<< '\t' << Obj[i].engKnowledge << endl;
	}
}


#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// for string delimiter
vector<string> split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

int main() {
	string str = "adsf-+qwret-+nvfkbdsj-+orthdfjgh-+dfjrleih";
	string delimiter = "-+";
	vector<string> v = split(str, delimiter);

	for (auto i : v) cout << i << endl;

	return 0;
}