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

void secretary(string SecretaryFileName) //NO LA TERMINE NO TOQUEN NADA
{
	srand(NULL);

	int comeBack, change, answered, satisfied; //%2 para 0 y 1
	
	fstream fp;

	fp.open(SecretaryFileName, ios::in);
	if (!(fp.open()))
		return;

	while (fp1)
	{
		for (int i = 0; i < 10; i++) //lamo como maximo 10 veces cada paciente
		{
			answered = rand() % 2; //0: no contesto, 1: contesto
			if (answered == 1)
			{
				comeBack = rand() % 2;//0: no quiere volver, 1: quiere volver
				if (comeBack == 1)
				{
					change = rand()%;/////////////
					switch (change)
					{
					case 0:
					{
						
					}
					}

				}
			}
		}
	}


}

