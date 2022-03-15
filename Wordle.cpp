#include <iostream>
#include <cstring>
using namespace std;

struct Palabra
{
	string pal;
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
	string joc;
	Palabra intento;
	int contador = 0, contadorPartidas=0, cosa;
	bool Juego = 0;
	joc = "REINA";
	Menu();

	while ((contadorPartidas < 5)&& Juego==0)
	{
		cin >> intento.pal;

		//CONTROLAR QUE LA PALABRA TENGA 5 LETRAS
		if (intento.pal.length() != 5)
		{
			do
			{
				cout << "La paraula ha de tenir 5 lletres" << endl;
				cin >> intento.pal;
			} while (intento.pal.length() != 5);
		}

		for (int i = 0; i < intento.pal.length(); i++)
		{
			intento.pal[i] = toupper(intento.pal[i]);
		}

		if (intento.pal==joc)
		{
			Juego = 1;
		}

		for (int i = 0; i < 5; i++)
		{
			contador = 0;
			for (int j = 0; j < 5; j++)
			{
				if (intento.pal[i] == joc[j])
				{
					if (j == i)
					{
						cout << " Verde ";
						//j = 5; en teoria tiene que funcionar sin esto
					}
					else
					{
						cout << " Amarillo ";
					}

				}
				else
				{
					contador++;
					if (contador == 5)
					{
						cout << " Gris ";
					}
				}
			}
		}

		cout << endl;
		contadorPartidas++;
	}
	
	if (contadorPartidas <= 5)
		cout << "Has gando!!" << endl;
	else
	{
		cout << "Has perdido" << endl<<endl;
		cout << "La palabra era " << joc;
	}


	cin >> cosa;
	return 0;
}
