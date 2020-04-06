#include "Service.h"

Service::Service()
{
}

Service::Service(const Repo<Produs>& repository) : repo{ repository } {}

void Service::addProdus(char* nume, int pret, int nr_exemplare)
{
	Produs p = { nume, pret, nr_exemplare };
	repo.addProdus(p);

}

void Service::updateProdus(char* numeVechi, int pretVechi, int nr_exemplareVechi, char* nume, int pret, int nr_exemplare)
{
	Produs p = { nume, pret, nr_exemplare };
	Produs pVechi = { numeVechi, pretVechi, nr_exemplareVechi };
	repo.updateProdus(pVechi, p);
}

void Service::removeProdus(char* nume, int pret, int nr_exemplare)
{
	Produs p = { nume, pret, nr_exemplare };
	repo.removeProdus(p);
}

set<Produs> Service::getAll()
{
	return repo.getAll();
}

int Service::getSize()
{
	return repo.getSize();
}