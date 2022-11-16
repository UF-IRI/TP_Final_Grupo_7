
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


