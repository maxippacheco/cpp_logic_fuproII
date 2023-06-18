// Ejercicio 2 (30 pts) En una carrera de motos se registraron los tiempos de cada una de las 27 vueltas de cada uno
// de los 18 competidores, y ahora se desean analizar estos datos. Escriba un programa para: a) Permitir primero la
// carga de los nombres de cada uno de los competidores (en orden), y luego, (también en orden) los tiempos de
// cada competidor por cada vuelta (en segundos). b) Encontrar la mejor vuelta de toda la carrera e informar su
// tiempo, qué número de vuelta fue, y el nombre del competidor que la logró (nota: la mejor es la de menor
// tiempo). c) Informar el tiempo de vuelta promedio considerando los 18x27 tiempos (el promedio de todos los
// tiempos). Debe utilizar funciones para los incisos b y c.


#include<iostream>
#include<vector>
#include "matrix"

using namespace std;

struct Competidor{
	string nombre;
	vector<int> tiempos;
};

int main(){

	// tiempo en segundos
	vector<Competidor> carrera(3);
	
	// a. cargar ternas
	for (size_t i = 0; i < carrera.size(); i++)
	{
		cout << "Ingrese su nombre: " << endl; cin >> carrera[i].nombre; 
		carrera[i].tiempos.resize(27);
		for (size_t j = 0; j < carrera[i].tiempos.size(); j++)
		{
			// cout << "Ingrese el tiempo en segundos [" << j << "]: " << endl;
			// cin >> carrera[i].tiempos[j];
			carrera[i].tiempos[j] = rand()%120;
		}
	}
	
	// b. mejor tiempo por vuelta
	for (size_t j = 0; j < carrera[0].tiempos.size(); j++)
	{
		int menor = 9999, vuelta; string menor_nombre;
		for (size_t i = 0; i < carrera.size(); i++)
		{
			if( menor > carrera[i].tiempos[j]){
				menor = carrera[i].tiempos[j];
				vuelta = j + 1;
				menor_nombre = carrera[i].nombre;
			}
		}
		
		cout << "El mejor tiempo de la vuelta " << vuelta << " fue " << menor_nombre << " con un tiempo de " << menor << endl;
	}

	// c. promedio de todos los tiempos

	int suma_total = 0;
	for (size_t i = 0; i < carrera.size(); i++)
	{
		for (size_t j = 0; j < carrera[i].tiempos.size(); j++)
		{
			suma_total += carrera[i].tiempos[j];
		}
	}

	// divido por la cantidad de competidores por los tiempos
	float prom = suma_total/(18*27);
	cout << "El promedio de los tiempos es de: " << prom << endl;
	

	return 0;
}