#pragma once

#include "Produs.h"
#include "Repo.h"

class Service
{
private:
    Repo<Produs> repo;
public:
    Service();
    Service(const Repo<Produs>& repository);

    void addProdus(char* nume, int pret, int nr_exemplare);
    void updateProdus(char* numeVechi, int pretVechi, int nr_exemplareVechi, char* nume, int pret, int nr_exemplare);
    void removeProdus(char* nume, int pret, int nr_exemplare);

    set<Produs> getAll();

    int getSize();
};
