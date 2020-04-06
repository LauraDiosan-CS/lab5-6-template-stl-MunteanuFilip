#pragma once
#include <iostream>
using namespace std;
#include <ostream>
class Produs {
private:
	char* nume;
	int pret;
	int nr_exemplare;
public:
	Produs();
	Produs(const char* nume, int pret, int nr_exemplare);
	Produs(const Produs& p);
	~Produs();
	char* getNume();
	int getPret();
	int getNrExemplare();
	Produs& operator=(const Produs& p);
	friend bool operator<(const Produs& p1, const Produs& p2);
	bool operator==(const Produs& p);
	friend ostream& operator<<(ostream& os, const Produs& p);

};