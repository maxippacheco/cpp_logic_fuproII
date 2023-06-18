// Ejercicio 3 (20 pts). Se ingresan como datos 100 nombres de personas que están ordenados alfabéticamente.
// Realice un algoritmo que lea un nuevo nombre y lo inserte en la lista de tal manera que el orden se mantenga.
// Luego muestre la nueva lista resultante. 

#include<iostream>
#include<vector>

using namespace std;

int main(){

	vector<string> nombres(3);

	cout << "Ingrese nombres ordenador alfabeticamente: " << endl;
	for (size_t i = 0; i < nombres.size(); i++)
	{
		cout << "["  << i << "]: "; cin >> nombres[i];
	}

	string nombre_agregar; 
	
	cout << "Ingrese el nombre" << endl; cin >> nombre_agregar;

	

  int posicion = 0;
  for (size_t i = 0; i < nombres.size(); i++)
	{
		if( nombre_agregar > nombres[posicion] ) posicion = i;
	}
	
  nombres.push_back(""); // Agregar un elemento adicional al final del vector


	// correr las posiciones
	for (size_t i = nombres.size()-1; i > posicion; i--)
	{
		nombres[i] = nombres[i - 1];
	}
	
	nombres[posicion] = nombre_agregar;

	for (size_t i = 0; i < nombres.size(); i++)
	{
		cout << nombres[i] << endl;
	}
	
		


	return 0;
}

