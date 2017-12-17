#pragma once
#include"Person.h"
class Bus {
	char Marka[20];
	int Marsh;
	int Number;
	int Year;
	int Probeg;
	Person npc;
public:
	Bus();
	int getMarsh();
	int getProbeg();
	int getYear();
	void show();
};

void SameMarsh(Bus *, int);
void VuborProbeg(Bus *, int);
void VuborYear(Bus *, int,int);
