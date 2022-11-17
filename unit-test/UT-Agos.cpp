#include "libreria.h"
#include "gmock/gmock.h"
namespace funciones::tests
/*
time_t convertDate(string dato);
void newFile(string SecretaryFileName, secretaryList*& listPacient, int size); //recibir un array de secretaria
void secretary(string SecretaryFileName, int sizeFile);
void appointmentList(string AppointmentFileName, appointment*& list, int* appSize);
*/

TEST(convertDate, test1)
{
	string hoy = "18/11/22";
	time_t today = convertDate(hoy);
	//claro pero qsy quien es today sin mandarlo a la funcion pq el actual va a ser dif en segundos
	
}

TEST(newFile, test1)
{

}

TEST(secretary,test1) //aca va a haber que hacer varios
{

}

TEST(appointmentList, test1)
{
z
}