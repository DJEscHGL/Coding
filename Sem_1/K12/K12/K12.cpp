﻿#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	int n;
	cout << "Число = ";
	cin >> n;
	/*
	Через % мы находим остаток от деления одного числа на другое прим. 15 % 10 = 5  987 % 100 = 87
	А через / мы находим челое значение 15 / 10 = 1  987 / 100 = 9
	*/
	cout << endl << "Последняя цифра = " << n % 10;
	while (n > 10)
		n /= 10;
	cout << "; Первая цифра = " << n;
}