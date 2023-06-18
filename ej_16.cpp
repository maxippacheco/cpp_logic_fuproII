// Ejercicio 1 [25 pts] Escriba un programa que permita leer una serie de valores numéricos enteros y los almacene
// en un arreglo. Se desconoce de antemano de cuántos valores se trata, pero se sabe que la lectura de datos termina
// cuando se ingresa el valor -1. Escriba una función que cuente la cantidad de valores que se encuentran por
// encima del promedio e inserte dicha cantidad al principio del arreglo. Utilizar la función desde el programa
// principal y mostrar el arreglo antes y después de la inserción.

#include<iostream>
#include<vector>

using namespace std;

vector<int> find_average_and_push( vector<int> &arr);

int main(){

	vector<int> data;

	int new_value;

	cout << "Enter a new value: " << endl;
	cin >> new_value; 

	// load values
	while (new_value != -1)
	{
		data.push_back(new_value);

		cout << "Enter a new value: " << endl;
		cin >> new_value; 
	}

	cout << "----- Before insertion -----" << endl;
	for (int &element : data)
	{
		cout << element << " ";
	}

	vector<int>data_modified = find_average_and_push(data);
		
		cout << endl << "<----- After insertion -----" << endl;
	for (int &element : data)
	{
		cout << element << " ";
	}
	


	return 0;
}

vector<int> find_average_and_push( vector<int> &arr ){

	// find average
	int prom = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		prom += arr[i];		
	}
	
	prom = prom/arr.size();

	arr.resize(arr.size() + 1);
	for (size_t i = arr.size()-1; i > 0; i--)
	{
		// move all the elements
		arr[i] = arr[i - 1];
	}
	
	arr[0] = prom;

	return arr;

}