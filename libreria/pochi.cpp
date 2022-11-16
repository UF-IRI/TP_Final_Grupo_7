
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


