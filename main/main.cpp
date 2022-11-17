#include "iri.cpp"
#include "libreria.h"
#include "pochi.cpp"
#include "loren.cpp"
#include "agos.cpp"
#include "almi.cpp"

int main() {

	string contactFile = "IRI_Contactos.csv";
	string appointmentFile = "IRI_Consultas.csv";
	int appointmentSize=0;
	appointment* listAppointment = new appointment[appointmentSize];
	readAppointment(appointmentFile, &appointmentSize, listAppointment);

	int unrecoverableSize = 0;
	pacient* listPacientUnrecoverable = new pacient[unrecoverableSize];
	string pacientFile = "IRI_Pacientes.csv";
	//readPacients( pacientFile, &unrecoverableSize, listPacientUnrecoverable, appointmentSize, listAppointment);

}