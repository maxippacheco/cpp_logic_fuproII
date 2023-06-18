// Ejercicio 3 (25 pts) Se pretende analizar el rendimiento académico de 200 egresados de una carrera cuyo plan
// contiene 35 materias. Escriba un programa que permita a) ingresar 200x35 ternas de datos compuestas por
// número de alumno (1 a 200), número de materia (1 a 35) y nota final (6 a 10) y muestre: b) el mejor promedio de
// la carrera; c) la materia más difícil (la que tenga menor promedio de nota), y d) la nota que obtuvo el alumno del
// mejor promedio para esa materia más difícil.

#include<iostream>
#include "matrix"

using namespace std;

int main(){

	// 200 egresados, 35 materias
	matrix<float> carrera(200, 35);

	// a. cargar ternas

	for (size_t i = 0; i < carrera.size(0); i++)
	{
		for (size_t j = 0; j < carrera.size(1); j++)
		{
			carrera[i][j] = rand() % 10;
		}
	}

	// b. mejor promedio de la carrera. mayor
	float mejor_promedio = 0, pos_mejor_prom;
	for (size_t i = 0; i < carrera.size(0); i++)
	{
		for (size_t j = 0; j < carrera.size(1); j++)
		{
			if( carrera[i][j] > mejor_promedio ){
				mejor_promedio = carrera[i][j];
				pos_mejor_prom = i;
			}
		}
	}
	cout << "El mejor promedio es de " << mejor_promedio << endl;

	// la materia más difícil => no esta bien
	float menor = 999, posicion_menor;
	for (size_t j = 0; j < carrera.size(1); j++)
	{
		float prom_col = 0;
		for (size_t i = 0; i < carrera.size(0); i++)
		{
			prom_col += carrera[i][j];
		}

		if( menor > (prom_col/35)){
			menor = prom_col/35;
			posicion_menor = j;
		}

	}
	
	cout << "El promedio es: " << menor << endl;
	cout << "La posicion es: " << posicion_menor << endl;

	// d) la nota que obtuvo el alumno del mejor promedio para esa materia más difícil.
	cout << "El alumno con promedio " << mejor_promedio << " en la materia " << posicion_menor << " obtuvo " << carrera[pos_mejor_prom][posicion_menor] << endl;

	return 0;
}