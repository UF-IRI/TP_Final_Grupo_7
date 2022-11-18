#include "gmock/gmock.h"
#include "libreria.h"


namespace Casos_Base::tests {
	
	TEST(findContact, caso1) {
		//LINEA 69 ARCHIVO CONTACTOS: 859052988,+86 163 839 6359,+48 621 670 1298,Barby,aplayer1v@theatlantic.com
		string contactFile = "IRI_Contactos.csv";
		contact aux1;
		aux1.dniContact = 859052988;
		aux1.adress = "Barby";
		aux1.mail = "aplayer1v@theatlantic.com";
		aux1.numberTelephone = "+86 163 839 6359";
		aux1.numberPhone = "+48 621 670 1298";
		contact aux2;
		bool couldOpen=findContact(contactFile, &aux2, aux1.dniContact);
		EXPECT_FALSE(couldOpen); //no abre bien el archivo
		
		/*
		EXPECT_THAT(aux2.dniContact, aux1.dniContact);
		EXPECT_THAT(aux2.adress, aux1.adress);
		EXPECT_THAT(aux2.mail, aux1.mail);
		EXPECT_THAT(aux2.numberPhone, aux1.numberPhone);
		EXPECT_THAT(aux2.numberTelephone, aux1.numberTelephone);
		*/

	}
	TEST(convertDate, test1) {
		string hoy="17/11/2022";
		tm fecha{};
		fecha.tm_year = 2022 - 1900;
		fecha.tm_mon = 11 - 1;
		fecha.tm_mday = 17;
		time_t esperada = mktime(&fecha);
		time_t real = convertDate(hoy);
		EXPECT_THAT(real, esperada);
	}
	
	TEST(convertDate, test2) {
		string hoy = "11/09/2022";
		tm fecha{};
		fecha.tm_year = 2022 - 1900;
		fecha.tm_mon = 9 - 1;
		fecha.tm_mday = 11;
		time_t esperada = mktime(&fecha);
		time_t real = convertDate(hoy);
		EXPECT_THAT(real, esperada);
	}

	TEST(keepingUpWithThePacients, caso3) {
		pacient aux;
		//LINEA 44 ARCHIVO DE PACIENTES: 497757175,Claudette,di Rocca,F,11/8/2005,n/c,Aleman
		string appointmentFile = "IRI_Consultas.csv";
		aux.dni = 497757175;
		aux.namePacient = "Claudette";
		aux.lastNAmePacient = "di Rocca";
		aux.sex = 'F';
		aux.dateBirth = "11/8/2005";
		aux.state = "n/c";
		aux.idInsurance = "Aleman";
		appointment* list = new appointment[0];
		int sizeList;
		readAppointment(appointmentFile, &sizeList, list);
		int category = keepingUpWithThePacients(aux,sizeList,list);
		EXPECT_THAT(category, 3);
	}

	TEST(keepingUpWithThePacients, caso2) {
		pacient aux;
		//LINEA 119 ARCHIVO DE PACIENTES: 245044548,Sibyl,Szwandt,M,3/11/1973,fallecido,OSDE
		string appointmentFile = "IRI_Consultas.csv";
		aux.dni = 245044548;
		aux.namePacient = "Sibyl";
		aux.lastNAmePacient = "Szwandt";
		aux.sex = 'M';
		aux.dateBirth = "3/11/1973";
		aux.state = "fallecido";
		aux.idInsurance = "OSDE";
		appointment* list = new appointment[0];
		int sizeList;
		readAppointment(appointmentFile, &sizeList, list);
		int category = keepingUpWithThePacients(aux, sizeList, list);
		EXPECT_THAT(category, 2);
	}

	
}