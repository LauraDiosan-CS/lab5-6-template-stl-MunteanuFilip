#include "Tests.h"
#include "Repo.h"
#include "Service.h"
#include "Produs.h"
#include <assert.h>
#include <set>

void tests()
{
	void testAddRepo();
	void testRemoveRepo();
	void testUpdateRepo();
}

void testAddRepo()
{
	Produs produs[2];
	Repo<Produs> repo;

	char* nume1 = new char[20];
	char* nume2 = new char[20];
	int pret1 = 12, pret2 = 10;
	int nr_ex1 = 3, nr_ex2 = 5;

	strcpy_s(nume1, 4, "bbb");
	Produs produs1(nume1, pret1, nr_ex1);

	strcpy_s(nume2, 5, "rrrr");
	Produs produs2(nume2, pret2, nr_ex2);

	repo.addProdus(produs1);
	repo.addProdus(produs2);

	assert(repo.getSize() == 2);

}

void testRemoveRepo()
{
	Produs produs[2];
	Repo<Produs> repo;

	char* nume3 = new char[20];
	char* nume4 = new char[20];
	int pret3 = 7, pret4 = 14;
	int nr_ex3 = 2, nr_ex4 = 1;

	strcpy_s(nume3, 3, "ee");
	Produs produs3(nume3, pret3, nr_ex3);

	strcpy_s(nume4, 4, "vvv");
	Produs produs4(nume4, pret4, nr_ex4);

	repo.addProdus(produs3);
	repo.addProdus(produs4);

	repo.removeProdus(produs3);

	assert(repo.getSize() == 1);

}

void testUpdateRepo()
{
	Produs produs[2];
	Repo<Produs> repo;

	char* nume3 = new char[20];
	char* nume4 = new char[20];
	int pret3 = 7, pret4 = 14;
	int nr_ex3 = 2, nr_ex4 = 1;

	strcpy_s(nume3, 7, "abcdef");
	Produs produs3(nume3, pret3, nr_ex3);

	strcpy_s(nume4, 4, "qwe");
	Produs produs4(nume4, pret4, nr_ex4);

	repo.addProdus(produs3);
	repo.addProdus(produs4);

	Service serv;
	serv.updateProdus(nume3, pret3, nr_ex3, nume4, pret4, nr_ex4);


	set<Produs> produse = serv.getAll();

	assert(produse.find(produs3) == produse.end());
	assert(produse.find(produs4) != produse.end());

}