#ifndef FUZZY_NUMBER_H
#define FUZZY_NUMBER_H
#include "header.h"

class FuzzyNumber
{
	double* left_;
	double* middle_;
	double* right_;
public:
	FuzzyNumber();
	FuzzyNumber(const double& left, const double& middle, const double& right);
	FuzzyNumber(const tuple<double, double, double>& tuple);

	FuzzyNumber(const FuzzyNumber& other);
	~FuzzyNumber();

	double getLeft() const;
	double getMiddle() const;
	double getRight() const;
	tuple<double, double, double> getValues() const;

	void setLeft(const double& value);
	void setMiddle(const double& value);
	void setRight(const double& value);
	void setTuple(const tuple<double, double, double>& tuple);
	void setTuple(const double& left, const double& middle, const double& right);

	void multiply(const FuzzyNumber& other);
	void subtract(const FuzzyNumber& other);
	void divide(const FuzzyNumber& other);
	void add(const FuzzyNumber& other);

	friend ostream& operator<<(ostream& os, const FuzzyNumber& fuzzyNumber);
	friend istream& operator>>(istream& isleftFuzzyNumber, const FuzzyNumber& fuzzyNumber);

	FuzzyNumber& operator=(const FuzzyNumber& other);
	FuzzyNumber& operator=(const tuple<double, double, double>& tuple);
};
#endif
