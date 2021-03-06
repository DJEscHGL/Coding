﻿#include <iostream>
#include <time.h>

using namespace std;

class Vehicle {
protected:
	int id, perMan;
	double perKm, maxSpeed, perKg;
public:
	void setId(int i) {
		id = i + 1;
	}
	void show() {
		cout << id << "\t" << maxSpeed << "\t\t" << perKm << "\t\t" << perKg << endl;
	}
	int getID() {
		return id;
	}
	double getMaxSpeed() {
		return maxSpeed;
	}
	double getCostKM() {
		return perKm;
	}
	double getCostKG() {
		return perKg;
	}
	virtual void costOfKM() = 0;
	virtual void costOfKG() = 0;
	virtual void setMaxSpeed() = 0;
};

class Car : public Vehicle {
public:
	virtual void costOfKM() {
		perKm = maxSpeed * 0.03;
	}
	virtual void costOfKG() {
		perKg = perKm * 0.5;
	}
	virtual void setMaxSpeed() {
		cout << "Максимальная скорость машины: ";
		cin >> maxSpeed;
	}
};

class Bicycle : public Vehicle {
public:
	virtual void costOfKM() {
		perKm = maxSpeed * 0.04;
	}
	virtual void costOfKG() {
		perKg = perKm * 0.7;
	}
	virtual void setMaxSpeed() {
		cout << "Максимальная скорость велосипеда: ";
		cin >> maxSpeed;
	}
};

class Carriage : public Vehicle {
public:
	virtual void costOfKM() {
		perKm = maxSpeed * 0.05;
	}
	virtual void costOfKG() {
		perKg = perKm * 0.9;
	}
	virtual void setMaxSpeed() {
		cout << "Максимальная скорость повозки: ";
		cin >> maxSpeed;
	}
};

int main() {
	srand((unsigned int)time(NULL));
	setlocale(0, "");
	double distance, weight;
	int num, numCar, numBicycle, numCarriage;
	cout << "Введите длину маршрута: ";
	cin >> distance;
	cout << "Введите перевозимый вес: ";
	cin >> weight;
	cout << "Введите количество машин: ";
	cin >> numCar;
	cout << "Введите количество велосипедов: ";
	cin >> numBicycle;
	cout << "Введите количество повозок: ";
	cin >> numCarriage;
	num = numCar + numBicycle + numCarriage;
	auto transport = new Vehicle*[num];
	for (int i = 0; i < numCar; i++) {
		transport[i] = new Car;
		transport[i]->setId(i);
		transport[i]->setMaxSpeed();
		transport[i]->costOfKM();
		transport[i]->costOfKG();
	}
	for (int i = numCar; i < num - numCarriage; i++) {
		transport[i] = new Bicycle;
		transport[i]->setId(i);
		transport[i]->setMaxSpeed();
		transport[i]->costOfKM();
		transport[i]->costOfKG();
	}
	for (int i = num - numCarriage; i < num; i++) {
		transport[i] = new Carriage;
		transport[i]->setId(i);
		transport[i]->setMaxSpeed();
		transport[i]->costOfKM();
		transport[i]->costOfKG();
	}
	bool flag = true;
	int choice2;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Вывод всего транспорта\n2.Таблица стоимости";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			cout << "ID" << "\t" << "Cкорость" << "\t" << "За километр" << "\t" << "За килограмм" << endl;
			for (int i = 0; i < num; i++) {
				transport[i]->show();
			}
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "ID" << "\t" << "Полная перевозка" << "\t" << "Перевозка грузов" << "\t" << "Перевозка пассажиров" << "\t" << "Время перевозки" << endl;
			for (int i = 0; i < num; i++) {
				cout << transport[i]->getID() << "\t" << transport[i]->costOfKG() * weight + distance * transport[i]->getCostKM() << "\t" << transport[i]->getCostKG() * weight << "\t" << distance * transport[i]->getCostKM() << "\t" << distance / transport[i]->getMaxSpeed() << endl;
			}
			system("pause");
			break;
		}
	}
}