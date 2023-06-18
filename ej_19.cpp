// Ej. 3. (20 ptos). Se lee en un arreglo lineal de 10 elementos nombres de personas ya ordenados alfabéticamente,
// realice la lectura y programe lo siguiente: a). Permita ingresar un nombre a ser eliminado, para esto debe
// desplazar los nombres pisando el nombre a eliminar. b). Inserte un nuevo nombre manteniendo el orden
// alfabético del arreglo.

#include<iostream>
#include<vector>
using namespace std;

int buscar_pos(vector<string> &arr, string new_name);
vector<string> delete_arr(vector<string> &arr, string to_delete, int pos);

int main(){

	vector<string> nombres;

	string new_name;
	cout << "Ingrese un nombre: " << endl; cin >> new_name;

	while (new_name != "")
	{
		nombres.push_back(new_name);
		cout << "Ingrese un nombre: " << endl; cin >> new_name;
	}

	string to_delete;
	cout << "Ingrese nombre a eliminar"; cin >> to_delete;

	int pos = buscar_pos(nombres, new_name);

	if( pos >= 0 ){
		vector<string> arr_with_removed_element = delete_arr(nombres, to_delete, pos);
	}



	return 0;	
}

int buscar_pos(vector<string> &arr, string new_name){
	for (size_t i = 0; i < arr.size(); i++)
	{
		if( arr[i] == new_name ){
			return i;
		}
	}

	return -1;
}

vector<string> delete_arr(vector<string> &arr, string to_delete, int pos){
	for (size_t i = pos; i < arr.size()-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	
	//delete
	arr.resize(arr.size()-1);

	return arr;
}