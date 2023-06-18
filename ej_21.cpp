// Ej. 2 (35pts) En una localidad se realizan elecciones municipales. Se presentan 7 partidos políticos y existen 18
// barrios en el municipio. Escriba un programa en C++ que lea inicialmente los nombres de cada candidato y el
// código de partido (1..7) al que pertenece. Luego debe leer los datos que llegan de cada una de las 145 mesas
// electorales. Se ingresan 9 datos por mesa: cod. barrio, cant. votos blanco, cant. votos partido 1, cant. votos
// partido 2, ..., cant. votos partido 7. a) Escriba una función que permita obtener el código del partido ganador y el
// % de votos obtenido sobre el total. b) Informe el nombre del próximo intendente. c) Muestre el % de votos
// obtenido por cada candidato. d) Escriba una función que devuelva el cod. del barrio que obtuvo mayor cantidad
// de votos en blanco.
//TODO : TERMINAR ESTE EJERCICIO

#include<iostream>
#include "matrix"

using namespace std;

vector<int> buscar_partido_ganador(matrix<int> &elecciones, int cod_municipio);

int main(){

	matrix<int> elecciones(7, 18);

	for (size_t i = 0; i < elecciones.size(0); i++)
	{
		for (size_t j = 0; j < elecciones.size(1); j++)
		{
			elecciones[i][j] = rand()% 1000;
		}
		
	}
	
	return 0;
}

vector<int> buscar_partido_ganador(matrix<int> &elecciones, int cod_municipio){


}