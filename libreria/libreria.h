#include <string>
#include <ctime>
#include <iostream>
#include <stringstream>

using namespace std;


//STRUCTS:

typedef struct fecha {
	int day, month, year;
} fecha;

typedef struct appointment {
	unsigned int dniPacient;
	fecha dateAppointment;
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
	unsigned int dni;
	string namePacient;
	string lastNAmePacient;
	string sex;
	fecha dateBirth;
	unsigned int idInsurance;
}pacient;


//FUNCIONES:

time_t PasarAFecha(string dato);