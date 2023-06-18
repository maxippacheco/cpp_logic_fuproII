// Ejercicio 1 (25 pts). Se ingresan 200 valores numéricos provenientes de un sensor de presión. Debido a fallas de
// comunicación, se ingresaron algunos valores negativos. Realice un programa que reemplace todos los valores
// negativos por en promedio entre el máximo y mínimo valor lista (tenga en cuenta de no considerar los valores
// negativos en la obtención del menor). Muestre el arreglo modificado y informe cuántos reemplazos hizo.

#include<iostream>
#include<vector>

using namespace std;

int main(){

	vector<int> sensor_presion(3);

	for (size_t i = 0; i < sensor_presion.size(); i++)
	{
		cin >> sensor_presion[i];
	}
	
	// todos los valores negativos por en promedio entre el máximo y mínimo valor lista
	
	// obtener mayor y menor
	int mayor = 0, menor = 999;
	for (size_t i = 0; i < sensor_presion.size(); i++)
	{
		if(sensor_presion[i] > mayor && sensor_presion[i] >= 0){
			mayor = sensor_presion[i];
		}

		if(menor > sensor_presion[i] && sensor_presion[i] >= 0){
			menor = sensor_presion[i];
		}
	}

	int prom = (mayor + menor)/2;

	int cant_reemplazos = 0;
	for (size_t i = 0; i < sensor_presion.size(); i++)
	{
		if( sensor_presion[i] < 0 ){
			sensor_presion[i] = prom;
			cant_reemplazos++;
		}
	}

	for (size_t i = 0; i < sensor_presion.size(); i++)
	{
		cout << sensor_presion[i] << " " << endl;
	}
	cout << "Se hicieron un total de " << cant_reemplazos << " reemplazos." << endl;
	

	return 0;
}