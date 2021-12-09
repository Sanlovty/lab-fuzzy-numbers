#ifndef FUZZY_NUMBER_H
#define FUZZY_NUMBER_H
#include "header.h"

class FuzzyNumber
{
	/* �� ����� ������ �����, ������� ������� � �������: 
	 *	left_ ��� x - e1
	 *	middle_ ��� x
	 *	right_ ��� x + e1
	 */
	double* left_;
	double* middle_;
	double* right_;
public:
	// ����������� ��� ����������
	FuzzyNumber();

	// ����������� � 3�� ����������� � ���� ������������ �����
	FuzzyNumber(const double& left, const double& middle, const double& right);

	// ����������� � 1 ���������� � ���� ������� �� 3� ������������ �����
	FuzzyNumber(const tuple<double, double, double>& tuple);

	// ����������� �����������
	FuzzyNumber(const FuzzyNumber& other);

	// ����������
	~FuzzyNumber();


	// ������ ��������� �������� �������� ����� left_,middle_,right_  ��������������
	double getLeft() const;
	double getMiddle() const;
	double getRight() const;
	// ������ ��������� �������, ���������� �� ����� left_,middle_,right_
	tuple<double, double, double> getValues() const;

	// ������ ���������� ������ ��������� �������� ����� left_,middle_,right_  ��������������
	void setLeft(const double& value) const;
	void setMiddle(const double& value) const;
	void setRight(const double& value) const;

	// ������ ���������� �������, ���������� �� 3� ������������ ����� ����� left_,middle_,right_
	void setTuple(const tuple<double, double, double>& tuple) const;
	// ������ ����������3� ������������ ����� ����� left_,middle_,right_
	void setTuple(const double& left, const double& middle, const double& right) const;

	// �������� ������ ���������, ������� ����������� ���� left_,middle_,right_
	// ,������� �� �� ������ FuzzyNumber, ������ �� 3� �����, 3 ����� ��������������
	void multiply(const FuzzyNumber& other) const;
	void multiply(const tuple<double, double, double>& tuple) const;
	void multiply(const double& left, const double& middle, const double& right) const;

	// �������� ������ ���������, ������� ����������� ���� left_,middle_,right_
	// ,������� �� ��� ������ FuzzyNumber, ������ �� 3� �����, 3 ����� ��������������
	void subtract(const FuzzyNumber& other) const;
	void subtract(const tuple<double, double, double>& tuple) const;
	void subtract(const double& left, const double& middle, const double& right) const;

	// �������� ������ �������, ������� ����������� ���� left_,middle_,right_
	// ,���� �� �� ������ FuzzyNumber, ������ �� 3� �����, 3 ����� ��������������
	void divide(const FuzzyNumber& other) const;
	void divide(const tuple<double, double, double>& tuple) const;
	void divide(const double& left, const double& middle, const double& right) const;

	// �������� ������ ��������, ������� ����������� ���� left_,middle_,right_
	// ,��������� � ��� ������ FuzzyNumber, ������ �� 3� �����, 3 ����� ��������������
	void add(const FuzzyNumber& other) const;
	void add(const tuple<double, double, double>& tuple) const;
	void add(const double& left, const double& middle, const double& right) const;

	// �����, ������� ���������� True, ���� ������ FuzzyNumber, ������� ��� �����
	// � �������� ���������, ��������� � ����� �������� (����� ���)
	bool equals(const FuzzyNumber& other) const;

	// �����, ������� ���������� True, ���� ������ FuzzyNumber, ������� ��� �����
	// � �������� ���������, �� ��������� � ����� �������� (�� ����� ���)
	bool notEquals(const FuzzyNumber& other) const;

	// ������������� �������� ������ 
	friend ostream& operator<<(ostream& os, const FuzzyNumber& fuzzyNumber);
	// ������������� �������� ����� 
	friend istream& operator>>(istream& is, const FuzzyNumber& fuzzyNumber);

	// ������������� �������� ����� ��� ������� FuzzyNumber  
	FuzzyNumber& operator=(const FuzzyNumber& other);
	// ������������� �������� ����� ��� ������� �� 3� �����
	FuzzyNumber& operator=(const tuple<double, double, double>& tuple);
};

#endif
