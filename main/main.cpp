#include "iri.cpp"
#include <iostream>
#include "libreria.h"

int main() 
{

	string contactFile = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\input\\Contactos.csv";
	string appointmentFile = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\input\\Consultas.csv";
	string pacientFile = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\input\\Pacientes.csv";
	string filePacientUnrecoverable = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\output\\IRI_Irrecuperables.csv";
	string filePacientRecoverable = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\output\\IRI_Recuperables.csv";
	int appointmentSize=0;
	appointment* listAppointment = new appointment[appointmentSize];
	readAppointment(appointmentFile, &appointmentSize, listAppointment);
	int sizeSecretaryList=0;
	int unrecoverableSize = 0;
	secretaryList* listSec = new secretaryList[sizeSecretaryList];
	pacient* listPacientUnrecoverable = new pacient[unrecoverableSize];
	readPacient( pacientFile, &unrecoverableSize, listPacientUnrecoverable, appointmentSize, listAppointment, pacientFile, filePacientUnrecoverable, &sizeSecretaryList,listSec);
	newFile(filePacientRecoverable,listSec, sizeSecretaryList);
	secretary(filePacientRecoverable, sizeSecretaryList);



	delete[] listAppointment;
	listAppointment = NULL;
	delete[] listSec;
	listSec = NULL;
	delete[] listPacientUnrecoverable;
	listPacientUnrecoverable = NULL;
	//listo
	return 0;

}