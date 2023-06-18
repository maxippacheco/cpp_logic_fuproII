// Ejercicio 2 (35 pts). La ciudad asigna un monto fijo de $100.000 por cada mes, a cada una de 10 escuelas
// rurales durante todo el 2017 para gastos. Mensualmente cada escuela realiza compras que se irán acumulando.
// Escriba un programa que organice una tabla de 10x12 con los totales de montos que cada escuela ha tenido en
// cada mes. Los datos que se ingresan por cada compra son: código de de la escuela (entre 1 y 10), dia, mes, año y
// el monto, pudiendo haber más de una compra mensual para la misma escuela. Los datos finalizan con el código
// de escuela igual a 0. Luego, se desea obtener e informar: a) Al finalizar el año, ¿cuánto dinero le sobró a cada
// escuela? b) ¿Cuántas escuelas gastaron todo el dinero en el mes de febrero? c) ¿Cuál fue la escuela que menos
// gastó en octubre?

#include<iostream>
#include "matrix"

using namespace std;

int main(){

	int monto_fijo = 100000;
	matrix<int> montos(10, 12);

	int cod_escuela, monto, dia, mes, anio;

	cout << "Ingrese codigo de la escuela: "; cin >> cod_escuela;

	while (cod_escuela != 0)
	{
		cout << "Ingrese el monto " << endl; cin >> monto;
		cout << "Ingrese la fecha: " << endl;
		cout << "Dia: " << endl; cin >> dia;
		cout << "Mes: " << endl; cin >> mes;
		cout << "Anio: " << endl; cin >> anio;

		montos[cod_escuela][mes] += monto;

		cout << "Ingrese codigo de la escuela: "; cin >> cod_escuela;
	}

	
	for (size_t i = 0; i < montos.size(0); i++)
	{
		int sumaTotal = 0;
		for (size_t j = 0; j < montos.size(1); j++)
		{
			sumaTotal += montos[i][j];
		}
		int gasto = monto_fijo - sumaTotal;

		// a. lo que le quedo a la escuela a fin de curso
		cout << "La escuela " << i << " al finalizar el anio se quedo con " << "$ " << gasto << endl;
	}

	// b) ¿Cuántas escuelas gastaron todo el dinero en el mes de febrero?
	for (size_t j = 0; j < montos.size(1); j++)
	{
		int sumaFeb = 0;
		
		sumaFeb += montos[j][1];	
		if( sumaFeb == monto_fijo ){
			cout << "La escuela " << j << " gasto todo el monto dado." << endl;
		}
	}
	
	//c) ¿Cuál fue la escuela que menos gastó en octubre?
	int menor = 999, pos_menor;
	for (size_t j = 0; j < montos.size(0); j++)
	{
		int sumaOct = 0;
		sumaOct += montos[j][9];

		if( menor > sumaOct ){
			menor = sumaOct;
			pos_menor = j;
		}			
	}

	cout << "La escuela que menos gasto fue la escuela " << pos_menor << " con un gasto de $" << menor << endl;
	

	return 0;
}