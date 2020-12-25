#include<iostream>
#include<cmath>
#include<iomanip>
#include"class_float.h"
using namespace std;

Rational::Rational()
{
	numer = 0;
	denom = 1;
}
Rational::Rational(int a)
{
	numer = a; denom = 1;
}
Rational::Rational(int a, int b)
{
	numer = a; denom = b;
}

Rational& Rational::operator += (const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom = denom * r.denom;
	return *this;
}
void Rational::simplify()
{
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom % i == 0)
		{
			numer = numer / i;
			denom = denom / i;
			i--;
		}
}
Rational Rational::operator + (const Rational& r) const
{
	Rational res(*this);
	return res += r;
}
Rational Rational::operator - () const
{
	Rational r(-numer, denom);
	return r;
}
Rational& Rational::operator -= (const Rational& r)
{
	return(*this += (-r));
}
Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}

Rational sqr(Rational d)
{
	double a, b;
	a = double(d.numer);
	b = double(d.denom);
	if (a >= 0)
	{
		a = pow(a, 0.5);
		b = pow(b, 0.5);
		//cout<<d<<endl << a << endl << b << endl << a / b<<endl;
		while (a > intmax || b > intmax)
		{
			a = a / 10;
			b = b / 10;
		}
		while (a < 1000000 && b < 1000000)
		{
			a = a * 10;
			b = b * 10;
		}
		return Rational(int(a), int(b));
	}
	else
		return Rational();
}

bool Rational::operator == (const Rational& r) const
{
	return(numer == r.numer) && (denom == r.denom);
}
bool Rational::operator != (const Rational& r) const
{
	return !(*this == r);
}

istream& operator >> (istream& in, Rational& r)
{
	in >> r.numer >> r.denom; return in;
}
ostream& operator << (ostream& out, Rational& r)
{
	out << r.numer << "/" << r.denom; return out;
}

void Rational::clear()
{
	numer = 0;
	denom = 1;
}
Rational operator * (int a, Rational b)
{
	b.numer = a * b.numer;
	return b;
}
Rational Rational::operator - (Rational b)
{
	Rational r(*this);
	b = -b;
	//cout << this << endl << b;
	r += b;
	return(r);
}
Rational operator * (Rational a, Rational b)
{
	a.numer = a.numer * b.numer;
	a.denom = a.denom * b.denom;
	return(a);
}
Rational Rational::operator / (int b)
{
	Rational r(*this);
	r.denom = r.denom * b;
	r.simplify();
	return(r);
}
