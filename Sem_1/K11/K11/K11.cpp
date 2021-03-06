﻿#include <iostream>

using namespace std;

int Sum1(int n1, int n2) /*

Всего два типа функций void и не-void(зависит от типа данного которое доллжна вернуть функция)
В данном случаем не-void (int)
Для функции пишется так 
			тип_функции название_функции (тип_переменной название, ...) - внутри скобок переменные которые передаём функции из другой(где её вызвали(в данном случае main) )
						 */
{
	//Изначально сумма равна 0, дальше ищем первое четное число (проверяем делимость на ноль и отдельное есловие для нуля) и циклом через каждое  второе число считаем сумму
	int sum = 0;
	if (n1 % 2 != 0)
			n1++;
	if (n1 == 0)
		n1 += 2;
	for (; n1 <= n2; n1 += 2)
		sum += n1;
	/* 
	Чтобы функция вернула значение нужно ввести 
								return значение;
			в качестве значение может быть переменная или конкретное число/слово (зависит от типа функции)
	*/
	return sum;
}

int Su2(int n1, int n2)
{
	//Тут как и в первой функции, только считаем количество
	int num = 0;
	if (n1 % 2 != 0)
		n1++;
	if (n1 == 0)
		n1 += 2;
	for (; n1 <= n2; n1 += 2)
		num++;
	return num;
}

int main()
{
	setlocale(0, ""); // Русский язык
	//Тут просто 2 числа N1 и N2 типа int и вводим их с клавиатуры
	int n1, n2;
	cout << "N1 = ";
	cin >> n1;
	cout << endl << "N2 = ";
	cin >> n2;
	cout << endl;
	//Вызываем две функции и выводим их ответ
	cout << "Сумма четных = " << Sum1(n1, n2) << ";  Количество четных = " << Su2(n1, n2);
}