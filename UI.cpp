#include <iostream>
#include "UI.h"

using namespace std;

UI::UI()
{

}

UI::UI(const Service& service)
{
	this->service = service;
}

UI::~UI()
{
}

void UI::addProdus()
{
	char nume[30];
	int pret, nr_exemplare;

	cout << "Dati nume: ";
	cin >> nume;

	cout << "Dati pret: ";
	cin >> pret;

	cout << "Dati nr de exemplare: ";
	cin >> nr_exemplare;

	service.addProdus(nume, pret, nr_exemplare);
	cout << endl << "Produsul a fost adaugat!" << endl;
}

void UI::updateProdus()
{
	int id;
	char nume[30];
	int pret, nr_exemplare;

	char numeVechi[30];
	int pretVechi, nr_exemplareVechi;

	cout << "ID to update: "; cin >> id; 

	cout << "Dati nume vechi: ";
	cin >> numeVechi;

	cout << "Dati pret vechi: ";
	cin >> pretVechi;

	cout << "Dati nr de exemplare vechi: ";
	cin >> nr_exemplareVechi;


	cout << "Dati nume nou: ";
	cin >> nume;

	cout << "Dati pret nou: ";
	cin >> pret;

	cout << "Dati nr de exemplare nou: ";
	cin >> nr_exemplare;


	service.updateProdus(id, numeVechi, pretVechi, nr_exemplareVechi, nume, pret, nr_exemplare);
	cout << endl << "Produsul a fost updatat!" << endl;
}

void UI::deleteProdus()
{
	int id;
	char nume[30];
	int pret, nr_exemplare;

	cout << "Dati id: ";
	cin >> id;

	cout << "Dati nume: ";
	cin >> nume;

	cout << "Dati pret: ";
	cin >> pret;

	cout << "Dati nr de exemplare: ";
	cin >> nr_exemplare;

	service.removeProdus(id,nume, pret, nr_exemplare);
	cout << endl << "Produsul a fost sters!" << endl;
}

void UI::displayProdus()
{
	set <Produs> produse = service.getAll();
	for (auto it = produse.begin(); it != produse.end(); ++it)
	{
		cout << *it << '\n';
	}
}
void UI::display()
{
	cout << endl;
	cout << "    Pentru cumparare alegeti 1/mai multe produse si cantitatea acestora." << endl;
	cout << "    Pentru a vedea situatia produselor apasati tasta 2"<<endl;
	cout << "    ATENTIE! Tranzactia se considera efectuata doar daca produsele exista si sunt suficiente exemplare."<<endl;
	cout << "    ATENTIE! Puteti returna doar cate 1 produs pe rand, specificand numele si cantitatea!" << endl;
	cout << endl;
	
	
}

void UI::show_menu()
{
	cout << "     |-----------------------------MENIU----------------------------|" << endl;
	cout << "     |       1. Adaugare produs                                     |" << endl;
	cout << "     |       2. Afisare produs                                      |" << endl;
	cout << "     |       3. Update produs                                       |" << endl;
	cout << "     |       4. Stergere produs                                     |" << endl;
	cout << "     |--------------------------------------------------------------|" << endl;
	cout << "     |       5. Cumparare produs                                    |" << endl;
	cout << "     |       6. Returnare produs                                    |" << endl;
	cout << "     |       0. EXIT                                                |" << endl;
	cout << "     |--------------------------------------------------------------|" << endl;
	cout << endl;
}

void UI::cumparaProdus()
{
	cout << "Cate produse cumparati? ";
	int n, i, nrExemplare, id;
	char nume[40];
	cin >> n; cout << endl;
	for (i = 0; i < n; ++i)
	{
		cout << "Dati id: ";
		cin >> id;

		cout << "Dati nume: ";
		cin >> nume;

		cout << "Dati nr de exemplare: ";
		cin >> nrExemplare;
		int raspunsFunctie = service.cumparaProdus(id, nume, nrExemplare);
		if (raspunsFunctie == -1)
			cout << "Produs incorect! \n";
		else
			if (raspunsFunctie == -2)
				cout << "Nr bucati prea mic! \n";
			else
				cout << "Produs cumparat! \n";
	}
}

void UI::returneazaProdus()
{
	int id, nrExemplare;
	char nume[40];
	cout << "Dati id: ";
	cin >> id;

	cout << "Dati nume: ";
	cin >> nume;

	cout << "Dati nr de exemplare: ";
	cin >> nrExemplare;
	if (service.returneazaProdus(id, nume, nrExemplare) == -1)
		cout << "Produs incorect! \n";
	else
		cout << "Produs returnat! \n";
}

int UI::run()
{
	
	int op = -1;
	do
	{
		display();
		show_menu();
		int op;
		cout << "Dati optiunea: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{
			exit(1);
			break;
		}
		case 1:
		{
			addProdus();
			cout << "\n";
			break;
		}
		case 2:
		{
			cout << "\n";
			displayProdus();
			cout << "\n";
			break;
		}
		case 3:
		{
			updateProdus();
			cout << "\n";
			break;
		}
		case 4:
		{
			deleteProdus();
			cout << "\n";
			break;
		}
		case 5:
		{
			cumparaProdus();
			cout << "\n";
			break;
		}
		case 6:
		{
			returneazaProdus();
			cout << endl;
			break;
		}


		default:
		{
			cout << "Comanda imposibila!";
			cout << "\n";
		}
		}
	} while (op != 0);
}