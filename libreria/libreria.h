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
	string lastNameDoctor;
	string specialty;
	string telephoneDoctor;
	bool active;
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
//AGOS
time_t convertDate(string dato);
void newFile(string SecretaryFileName, pacient*& listPacient, int size);
void secretary(string SecretaryFileName, string AppointmentFileName, string PacientFileName, string ContactsFileName);
//LOREN
void readPacients(string nameFilePacient, int* sizeListPacient, pacient*& listPacient);
void addPacient(int* sizeListPacient, pacient*& listPacient, pacient aux);
void readAppointment(string nameFileAppointment, int* sizeListAppointment, appointment*& listAppointment);
time_t lastAppointment(unsigned int dniAux, int sizeListAppointment, appointment* listAppointment, bool *went);
void addAppointment(int* sizeListAppointment, appointment*& listAppointment, appointment aux);
//ALMA
void findContact(string nameFileContacts, contact* aux, long unsigned int DNI);
//POCHI
bool keepingUpWithThePacients(pacient aux);