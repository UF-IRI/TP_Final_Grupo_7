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

void newFile(string SecretaryFileName, pacient*& listPacient, int size)
{
	fstream fp;

	fp.open(SecretaryFileName, ios::out);
	if (!(fp.is_open()))
		return;

	fp << "DNI, Nombre, Apellido, ObraSocial" << endl;
	for (int i = 0; i < size; i++)
	{
		fp << listPacient[i].dni << " , " << listPacient[i].namePacient << " , " << listPacient[i].lastNAmePacient << " , " << listPacient[i].idInsurance << endl;
	}

	fp.close();

}

//REVISAR
void secretary(string SecretaryFileName, int *sizeFile, string MedicalInsuranceFile) //NO LA TERMINE NO TOQUEN NADA
{
	srand(NULL);

	int comeBack, change, answered, MI; //%2 para 0 y 1
	int counter = 0;
	fstream fp;

	fp.open(SecretaryFileName, ios::in); //abro archivo de la secretaria para leer
	if (!(fp.open()))
		return;

	char comma=0;
	string dummy;
	getline(fp, dummy); //leo la primer linea con el encabezado

	secretaryList* finalList = new secretaryList[*sizeFile]; //me creo un array para desp cambiar esto y sobreescribir

	while(fp) //leo los datos en el array
	{
		fp >> finalList[j].dni >> comma >> finalList[j].name >> comma >> finalList[j].lastName >> comma >> finalList[j].medicalInsurance; //leo los datos en el array
	}
	fp.close(); //cierro el archivo

	fp.open(MedicalInsuranceFile,ios::in); //abro el archivo de obras sociales
	if (!(fp.open()))
		return;

	insurance *medicalInsuranceList=new insurance[6]; //me creo un array de obras sociales

	getline(fp, dummy);//leo la primer linea con el encabezado

	int a = 0;
	while (fp)
	{
		fp >> medicalInsuranceList[a].idInsurance >> comma >> medicalInsuranceList[a].nameInsurance;
		a++;
	}

	fp.close();

	for(int k=0; k<*sizeFile; k++)
	{
		for (int i = 0; i < 10; i++) //llamo como maximo 10 veces cada paciente
		{
			answered = rand() % 2; //0: no contesto, 1: contesto
			if (answered == 1)
			{
				comeBack = rand() % 2;//0: no quiere volver, 1: quiere volver
				if (comeBack == 1)
				{
					change = rand() % 2;//0: no quiere cambiar ningun dato 1:cambio su obra social
					if (change == 1)
					{
						MI = rand() % 6; //numeros del 0 al 5, c/u tiene una obra social asignada
						finalList[k].medicalInsurance = medicalInsuranceList[MI].nameInsurance;
					}
				}
				else //si no quiere volver lo elimino de la lista de la secretaria
				{ 
					counter++; //cuento cada vez que elimine a alguien de la lista
					for (int a = k; a < *sizeFile - 1; a++)
					{
						finalList[a] = finalList[a + 1];
					}
					k--; //le resto uno a k asi vuelvo a fijarme esa posicion
				}
				break;
			}
		}
	}

	delete[] medicalInsuranceList;
	medicalInsuranceList = NULL;

	*sizeFile = *sizeFile - counter;

	fp.open(SecretaryFileName, ios::out); //abro archivo de la secretaria para sobreescribir
	if (!(fp.open()))
		return;

	fp << "DNI, Nombre, Apellido, ObraSocial" << endl; //sobreescribo el encabezado

	for (int i = 0; i < *sizeFile; i++) //paso los datos del array corregido
	{
		fp << finalList[i].dni << " , " << finalList[i].name << " , " << finalList[i].lastName << " , " << finalList[i].medicalInsurance << endl;
	}

	delete[] medicalInsuranceList;
	medicalInsuranceList = NULL;
}

