#include<iostream>
#include<cmath>
#include<iomanip>
#include"class_float.cpp"
using namespace std;

int main()
{
	Rational a, b, c, diskriminant, k, l,x1,x2;
	int a1, b1, c1;
	cout << "Enter the arguments" << endl;
	cin >> a >> b >> c;
	k = 4 * a * c;
	l = b * b;
	diskriminant = l - k;
	diskriminant=sqr(diskriminant);
	//cout <<k<<endl<<l<<endl<< diskriminant << endl;
	x1 = (-b + diskriminant) / 2;
	x2 = (-b - diskriminant) / 2;
	cout << x1 << endl << x2 << endl;

}
