#include "fuzzy_number.h"

FuzzyNumber::FuzzyNumber() : left_(new double()), middle_(new double()), right_(new double())
{
}

FuzzyNumber::FuzzyNumber(const double& left,
                         const double& middle,
                         const double& right)
	: left_(new double(left)),
	  middle_(new double(middle)),
	  right_(new double(right))
{
}

FuzzyNumber::FuzzyNumber(const tuple<double, double, double>& tuple)
	: left_(new double(get<0>(tuple))),
	  middle_(new double(get<1>(tuple))),
	  right_(new double(get<2>(tuple)))
{
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& other)
	: left_(new double(other.getLeft())),
	  middle_(new double(other.getMiddle())),
	  right_(new double(other.getRight()))
{
}

FuzzyNumber::~FuzzyNumber()
{
	delete left_;
	delete middle_;
	delete right_;
}

double FuzzyNumber::getLeft() const
{
	return *left_;
}

double FuzzyNumber::getMiddle() const
{
	return *middle_;
}

double FuzzyNumber::getRight() const
{
	return *right_;
}

tuple<double, double, double> FuzzyNumber::getValues() const
{
	return tuple<double, double, double>(*left_, *middle_, *right_);
}

void FuzzyNumber::setLeft(const double& value) const
{
	*left_ = value;
}

void FuzzyNumber::setMiddle(const double& value) const
{
	*middle_ = value;
}

void FuzzyNumber::setRight(const double& value) const
{
	*right_ = value;
}

void FuzzyNumber::setTuple(const tuple<double, double, double>& tuple) const
{
	setTuple(get<0>(tuple), get<1>(tuple), get<2>(tuple));
}

void FuzzyNumber::setTuple(const double& left, const double& middle, const double& right) const
{
	*left_ = left;
	*middle_ = middle;
	*right_ = right;
}

void FuzzyNumber::multiply(const FuzzyNumber& other) const
{
	*left_ = *middle_ * *other.middle_ - *other.middle_ * *left_ - *middle_ * *other.left_ + *left_ * *
		other.left_;
	*middle_ = *middle_ * *other.middle_;
	*right_ = *middle_ * *other.middle_ + *other.middle_ * *right_ + *middle_ * *other.right_ + *right_ *
		*other.right_;
}

void FuzzyNumber::subtract(const FuzzyNumber& other) const
{
	*left_ = *middle_ - *other.middle_ - *left_ - *other.left_;
	*middle_ = *middle_ - *other.middle_;
	*right_ = *middle_ - *other.middle_ + *right_ + *other.right_;
}

void FuzzyNumber::divide(const FuzzyNumber& other) const
{
	*left_ = (*middle_ - *left_) / (*other.middle_ + *other.right_);
	*middle_ = *middle_ / *other.middle_;
	*right_ = (*middle_ + *right_) / (*other.middle_ - *other.left_);
}

void FuzzyNumber::add(const FuzzyNumber& other) const
{
	*left_ = *middle_ + *other.middle_ - *left_ - *other.left_;
	*middle_ = *middle_ + *other.middle_;
	*right_ = *middle_ + *other.middle_ + *right_ + *other.right_;
}

bool FuzzyNumber::equals(const FuzzyNumber& other) const
{
	return *left_ == *other.left_ && *middle_ == *other.middle_ && *right_ == *other.right_;
}

bool FuzzyNumber::notEquals(const FuzzyNumber& other) const
{
	return !equals(other);
}

FuzzyNumber& FuzzyNumber::operator=(const FuzzyNumber& other)
{
	if (&other != this)
	{
		setTuple(other.getValues());
	}
	return *this;
}

FuzzyNumber& FuzzyNumber::operator=(const tuple<double, double, double>& tuple)
{
	setTuple(tuple);
	return *this;
}

ostream& operator<<(ostream& os, const FuzzyNumber& fuzzyNumber)
{
	os << "(" << *fuzzyNumber.left_ << "," << *fuzzyNumber.middle_ << "," << *fuzzyNumber.right_ << ")";
	return os;
}

istream& operator>>(istream& is, const FuzzyNumber& fuzzyNumber)
{
	is >> *fuzzyNumber.left_ >> *fuzzyNumber.middle_ >> *fuzzyNumber.right_;
	return is;
}
