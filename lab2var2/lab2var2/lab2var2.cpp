// lab2var2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
string Sname;
char InicOne[2];
char InicTwo[2];
getline(cin, Sname);
istringstream si(Sname);
cout << Sname << endl;
cin >> InicOne;
cout << InicOne<<endl;
cin >> InicTwo;
cout << InicTwo << endl;
cout << Sname << InicOne << InicTwo << endl;
system("pause");
};


