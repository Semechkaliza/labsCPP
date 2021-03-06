#pragma once
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <cmath>
using namespace std;
int n;
class Polygon1
{
public:
	virtual double Square(void) = 0;
	virtual double Perimeter(void) = 0;
};
class Polygon :Polygon1
{
	double *x = new double[n];
	double *y = new double[n];
public:
	Polygon();
	Polygon(double *, double *);
	const Polygon& operator= (const Polygon&);
	double Square(void);
	double Perimeter(void);
	void Print_Polygon(void);
	friend void ChoosePoint(double *, double *);
};

class Triangle : public Polygon
{
private:
	double x1, y1;
	double x2, y2;
	double x3, y3;
public:
	Triangle();
	Triangle(const double&, const double&, const double&, const double&, const double&, const double&);
	Triangle operator= (Triangle& x);
	const Triangle& operator= (const Triangle&);
	double Square(void);
	double Perimeter(void);
	void Print_Triangle(void);
	bool Is_Possible(void);
	void Mediana();
	void Height();
	void Bissectrisa();
	void IntersectionM();
	void IntersectionB();
	void IntersectionH();
};
Polygon::Polygon()
{
	for (int i = 0; i<n; i++) {
		x[i] = 0;
		y[i] = 0;
	}
}

Polygon::Polygon(double *a, double *b)
{
	for (int i = 0; i<n; i++) {
		x[i] = a[i];
		y[i] = b[i];
	}
};

double Polygon::Square()
{
	double A = sqrt((y[2] - y[1])*(y[2] - y[1]) + (x[2] - x[1])*(x[2] - x[1]));
	double k = 3.14 / n;
	return (((A*A)*n) / 4 * tan(k));
};

double Polygon::Perimeter()
{
	double A = sqrt((y[2] - y[1])*(y[2] - y[1]) + (x[2] - x[1])*(x[2] - x[1])); 
	return n * A; 
};

void Polygon::Print_Polygon()
{
	for (int i = 0; i<n; i++) {
		cout << "x" << i << "=" << x[i] << endl;
		cout << "y" << i << "=" << y[i] << endl;
	}
	cout << "\n";
	cout << "P = " << Perimeter() << ", S = " << Square() << endl;
};
void ChoosePoint(double *x, double *y) {
	int j, k, q;
	cout << "Choose points" << endl;
	for (int i = 0; i<n; i++) {
		cout << "(" << x[i] << "," << y[i] << ");\n";
	}
	cin >> j >> k >> q;
	Triangle a(x[j], y[j], x[k], y[k], x[q], y[q]);
	if (a.Is_Possible()) {
		cout << "Your Triangle build" << endl;
		a.Print_Triangle();
	}
	else cout << "\n Impossible to create Triangle. Please, press any key to continue...\n";
}

Triangle::Triangle(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f)
{
	x1 = a; y1 = b; x2 = c; y2 = d; x3 = e; y3 = f;
};

Triangle Triangle::operator= (Triangle& x)
{
	return Triangle(this->x1 = x.x1, this->y1 = x.y1, this->x2 = x.x2, this->y2 = x.y2, this->x3 = x.x3, this->y3 = x.y3);
};

double Triangle::Square(void)
{
	double A = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)); 
	double B = sqrt((y3 - y2)*(y3 - y2) + (x3 - x2)*(x3 - x2)); 
	double C = sqrt((y1 - y3)*(y1 - y3) + (x1 - x3)*(x1 - x3));
	double p = (A + B + C) / 2; 
	return sqrt(p * (p - A) * (p - C) * (p - B));
};

double Triangle::Perimeter() 
{
	double A = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)); 
	double B = sqrt((y3 - y2)*(y3 - y2) + (x3 - x2)*(x3 - x2)); 
	double C = sqrt((y1 - y3)*(y1 - y3) + (x1 - x3)*(x1 - x3)); 
	return A + B + C; 
};

void Triangle::Print_Triangle() 
{
	cout << "x1 = " << x1 << ", y1 = " << y1 << endl;
	cout << "x2 = " << x2 << ", y2 = " << y2 << endl;
	cout << "x3 = " << x3 << ", y3 = " << y3 << endl;
	cout << "\n";
	cout << "P = " << Perimeter() << ", S = " << Square() << endl;
	cout << "\n Mediana's:\n";
	Mediana();
	cout << "\n Height's:\n";
	Height();
	cout << "\n Bissectrisa's:\n";
	Bissectrisa();
	cout << "\n";
	cout << "\n Intersection of Bissectrisas:\n";
	IntersectionB();
	cout << "\n";
	cout << "\n Intersection of Medians:\n";
	IntersectionM();
	cout << "\n";
	cout << "\n Intersection of Heights:\n";
	IntersectionH();
	cout << "\n";
};

