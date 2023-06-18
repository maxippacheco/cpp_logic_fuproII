// Ej. 1 (20pts) En un programa C++ se ha definido el tipo: struct datatime {int hh, mm, ss}; donde 3 enteros
// representan una hora determinada (hora, minutos y segundos). Escriba el código de una función C++ llamada
// diff_time(...) de tipo datatime, la cual debe recibir como parámetros 2 variables de tipo datatime. La función
// debe calcular la diferencia de tiempo entre el 1er parámetro y el 2do.


#include<iostream>
using namespace std;

struct DataTime{
	int hh, mm, ss;
};

int calcular_diff(DataTime fecha1, DataTime fecha2);

int main(){

	DataTime fecha1, fecha2;
	
	cout << "Ingrese la primer fecha: " << endl;
	cout << "Horas: " << endl; cin >> fecha1.hh;
	cout << "Minutos: " << endl; cin >> fecha1.mm;
	cout << "Segundos: " << endl; cin >> fecha1.ss;

	cout << "Ingrese la segunda fecha: " << endl;
	cout << "Horas: " << endl; cin >> fecha2.hh;
	cout << "Minutos: " << endl; cin >> fecha2.mm;
	cout << "Segundos: " << endl; cin >> fecha2.ss;


	int diff = calcular_diff(fecha1, fecha2);	

	int horas = diff / 3600;
	diff = diff % 3600;
	int minutos = diff / 60, segundos = diff % 60;

	cout << "Horas: " << horas << endl;
	cout << "Minutos: " << minutos << endl;
	cout << "Segundos: " << segundos << endl;


	return 0;
}

int calcular_diff(DataTime fecha1, DataTime fecha2){
	return (((fecha1.hh*60*60) + (fecha1.mm*60) + fecha1.ss) - ((fecha2.hh*60*60) + (fecha2.mm * 60) + fecha2.ss));
}