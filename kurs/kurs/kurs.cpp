#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ride
{
private:
	string time;
public:
	string station;
	friend istream& operator>>(istream& in, ride& ride)
	{
		in >> ride.station;
		in >> ride.time;
		return in;
	}
	friend ostream& operator<<(ostream& out, const ride& ride)
	{
		out << ride.station << ' ' << ride.time;
		return out;
	}
};

template <class T1, class T2>
class collection
{
private:
	class element
	{
	public:
		T1 key;
		T2 item;
		element& operator= (const element &element)
		{
			key = element.key;
			item = element.item;
			return *this;
		}
	};
	int size;
	element *array;
public:
	collection();
	~collection();

	void search_number(int number);
	void search_station(string station);
	void addition_element(T1 key, T2 item);

	collection& operator[](unsigned int i);

	template <class T1, class T2>
	friend ostream& operator<<(ostream& out, const collection<T1, T2>& collection);

	template <class T1, class T2>
	friend istream& operator>>(istream & in, collection<T1, T2> & collection);
};

template<class T1, class T2>
collection<T1, T2>::collection()
{
	size = 5;
	array = new element[size];
}

template<class T1, class T2>
collection<T1, T2>::~collection()
{
	delete[] array;
}

template<class T1, class T2>
void collection<T1, T2>::addition_element(T1 key, T2 item)
{
	element *new_array = new element[size + 1];
	for (int i = 0; i < size; i++)
		new_array[i] = array[i];
	new_array[size].key = key;
	new_array[size].item = item;
	size++;
	delete[] array;
	array = new_array;
}

template<class T1, class T2>
collection<T1, T2> & collection<T1, T2>::operator[](unsigned int i)
{
	return array[i];
}

template<class T1, class T2>
ostream& operator<<(ostream& out, const collection<T1, T2>& collection)
{
	for (int i = 0; i < collection.size; i++)
	{
		out << collection.array[i].key << ' ' << collection.array[i].item << '\n';
	}
	return out;
}

template<class T1, class T2>
istream& operator>>(istream & in, collection<T1, T2> & collection)
{
	T1 key; T2 item;
	while (in >> key) {
		if (in.peek() == '\n') break;
		in >> item;
		collection.addition_element(key, item);
	}
	return in;
}

template<class T1, class T2>
void collection<T1, T2>::search_number(int number)
{
	int counter = size--;
	for (int i = 0; i < counter; i++)
		if (array[i].key == number)
			cout << array[i].key << ' ' << array[i].item << '\n';
}

template<class T1, class T2>
void collection<T1, T2>::search_station(string station)
{
	int counter = size--;
	for (int i = 0; i < counter; i++)
		if (array[i].item.station == station)
			cout << array[i].key << ' ' << array[i].item << '\n';
}

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream table;
	table.open("C:Users\\ILYA\\Desktop\\GitHub\\StudentCpp\\kurs\\kurs\\table.txt");
	if (!table)
	{
		cout << "Ошибка отсутствует файл " << endl;
		return -1;
	}
	else
	{
		collection<int, ride> arr;
		table >> arr;
		table.close();
		for (int option = 1; option != 5; )
		{
			cout << "Выберите действие" << endl
				<< "1 - Вывод всех рейсов" << endl
				<< "2 - Добавить рейс" << endl
				<< "3 - Поиск поезда по номеру" << endl
				<< "4 - Поиск рейсов до станции" << endl
				<< "5 - Сохранить и Выйти" << endl;
			int kay;
			ride item;
			cin >> option;
			string station;
			switch (option)
			{
			case 1:
				cout << arr << endl;
				break;
			case 2:
				cout << "Введите номер поезда, станцию, до которой он едет и время отправления";
				cin >> kay;
				cin >> item;
				arr.addition_element(kay, item);
				break;
			case 3:
				cout << "Введите номер поезда";
				int number;
				cin >> number;
				arr.search_number(number);
				break;
			case 4:
				cout << "Введите название станции";
				cin >> station;
				arr.search_station(station);
				break;
			case 5:
				break;
			default:
				cout << "Неверное число";
				break;
			}
		}
		fstream entry;
		remove("table.txt");
		entry.open("table.txt", fstream::app);
		entry << arr << endl;

		return 0;
	}
}