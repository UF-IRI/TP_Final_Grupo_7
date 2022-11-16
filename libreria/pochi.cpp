
#include "libreria.h"

int keepingUpWithThePacients(pacient aux, int sizeListAppointment, appointment* listAppointment) 
{
	int category=-1;
	appointment app;
	bool went;
	if (aux.state != "internado" && aux.state != "Internado" && aux.state != "fallecido" && aux.state != "Fallecido")
	{
		time_t current = time(0);
		time_t lastAp = lastAppointment(aux.dni, sizeListAppointment, listAppointment, &app);
		went = app.asistance;
		double timeSinceLastApp = difftime(current, lastAp);
		if (timeSinceLastApp < 315576000)//menos de 10 a�os en segundos
		{
			if (timeSinceLastApp > 0) // ya pas�
			{
				if (went)
					category = 3; //hace menos de 10 a�os, ya pas� su fecha y vino --> no me importa
				else
					category = 1;// hace menos de 10 a�os, ya pas� la fecha de la consulta y no vino --> recuperable
			}
			else
				category = 3; // hace menos de 10 a�os pero la consulta est� programada para el futuro
		}
		else //hace m�s de 10 anos
		{
			if (!went)
				category = 2;// hace m�s de 10 a�os y no vino --> irrecuperable
			else
				category = 3;// hace m�s de 10 a�os pero vino --> no me importa
		}
	}
	else
	{
		if (aux.state == "internado" || aux.state == "Internado")
			category = 3; //est� internado--> ya conozco su estado --> no me importa
		else //est� muerto
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

	

	while (filePacient)
	{
		filePacient >> aux.dni >> coma >> aux.namePacient >> coma >> aux.lastNAmePacient >> coma >> aux.sex >> coma >> aux.dateBirth >> coma >> aux.state >> coma >> aux.idInsurance;
		alreadythere = false;
		for (int i = 0; i < *sizelist; i++)
		{
			if (**list[i] == aux.idInsurance) //ya lo ten�a en la lista --> no lo agrego
			{
				break;//para no seguir comparando si ya lo encontr�
			}
		}
		if (i==*sizeList) //significa que nunca hizo el break --> no lo encontr�
		{
			string* newList = new string[*sizeList + 1];
			newList[*sizeList] = aux.idInsurance; //redimensiono el array para agregar las obras sociales distintas
		}
	}
	filePacient.close;
	*sizeList=*sizeList+1;
	delete* list;
	*list = newList;
	return true;
}
