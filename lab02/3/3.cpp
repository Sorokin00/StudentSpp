#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	bool e = 0;
	bool error = 0;
	char stroka[1000];
	cin.getline(stroka, 999);
	int i = 0;
	char znak;
	int one[1000];
	int chet1 = 0;
	bool end = 0;
	while (!(end))
	{
		if ((stroka[i] == '+') | (stroka[i] == '-') | (stroka[i] == '*') | (stroka[i] == '/') | (stroka[i] == ' ') | ((stroka[i] >= '0') & (stroka[i] <= '9')))
		{
			if (stroka[i] >= '0' & stroka[i] <= '9')
			{
				one[chet1] = stroka[i];
				chet1++;
			}
			if ((stroka[i] == '+') | (stroka[i] == '-') | (stroka[i] == '*') | (stroka[i] == '/'))
			{
				znak = stroka[i];
				end = 1;
			}
			i++;
		}
		else
		{
			cout << "Неверное значение";
			error = 1;
			end = 1;
		}
	}
	chet1--;
	int two[1000];
	int chet2 = 0;
	bool end2 = 0;
	while ((1000, '\n') & (!(error)))
	{
		if ((stroka[i] == ' ') | ((stroka[i] >= '0') & (stroka[i] <= '9')))
		{
			if (stroka[i] >= '0' & stroka[i] <= '9')
			{
				two[chet2] = stroka[i];
				chet2++;
			}
		}
		else
		{
			cout << "Неверное значение";
			error = 1;
		}
		i++;
	}
	chet2--;
	int a = 0;
	int x = 1;
	while (chet1 >= 0)
	{
		a = a + one[chet1] * x;
		x = x * 10;
		chet1--;
	}
	int b = 0;
	x = 1;
	while (chet2 >= 0)
	{
		a = a + one[chet1] * x;
		x = x * 10;
		chet2--;
	}
	int c;
	if (znak == '+')
	{
		c = a + b;
	}
	if (znak == '-')
	{
		c = a - b;
	}
	if (znak == '*')
	{
		c = a * b;
	}
	if (znak == '/')
	{
		c = a / b;
	}
	cout << "Результат:" << c;
	return 0;
}