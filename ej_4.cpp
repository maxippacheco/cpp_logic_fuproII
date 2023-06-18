// Ejercicio 2 (25pts) La Fórmula 1 está buscando mejorar la seguridad agregando nuevos elementos para proteger
// las cabezas de los pilotos. Se probaron tres sistemas: el "shield" (una especie de "parabrisas" blindado), el "halo"
// (un armazón de carbono) y el "ghost" (sin piloto en el auto, manejado con control remoto). Ciertos equipos han
// probado algunos de estos elementos y han calificado los resultados en una escala de 1 a 5 estrellas. Se requiere
// un programa C++ para analizar estos datos y ayudar a decidir cuál es la mejor opción. a) Se ingresan ternas de
// datos compuestas por un código de equipo (de 1 a 10), un código de sistema (1-shield, 2-halo, 3-ghost), y la
// calificación (1 a 5 estrellas). Los datos finalizan con código de equipo 0. Organice estos datos en una matriz de
// 10x3 (10 equipos, 3 sistemas), donde cada posición debe guardar la cantidad de estrellas asignadas por ese
// equipo a ese sistema, o -1 si ese equipo no probó ese sistema. b) muestre solo los equipos que calificaron los tres
// sistemas, con sus respectivas calificaciones. c) Informe el nombre del sistema que obtuvo un mayor promedio de
// estrellas (el promedio se calcula considerando todos los equipos que probaron el sistema, sin considerar los -1).
// Defina y utilice para ello una función calcular_promedio que calcule el promedio de un sistema.

#include<iostream>
#include "matrix"
using namespace std;

int main(){

	matrix<int> datos(10, 3, -1);

	int codigo_equipo, codigo_sistema, calificacion;

	cout << "Ingrese el codigo del equipo (1 al 10)" << endl; cin >> codigo_equipo;

	while (codigo_equipo != 0)
	{

		cout << "Ingrese el codigo del sistema (1 al 3)" << endl; cin >> codigo_sistema;

		cout << "Ingrese calificacion " << endl; cin >> calificacion;

		// validar calificacion
		if( calificacion == -1 || calificacion > 0 && calificacion <= 5 ){
			datos[codigo_equipo, codigo_sistema] = calificacion;
		}else{
			cout << "Calificacion incorrecta, por favor ingrese nuevamente los datos " << endl; 
		}
	
		cout << "Ingrese el codigo del equipo (1 al 10)" << endl; cin >> codigo_equipo;
	}
	
	// b) muestre solo los equipos que calificaron los tres sistemas, con sus respectivas calificaciones.
	// todo hacer
	for (size_t i = 0; i < datos.size(0); i++)
	{
		for (size_t j = 0; j < datos.size(1); j++)
		{
			if(datos[i][0] != -1 && datos[i][1] != -1 && datos[i][2] != -1){
				cout << "Sistema " << j + 1 << " equipo " << i + 1 << " calificacion " << calificacion << endl;
			}
		}
		
	}
	


	return 0;
}