bool Triangle::Is_Possible() 
{
	double A = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)); 
	double B = sqrt((y3 - y2)*(y3 - y2) + (x3 - x2)*(x3 - x2));
	double C = sqrt((y1 - y3)*(y1 - y3) + (x1 - x3)*(x1 - x3)); 
	return ((A + B)>C) & ((B + C)>A) & ((A + C)>B);
};

void Triangle::Mediana() {
	double A = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)); 
	double B = sqrt((y3 - y2)*(y3 - y2) + (x3 - x2)*(x3 - x2)); 
	double C = sqrt((y1 - y3)*(y1 - y3) + (x1 - x3)*(x1 - x3)); 
	double m1 = ((sqrt(2 * (A*A) + 2 * (B*B) - (C*C))) / 2);
	double m2 = ((sqrt(2 * (A*A) + 2 * (C*C) - (B*B))) / 2);
	double m3 = ((sqrt(2 * (C*C) + 2 * (B*B) - (A*A))) / 2);
	cout << m1 << endl << m2 << endl << m3 << endl;
}

void Triangle::Height() {
	double A = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)); 
	double B = sqrt((y3 - y2)*(y3 - y2) + (x3 - x2)*(x3 - x2)); 
	double C = sqrt((y1 - y3)*(y1 - y3) + (x1 - x3)*(x1 - x3)); 
	double p = (A + B + C) / 2; 
	double h1 = ((2 * sqrt(A*B*p*(p - C)) / A + B));
	double h2 = ((2 * sqrt(A*C*p*(p - B)) / A + C));
	double h3 = ((2 * sqrt(C*B*p*(p - A)) / C + B));
	cout << h1 << endl << h2 << endl << h3 << endl;
}

void Triangle::Bissectrisa() {
	double A = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)); 
	double B = sqrt((y3 - y2)*(y3 - y2) + (x3 - x2)*(x3 - x2)); 
	double C = sqrt((y1 - y3)*(y1 - y3) + (x1 - x3)*(x1 - x3)); 
	double p = (A + B + C) / 2; 
	double b1 = 2 / A * sqrt(p*(p - A)*(p - B)*(p + C));
	double b2 = 2 / A * sqrt(p*(p - A)*(p + B)*(p - C));
	double b3 = 2 / A * sqrt(p*(p + A)*(p - B)*(p - C));
	cout << b1 << endl << b2 << endl << b3 << endl;
}

void Triangle::IntersectionM() {
	double m1 = (x1 + x2 + x3) / 3;
	double m2 = (y1 + y2 + y3) / 3;
	cout << m1 << " , " << m2;
}

void Triangle::IntersectionB() {
	double A = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)); 
	double B = sqrt((y3 - y2)*(y3 - y2) + (x3 - x2)*(x3 - x2)); 
	double C = sqrt((y1 - y3)*(y1 - y3) + (x1 - x3)*(x1 - x3)); 
	double b1 = (A*x1 + B * x2 + C * x3) / (A + B + C);
	double b2 = (A*y1 + B * y2 + C * y3) / (A + B + C);
	cout << b1 << " , " << b2;
}
void Triangle::IntersectionH() {
	double A = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1)); 
	double B = sqrt((y3 - y2)*(y3 - y2) + (x3 - x2)*(x3 - x2)); 
	double C = sqrt((y1 - y3)*(y1 - y3) + (x1 - x3)*(x1 - x3)); 
	double h1 = (A*x1 + B * x2 + C * x3) / (A + B);
	double h2 = (A*y1 + B * y2 + C * y3) / (A + B);
	cout << h1 << " , " << h2;
}

int main()
{
	cout << "Number of sides:\n";
	cin >> n;
	Polygon p1; 
	double *x = new double[n];
	double *y = new double[n];
	for (int i = 0; i<n; i++) {
		cout << "\n Input coordinates x,y:\n";
		cin >> x[i];
		cin >> y[i];
	}
	Polygon p2(x, y);
	p2.Print_Polygon();
	cout << "Triangle can be made from your Polygon. ";
	ChoosePoint(x, y);
	return 0;
};
