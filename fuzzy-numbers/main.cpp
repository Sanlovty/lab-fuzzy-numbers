#include <iostream>
#include "fuzzy_number.h"
using namespace std;

int main()
{
	// Создаём один обьект, используя конструктор с 3 параметрами
	const FuzzyNumber fuzzyNumber(1, 5, 7);
	// Создаём один обьект, используя конструктор с кортежем
	FuzzyNumber fuzzyNumberSecond(tuple<double, double, double>(2, 2, 2));
	// Создаём один обьект, используя конструктор копирования
	FuzzyNumber fuzzyNumberThird(fuzzyNumber);

	// Проверяем пегруженный оператор равно
	fuzzyNumberThird = fuzzyNumber;
	// Проверяем метод добавления
	fuzzyNumber.add(1, 1, 1);
	// Проверяем метод деления
	fuzzyNumber.divide(2, 10, 5);
	// Проверяем метод вычитания
	fuzzyNumber.subtract(3, 14, 4);
	// Проверяем метод умножения
	fuzzyNumber.multiply(5, 5, 5);
	// Проверяем метод установки сразу трёх значений
	fuzzyNumber.setTuple(2, 15, 8);
	// Проверяем метод установки значения x-e1
	fuzzyNumber.setLeft(1);
	// Проверяем метод установки значения x
	fuzzyNumber.setMiddle(2);
	// Проверяем метод установки значения x+e1
	fuzzyNumber.setRight(3);

	// Проверяем метод, возвращающий кортеж значений x-e1,x,x+e1
	tuple<double, double, double> response = fuzzyNumber.getValues();
	// Проверяем перегруженный оператор ввода
	cin >> fuzzyNumber;
	// Проверяем перегруженный оператор вывода
	cout << fuzzyNumber;
	// Проверяем метод сравнения
	cout << endl << "Is FuzzyNumber equals to FuzzyNumberThird ? - " << fuzzyNumber.equals(fuzzyNumberThird) << endl;
	return 0;
}
