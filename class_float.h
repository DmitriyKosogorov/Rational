#pragma once
#ifndef Class_Float_H
#define Class_Float_H
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const int intmax = 2100000000;

class Rational
{
//private:

public:
	int numer, denom;
	Rational();
	Rational(int a);
	Rational(int a, int b);
	Rational& operator += (const Rational& r);
	void simplify();
	Rational operator + (const Rational& r) const;
	Rational operator - () const;
	Rational& operator -= (const Rational& r);
	bool operator == (const Rational& r) const;
	bool operator != (const Rational& r) const;
	Rational operator / (int b);
	Rational operator ++(int);
	Rational operator - (Rational b);
	friend istream& operator >> (istream& in, Rational& r);
	friend ostream& operator << (ostream& out, Rational& r);
	void clear();
};
	Rational operator * (int a, Rational b);
	Rational operator * (Rational a, Rational b);
	Rational sqr(Rational d);

#endif