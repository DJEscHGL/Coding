﻿#include <iostream>
#include <time.h>
#include <cmath>


using namespace std;

class Matrix {
private:
	int n = 5;
	int** matr;
public:
	//Конструктор
	Matrix() {
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = rand() % 100;
			}
		}
	}
	//Конструктор копирования
	Matrix(const Matrix& obj) {
		n = obj.n;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = obj.matr[i][j];
			}
		}
	}
	//Конструктор пустой матрицы(для операций)
	Matrix(const Matrix& obj, bool ch) {
		n = obj.n;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[n];
	}
	//Деструктор
	~Matrix() {
		for (int i = 0; i < n; i++)
			delete[] matr[i];
		delete[] matr;
	}
	//Вывод матрицы
	void output() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	//Сложение матриц
	void Summig(Matrix ob1, Matrix ob2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = ob1.matr[i][j] + ob2.matr[i][j];
			}
		}
	}
	//Вычитание матриц
	void Subtraction(Matrix ob1, Matrix ob2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = ob1.matr[i][j] - ob2.matr[i][j];
			}
		}
	}
	//Умножение матриц
	void Multiplication(Matrix ob1, Matrix ob2) {
		int buffer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int q = 0; q < n; q++) {
					buffer += ob1.matr[i][q] * ob2.matr[q][j];
				}
				matr[i][j] = buffer;
			}
		}
	}
	//Норма матрицы
	void Norma() {
		int norma = 0, buff = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				buff += abs(matr[i][j]);
			}
			if (norma <= buff)
				norma = buff;
			buff = 0;
		}
		cout << norma << endl;
	}
	//Перегрузка операции присваивания
	Matrix operator= (Matrix obj) {
		n = obj.n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = obj.matr[i][j];
			}
		}
		return *this;
	}
};

//Перегрузка операции сложения
Matrix operator+ (Matrix ob1, Matrix ob2) {
	Matrix result(ob1, true);
	result.Summig(ob1, ob2);
	return result;
}

//Перегрузка операции вычитания
Matrix operator- (Matrix ob1, Matrix ob2) {
	Matrix result(ob1, true);
	result.Subtraction(ob1, ob2);
	return result;
}

//Перегрузка операции умножения
Matrix operator* (Matrix ob1, Matrix ob2) {
	Matrix result(ob1, true);
	result.Multiplication(ob1, ob2);
	return result;
}

void Func(Matrix* obj, int k) {
	int m;
	cout << "Какую матрицу изменить от " << 0 << " до " << k - 1 << endl;
	cin >> m;
	Matrix res(obj[m], true);
	res.Multiplication(obj[m], obj[m]);
	obj[m] = res;
	cout << "Новая матрица:\n";
	obj[m].output();
}

int main() {
	setlocale(0, "");
	srand((unsigned int)time(NULL));
	int k, m1, m2;
	cout << "Введите количество матриц: ";
	cin >> k;
	Matrix* obj = new Matrix[k];
	Matrix copyOf1(obj[0]);
	Matrix result(obj[0], true);
	bool flag = true;
	bool flag1 = true;
	//Меню
	while (flag) {
		system("cls");
		int choice;
		cout << "Введите номер нужного пункта\n0.Выход\n1.Вывод матриц\n2.Проверка перегрузок операторов.\n3.Основное условие" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			for (int i = 0; i < k; i++) {
				cout << "/////////////////////////////\n";
				obj[i].output();
			}
			system("pause");
			break;
		case 2:
			flag1 = true;
			while (flag1) {
				system("cls");
				int choice1;
				cout << "Введите номер нужного пункта\n0.Выход\n1.Суммирование.\n2.Вычитание.\n3.Умножение.\n4.Норма матрицы." << endl;
				cin >> choice1;
				switch (choice1) {
				case 0:
					flag1 = false;
					break;
				case 1:
					system("cls");
					cout << "Какие матрицы сложить от " << 0 << " до " << k - 1 << endl;
					cin >> m1;
					cin >> m2;
					result = obj[m1] + obj[m2];
					obj[m1].output();
					cout << "/////////////////////////////\n";
					obj[m2].output();
					cout << "Результат:\n";
					result.output();
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "Какие матрицы вычесть от " << 0 << " до " << k - 1 << endl;
					cin >> m1;
					cin >> m2;
					result = obj[m1] - obj[m2];
					obj[m1].output();
					cout << "/////////////////////////////\n";
					obj[m2].output();
					cout << "Результат:\n";
					result.output();
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "Какие матрицы умножить от " << 0 << " до " << k - 1 << endl;
					cin >> m1;
					cin >> m2;
					result = obj[m1] * obj[m2];
					obj[m1].output();
					cout << "/////////////////////////////\n";
					obj[m2].output();
					cout << "Результат:\n";
					result.output();
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "Норму какой матрицы вычеслить от " << 0 << " до " << k - 1 << endl;
					cin >> m1;
					obj[m1].Norma();
					system("pause");
					break;
				}
			}
			break;
		case 3:
			system("cls");
			Func(obj, k);
			system("pause");
			break;
		default:
			system("cls");
			cout << "Введён неверный вариант";
			system("pause");
			break;
		}
	}
}
