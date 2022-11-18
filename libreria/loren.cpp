#include "libreria.h"

void readPacient(string nameFilePacient, int * sizeListPacientUnrecoverable, pacient *& listPacientUnrecoverable, int sizeListAppointment, appointment* listAppointment, string nameFileContact, string filePacientUnrecoverable, int* sizeSec) //leo todos los pacientes (menos los que fallecieron)
{
	fstream filePacient;
	filePacient.open(nameFilePacient, ios::in); //abro el archivo de paciente para lectura
	if (sizeListPacientUnrecoverable == nullptr || listPacientUnrecoverable == nullptr || !(filePacient.is_open()))
		return;
	string dummy;
	int group;
	filePacient >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy
		>> dummy >> dummy;//leo la primera linea del csv (texto inutil)

	pacient aux;
	*sizeSec=0;
	secretaryList* listSec = new secretaryList[sizeSec]; //me creo una lista dinamica que es con la que luego haremos el archivo de secretaria
	secretaryList auxSec;

	while (filePacient) { //recorro el archivo de pacientes
		filePacient >> aux.dni >> dummy >> aux.namePacient >> dummy >> aux.lastNAmePacient >> dummy
			>> aux.sex >> dummy >> aux.dateBirth >> dummy >> aux.state >> dummy >> aux.idInsurance;
		group = keepingUpWithThePacients(aux, sizeListAppointment, listAppointment); //función que se fija el grupo al que pertenece el paciente
		if (group == 1) // 1: recuperable (lo paso a secretaria)
		{
			auxSec = convertToSecretary(aux, listAppointment, sizeListAppointment, nameFileContact); //
			if (auxSec.dniSecL != 0)
			{
				addSecetaryList(sizeSec, auxSec, &listSec);
			}
		}	
		else if(group == 2) // grupo 2: irrecuperable(lo agrego a la lista de irrecuperables)
			addPacientUnrecoverable(sizeListPacientUnrecoverable, listPacientUnrecoverable, aux); //funcion de agregar paciente a la lista de irrecuperables
	}
	writeFileUnrecoverable(filePacientUnrecoverable, *sizeListPacientUnrecoverable, listPacientUnrecoverable);
	filePacient.close();
	return;

}


void addPacientUnrecoverable(int* sizeListPacientUnrecoverable, pacient*& listPacientUnrecoverable, pacient aux) //esta funcion va a ir agregando los pacientes q recibe a la lista de pacientes irrecuperables
{
	if (sizeListPacientUnrecoverable == nullptr || listPacientUnrecoverable == nullptr)
		return;
	*sizeListPacientUnrecoverable = *sizeListPacientUnrecoverable + 1; //agrego un tamaño a la lista
	int i = 0;
	pacient* listAuxPU = new pacient[*sizeListPacientUnrecoverable];
	while (i < *sizeListPacientUnrecoverable - 1)
	{
		listAuxPU[i] = listPacientUnrecoverable[i];
		i++;
	}
	listAuxPU[i] = aux;
	delete[]listPacientUnrecoverable;
	listPacientUnrecoverable = listAuxPU;
	return;
}

void readAppointment(string nameFileAppointment, int *sizeListAppointment, appointment *& listAppointment)
{
	if (sizeListAppointment == nullptr || listAppointment == nullptr)
		return;
	fstream fileAppointment;
	fileAppointment.open(nameFileAppointment, ios::in);
	if (!(fileAppointment.is_open()))
		return;
	string dummy;
	fileAppointment >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy;
	appointment aux;
	while (fileAppointment) {
		fileAppointment >> aux.dniPacient >> dummy >> aux.dateRequest >> dummy >> aux.dateAppointment >> dummy >>
			aux.asistance >> dummy >> aux.idDoctor;
		addAppointment(sizeListAppointment, listAppointment, aux);
	}
	fileAppointment.close();
	return;

}

void addAppointment(int* sizeListAppointment, appointment *& listAppointment, appointment aux) //funcion de agregarr consulta a la lista de consultas
{
	if (sizeListAppointment == nullptr || listAppointment == nullptr)
		return;
	*sizeListAppointment = *sizeListAppointment + 1;
	int i = 0;
	appointment* listAuxA = new appointment[*sizeListAppointment];
	while (i < *sizeListAppointment + 1);
	{
		listAuxA[i] = listAppointment[i];
		i++;
	}
	listAuxA[i] = aux;
	delete[]listAppointment;
	listAppointment = listAuxA;
	return;
}


time_t lastAppointment(unsigned int dniAux, int sizeListAppointment, appointment* listAppointment, appointment* lastApp) //funcion q te devuelve la ultima fecha de consulta de un paciente recibido por dni
{
	time_t dateaux, lastDateT = 0;
	if (listAppointment == nullptr)
		return 0;
	string lastDateString;
	long int x = 0;
	bool first = false;

	for (int i = 0; i < sizeListAppointment; i++) {
		if (listAppointment[i].dniPacient == dniAux && !(first)) {
			lastDateString = listAppointment[i].dateAppointment;	//inicializo la ultima fecha en la primera q encuentre de ese paciente
			lastDateT = convertDate(lastDateString); //me paso la ultima fecha a time_t para comparar
			first = true;
			*lastApp= listAppointment[i];
		}
			 
		if (listAppointment[i].dniPacient == dniAux)
		{
			dateaux = convertDate(listAppointment[i].dateAppointment); //me paso la fecha a time_t para comparar
			x = difftime(dateaux, lastDateT); //comparo las dos fechas

			// prueba:    t2=2022, t1= 2003, difftime(t2,t1) = 599616000,  t2-t1.
			if (x > 0) //si x es positivo, dateaux fue despues que lastDateT
			{
				lastDateT = dateaux;
				*lastApp = listAppointment[i];
			}
		}
	}
	return lastDateT;
}


void writeFileUnrecoverable(string nameFileUnrecoverable, int sizeListPacientUnrecoverable, pacient* listPacientUnrecoverable)
{
	fstream fileUnrecoverable;
	fileUnrecoverable.open(nameFileUnrecoverable, ios::out);
	if (listPacientUnrecoverable == nullptr || !(fileUnrecoverable.is_open()))
		return;
	fileUnrecoverable << "NamePacient" << "," << "LastNamePacient" << "," << "DNI" << "," << "State" << endl;
	int i = 0;
	while (fileUnrecoverable)
	{
		fileUnrecoverable << listPacientUnrecoverable[i].namePacient << "," << listPacientUnrecoverable[i].lastNAmePacient
			<< "," << listPacientUnrecoverable[i].dni << "," << listPacientUnrecoverable[i].state << endl;
		i++;
	}
	fileUnrecoverable.close();
	delete[]listPacientUnrecoverable; //lo deleteo aca en vez de ene el main(seria lo mismo en teoria)
	return;
}
