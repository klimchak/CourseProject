#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char date[11]; // mm/dd/yyyy
	int mm, dd, yyyy;

	cout << "Enter date : ";
	cin >> date;

	if (strlen(date) < 10 || strlen(date) > 10)
	{
		cout << "\n Error:Input should be in mm/dd/yyyy format";
	}
	else if (strlen(date) == 10)
	{
		char m[3], d[3], y[5];
		int i, j;

		for (i = 0; i < 2; i++)
			m[i] = date[i];

		for (i = 3, j = 0; i < 5; i++, j++) {
			d[j] = date[i];
		}
		for (i = 6, j = 0; i < 10; i++, j++)
			y[j] = date[i];

		mm = atoi(m);
		dd = atoi(d);
		yyyy = atoi(y);

		cout << "\n Month : " << mm;
		cout << "\n Day : " << dd;
		cout << "\n Year : " << yyyy;
	}
	else
	{
		cout << "\n Error:Input should be in mm/dd/yyyy format";
	}
	return 0;
}