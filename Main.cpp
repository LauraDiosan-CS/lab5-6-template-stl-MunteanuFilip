#include "Tests.h"
#include <iostream>
#include "UI.h"
#include "RepoFile.h"
using namespace std;


int main()
{
	tests();
	cout << "...teste trecute cu succes!" << endl;

	RepoFile <Produs> repoProdus("Produs.txt");
	Service service = { repoProdus };

	UI ui = { service };
	ui.run();

	return 0;
}