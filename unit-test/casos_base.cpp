#include "gmock/gmock.h"
#include "libreria.h"

//void findContact(string nameFileContacts, contact* aux, long unsigned int DNI);
//int keepingUpWithThePacients(pacient aux, int sizeListAppointment, appointment *listAppointment);
//bool insuranceList(string nameFilePacient, string** list, int*sizeList); //genera array de obras sociales
//void newFile(string SecretaryFileName, secretaryList*& listPacient, int size); //recibir un array de secretaria
//void secretary(string SecretaryFileName, int sizeFile); 


namespace Casos_Base::tests {
	TEST(findContact, caso1) {
		//LINEA 151 ARCHIVO CONTACTOS: 333091407,+62 716 586 7774,+47 251 120 0090,Almo,kwebling45@ihg.com
		string contactFile = "IRI_Contactos.csv";
		long unsigned int dni = 333091407;
		contact aux1;
		aux1.dniContact = 333091407;
		aux1.adress = "Almo";
		aux1.mail = "kwebling45@ihg.com";
		aux1.numberTelephone = "+62 716 586 7774";
		aux1.numberPhone = "+47 251 120 0090";
		contact aux2;
		findContact(contactFile, &aux2, dni);
		ASSERT_THAT(aux2.adress, aux1.adress);
		ASSERT_THAT(aux2.dniContact, aux1.dniContact);
		ASSERT_THAT(aux2.mail, aux1.mail);
		ASSERT_THAT(aux2.numberPhone, aux1.numberPhone);
		ASSERT_THAT(aux2.numberTelephone, aux1.numberTelephone);
	}
	/*
	TEST(Casos_Base, Test_Caso2) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso3) {
		ASSERT_THAT(1, 1);
	}
	*/
	
}