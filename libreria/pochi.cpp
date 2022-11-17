
#include "libreria.h"

int keepingUpWithThePacients(pacient aux, int sizeListAppointment, appointment* listAppointment) 
{
	int category = -1;
	appointment app;
	bool went;
	if (aux.state != "internado" && aux.state != "Internado" && aux.state != "fallecido" && aux.state != "Fallecido")
	{
		time_t current = time(0);
		time_t lastAp = lastAppointment(aux.dni, sizeListAppointment, listAppointment, &app);
		went = app.asistance;
		double timeSinceLastApp = difftime(current, lastAp);
		if (timeSinceLastApp < 315576000)//menos de 10 años en segundos
		{
			if (timeSinceLastApp > 0) // ya pasó
			{
				if (went)
					category = 3; //hace menos de 10 años, ya pasó su fecha y vino --> no me importa
				else
					category = 1;// hace menos de 10 años, ya pasó la fecha de la consulta y no vino --> recuperable
			}
			else
				category = 3; // hace menos de 10 años pero la consulta está programada para el futuro
		}
		else //hace más de 10 anos
		{
			if (!went)
				category = 2;// hace más de 10 años y no vino --> irrecuperable
			else
				category = 3;// hace más de 10 años pero vino --> no me importa
		}
	}
	else
	{
		if (aux.state == "internado" || aux.state == "Internado")
			category = 3; //está internado--> ya conozco su estado --> no me importa
		else //está muerto
			if (aux.state == "fallecido" || aux.state == "Fallecido")
			{
				category = 2; //muerto --> irrecuperable
			}
			else
				category = 3; //no conozco su estado --> no me importa
	}
	return category;
	
}

bool insuranceList(string nameFilePacient, string** list, int* sizeList) //genera array de obras sociales
{
	fstream filePacient;
	filePacient.open(nameFilePacient, ios::in);
	if (sizeList == nullptr || list == nullptr || *list == nullptr || !(filePacient.is_open()))
		return false;

	//para leer
	string dummy;
	char coma;
	pacient aux;
	filePacient >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; // leo la primera linea --> encabezados
	bool alreadythere;
	int i;

	string* newList = new string[*sizeList + 1];

	while (filePacient)
	{
		filePacient >> aux.dni >> coma >> aux.namePacient >> coma >> aux.lastNAmePacient >> coma >> aux.sex >> coma >> aux.dateBirth >> coma >> aux.state >> coma >> aux.idInsurance;
		alreadythere = false;
		for ( i = 0; i < *sizeList; i++)
		{
			if (*list[i] == aux.idInsurance) //ya lo tenía en la lista --> no lo agrego
			{
				break;//para no seguir comparando si ya lo encontré
			}
		}
		if (i==*sizeList) //significa que nunca hizo el break --> no lo encontró
		{
			
			newList[*sizeList] = aux.idInsurance;
		}
	}
	filePacient.close();
	*sizeList=*sizeList+1;
	delete* list;
	*list = newList;
	return true;
}


void addSecetaryList(int* sizeList, secretaryList aux, secretaryList** listSec)
{
	if (sizeList == nullptr || listSec == nullptr || *listSec == nullptr)
		return;
	
	secretaryList* newList = new secretaryList[*sizeList + 1];

	int i;
	for (i = 0; i < *sizeList; i++)
	{
		newList[i] = *listSec[i];
	}
	newList[i] = aux;

	delete[] * listSec;
	*listSec = newList;
	*sizeList = *sizeList + 1;
	return;

}

void generateApp(appointment*& list, int* size, long unsigned int DNI, int sizeListAppointment, appointment* listAppointment)
{
	srand(time(NULL));
	//HOY EN TRES VARIABLES
	time_t current = time(NULL);
	tm *today;
	today = localtime(&current);
	string dateReq = to_string(today->tm_mon) + "/" + to_string(today->tm_mday) + "/" + to_string(today->tm_mon);
	//FECHA CONSULTA EN TRES VARIABLES
	tm dateNewApp;
	time_t compareNewApp;//la voy a usar para comparar con la fecha actual y asegurarme de que el día que me genera no haya pasado
	string finalDate;

	bool again;

	do
	{
		again = false;
		//genero un año (este año o el año que viene)
		dateNewApp.tm_year = rand() % 3+today->tm_year-1900 ;  //le resto 1900 para convertirlo a time_t, después los vuelvo a sumar
		dateNewApp.tm_mon = rand() % 12; //lo haría +1 pero para pasarlo a time_t le tengo que restar uno entonces no hago nada
		if (dateNewApp.tm_mon == 2)
		{
			dateNewApp.tm_mday = rand() % 28+1;
		}
		else
			if (dateNewApp.tm_mon == 4 || dateNewApp.tm_mon == 6 || dateNewApp.tm_mon == 9 || dateNewApp.tm_mon == 11)
			{
				dateNewApp.tm_mday = rand() % 30+1;
			}
			else
				dateNewApp.tm_mday = rand() % 31+1;
		// me aseguro que todavía no haya pasado la fecha
		compareNewApp = mktime(&dateNewApp);
		long int fromNow = difftime(compareNewApp, current);
		
		if (fromNow <= 0) //la fecha ya pasó
			again = true;
		else
		{
		//vuelvo a acomodar la fecha en tm para pasarla a string 
			dateNewApp.tm_year = dateNewApp.tm_year + 1900;
			dateNewApp.tm_mon = dateNewApp.tm_mon + 1;
			int cont = 0;
			 		
			finalDate = to_string(dateNewApp.tm_mon) + "/" + to_string(dateNewApp.tm_mday) + "/" + to_string(dateNewApp.tm_year);//las uno y las convierto en un string
			appointment* newList = new appointment[*size + 1];
			int i;
			for (i = 0; i < *size; i++)
			{
				newList[i] = list[i];
			}
			for (int i = 0; i < *size; i++)
			{
				if (list[i].dateAppointment == finalDate)
				{
					cont++;
				}
			}
			if (cont <= 200)//mi hospital tiene un max de 200 consultas al dia porque lo decido yo porque no encuentro estadisticas del promedio de pacientes al dia en un hospital y son las 12 de la noche y mañana rindo
				again = true;

		}
		

	} while (again);
		//ahora ya tengo una fecha que es 1)futura, 2)no está en un mismo dia con mas de 200 consultas

	//BUSCO EL MÉDICO DE LA ÚLTIMA CONSULTA (ASUMO QUE QUIERE REPROGRAMAR UNA CONSULTA PARA LO MISMO QUE LA ÚLRIMA --> MISMO MÉDICO) --> SI EL MÉDICO NO ESTÁ ACTIVO QUE REVIVA <3
	appointment appDr;
	time_t dummy = lastAppointment(DNI, sizeListAppointment, listAppointment, &appDr);


	// me creo una variable para esta appointment en particular
	appointment newApp;
	newApp.asistance = false;//porque todavía no fue
	newApp.dateAppointment = finalDate;
	newApp.dateRequest = dateReq;
	newApp.dniPacient = DNI;
	newApp.idDoctor = appDr.idDoctor;
	
	appointment* newList = new appointment[*size + 1];
	int i;
	for (i = 0; i < *size; i++)
	{
		newList[i] = list[i];
	}
	newList[i] = newApp;
	delete list;
	list = newList;

	*size = *size + 1;
	return;
}





