#include "iri.cpp"
#include <iostream>
#include "libreria.h"

int main() 
{

	string contactFile = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Contactos.csv";
	string appointmentFile = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Consultas.csv";
	string pacientFile = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Pacientes.csv";
	string filePacientUnrecoverable = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\output\\IRI_Irrecuperables.csv";
	string filePacientRecoverable = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\output\\IRI_Recuperables.csv";
	int appointmentSize=0;
	appointment* listAppointment = new appointment[appointmentSize];
	readAppointment(appointmentFile, &appointmentSize, listAppointment);
	int sizeSecretaryList=0;
	int unrecoverableSize = 0;
	pacient* listPacientUnrecoverable = new pacient[unrecoverableSize];
	readPacient( pacientFile, &unrecoverableSize, listPacientUnrecoverable, appointmentSize, listAppointment, pacientFile, filePacientUnrecoverable, &sizeSecretaryList);
	newFile(filePacientRecoverable, , sizeSecretaryList);
	secretary(filePacientRecoverable, sizeSecretaryList);

	/*
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