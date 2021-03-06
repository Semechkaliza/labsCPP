#include "stdafx.h"
#include <iostream>
using namespace std;
class Fraction {
public:
	int a;
	int b;
	Fraction() : a(0), b(1) {};
	Fraction(int a, int b) {
		(*this).a = a;
		(*this).b = b;
		cout << "Konstruct works\n";
	};
	void NOD() {
		int a_1 = a;
		int b_1 = b;
		int buf;
		while (b_1 != 0) {
			buf = b_1;
			b_1 = a_1 % b_1;
			a_1 = buf;
		}
		a /= a_1;
		b /= a_1;
	};
	void show() {
		int buf = a % b;
		if (!buf) cout << a / b << endl;
		else cout << a << "/" << b << endl;
	};
	~Fraction() {
		cout << "Destruct works\n";
	};
};

class addMultFraction {
public:
	Fraction drob1;
	Fraction drob2;
	addMultFraction(int a, int b, int a1, int b1) : drob1(a, b), drob2(a1, b1) {}
	friend Fraction& operator+(Fraction &drob1, Fraction &drob2);
	friend Fraction& operator*(Fraction &drob1, Fraction &drob2);
	friend Fraction& operator-(Fraction &drob1, Fraction &drob2);
	friend Fraction& operator/(Fraction &drob1, Fraction &drob2);
	friend Fraction& operator<(Fraction &drob1, Fraction &drob2);
	friend Fraction& operator>(Fraction &drob1, Fraction &drob2);
	friend Fraction& operator==(Fraction &drob1, Fraction &drob2);
	friend ostream& operator<<(ostream &cout, const Fraction& y);
	friend istream& operator>>(istream &in, const Fraction &y);
	void show() {
		cout << "First fraction: " << drob1.a << "/" << drob1.b << endl;
		cout << "Second fraction: " << drob2.a << "/" << drob2.b << endl;
		cout << endl;
	};
};

Fraction& operator+(Fraction &drob1, Fraction &drob2) {
	Fraction * temp = new Fraction;
	(*temp).b = drob1.b * drob2.b;
	(*temp).a = (((*temp).b) / drob1.b) * drob1.a + (((*temp).b) / drob2.b) * drob2.a;
	return *temp;
}

Fraction& operator*(Fraction &drob1, Fraction &drob2) {
	Fraction * temp = new Fraction;
	(*temp).a = drob1.a * drob2.a;
	(*temp).b = drob1.b * drob2.b;
	return *temp;
}
Fraction& operator-(Fraction &drob1, Fraction &drob2) {
	Fraction * temp = new Fraction;
	(*temp).b = drob1.b * drob2.b;
	(*temp).a = (((*temp).b) / drob1.b) * drob1.a - (((*temp).b) / drob2.b) * drob2.a;
	return *temp;
}

Fraction& operator/(Fraction &drob1, Fraction &drob2) {
	Fraction * temp = new Fraction;
	(*temp).a = drob1.a * drob2.b;
	(*temp).b = drob1.b * drob2.a;
	return *temp;
}
Fraction& operator==(Fraction &drob1, Fraction &drob2)
{
	Fraction * temp = new Fraction;
	if ((drob1.a == drob2.a) && (drob1.b == drob2.b)) cout << "Fractions are equals" << endl;
	else cout << "Fractions aren't eguals" << endl;
	return *temp;
}
Fraction& operator<(Fraction &drob1, Fraction &drob2)
{
	Fraction * temp = new Fraction;
	if (drob1.b == drob2.b) {
		if (drob1.a < drob2.a) cout << "First fraction is less" << endl;
		else cout << "Second fraction is less";
	};
	if (drob1.a == drob2.a)
	{
		if (drob1.b < drob2.b) cout << "Second fraction is less" << endl;
		else cout << "First fraction is less";
	};
	return *temp;
}
Fraction& operator>(Fraction &drob1, Fraction &drob2)
{
	Fraction * temp = new Fraction;
	if (drob1.b == drob2.b) {
		if (drob1.a > drob2.a) cout << "First fraction is more" << endl;
		else cout << "Second fraction is more" << endl;
	};
	if (drob1.a == drob2.a)
	{
		if (drob1.b > drob2.b) cout << "first fraction is more" << endl;
		else cout << "second fraction is more" << endl;
	};
	return *temp;
}
ostream& operator<<(ostream &out, const Fraction &y) {
	out << y.a;
	return out;
}
istream& operator>>(istream &in, Fraction &y) {
	in >> y.a;
	return in;
}
void changeArray(Fraction* array, int c) {
	if (c % 2 == 0) {
		for (int i = 0; i<c; i += 2)
		{
			array[i] = array[i] + array[i + 1];
			cout << array[i] << endl;
		}

	}
	else for (int i = 0; i<c - 1; i += 2) {
		array[i] = array[i] + array[i + 1];
		cout << array[i] << endl;
	}
}

int main()
{
	int num1, den1, num2, den2;
	cout << "Enter first numerator and denomenator" << endl;
	cin >> num1;
	while (1) {
		cin >> den1;
		if (den1) break;
		else cout << "Enter ne 0 in denomenator" << endl;
	};
	cout << "Enter second numerator and denomenator" << endl;
	cin >> num2;
	while (1) {
		cin >> den2;
		if (den2) break;
		else cout << "Enter ne 0 in denomenator" << endl;
	};

	Fraction drob0;
	addMultFraction drob(num1, den1, num2, den2);

	drob.show();

	cout << "What will we do with fractions? \n 1-sum \n 2- multiplication \n 3-difference \n 4-product \n 5-less \n 6-more \n 7-equals \n 8-assignment" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1: {
		cout << "The sum: ";
		drob0 = drob.drob1 + drob.drob2;
		drob0.NOD();
		drob0.show();
		break;
	}
	case 2: {
		cout << "Multiplication: ";
		drob0 = drob.drob1 * drob.drob2;
		drob0.NOD();
		drob0.show();
		break;
	}
	case 3: {
		cout << "Difference: ";
		drob0 = drob.drob1 - drob.drob2;
		drob0.NOD();
		drob0.show();
		break;
	}

	case 4: {
		cout << "Product: ";
		drob0 = drob.drob1 / drob.drob2;
		drob0.NOD();
		drob0.show();
		break;
	}
	case 5: {
		cout << "Compare(less):  ";
		drob0 = drob.drob1 < drob.drob2;
		break;
	}
	case 6: {
		cout << "Compare(more):  ";
		drob0 = drob.drob1 > drob.drob2;
		break;
	}
	case 7: {
		cout << "Compare(equals):  ";
		drob0 = drob.drob1 == drob.drob2;
		break;
	}
	case 8: {
		cout << "Assignment:";
		drob.drob1 = drob.drob2;
		drob.show();
		break;
	}
	}

	int razm;
	cout << "Enter razmer massiva" << endl;
	cin >> razm;
	cout << "Old massiv: \n";

	Fraction* array = new Fraction[razm];
	for (int i = 0; i<razm; i++) {
		cin >> array[i];
	}
	cout << "New massive: \n";
	changeArray(array, razm);

	system("pause");
}
