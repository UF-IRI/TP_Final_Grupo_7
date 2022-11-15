#include "libreria.h"


//supongo que ya se creo una lista de pacientes con tamaño cero

void readPacients(string nameFilePacient, int* sizeListPacient, pacient *& listPacient) //leo todos los pacientes (menos los que fallecieron)
{
	if (sizeListPacient == nullptr || listPacient == nullptr)
		return;
	fstream filePacient;
	filePacient.open(nameFilePacient, ios::in);
	if (!(filePacient.is_open()))
		return;
	string dummy;
	bool keep;

	dummy = getline(cin, filePacient); //leo la primera linea del csv (texto inutil), habria q ver si funciona xq me da miedo el getline
	pacient aux;

	while (filePacient) {
		keep = false;
		filePacient >> aux.dni >> dummy >> aux.namePacient >> dummy >> aux.lastNAmePacient >> dummy
			>> aux.sex >> dummy >> aux.dateBirth >> dummy >> aux.state >> dummy >> aux.idInsurance;
		keep = keepingUpWithThePacients(aux); //función que se fija si el paciente es recuperable --> ultima consulta hace menos de 10 años
		if (keep) //si me devuelve un true es xq se lo tengo q pasar a la secretaría, si me devuelve un false es irrecuperable
			addPacient(sizeListPacient, listPacient, aux);//funcion de agregar paciente a lista de posibles recuperables
		else
			//funcion de agregar paciente a lista de irrecuperable
	}
	filePacient.close;
	return;
}


void addPacient(int* sizeListPacient, pacient*& listPacient, pacient aux) //esta funcion va a ir agregando los pacientes q recibe a la lista de pacientes
{
	if (sizeListPacient == nullptr || listPacient == nullptr)
		return;
	*sizeListPacient = *sizeListPacient + 1; //agrego un tamaño a la lista
	int i = 0;
	pacient* listAuxP = new pacient[*sizeListPacient];
	while (i < *sizeListPacient - 1)
	{
		listAux[i] = listPacient[i];
		i++;
	}
	listAux[i] = aux;
	delete[]listPacient;
	listPacient = listAuxP;
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
	appointment aux;
	while (fileAppointment) {
		fileAppointment >> aux.dniPacient >> dummy >> aux.dateRequest >> dummy >> aux.dateAppointment >> dummy >>
			aux.asistance >> dummy >> aux.idDoctor;
		addAppointment()
	}
	fileAppointment.close;
	return

}

void addAppointment(int* sizeListAppointment, appointment *& listAppointment, appointment aux) //ver
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


time_t lastAppointment(unsigned int dniAux, int sizeListAppointment, appointment* listAppointment, bool	*went) //funcion q te devuelve la ultima fecha de consulta de un paciente recibido por dni
{
	time_t dateaux, lastDateT;
	if (listAppointment == nullptr)
		return 0;
	string lastDateString;
	long int x = 0;
	bool first = false;

	for (int i = 0; i < *sizeListAppointment; i++) {
		if (listAppointment[i].dniPacient == dniAux && !(first)) {
			lastDateString = listAppointment[i].dateAppointment;	//inicializo la ultima fecha en la primera q encuentre de ese paciente
			lastDateT = convertDate(lastDateString); //me paso la ultima fecha a time_t para comparar
			first = true;
			*went = listAppointment[i].asistance;
		}
			 
		if (listAppointment[i].dniPacient == dniAux)
		{
			dateaux = convertDate(listAppointment[i].dateAppointment); //me paso la fecha a time_t para comparar
			x = difftime(dateaux, lastDateT); //comparo las dos fechas

			// prueba:    t2=2022, t1= 2003, difftime(t2,t1) = 599616000,  t2-t1.
			if (x > 0) //si x es positivo, dateaux fue despues que lastDateT
			{
				lastDateT = dateaux;
				*went = listAppointment[i].asistance;
			}
		}
		else
			latDateT = 0;
	}
	return lastDateT;

}

