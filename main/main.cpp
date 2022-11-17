#include "iri.cpp"
#include "libreria.h"
#include "pochi.cpp"
//#include "loren.cpp"

int main() {


	string appointmentFile = "IRI_Consultas.csv";
	int appointmentSize=0;
	appointment* listAppointment = new appointment[0];
	readAppointment(appointmentFile, &appointmentSize, listAppointment);

	int unrecoverableSize = 0;
	pacient* listPacientUnrecoverable = new pacient[0];
	string pacientFile = "IRI_Pacientes.csv";
	//readPacients( pacientFile, &unrecoverableSize, listPacientUnrecoverable, appointmentSize, listAppointment);

}