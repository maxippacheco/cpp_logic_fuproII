// Ejercicio 1 [15 pts] Escriba una función que reciba una matriz de elementos de tipo float de 20 filas y 14
// columnas, y genere un vector con los mayores elementos de cada fila.


#include<iostream>
#include<vector>
#include "matrix"
using namespace std;


vector<int> retornar_las_filas_mayores(matrix<int> &arr);

int main(){

	matrix<int> numeros(20, 14);

	for (size_t i = 0; i < numeros.size(0); i++)
	{
		for (size_t j = 0; j < numeros.size(1); j++)
		{
			numeros[i][j] = rand()%100;
		}
		
	}
	

	for (size_t i = 0; i < numeros.size(0); i++)
	{
		for (size_t j = 0; j < numeros.size(1); j++)
		{
			cout << numeros[i][j] << "  ";
		}
		cout << endl;
	}
	
	vector<int> mayores = retornar_las_filas_mayores(numeros);

	for (size_t i = 0; i < mayores.size(); i++)
	{
		cout << mayores[i] << endl;
	}
	

	return 0;
}

vector<int> retornar_las_filas_mayores(matrix<int> &arr){
	vector<int> mayores(20);

	for (size_t i = 0; i < arr.size(0); i++)
	{
		int el_mayor = 0;
		for (size_t j = 0; j < arr.size(1); j++)
		{
			if( arr[i][j] > el_mayor ){
				el_mayor = arr[i][j];
			}

		}
		mayores[i] = el_mayor;
	}
	
	return mayores;
}