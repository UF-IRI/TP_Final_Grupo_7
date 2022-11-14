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

