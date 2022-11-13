#include "libreria.h"


//supongo que ya se creo una lista de pacientes con tamaño cero

void readPacients(string nameFilePacient, int* sizeListPacient, pacient *& listPacient) //leo todos los pacientes (menos los que fallecieron)
{
	fstream filePacient;
	filePacient.open(nameFile, ios::in);
	if (!(filePacient.is_open()))
		return;
	string dummy;
	string death1 = "fallecido", death2 = "Fallecido";

	dummy = getline(cin, filePacient); //leo la primera linea del csv (texto inutil), habria q ver si funciona xq me da miedo el getline

	pacient aux;
	while (filePacient) {
		filePacient >> aux.dni >> dummy >> aux.namePacient >> dummy >> aux.lastNAmePacient >> dummy
			>> aux.sex >> dummy >> aux.dateBirth >> dummy >> aux.state >> dummy >> aux.idInsurance;

		if (aux.state != death1 && aux.state != death2) //si no esta muerto lo paso a la funcion y lo agrego a la lista
			addPacient(sizeList, listPacient, aux);
	}
	filePacient.close;
	return;
}


void addPacient(int* sizeListPacient, pacient*& listPacient, pacient aux) //esta funcion va a ir agregando los pacientes q recibe a la lista de pacientes
{
	*sizeListPacient = *sizeListPacient + 1; //agrego un tamaño a la lista
	int i = 0;
	pacient* listAuxP = new pacient[*sizeListPacient];
	while (i < *sizeListPacient - 1)
	{
		listAux[i] = listPacient[i];
		i++;
	}
	delete[]listPacient;
	listPacient = listAuxP;
	return;
}


void readAppointment(string nameFileAppointment, int* sizeListAppointment, appointment *& listAppointment)
{
	*sizeListAppointment = *sizeListAppointment + 1;
	int i = 0;
	appointment* listAuxA = new appointment[*sizeListAppointment];
	while (i < *sizeListAppointment + 1);
	{
		listAuxA[i] = listAppointment[i];
		i++;
	}
	delete[]listAppointment;
	listAppointment = listAuxA;
	return;
}


time_t lastAppointment(unsigned int dniAux, int* sizeListAppointment, appointment*& listAppointment) //funcion q te devuelve la ultima fecha de consulta de un paciente recibido por dni
{
	time_t date;
	string lastDate;
	bool first = false;
	for (int i = 0; i < *sizeListAppointment; i++) {
		if (listAppointment[i].dniPacient == dniAux && !(first))
			lastDate = listAppointment[i].dateAppointment;

	}
	//todavia no la termine

}