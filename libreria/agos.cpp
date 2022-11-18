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
		fp << listPacient[i].dniSecL << " , " << listPacient[i].namePacientSecL << " , " << listPacient[i].lastNamePacientSecL<< " , " << listPacient[i].cellphoneNumberSecL<<" , "<<listPacient[i].medicalInsuranceSecL<< " , "<<listPacient[i].idDoctorSecL<<" , " << listPacient[i].answerSecL << endl;
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
		fp >> finalList[i].dniSecL >> comma >> finalList[i].namePacientSecL >> comma >> finalList[i].lastNamePacientSecL >> comma >> finalList[i].cellphoneNumberSecL >> comma >> finalList[i].medicalInsuranceSecL >> comma >> finalList[i].idDoctorSecL >> comma >> finalList[i].answerSecL; //leo los datos en el array
		i++;
	}

	fp.close();

	//QUEDA CON EL PATH DE MI COMPU??
	string pacientFile = "Pacientes.csv";
	string contactFile = "Contactos.csv";
	string appointmentFile = "Consultas.csv";
	
	contact contactPacient;
	int insuranceListSize=0;
	string* insuranceList=new string[0];//en la funcion se le asigna una nueva direccion
	appointment* appNewList = new appointment[0];
	appointment* appList = new appointment[0];
	int appointmentNewListSize = 0;
	int appSize = 0;
	bool medicalInsuranceArray = (pacientFile, &insuranceList, &insuranceListSize);
	readAppointment(appointmentFile, &appSize, appList);

	int a = 0;
	for (int k = 0; k < sizeFile; k++)
	{
		findContact(contactFile, &contactPacient, finalList[k].dniSecL);
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
						generateApp(appNewList,&appointmentNewListSize,finalList[k].dniSecL,appSize, appList); 
						finalList[k].answerSecL = "El paciente ha programado una nueva consulta";

						change = rand() % 2;//0: no quiere cambiar ningun dato 1:cambio su obra social 
						
						if (change == 1)
						{
							if (medicalInsuranceArray)
							{
								string aux=finalList[k].medicalInsuranceSecL; //para que no sea la misma q tenia antes
								do
								{
									idInsurance = rand() % insuranceListSize;
									finalList[k].medicalInsuranceSecL = insuranceList[idInsurance];

								} while (aux == insuranceList[idInsurance]);
							}
						}

					}
					else //no quiere volver
					{
						finalList[k].answerSecL = "El paciente no desea volver";
					}
					break;
				}
			}
			if (a == 10) //si recorri el for entero entonces no contesto
				finalList[k].answerSecL= "El paciente no pudo ser contactado";
		}
	}

	fp.open(SecretaryFileName, ios::out); //abro archivo de la secretaria para sobreescribir
	if (!(fp.is_open()))
		return;

	fp << "DNI, Nombre, Apellido, Telefono, ObraSocial, ID-Medico, Estado" << endl;
	for (int i = 0; i < sizeFile; i++)
	{
		fp << finalList[i].dniSecL << " , " << finalList[i].namePacientSecL << " , " << finalList[i].lastNamePacientSecL << " , " << finalList[i].cellphoneNumberSecL << " , " << finalList[i].medicalInsuranceSecL << " , " << finalList[i].idDoctorSecL<<" , "<<finalList[i].answerSecL << endl;
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

