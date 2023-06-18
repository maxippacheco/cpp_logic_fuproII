/*
	En una carrera de 200 metros participaron N atletas, donde N es un valor que se lee al
	comienzo (se sabe que hay menos de 50 atletas). Por cada atleta se ingresa el nombre y tiempo registrado (en
	seg). a) Muestre los nombres de los 2 ganadores y sus tiempos. b) Determine cuÃ¡ntos atletas estuvieron a 5
	segundos o menos de obtener el segundo lugar.
*/

#include<iostream>
#include<vector>
using namespace std;

struct Atleta{
	string nombre;
	int tiempo_segundos;
};


int main(){

	int n; cin >> n;

	while (n > 50)
	{
		cout << "No hay esa cantidad de atletas, ingrese nuevamente." << endl;
		cin >> n;
	}
	
	cin.ignore();
	vector<Atleta> atletas(n);

	// a. cargar ternas
	for (Atleta & atleta: atletas)
	{
		cout << "Ingrese el nombre del atleta: " << endl;
		getline(cin, atleta.nombre);
		cout << "Ingrese el tiempo del atleta (en segundos): " << endl;
		cin >> atleta.tiempo_segundos;
		cin.ignore();
	}
	
	// b. primero y segundo
	Atleta primero, segundo;
	for (Atleta atleta : atletas)
	{
		if( primero.tiempo_segundos > atleta.tiempo_segundos){
			// cambio el segundo por el primero
			segundo.tiempo_segundos = primero.tiempo_segundos;
			segundo.nombre = primero.nombre;

			// cambio el primero por el que esta iterando
			primero.tiempo_segundos = atleta.tiempo_segundos;
			primero.nombre = atleta.nombre;
		
		} else if ( segundo.tiempo_segundos > atleta.tiempo_segundos ){
			segundo.tiempo_segundos = atleta.tiempo_segundos;
			segundo.nombre = atleta.nombre;
		}
	}

	cout << "El ganador es " << primero.nombre << " con un tiempo de " << primero.tiempo_segundos << "seg" << endl;
	cout << "El segundo es " << segundo.nombre << " con un tiempo de " << segundo.tiempo_segundos << "seg" << endl;

	int cantidad_atletas = -1;
	for (Atleta & atleta: atletas)
	{
		if(( (atleta.tiempo_segundos > segundo.tiempo_segundos) && (segundo.tiempo_segundos - atleta.tiempo_segundos) <= 5)){
			cantidad_atletas++;
		}
	}
	
	cout << "Los atletas que estuvieron 5 segundos o menos de obtener el segundo lugar fueron " << cantidad_atletas << endl;

	return 0;
}
