
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

secretaryList convertToSecretary(pacient aux, string nameFileAppointment, string nameFileContacts) //recibe un paciente y carga los datos 
																	//en un struct del tipo secretaria y busca el id-medico
																	//en el arch de consultas
{
	fstream readapp, readcon;
	bool found = false;
	bool found2 = false;
	readapp.open(nameFileAppointment, ios::in);
	readcon.open(nameFileContacts, ios::in);

	secretaryList auxsec;

	auxsec.dni = aux.dni;
	auxsec.namePacient = aux.namePacient;
	auxsec.lastNamePacient = aux.lastNAmePacient;
	auxsec.medicalInsurance = aux.idInsurance;

	char coma;
	string dummy;

	long unsigned int dniaux = 0;
	
	string iddocaux;
	readapp >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;//header

	while (readapp) //leo el archivo de appointment
	{
		readapp >> dniaux >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> iddocaux;
		if (dniaux == aux.dni)
		{
		auxsec.idDoctor = dniaux;
		found = true;
		}
	}readapp.close();

	if (!(found))
	{
		auxsec.idDoctor = 0;
	}

	string cellphoneaux;
	readcon >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;//header
	while (readcon) //leo el de contactos
	{
		readcon >> dniaux >> coma >> cellphoneaux >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		
		if (dniaux == aux.dni)
		{
			auxsec.cellphoneNumber = cellphoneaux;
		}

	}readcon.close();

	if (!(found2))
	{
		auxsec.cellphoneNumber = 0;
	}

	auxsec.answer = '.';

	return auxsec;

}

bool doctorIdList(string nameFileAppointment, string** list, int* sizeList)
{
	fstream readapp;

	readapp.open(nameFileAppointment, ios::in);
	if (!(readapp.is_open())) return false;

	char coma;
	string dummy;

	readapp >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;//header

	appointment aux;

	while (readapp)
	{
		readapp >> aux.dniPacient >> coma >> aux.dateAppointment >> coma >> aux.dateAppointment >> coma >> aux.asistance >> coma >> aux.idDoctor;
		for (int i = 0; i < *sizeList:i++)
		{
			if (**list[i] == aux.idDoctor)
			{
				break;
			}
		}
		if (i == *sizeList)
		{
			string* newdoc = new string[*sizeList + 1];
			newdoc[*sizeList] = aux.idDoctor;
		}
	}
	readapp.close();
	*sizeList = *sizeList + 1;
	delete* list;
	*list = newdoc;
	return true;
}

}

