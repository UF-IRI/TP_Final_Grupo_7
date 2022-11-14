
#include "libreria.h"

bool keepingUpWithThePacients(pacient aux, int sizeListAppointment, appointment* listAppointment) //DEVUELVO TRUE SOLO SI NO ESTÁ INTERNADO NI MUERTO, SU ULTIMA CONSULTA FUE HACE MENOS DE 10 AOS Y NO ASISTIÓ
{
	bool stays=false;
	bool went;
	if (aux.state != "internado" && state != "Internado" && state != "muerto" != "Muerto")
	{
		time_t current = time(0);
		time_t lastAp = lastAppointment(aux.dni, sizeListAppointment, listAppointment, &went);
		double timeSinceLastApp = difftime(current, lastAp);
		if (timeSinceLastApp < 315576000 && timeSinceLastApp>0 && !went)//10 años en segundos
		{
			stays = true;
		}
	}

	return stays;
}





