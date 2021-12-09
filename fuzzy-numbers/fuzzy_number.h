#ifndef FUZZY_NUMBER_H
#define FUZZY_NUMBER_H
#include "header.h"

class FuzzyNumber
{
	/* Та самая тройка чисел, которая указана в задании: 
	 *	left_ это x - e1
	 *	middle_ это x
	 *	right_ это x + e1
	 */
	double* left_;
	double* middle_;
	double* right_;
public:
	// Конструктор без параметров
	FuzzyNumber();

	// Конструктор с 3мя параметрами в виде вещественных чисел
	FuzzyNumber(const double& left, const double& middle, const double& right);

	// Конструктор с 1 параметром в виде кортежа из 3х вещественных чисел
	FuzzyNumber(const tuple<double, double, double>& tuple);

	// Конструктор копирования
	FuzzyNumber(const FuzzyNumber& other);

	// Деструктор
	~FuzzyNumber();


	// Методы получения числовых значений полей left_,middle_,right_  соответственно
	double getLeft() const;
	double getMiddle() const;
	double getRight() const;
	// Методы получения кортежа, состоящего из полей left_,middle_,right_
	tuple<double, double, double> getValues() const;

	// Методы присвоения нового числового значения полям left_,middle_,right_  соответственно
	void setLeft(const double& value) const;
	void setMiddle(const double& value) const;
	void setRight(const double& value) const;

	// Методы присвоения кортежа, состоящего из 3х вещественных чисел полям left_,middle_,right_
	void setTuple(const tuple<double, double, double>& tuple) const;
	// Методы присвоения3х вещественных чисел полям left_,middle_,right_
	void setTuple(const double& left, const double& middle, const double& right) const;

	// Вариации метода умножения, который преобразует поля left_,middle_,right_
	// ,умножая их на обьект FuzzyNumber, кортеж из 3х чисел, 3 числа соответственно
	void multiply(const FuzzyNumber& other) const;
	void multiply(const tuple<double, double, double>& tuple) const;
	void multiply(const double& left, const double& middle, const double& right) const;

	// Вариации метода вычитания, который преобразует поля left_,middle_,right_
	// ,вычитая из них обьект FuzzyNumber, кортеж из 3х чисел, 3 числа соответственно
	void subtract(const FuzzyNumber& other) const;
	void subtract(const tuple<double, double, double>& tuple) const;
	void subtract(const double& left, const double& middle, const double& right) const;

	// Вариации метода деления, который преобразует поля left_,middle_,right_
	// ,деля их на обьект FuzzyNumber, кортеж из 3х чисел, 3 числа соответственно
	void divide(const FuzzyNumber& other) const;
	void divide(const tuple<double, double, double>& tuple) const;
	void divide(const double& left, const double& middle, const double& right) const;

	// Вариации метода сложения, который преобразует поля left_,middle_,right_
	// ,прибавляя к ним объект FuzzyNumber, кортеж из 3х чисел, 3 числа соответственно
	void add(const FuzzyNumber& other) const;
	void add(const tuple<double, double, double>& tuple) const;
	void add(const double& left, const double& middle, const double& right) const;

	// Метод, который возвращает True, если обьект FuzzyNumber, который был введён
	// в качестве параметра, совпадает с нашим объектом (равен ему)
	bool equals(const FuzzyNumber& other) const;

	// Метод, который возвращает True, если обьект FuzzyNumber, который был введён
	// в качестве параметра, НЕ совпадает с нашим объектом (НЕ равен ему)
	bool notEquals(const FuzzyNumber& other) const;

	// Перегруженный оператор вывода 
	friend ostream& operator<<(ostream& os, const FuzzyNumber& fuzzyNumber);
	// Перегруженный оператор ввода 
	friend istream& operator>>(istream& is, const FuzzyNumber& fuzzyNumber);

	// Перегруженный оператор равно для обьекта FuzzyNumber  
	FuzzyNumber& operator=(const FuzzyNumber& other);
	// Перегруженный оператор равно для кортежа из 3х чисел
	FuzzyNumber& operator=(const tuple<double, double, double>& tuple);
};

#endif
