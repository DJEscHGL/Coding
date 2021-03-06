﻿#include <iostream>

using namespace std;

class Complex {
public:
	int a, b; 
	void Summing(Complex fst, Complex snd) {
		a = fst.a + snd.a;
		b = snd.b + snd.b;
	}
	void Multiplication(Complex fst, Complex snd) {
		a = fst.a * snd.a - fst.b * snd.b;
		b = fst.a * snd.a + fst.b * snd.b;
	}
	Complex operator= (Complex obj) {
		a = obj.a;
		b = obj.b;
		return *this;
	}
};

Complex operator+ (Complex num1, Complex num2) {
	Complex result;
	result.Summing(num1, num2);
	return result;
}

Complex operator* (Complex num1, Complex num2) {
	Complex result;
	result.Multiplication(num1, num2);
	return result;
}

istream operator>> (istream& inn, Complex num) {
	cout << "Целая часть числа: ";
	inn >> num.a;
	cout << "Мнимая часть числа: ";
	inn >> num.b;
	return inn;
}

ostream operator<< (ostream& out, Complex num) {
	if (num.b < 0)
		out << num.a << num.b << "i" << endl;
	else if (num.b != 0)
		out << num.a << "+" << "i" << endl;
	else
		out << num.a << "+" << num.b << "i" << endl;
	return out;
}

class ComplexVector {
public:
	int n;
	Complex** vector;
	ComplexVector(int nn) {
		n = nn;
		vector = new Complex*[n];
		for (int i = 0; i < n; i++) {
			vector[i] = new Complex;
		}
		for (int i = 0; i < n; i++) {
			cin >> *vector[i];
		}
	}
	void Out() {
		for (int i = 0; i < n; i++) {
			cout << vector[i];
		}
	}
};

int main() {
	int num;
	num = 2;
	ComplexVector vect(num);
	vect.Out();
}