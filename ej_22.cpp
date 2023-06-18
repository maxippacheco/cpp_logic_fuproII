// Ejercicio 1 (25 pts) a) Declare un struct DatosMatriz que contenga los siguientes campos: un flotante promedio,
// y dos enteros cantidad_menor y cantidad_mayorIgual. b) Escriba una función AnalizarMatriz que reciba una
// matriz de Nx12 valores flotantes y retorne un struct del tipo DatosMatriz. En el struct debe guardar el promedio
// de todos los valores de la matriz, y las cantidades de elementos de la misma mayores o iguales y menores a
// dicho promedio. c) Escriba un programa cliente que genere una matriz de 5x12 flotantes con valores aleatorios
// entre 0 y 1, y muestre los resultados de invocar a la función con dicha matriz. Ayuda: para generar un flotante
// aleatorio entre 0 y 1 puede usar la expresión “(rand()%1001)/1000.f”

#include<iostream>
#include "matrix"
using namespace std;

struct DatosMatriz{
	float promedio; 
	int cant_menor, cant_mayorIgual;
};

DatosMatriz analizar_matriz(matrix<float> &matrix);
matrix<float> generar_matriz();
void mostrar_matriz(matrix<float> &matrix);

int main(){

	int n;

	cin >> n;

	matrix<float> valores(n, 12);

	for (size_t i = 0; i < valores.size(0); i++)
	{
		for (size_t j = 0; j < valores.size(1); j++)
		{
			valores[i][j] = rand()%500;
		}
		
	}

	DatosMatriz datos = analizar_matriz(valores);

	cout << "Promedio: " << datos.promedio << endl;
	cout << "Valores mayores al promedio: " << datos.cant_mayorIgual << endl;
	cout << "Valores menores al promedio: " << datos.cant_menor << endl;
	
	matrix<float> matriz_generada = generar_matriz();
	mostrar_matriz(matriz_generada);

	return 0;
}

DatosMatriz analizar_matriz(matrix<float> &matrix){
	DatosMatriz datos;
	datos.cant_mayorIgual = 0;
	datos.cant_menor = 0;

	float suma_total = 0;
	for (size_t i = 0; i < matrix.size(0); i++)
	{
		for (size_t j = 0; j < matrix.size(1); j++)
		{
			suma_total += matrix[i][j];	
		}
	}

	datos.promedio = (suma_total)/(matrix.size(0)*matrix.size(1));
	
	for (size_t i = 0; i < matrix.size(0); i++)
	{
		for (size_t j = 0; j < matrix.size(1); j++)
		{
			if(datos.promedio > matrix[i][j]){
				++datos.cant_mayorIgual;
			}else{
				++datos.cant_menor;
			}
		}
		
	}
	
	return datos;
}

matrix<float> generar_matriz(){
	matrix<float> datos(5,12);

	for (size_t i = 0; i < datos.size(0); i++)
	{
		for (size_t j = 0; j < datos.size(1); j++)
		{
			datos[i][j] = (rand()%1001)/1000.f;
		}
		
	}

	return datos;
}

void mostrar_matriz(matrix<float> &matrix){
	for (size_t i = 0; i < matrix.size(0); i++)
	{
		for (size_t j = 0; j < matrix.size(1); j++)
		{
			cout << "[" << i << "]" << "[" << j << "]" << matrix[i][j] << endl;
		}
		
	}
	
}