#pragma once
#include <iostream>
using namespace std;
#include <ostream>
class Produs {
private:
	int id;
	char* nume;
	int pret;
	int nr_exemplare;
public:
	Produs();
	Produs(int id, const char* nume, int pret, int nr_exemplare);
	Produs(const Produs& p);
	~Produs();

	int getId();
	char* getNume();
	int getPret();
	int getNrExemplare();

	void setNume(const char*); 
	void setPret(int); 
	void setNrExemplare(int); 
	
	Produs& operator=(const Produs& p);
	friend bool operator<(const Produs& p1, const Produs& p2);
	bool operator==(const Produs& p);
	friend ostream& operator<<(ostream& os, const Produs& p);
	friend istream& operator>>(istream& is, Produs& p); 
};