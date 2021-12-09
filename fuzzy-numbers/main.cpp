#include <iostream>
#include "fuzzy_number.h"
using namespace std;

int main()
{
	const FuzzyNumber fuzzyNumber(1, 5, 7);
	FuzzyNumber fuzzyNumberSecond(tuple<double, double, double>(2, 2, 2));
	FuzzyNumber fuzzyNumberThird(fuzzyNumber);

	fuzzyNumberThird = fuzzyNumber;
	fuzzyNumber.add(1, 1, 1);
	fuzzyNumber.divide(2, 10, 5);
	fuzzyNumber.subtract(3, 14, 4);
	fuzzyNumber.multiply(5, 5, 5);
	fuzzyNumber.setTuple(2, 15, 8);
	fuzzyNumber.setLeft(1);
	fuzzyNumber.setMiddle(2);
	fuzzyNumber.setRight(3);

	tuple<double, double, double> response = fuzzyNumber.getValues();
	cin >> fuzzyNumber;
	cout << endl << "Is FuzzyNumber equals to FuzzyNumberThird ? - " << fuzzyNumber.equals(fuzzyNumberThird) << endl;
	return 0;
}
