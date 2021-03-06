﻿#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <locale>

using namespace std;
ifstream input("input.txt");
ofstream output("output.txt");

class Worker {
private:
	string name;
	string position;
	int year;
	double salary;
public:
	string GetName() {
		return name;
	}
	string GetPosition() {
		return position;
	}
	int GetYear() {
		return year;
	}
	double GetSalary() {
		return salary;
	}
	void SetName(string valName) {
		name = valName;
	}
	void SetPosition(string valPosition) {
		position = valPosition;
	}
	void SetYear(int valYear) {
		year = valYear;
	}
	void SetSalary(double valSalary) {
		salary = valSalary;
	}
	void Show() {
		output << name << "\t" << position << "\t\t" << year << "\t\t" << salary << endl;
	}
};

void ch1(Worker* workers, int n) {
	double years;
	system("cls");
	cout << "Введите стаж работы = ";
	cin >> years;
	system("cls");
	output << "ФИО\tДолжность\tГод\t\tЗарплата" << endl;
	for (int i = 0; i < n; i++) {
		if (2020 - workers[i].GetYear() > years)
			workers[i].Show();
	}
	output << endl;
}

void ch2(Worker* workers, int n) {
	double money;
	system("cls");
	cout << "Введите размер зарплаты = ";
	cin >> money;
	system("cls");
	output << "ФИО\tДолжность\tГод\t\tЗарплата" << endl;
	for (int i = 0; i < n; i++) {
		if (workers[i].GetSalary() > money)
			workers[i].Show();
	}
	output << endl;
}

void ch3(Worker* workers, int n) {
	string post;
	system("cls");
	cout << "Введите должность = ";
	cin.get();
	cin >> post;
	system("cls");
	output << "ФИО\tДолжность\tГод\t\tЗарплата" << endl;
	for (int i = 0; i < n; i++) {
		if (workers[i].GetPosition() == post)
			workers[i].Show();
	}
	output << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	string s, q;
	double d;
	int k;
	//cout << "Количество работников = ";
	input >> n;
	Worker* workers = new Worker[n];
	for (int i = 0; i < n; i++) {
		//cout << "ФИО = ";
		input.get();
		getline(input, s);
		workers[i].SetName(s);
		//cout << "Год = ";
		input >> k;
		workers[i].SetYear(k);
		//cout << "Должность = ";
		input.get();
		getline(input, q);
		workers[i].SetPosition(q);
		//cout << "Зарплата = ";
		input >> d;
		workers[i].SetSalary(d);
	}
	bool flag = true;
	while (flag) {
		int choice;
		cout << "Введите номер нужного пункта\n0.Выход\n1.Работники со стажем выше введённого.\n2.Работники с зарплатой выше введённой.\n3.Работники введённой должности." << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			ch1(workers, n);
			system("pause");
			break;
		case 2:
			ch2(workers, n);
			system("pause");
			break;
		case 3:
			ch3(workers, n);
			system("pause");
			break;
		default:
			system("cls");
			cout << "Введён неверный вариант";
			break;
		}
	}
	input.close();
	output.close();
}