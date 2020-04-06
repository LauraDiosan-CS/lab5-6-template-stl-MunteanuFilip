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
	char nume[30];
	int pret, nr_exemplare;

	char numeVechi[30];
	int pretVechi, nr_exemplareVechi;

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


	service.updateProdus(numeVechi, pretVechi, nr_exemplareVechi, nume, pret, nr_exemplare);
	cout << endl << "Produsul a fost updatat!" << endl;
}

void UI::deleteProdus()
{
	char nume[30];
	int pret, nr_exemplare;

	cout << "Dati nume: ";
	cin >> nume;

	cout << "Dati pret: ";
	cin >> pret;

	cout << "Dati nr de exemplare: ";
	cin >> nr_exemplare;

	service.removeProdus(nume, pret, nr_exemplare);
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

void UI::show_menu()
{
	cout << endl;
	cout << "1. Adaugare produs" << endl;
	cout << "2. Afisare produs" << endl;
	cout << "3. Update produs" << endl;
	cout << "4. Stergere produs" << endl;
	cout << "0. Iesire" << endl;
	cout << endl;
	cout << endl;
}

int UI::run()
{
	//UserInterface userInterface;
	int op = -1;
	do
	{
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


		default:
		{
			cout << "Optiune inexistenta!";
			cout << "\n";
		}
		}
	} while (op != 0);
}