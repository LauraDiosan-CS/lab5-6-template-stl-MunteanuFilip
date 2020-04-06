#include "Produs.h"
#include <cstring>

Produs::Produs()
{
	this->nume = NULL;
	this->pret = 0;
	this->nr_exemplare = 0;
}

Produs::Produs(const char* name, int pret, int nr_exemplare)
{
	this->nume = new char[strlen(name) + 1];
	strcpy_s(this->nume, strlen(name) + 1, name);

	this->pret = pret;
	this->nr_exemplare = nr_exemplare;
}

Produs::Produs(const Produs& p)
{
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);

	this->pret = p.pret;
	this->nr_exemplare = p.nr_exemplare;

}

Produs::~Produs()
{
	if (this->nume)
	{
		delete[] this->nume;
		this->nume == NULL;
	}

}

char* Produs::getNume()
{
	return this->nume;
}

int Produs::getPret()
{
	return this->pret;
}

int Produs::getNrExemplare()
{
	return this->nr_exemplare;
}

Produs& Produs::operator=(const Produs& p)
{
	if (this->nume)
	{
		delete[] this->nume;
		this->nume == NULL;
	}
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);

	this->pret = p.pret;

	this->nr_exemplare = p.nr_exemplare;

	return*this;
}




bool Produs::operator==(const Produs& p)
{
	return strcmp(this->nume, p.nume) == 0 && this->pret == p.pret && this->nr_exemplare == p.nr_exemplare;
}



bool operator<(const Produs& p1, const Produs& p2)
{
	if (p1.pret != p2.pret)
		return p1.pret < p2.pret;
	else
		if (p1.nume != p2.nume)
			return strcmp(p1.nume, p2.nume) < 0;
	return p1.nr_exemplare < p2.nr_exemplare;
}

ostream& operator<<(ostream& os, const Produs& p)
{
	cout << "Nume: " << p.nume << " Pret: " << p.pret << " Numar exemplare: " << p.nr_exemplare << '\n';
	return os;
}