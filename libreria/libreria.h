#include <string>
#include <ctime>
#include <iostream>
#include <stringstream>
#include <fstream>

using namespace std;


//STRUCTS:

typedef struct appointment {
	unsigned int dniPacient;
	string dateAppointment;
	string dateRequest;
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
	string dateBirth;
	string state; //muerto, internado, no se sabe
	string idInsurance;
}pacient;



//FUNCIONES:

time_t convertDate(string dato);
void readPacients(string nameFile, int* sizeListPacient, pacient*& listPatien);
void addPacient(int* sizeListPacient, pacient*& listPacient, pacient aux);
void readAppointment(string nameFileAppointment, int* sizeListAppointment, appointment*& listAppointment);
time_t lastAppointment(unsigned int dniAux, int* sizeListAppointment, appointment*& listAppointment);
