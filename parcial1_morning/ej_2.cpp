

#include<iostream>
#include<vector>

using namespace std;

struct Archivo{
	string nombre;
	int cant_lineas_codigo, cant_funciones;
};

pair<string, string> archivos_con_mas_lineas(vector<Archivo> &archivos);
void cant_total(vector<Archivo> &archivos);

int main(){

	// inciso a.
	int n;
	cout << "Ingrese la cantidad de datos: " << endl; cin >> n;

	vector<Archivo> archivos(n);

	for (size_t i = 0; i < archivos.size(); i++)
	{
		cout << "Ingrese el nombre del archivo: " << endl; cin >> archivos[i].nombre;
		cout << "Ingrese las lineas de codigo: " << endl; 
		// archivos[i].cant_lineas_codigo = rand()%1001;
		cin >> archivos[i].cant_lineas_codigo;
		cout << "Ingrese la cantidad de funciones: " << endl; 
		cin >> archivos[i].cant_funciones;
		// archivos[i].cant_funciones = 10;
	}
	
	// inciso b.
	for (size_t i = 0; i < archivos.size(); i++)
	{
		cout << "El promedio de lineas por funcion en el archivo " << i << " es de " 
		<< (archivos[i].cant_lineas_codigo/archivos[i].cant_funciones) << " lineas" << endl;
	}

	for (size_t i = 0; i < archivos.size(); i++)
	{
		cout << "ARCHIVO [" << i << "]" << endl;
		cout << "Lineas: " << archivos[i].cant_lineas_codigo << endl;
		cout << "Func: " << archivos[i].cant_funciones << endl;
	}
	
	pair<string, string> dos_may = archivos_con_mas_lineas(archivos);
	cout << "El mayor: " << dos_may.first << endl;
	cout << "El segundo: " << dos_may.second << endl;

	cant_total(archivos);

	return 0;
}

pair<string, string> archivos_con_mas_lineas(vector<Archivo> &archivos){

	Archivo mayor, segundo;
	mayor.cant_lineas_codigo = 0;	
	segundo.cant_lineas_codigo = 0;	
	for (size_t i = 0; i < archivos.size(); i++)
	{
		if(archivos[i].cant_lineas_codigo > mayor.cant_lineas_codigo){
			segundo = mayor;
			mayor = archivos[i];
		}else if( archivos[i].cant_lineas_codigo > segundo.cant_lineas_codigo ){
			segundo = archivos[i];
		}
	}
	
	pair<string, string> dos_mayores;
	dos_mayores.first = mayor.nombre;
	dos_mayores.second = segundo.nombre;

	return dos_mayores;
}

void cant_total(vector<Archivo> &archivos){
	int cant_funciones = 0, cant_lineas = 0;

	for (size_t i = 0; i < archivos.size(); i++)
	{
		cant_funciones += archivos[i].cant_funciones;
		cant_lineas += archivos[i].cant_lineas_codigo;
	}
	
	cout << "La cantidad total de lineas de codigo es de: " << cant_lineas << endl;
	cout << "La cantidad total de funciones es de: " << cant_funciones << endl;
}