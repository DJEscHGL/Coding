﻿#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;
ifstream input("input.txt");

class Vehicle {
public:
	int id, perMan;
	double perKm, perKg, maxSpeed;
	virtual void setId(int i) = 0;
	virtual void setMaxSpeed() = 0;
	virtual void setPerKm() = 0;
	virtual void setPerMan(int numOfMan) = 0;
	virtual void setPerKg() = 0;
	int getId() {
		return id;
	}
	double getMaxSpeed() {
		return maxSpeed;
	}
	double getPerKm() {
		return perKm;
	}
	double getPerKg() {
		return perKg;
	}
	void show() {
		cout << id << "\t" << maxSpeed << "\t\t" << perKm << "\t" << perKg << endl;
	}
};

class Car : public Vehicle {
public:
	virtual void setId(int i) {
		id = i + 1;
	}
	virtual void setMaxSpeed() {
		input >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * 0.4;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = ceil(numOfMan / 4); // округление в большую сторону
	}
	virtual void setPerKg() {
		perKg = maxSpeed * 0.01 + 2;
	}
};

class Bicycle : public Vehicle {
public:
	virtual void setId(int i) {
		id = i + 1;
	}
	virtual void setMaxSpeed() {
		input >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * 0.6;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = numOfMan;
	}
	virtual void setPerKg() {
		perKg = maxSpeed * 0.01 + 2;
	}
};

class Carriage : public Vehicle {
public:
	virtual void setId(int i) {
		id = i + 1;
	}
	virtual void setMaxSpeed() {
		input >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * 0.8;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = ceil(numOfMan / 6);
	}
	virtual void setPerKg() {
		perKg = maxSpeed * 0.01 + 2;
	}
};

void Calculate() {

}

int main() {
	srand((unsigned int)time(NULL));
	setlocale(0, "");
	double distance, weight;
	int numOfMan;
	cout << "Введите длину маршрута: ";
	cin >> distance;
	cout << "Введите перевозимый вес: ";
	cin >> weight;
	cout << "Введите количество перевозимых людей: ";
	cin >> numOfMan;
	/*Car n1, n2, n3;
	Bicycle n4, n5, n6;
	Carriage n7, n8, n9;
	Vehicle* transport[9] = {&n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9};*/
	auto transport = new Vehicle * [9];
	for (int i = 0; i < 3; i++)
		transport[i] = new Car;
	for (int i = 3; i < 6; i++)
		transport[i] = new Bicycle;
	for (int i = 6; i < 9; i++)
		transport[i] = new Carriage;
	for (int i = 0; i < 9; i++) {
		transport[i]->setId(i);
		transport[i]->setMaxSpeed();
		transport[i]->setPerKg();
		transport[i]->setPerKm();
		transport[i]->setPerMan(numOfMan);
	}
	bool flag = true;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Вывод всего транспорта\n2.Машины\n3.Велосипеды\n4.Повозки\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			cout << "ID" << "\t" << "MaxSpeed" << "\t" << "PerKM" << "\t" << "PerKG" << endl;
			for (int i = 0; i < 9; i++) {
				transport[i]->show();
			}
			system("pause");
			break;
		}
	}
	input.close();
}