//PROBANDO

#include "libreria.h"

time_t convertDate(string dato)
{
	int i = 0;
	int day, month, year;
	int cont = 0;
	string auxD, auxM, auxY;

	while (dato[i] != '\0')
	{
		int k = 0;
		while (dato[i] != '/')
		{

			switch (cont)
			{
			case 0:
			{
				auxD[k] = dato[i];
				break;
			}
			case 1:
			{
				auxM[k] = dato[i];
				break;
			}
			case 2:
			{
				auxY[k] = dato[i];
				break;
			}
			}
			k++;
			i++;

		}
		cont++;
		i++;
	}
	day = stoi(auxD);
	month = stoi(auxM);
	year = stoi(auxY);

	tm date{};
	date.tm_year = year-1900;
	date.tm_mon = month-1;
	date.tm_mday = day;

	time_t finalDate = mktime(&date);

	return finalDate;
}

//nombre apellido telefono id-medico obrasocial estado
void newFile(string SecretaryFileName, secretaryList*& listPacient, int size)
{
	fstream fp;

	fp.open(SecretaryFileName, ios::out);
	if (!(fp.is_open()))
		return;

	fp << "DNI, Nombre, Apellido, Telefono, ObraSocial, ID-Medico, Estado" << endl;
	for (int i = 0; i < size; i++)
	{
		fp << listPacient[i].dni << " , " << listPacient[i].namePacient << " , " << listPacient[i].lastNamePacient << " , " << listPacient[i].cellphoneNumber<<" , "<<listPacient[i].medicalInsurance<<" , "<<listPacient[i].answer<< endl;
	}
	fp.close();
}



void secretary(string SecretaryFileName, int sizeFile) //falta lo de escribir una nuesva consulta en el array de consultas
{
	srand(NULL);
	int comeBack, change, answered, idInsurance;
	fstream fp;

	fp.open(SecretaryFileName, ios::in); //abro archivo de la secretaria para leer
	if (!(fp.is_open()))
		return;

	char comma = 0;
	string dummy;

	secretaryList* finalList = new secretaryList[sizeFile]; //nueva lista con el tamanio de la que me pasan en el archivo

	fp >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy; //leo el encabezado

	int i = 0;
	while (fp)//cargo la lista con los datos
	{
		fp >> finalList[i].dni >> comma >> finalList[i].namePacient >> comma >> finalList[i].lastNamePacient >> comma >> finalList[i].cellphoneNumber >> comma >> finalList[i].medicalInsurance >> comma >> finalList[i].idDoctor >> comma >> finalList[i].answer; //leo los datos en el array
		i++;
	}

	fp.close();

	//QUEDA CON EL PATH DE MI COMPU??
	string pacientFile = "C:\\Users\\agosn\\source\\repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Pacientes.csv";
	string contactFile = "C:\\Users\\agosn\\source\\repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Consultas.csv";
	string appointmentFile = "C:\\Users\\agosn\\Source\\Repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Consultas.csv";
	
	contact contactPacient;
	int insuranceListSize=0;
	string* insuranceList=new string[0];//en la funcion se le asigna una nueva direccion
	appointment* appNewList = new appointment[0];
	appointment* appList = new appointment[0];
	int appointmentNewListSize = 0;
	int appSize = 0;
	bool medicalInsuranceArray = (pacientFile, &insuranceList, &insuranceListSize);
	appointmentList(appointmentFile, appList, &appSize);

	int a = 0;
	for (int k = 0; k < sizeFile; k++)
	{
		findContact(contactFile, &contactPacient, finalList[k].dni);
		if (&contactPacient != nullptr) //hago todo siempre y cuando lo haya encontrado
		{
			for (a = 0; a < 10; a++) //llamo como maximo 10 veces cada paciente
			{
				answered = rand() % 2; //0: no contesto, 1: contesto
				if (answered == 1)
				{
					comeBack = rand() % 2;//0: no quiere volver, 1: quiere volver
					if (comeBack == 1)
					{
						generateApp(&appNewList,&appointmentNewListSize,finalList[k].dni,appSize, appList);
						finalList[k].answer = "El paciente ha programado una nueva consulta";

						change = rand() % 3;//0: no quiere cambiar ningun dato 1:cambio su obra social 
						
						if (change == 1)
						{
							if (medicalInsuranceArray)
							{
								string aux=finalList[k].medicalInsurance; //para que no sea la misma q tenia antes
								do
								{
									idInsurance = rand() % insuranceListSize;
									finalList[k].medicalInsurance = insuranceList[idInsurance];

								} while (aux == insuranceList[idInsurance]);
							}
						}

					}
					else //no quiere volver
					{
						finalList[k].answer = "El paciente no desea volver";
					}
					break;
				}
			}
			if (a == 10) //si recorri el for entero entonces no contesto
				finalList[k].answer = "El paciente no pudo ser contactado";
		}
	}

	fp.open(SecretaryFileName, ios::out); //abro archivo de la secretaria para sobreescribir
	if (!(fp.is_open()))
		return;

	fp << "DNI, Nombre, Apellido, Telefono, ObraSocial, ID-Medico, Estado" << endl;
	for (int i = 0; i < sizeFile; i++)
	{
		fp << finalList[i].dni << " , " << finalList[i].namePacient << " , " << finalList[i].lastNamePacient << " , " << finalList[i].cellphoneNumber << " , " << finalList[i].medicalInsurance << " , " << finalList[i].answer << endl;
	}
	fp.close();

	fp.open(appointmentFile, ios::app); //agrego las nuevas consultas al archivo original
	if (!(fp.is_open()))
		return;
	for (int j = 0; j < appointmentNewListSize; j++)
	{
		fp << appNewList[j].dniPacient << " , " << appNewList[j].dateRequest << " , " << appNewList[j].dateAppointment << " , " << appNewList[j].asistance << " , " << appNewList[j].idDoctor << endl;
	}
	fp.close();

	delete[] finalList;
	finalList = NULL;
	delete[] insuranceList;
	insuranceList = NULL;
	delete[] appNewList;
	appNewList = NULL;
	delete[] appList;
	appList = NULL;
	
}

void appointmentList(string AppointmentFileName, appointment*& list, int* appSize)
{
	//genero una lista en memoria dinamica con todas las consultas que hay y me guardo el tamanio 
	fstream fp;
	fp.open(AppointmentFileName, ios::in);
	if (!(fp.is_open()))
		return;

	string dummy;
	char comma;

	fp >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy; //encabezado
	
	int i = 0;
	while (fp)
	{
		fp >> list[i].dniPacient >> comma >> list[i].dateRequest >> comma >> list[i].dateAppointment >> comma >> list[i].asistance >> comma >> list[i].idDoctor;
		i++;
	}

	*appSize = i;
	fp.close();

}
