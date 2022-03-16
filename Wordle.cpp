#include <iostream>
#include <cstring>
#include <windows.h>
#include<ctime>
#define color SetConsoleTextAttribute
using namespace std;

struct Palabra
{
	string pal[10]= {"REINA","AUDIO", "MANGO", "LIMON", "IDEAS", "FURIA", "FRUTA", "MADRE", "GRIFO", "HOGAR"};
};

void Menu()
{
	cout << "Bienvenido a Wordle!!" << endl << endl <<  "Supongo que ya sabes como va este juego, pero te lo explico un poquito." << endl << endl;
	cout << "Tienes que adivinar una palabra secreta de 5 letras, para ello tienes que ir poniendo palabras de 5 letras." << endl;
	cout << "Despues de poner la palabra te saldran diferentes colores."<<endl<< "Si el color es Verde y esta en la primera posicion, es que la primera" << endl;
	cout << "letra que has puesto esta en la posicion acertada," <<endl <<"si es Amarillo es que la letra que has puesto esta en la palabra secreta pero no en esa posicion" << endl;
	cout << "Si pone gris es que la letra no esta en la palabra secreta.           TIENES 5 INTENTOS." << endl;
	
} 





int main()
{
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
 	srand((unsigned)time(0));
 	
 	
	Palabra jocSelect;
	string intento;
	
	string joc;
	
	int contador=0, contadorPartidas=0;
	bool Juego = 0;
	

	Menu();
	
	while(Juego==0)
	{
		
		contadorPartidas=0;
	
		
		//Seleccion de palabra
		int i = (rand()%10)+1;
		joc=jocSelect.pal[i];
	
		while ((contadorPartidas < 5)&&Juego==0)
		{
			cin >> intento;

			//CONTROLAR QUE LA PALABRA TENGA 5 LETRAS
			if (intento.length() != 5)
			{
				do
				{
					cout << "La palabra debe tener 5 letras" << endl;
					cin >> intento;
				} while (intento.length() != 5);
			}

			for (int i = 0; i < intento.length(); i++)
			{
				intento[i] = toupper(intento[i]);
			}

			if (intento==joc)
			{
				Juego = 1;
			}

			for (int i = 0; i < 5; i++)
			{
				contador = 0;
				for (int j = 0; j < 5; j++)
				{
					if (intento[i] == joc[j])
					{
						if (j == i)
						{
							color(hConsole, 2);
							cout << " Verde ";
							color(hConsole, 7);	
				
						}
						else
						{
							color(hConsole, 6);
							cout << " Amarillo ";
							color(hConsole, 7);
						}

					}
					else
					{
						contador++;
						if (contador == 5)
						{
							color(hConsole, 8);	
							cout << " Gris ";
							color(hConsole, 7);	
						}
					}
				}
			}

			cout << endl;
			contadorPartidas++;
		}
	
		if (contadorPartidas < 5)
			cout << "Has ganado!!" << endl;
		else
		{
			cout << "Has perdido" << endl<<endl;
			cout << "La palabra era " << joc << endl;
		}
	
		cout <<"Quieres seguir jugando?" << endl;
		cout << "1: NO      0:SI" << endl;
		cin >> Juego;
	
	}


	system("pause");
	return 0;
}
