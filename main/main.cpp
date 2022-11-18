#include "iri.cpp"
#include <iostream>
#include "libreria.h"

int main() 
{

	string contactFile = "IRI_Contactos.csv";
	string appointmentFile = "IRI_Consultas.csv";
	string pacientFile = "IRI_Pacientes.csv";
	string filePacientUnrecoverable = "IRI_Irrecuperables.csv";
	string filePacientRecoverable = "IRI_Recuperables.csv";
	int appointmentSize=0;
	appointment* listAppointment = new appointment[appointmentSize];
	readAppointment(appointmentFile, &appointmentSize, listAppointment);
/*	int sizeSecretaryList;
	int unrecoverableSize = 0;
	pacient* listPacientUnrecoverable = new pacient[unrecoverableSize];
	readPacient( pacientFile, &unrecoverableSize, listPacientUnrecoverable, appointmentSize, listAppointment, pacientFile, filePacientUnrecoverable, &sizeSecretaryList);
	secretary(filePacientRecoverable, sizeSecretaryList);


	me creo lista de app
	leo el archivo de app y las guardo en una lista
	llamo a la funcion read pacients:
		leo el archivo de pacientes
			llamo a una funcion para ver si es recuperable o irrecuperable
				-irrecuperable: arma lista pacientunrecoverable--> y me escribe el file 
				-recuperable: arma lista de tipo secretaria  --> la guarda en un archivo
	llemo a secretaria y le paso: 
			
	*/

}