#include "stdafx.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
void Person::setPerson() {
	cout << "Sname: ";
	cin.clear(); 
	cin.sync(); 
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Sname, 30);
	cout << "InicOne: ";
	cin >> InicOne;
	cout << "\n InicTwo: ";
	cin >> InicTwo;
	cout << endl;
}

void Person::getPerson() {
	cout << "Person: " << Sname << ' ' << InicOne << ' ' << InicTwo << endl;
}