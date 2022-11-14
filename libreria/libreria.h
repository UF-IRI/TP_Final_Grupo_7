#include <string>
#include <ctime>
#include <iostream>
#include <stringstream>
#include <fstream>

using namespace std;


//STRUCTS:

typedef struct appointment {
	unsigned int dniPacient;
	time_t dateAppointment;
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
	long unsigned int dni;
	string namePacient;
	string lastNAmePacient;
	char sex;
	time_t dateBirth;
	string state; //muerto, internado, no se sabe
	string idInsurance;
}pacient;


typedef struct general {

	long unsigned int dni;

};


//FUNCIONES:

time_t pasarAFecha(string dato);
void readPacients(string nameFile, int* sizeListPacient, pacient*& listPatien);
void addPacient(int* sizeListPacient, pacient*& listPacient, pacient aux);
void readAppointment(string nameFileAppointment, int* sizeListAppointment, appointment*& listAppointment);
time_t lastAppointment(unsigned int dniAux, int* sizeListAppointment, appointment*& listAppointment);
