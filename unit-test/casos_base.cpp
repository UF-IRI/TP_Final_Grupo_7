#include "gmock/gmock.h"
#include "libreria.h"

//void findContact(string nameFileContacts, contact* aux, long unsigned int DNI);
//int keepingUpWithThePacients(pacient aux, int sizeListAppointment, appointment *listAppointment);
//bool insuranceList(string nameFilePacient, string** list, int*sizeList); //genera array de obras sociales
//void newFile(string SecretaryFileName, secretaryList*& listPacient, int size); //recibir un array de secretaria
//void secretary(string SecretaryFileName, int sizeFile); 


namespace Casos_Base::tests {
	TEST(findContact, caso1) {
		//LINEA 69 ARCHIVO CONTACTOS: 859052988,+86 163 839 6359,+48 621 670 1298,Barby,aplayer1v@theatlantic.com
		string contactFile = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Contactos.csv";
		contact aux1;
		aux1.dniContact = 859052988;
		aux1.adress = "Barby";
		aux1.mail = "aplayer1v@theatlantic.com";
		aux1.numberTelephone = "+86 163 839 6359";
		aux1.numberPhone = "+48 621 670 1298";
		contact aux2;
		bool aver=findContact(contactFile, &aux2, aux1.dniContact);
		EXPECT_FALSE(aver);
		EXPECT_THAT(aux2.dniContact, aux1.dniContact);
		EXPECT_THAT(aux2.adress, aux1.adress);
		EXPECT_THAT(aux2.mail, aux1.mail);
		EXPECT_THAT(aux2.numberPhone, aux1.numberPhone);
		EXPECT_THAT(aux2.numberTelephone, aux1.numberTelephone);
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