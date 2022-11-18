#include "iri.cpp"
#include "libreria.h"
#include "pochi.cpp"
#include "loren.cpp"
#include "agos.cpp"
#include "almi.cpp"

int main() {

	string contactFile = "IRI_Contactos.csv";
	string appointmentFile = "IRI_Consultas.csv";
	string pacientFile = "IRI_Pacientes.csv";
	string filePacientUnrecoverable = "IRI_Irrecuperables.csv";
	string filePacientRecoverable = "IRI_Recuperables.csv";
	int appointmentSize=0;
	appointment* listAppointment = new appointment[appointmentSize];
	readAppointment(appointmentFile, &appointmentSize, listAppointment);
	
	int unrecoverableSize = 0;
	pacient* listPacientUnrecoverable = new pacient[unrecoverableSize];
	readPacients( pacientFile, &unrecoverableSize, listPacientUnrecoverable, appointmentSize, listAppointment, pacientFile);
	
	/*
	me creo lista de app
	leo el archivo de app y las guardo en una lista
	llamo a la funcion read pacients:
		leo el archivo de pacientes
			llamo a una funcion para ver si es recuperable o irrecuperable
				-irrecuperable: arma lista pacientunrecoverable
				-recuperable: arma lista de tipo secretaria 
			
	*/

}