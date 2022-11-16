
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

secretaryList convertToSecretary(pacient aux, appointment* listAppointment, int sizeListAppointment, string nameFileContacts) //recibe un paciente y carga los datos 
																	//en un struct del tipo secretaria y busca el id-medico
																	//en el arch de consultas
{
	secretaryList auxsec;


	fstream readcon;
	bool found2 = false;
	readcon.open(nameFileContacts, ios::in);
	if (!(readcon.is_open()))
	{
		auxsec.dni = 0;
	}

	auxsec.dni = aux.dni;
	auxsec.namePacient = aux.namePacient;
	auxsec.lastNamePacient = aux.lastNAmePacient;
	auxsec.medicalInsurance = aux.idInsurance;

	char coma;
	string dummy;

	long unsigned int dniaux = 0;
	
	string iddocaux;

	appointment lastApp;
	time_t dummy = lastAppointment(aux.dni, sizeListAppointment, listAppointment, &lastApp);
	
	auxsec.idDoctor = lastApp.idDoctor;
	
	string cellphoneaux;
	readcon >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;//header
	while (readcon) //leo el de contactos
	{
		readcon >> dniaux >> coma >> cellphoneaux >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		
		if (dniaux == aux.dni)
		{
			auxsec.cellphoneNumber = cellphoneaux;
			found2 = true;
		}

	}readcon.close();

	if (!(found2))
	{
		auxsec.cellphoneNumber = 0;
	}

	auxsec.answer = '.';

	return auxsec;

}



