#include <string>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;


//STRUCTS:

typedef struct {
	unsigned int dniPacient;
	string dateAppointment;
	string dateRequest;
	bool asistance;
	string idDoctor;
} appointment;

typedef struct {
	unsigned int dniContact;
	string numberTelephone;
	string numberPhone;
	string adress;
	string mail;
} contact;

typedef struct {
	string doctorId;
	string nameDoctor;
	string lastNameDoctor;
	string specialty;
	string telephoneDoctor;
	bool active;
} doctor;

typedef struct {
	unsigned int idInsurance;
	string nameInsurance;
} insurance;

typedef struct {
	long unsigned int dni;
	string namePacient;
	string lastNAmePacient;
	char sex;
	string dateBirth;
	string state; //muerto, internado, no se sabe
	string idInsurance;
} pacient;

typedef struct  {
	string namePacientSecL;
	string lastNamePacientSecL;
	long unsigned int dniSecL;
	string medicalInsuranceSecL;
	string idDoctorSecL;
	string cellphoneNumberSecL;
	string answerSecL;
}secretaryList;



//FUNCIONES:
//AGOS
time_t convertDate(string dato);
void newFile(string SecretaryFileName, secretaryList*& listPacient, int size); //recibir un array de secretaria
void secretary(string SecretaryFileName, int sizeFile); 
//LOREN
void readPacient(string nameFilePacient, int* sizeListPacientUnrecoverable, pacient*& listPacientUnrecoverable, int sizeListAppointment, appointment* listAppointment, string nameFileContact, string filePacientUnrecoverable, int *sizeSec);
void addPacientUnrecoverable(int* sizeListPacientUnrecoverable, pacient*& listPacientUnrecoverable, pacient aux);
void readAppointment(string nameFileAppointment, int* sizeListAppointment, appointment*& listAppointment);
time_t lastAppointment(unsigned int dniAux, int sizeListAppointment, appointment* listAppointment, appointment* lastApp);
void addAppointment(int* sizeListAppointment, appointment*& listAppointment, appointment aux);
void writeFileUnrecoverable(string nameFileUnrecoverable, int sizeListPacientUnrecoverable, pacient* listPacientUnrecoverable);
//ALMA
bool findContact(string nameFileContacts, contact* aux, long unsigned int DNI);
secretaryList convertToSecretary(pacient aux, appointment* listAppointment, int sizeListAppointment, string nameFileContacts); //recibe un paciente y carga los datos 
																	//en un struct del tipo secretaria y busca el id-medico
																	//en el arch de consultas
//POCHI
int keepingUpWithThePacients(pacient aux, int sizeListAppointment, appointment *listAppointment);
bool insuranceList(string nameFilePacient, string** list, int*sizeList); //genera array de obras sociales
void generateApp(appointment*& list, int* size, long unsigned int DNI, int sizeListAppointment, appointment* listAppointment); //función que crea una consulta random y la agrega a un array de consultas para la secretaría
//AGOS FIJATE QUE CAMBIE LOS PARAMETROOOOOOOOOOS
void addSecetaryList(int* sizeList, secretaryList aux, secretaryList** listSec);




