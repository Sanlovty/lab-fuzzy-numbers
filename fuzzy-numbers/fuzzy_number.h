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

	void setLeft(const double& value) const;
	void setMiddle(const double& value) const;
	void setRight(const double& value) const;
	void setTuple(const tuple<double, double, double>& tuple) const;
	void setTuple(const double& left, const double& middle, const double& right) const;

	void multiply(const FuzzyNumber& other) const;
	void subtract(const FuzzyNumber& other) const;
	void divide(const FuzzyNumber& other) const;
	void add(const FuzzyNumber& other) const;

	bool equals(const FuzzyNumber& other) const;
	bool notEquals(const FuzzyNumber& other) const;

	friend ostream& operator<<(ostream& os, const FuzzyNumber& fuzzyNumber);
	friend istream& operator>>(istream& is, const FuzzyNumber& fuzzyNumber);

	FuzzyNumber& operator=(const FuzzyNumber& other);
	FuzzyNumber& operator=(const tuple<double, double, double>& tuple);
};
#endif
