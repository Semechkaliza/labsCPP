//9. Bus: Фамилия и инициалы водителя, Номер автобуса, Номер маршрута, Марка,
//	Год начала эксплуатации, Пробег.Создать массив объектов.Вывести :
//	а) список автобусов для заданного номера маршрута;
//	б) список автобусов, которые эксплуатируются больше 10 лет;
//	в) список автобусов, пробег у которых больше 10 000 км.

#include"stdafx.h"
#include<iostream>
#include <sstream>
#include <string>
#include"Bus.h"
#include"Person.h"
#define MAXYEAR 2007
#define MAXPROBEG 10000
#define MAXNUMBER 9999
#define MINYEAR 1900
#define MINNUMBER 1111
#define NORMPROBEG 100000

using namespace std;


int main() {
	istringstream  ssin(__DATE__);
	string mon, day, year;
	ssin >> mon >> day >> year;
	cout << "year  : "<< year<< std::endl;
	int y = atoi(year.c_str());
	Bus *spis;
	int n;
	cout << "enter buses number: "; cin >> n;
	spis = new Bus[n];
	cout << endl;
	for (int i = 0; i<n; i++) {
		cout << "==============================" << endl;
		spis[i].show();
	}
	SameMarsh(spis, n);
	VuborProbeg(spis, n);
	VuborYear(spis, n,y);
	delete[] spis;
	system("pause");
	return 0;
}

Bus::Bus() {
	npc.setPerson();
	while (int i = 1)
	{

		cout << "enter numer of bus: \n"; cin >> Number;
		if ((Number <= MAXNUMBER) && (Number >= MINNUMBER)) break;
		else {
			cin.clear();
			cin.ignore();
			cout << "Uncorrect number. Try again.(From 1111 to 9999)" << endl;
		}
	}
	while (int i = 1)
	{
		cout << "enter number of marshrut: \n"; cin >> Marsh;
		if (Marsh >0) break;
		else {
			cin.clear();
			cin.ignore();
			cout << "Uncorrect marshrut. Try again.(>0)" << endl;
		}

	}
	cout << "enter the mark of bus: \n"; cin >> Marka;
	while (int i = 1)
	{
		cout << "enter the year of start the bus: \n"; cin >> Year;
		if (Year >= MINYEAR) break;
		else {
			cin.clear();
			cin.ignore();
			cout << "Uncorrect year. Try again.(>1900 but <now)" << endl;
		}

	}
	while (int i = 1)
	{
		cout << "enter rhe amount of km: \n"; cin >> Probeg;
		if ((Probeg >0) && (Probeg<NORMPROBEG)) break;
		else {
			cin.clear();
			cin.ignore();
			cout << "Uncorrect probeg. Try again.(>0)" << endl;
		}

	}

	cout << endl;
}

void Bus::show() {
	npc.getPerson();
	cout << "Number: " << Number << endl;
	cout << "Marshrut: " << Marsh << endl;
	cout << "Marka: " << Marka << endl;
	cout << "Year: " << Year << endl;
	cout << "Probeg: " << Probeg << endl;

}

int Bus::getMarsh() {
	return Marsh;
}
int Bus::getYear() {
	return Year;
}
int Bus::getProbeg()
{
	return Probeg;
}

void SameMarsh(Bus *spis, int n) {
	int Marsh;
	int q = 0;
	cout << "Enter number of marsh: "; cin >> Marsh;
	for (int i = 0; i < n; i++)
		if (spis[i].getMarsh() == Marsh)
		{
			spis[i].show();
			q++;
		}
	if (!q) cout << "////////////////////Net zadannogo marshruta" << endl;
	cout << endl;
}
void VuborYear(Bus *spis, int n,int y) {
	cout << "Vubor po gody" << endl;
	int q = 0;
	for (int i = 0; i<n; i++)
		if (spis[i].getYear() < y)
		{
			spis[i].show();
			q++;
			cout << "///////////////////////// \n";
		}
	if (!q) cout << "//////////////////Vse avtobusy novye" << endl;
	cout << endl;
}
void VuborProbeg(Bus *spis, int n) {
	cout << "Vubor po probegy" << endl;
	int q = 0;
	for (int i = 0; i<n; i++)
		if (spis[i].getProbeg() > MAXPROBEG)
		{
			spis[i].show();
			q++;
			cout << "========================= \n";
		}
	if (!q) cout << "//////////////////Probeg kagdogo <10 000km" << endl;
	cout << endl;
}

