
#include "libreria.h"



void findContact(string nameFileContacts, contact* aux, long unsigned int DNI)
{
	//lo leo, mientras lo leo voy llenando el contenido del puntero, booleano true lo encontre. si
	//el bool sigue siendo false al puntero le digo null 

	bool found = false;
	fstream read;
	char coma = 0;
	string dummy;

	read.open(nameFileContacts, ios::in);

	if (!(read.is_open())) return;

	getline(read, dummy); //revisar, fuente loren

	while (read)
	{
		read >> *aux.dni >> coma >> *aux.numberTelephone >> coma >> *aux.numberPhone >> coma >> *aux.address >> coma >> *aux.mail;
		if (*aux.dni == DNI)
		{
			found = true;
			break;
		}
	}
	read.close();

	if (!(found)) //fuente agos.
	{
		aux = nullptr;

	}
	return;
}