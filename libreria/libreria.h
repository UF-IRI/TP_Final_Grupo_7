#include <string>
#include <ctime>
#include <iostream>
#include <stringstream>
#include <fstream>

using namespace std;


//STRUCTS:

typedef struct appointment {
	unsigned int dniPacient;
	string dateSaolicited;
	string dateAppointment;
	bool asistance;
	string idDoctor;
} appointment;

typedef struct contact {
	unsigned int dni;
	string numberTelephone;
	string numberPhone;
	string adress;
	string mail;
} contact;

typedef struct doctor {
	string doctorId;
	string nameDoctor;
	string latNameDoctor;
	string specialty;
};

typedef struct insurance {
	unsigned int idInsurance;
	string nameInsurance;
} insurance;

typedef struct pacient {
	unsigned int dniPacient;
	string namePacient;
	string lastNAmePacient;
	string sex;
	string dateBirth;
	unsigned int idInsurance;
	string state;
}pacient;


//FUNCIONES:

time_t PasarAFecha(string dato);
void readPacients(string nameFile, int* sizeListPacient, pacient*& listPatien);
void addPacient(int* sizeListPacient, pacient*& listPacient, pacient aux);
void readAppointment(string nameFileAppointment, int* sizeListAppointment, pacient*& listAppointment);

