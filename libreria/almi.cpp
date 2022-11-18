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

	read >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;

	while (read)
	{
		read >>aux->dniContact >> coma >> aux->numberTelephone >> coma >> aux->numberPhone >> coma >> aux->adress >> coma >> aux->mail;
		if (aux->dniContact == DNI)
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
	bool found2 = false;
	auxsec.dniSecL = aux.dni;
	auxsec.namePacientSecL = aux.namePacient;
	auxsec.lastNamePacientSecL = aux.lastNAmePacient;
	auxsec.medicalInsuranceSecL = aux.idInsurance;

	fstream readcon;
	readcon.open(nameFileContacts, ios::in); //abro el archivo de contactos para leerme el telefono de contacto del paciente q recibo
	if (!(readcon.is_open()))
	{
		auxsec.dniSecL = 0;
	}
	char coma;
	string dummy;

	long unsigned int dniaux = 0;
	string iddocaux;

	appointment lastApp;
	time_t dummys = lastAppointment(aux.dni, sizeListAppointment, listAppointment, &lastApp); //llamo a la funccion lastappointmente que me devuele la struct de ultima consulta por referencia
	
	auxsec.idDoctorSecL = lastApp.idDoctor; //solo me importa el id Doctor de la ultima consulta(el resto ni me lo guardo)
	
	string cellphoneaux;
	readcon >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;//header(no me interesa)
	while (readcon) //leo el archivo de contactos
	{
		readcon >> dniaux >> coma >> cellphoneaux >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		
		if (dniaux == aux.dni)
		{
			auxsec.cellphoneNumberSecL = cellphoneaux;
			found2 = true;
		}

	}readcon.close();

	if (!(found2))
	{
		auxsec.cellphoneNumberSecL = "0"; //si no econtro el contacto me lleno el campo con un 0 (no va a poder llamar al paciente). En este caso se podría pasar otro dato como mail, etc pero es muy retorcido para plantear
	}
	auxsec.answerSecL = '.'; //inicializo la respuesta del paciente con un . (luego la secretaría llenara este campo)
	return auxsec;
}



