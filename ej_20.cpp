// Ej. 3 (25pts) En una prueba de maratón compiten 35 atletas. Organice un struct con los datos de cada atleta:
// apellido, nombres, número asignado, h1,m1,s1; donde número asignado es un entero entre 1 y 35; y h1,m1,s1
// son 3 enteros para el tiempo empleado (hora, minutos, segundos) en completar la prueba. Si tiempo empleado es
// 0,0,0 significa que el atleta abandonó la prueba. Escriba un programa C++ que ingrese -una vez terminada la
// competencia- los datos, sin orden, de cada uno de los 35 atletas. a) Escribir una función que determine el atleta
// ganador y mostrar sus datos desde el programa cliente. b) Luego, mostrar los apellidos y nombres de todos los
// atletas que terminaron la competencia (sin contar los que abandonaron)

#include<iostream>
#include<vector>
using namespace std;

struct Atleta{
	string apellido, nombre;
	int h1,m1,s1;
};

Atleta ganador(vector<Atleta> &arr);

int main(){

	vector<Atleta> atletas(3);

	for (size_t i = 0; i < atletas.size(); i++)
	{
		cout << "Ingrese el nombre: " << endl; cin >> atletas[i].nombre;
		cout << "Ingrese el apellido: " << endl; cin >> atletas[i].apellido;
		cout << "---INGRESE EL TIEMPO---" << endl;
		cout << "Horas: " << endl; cin >> atletas[i].h1;
		cout << "Minutos: " << endl; cin >> atletas[i].m1;
		cout << "Segundos: " << endl; cin >> atletas[i].s1;
	}

	Atleta atleta_ganador = ganador(atletas);

	cout << "El ganador es: " << atleta_ganador.nombre << " " << atleta_ganador.apellido << endl;


	cout << "ATLETAS QUE TERMINARON LA COMPETENCIA" << endl;
	for (size_t i = 0; i < atletas.size(); i++)
	{
		// si es 0, 0, 0 la sumatoria de esto da 0
		int tiempo_segundos = (atletas[i].h1*60*60) + (atletas[i].m1 * 60) + atletas[i].s1;
		// se puede mejorar la condicion
		if( tiempo_segundos > 0 ){
			cout << atletas[i].nombre << " " << atletas[i].apellido << endl;
		}
	}
	


	return 0;
}

Atleta ganador(vector<Atleta> &arr){
	Atleta ganador;
	int menor_tiempo = 9999;
	for (size_t i = 0; i < arr.size(); i++)
	{
		int tiempo_segundos = (arr[i].h1*60*60) + (arr[i].m1 * 60) + arr[i].s1;

		if( menor_tiempo > tiempo_segundos && tiempo_segundos > 0 ){
			menor_tiempo = tiempo_segundos;
			ganador = arr[i];
		}
	}
	
	return ganador;
}