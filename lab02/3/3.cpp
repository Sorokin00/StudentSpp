#include "pch.h"
#include <iostream>
using namespace std;

float chackfloat()
{
	float x;
	while (!(cin >> x))
	{
		cout << "Неверное значение";
		cin.clear();
		cin.ignore(3000000, '\n');
	}
	return x;
}

char сheckchar()
{
	char x;
	while (!(cin >> x))
	{
		cout << "Неверное значение";
		cin.clear();
		cin.ignore(3000000, '\n');
	}
	return x;
}

char operation()
{
	char t;
	bool l = false;
	while (l == false)
	{
		t = сheckchar();
		if (t == '+' || t == '-' || t == '*' || t == '/')
		{
			l = true;
		}
		else
		{
			cout << "/nНевозможная операция/n";
		}
	}
	return t;
}


int main()
{
	setlocale(LC_ALL, "rus");
	float a;
	char b;
	float c;
	a = chackfloat();
	b = operation();
	c = chackfloat();
	float d;
	if (b == '+')
	{
		d = a + c;
	}
	if (b == '-')
	{
		d = a - c;
	}
	if (b == '*')
	{
		d = a * c;
	}
	if (b == '/')
	{
		d = a / c;
	}
	cout << "Результат:" << d;
}