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



void secretary(string SecretaryFileName, int *sizeFile)
{
	srand(NULL);
	int comeBack, change, answered, satisfied, idInsurance;
	fstream fp;

	fp.open(SecretaryFileName, ios::in); //abro archivo de la secretaria para leer
	if (!(fp.open()))
		return;

	char comma = 0;
	string dummy;

	secretaryList* finalList = new secretaryList[*sizeFile]; //nueva lista con el tamanio de la que me pasan en el archivo

	fp >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy; //leo el encabezado

	int i = 0;
	while (fp)//cargo la lista con los datos
	{
		fp >> finalList[i].dni >> comma >> finalList[i].namePacient >> comma >> finalList[i].lastNamePacient >> comma >> finalList[i].cellphoneNumber >> comma >> finalList[i].medicalInsurance >> comma >> finalList[i].idDoctor >> comma >> finalList[i].answer; //leo los datos en el array
		i++;
	}

	string pacientFile = "C:\\Users\\agosn\\source\\repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Pacientes.csv";
	string contactFile = "C:\\Users\\agosn\\source\\repos\\TP_Final_Grupo_7\\data_files\\input\\IRI_Consultas.csv";
	
	contact contactPacient;
	int insuranceListSize=0;
	string* insuranceList=new string[0];//en la funcion se le asigna una nueva direccion

	bool medicalInsuranceArray = (pacientFile, &insurancelist, &insuranceListSize);

	satisfied = 0;

	for (int k = 0; k < *sizeFile; k++)
	{
		findContact(contactFile, &contactPacient, finalList[k].dni);
		if (&contactPacient != nullptr) //hago todo siempre y cuando lo haya encontrado
		{
			for (int i = 0; i < 10; i++) //llamo como maximo 10 veces cada paciente
			{
				answered = rand() % 2; //0: no contesto, 1: contesto
				if (answered == 1)
				{
					comeBack = rand() % 2;//0: no quiere volver, 1: quiere volver
					if (comeBack == 1)
					{
						//nueva consulta!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
						finalList[k].answer = "El paciente ha programado una nueva consulta";

						while (satisfied == 0)
						//0: no esta satisfecho con los cambios, repito 1:esta satisfecho
						{
							change = rand() % 3;//0: no quiere cambiar ningun dato 1:cambio su obra social 2:cambio su medico
							switch (change)
							{
							case 0:
							{
								satisfied = 1;
								break;
							}
							case 1:
							{
								if (medicalInsuranceArray)
								{
									idInsurance = rand() % insuranceListSize;
									finalList[k].medicalInsurance = insuranceList[idInsurance];
								}
								satisfied = rand() % 2;
								break;
							}
							case 2:
							{
								//necesito mi funcion de id-medico
								satisfied = rand() % 2;
								break;
							}
							default:break;
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
		}
	}

	//NO TE OLVIDES LOS DELETES

}
