#include "Service.h"

Service::Service()
{
}

Service::Service(const Repo<Produs>& repository) : repo{ repository } {}

void Service::addProdus(char* nume, int pret, int nr_exemplare)
{

	int id = repo.getSize() + 1;
	this->repo.addProdus(Produs(id, nume, pret, nr_exemplare));
}

void Service::updateProdus(int id, char* numeVechi, int pretVechi, int nr_exemplareVechi, char* nume, int pret, int nr_exemplare)
{
	Produs p = { id, nume, pret, nr_exemplare }; 
	Produs pVechi = { id, numeVechi, pretVechi, nr_exemplareVechi }; 
	repo.updateProdus(pVechi, p);
}

void Service::removeProdus(int id, char* nume, int pret, int nr_exemplare)
{
	Produs p = { id, nume, pret, nr_exemplare };
	repo.removeProdus(p);
}

int Service::cumparaProdus(int id, char* nume, int nr_exemplare)
{
	Produs prodUpdate, p = { id, nume, 0, nr_exemplare }, prodVechi;
	set<Produs> listaProduse = repo.getAll();
	set <Produs> ::iterator iteratorProdus;
	for (iteratorProdus = listaProduse.begin(); iteratorProdus != listaProduse.end(); ++iteratorProdus) {
		prodVechi = *iteratorProdus;
		if (prodVechi == p)
			break;
	}
	if (iteratorProdus == listaProduse.end())
		return -1;
	if (prodVechi.getNrExemplare() < p.getNrExemplare())
		return -2;
	prodUpdate = prodVechi;
	prodUpdate.setNrExemplare(prodVechi.getNrExemplare() - p.getNrExemplare());
	repo.updateProdus(prodVechi, prodUpdate);
	return 1;
	
}

int Service::returneazaProdus(int id, char* nume, int nr_exemplare)
{
	Produs prodUpdate, p = { id, nume, 0, nr_exemplare }, prodVechi;
	set<Produs> listaProduse = repo.getAll();
	set <Produs> ::iterator iteratorProdus;
	for (iteratorProdus = listaProduse.begin(); iteratorProdus != listaProduse.end(); ++iteratorProdus) {
		prodVechi = *iteratorProdus;
		if (prodVechi == p)
			break;
	}
	if (iteratorProdus == listaProduse.end())
		return -1;
	prodUpdate = prodVechi;
	prodUpdate.setNrExemplare(prodVechi.getNrExemplare() + p.getNrExemplare());
	repo.updateProdus(prodVechi, prodUpdate);
	return 1;
}

set<Produs> Service::getAll()
{
	return repo.getAll();
}

int Service::getSize()
{
	return repo.getSize();
}

