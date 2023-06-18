// Ejercicio 3 (20 pts). Se ingresan como datos N valores numéricos ordenados en forma descendente (el valor de
// N se lee por teclado). Realice un algoritmo que lea un nuevo valor y lo inserte en la lista de tal manera que el
// orden se mantenga. Luego muestre la nueva lista resultante.


#include<iostream>
#include<vector>

using namespace std;

int main(){

	int n; cin >> n;
	vector<int> valores(n);

	cout << "Ingrese valores numericos de forma descendente: " << endl;
	for (size_t i = 0; i < valores.size(); i++)
	{
		cout << "["  << i << "]: "; cin >> valores[i];
	}


	int element_to_add;
	cout << "Ingrese un numero a insertar: "; cin >> element_to_add;

	// find position to add element
	int position_to_add;
	for (size_t i = 0; i < valores.size(); i++)
	{
		if(valores[i] > element_to_add && valores[i + 1] < element_to_add){
			position_to_add = i;
		}
	}

	valores.push_back(0);	

	for (size_t i = valores.size()-1; i > position_to_add; i--)
	{
		valores[i] = valores[i-1];
	}

	valores[position_to_add+1] = element_to_add;

	for (size_t i = 0; i < valores.size(); i++)
	{
		cout << valores[i] << endl;
	}
	



	return 0;
}