// Ejercicio 3 (25 pts) Se desea determinar cuáles fueron los dos delanteros más efectivos de la copa América.
// Escriba un programa para resolver este problema de la siguiente forma: a) El programa debe permitir ingresar
// por cada delantero seis datos: apellido nombres, cantidad de minutos jugados (MJ), goles convertidos (GC), tiros
// al arco (TA), tiros desviados (TD) y pases de gol realizados (PG). La carga de datos finaliza cuando el apellido
// se deja en blanco (cuando se presiona enter sin ingresar nada). b) El programa debe calcular, para cada delantero,
// un coeficiente de efectividad que se obtiene como (2*GC+PG)/MJ, y otro para la mala puntería denominado
// badaiming que se obtiene como la división entre los tiros desviados (TD) y el total de tiros efectuados al arco
// (TA). c) Finalmente, debe informar los apellidos de los dos delanteros con mayores valores de efectividad. Si
// hay dos delanteros con la misma efectividad, se considera mejor al que tenga un menor índice de badaiming

#include<iostream>
using namespace std;

struct Delantero{
	string nombre_completo;
	int cant_min_jugados, tiros_arco, tiros_desviados, pase_gol;
	float efectividad;
	float mala_punteria;
};

int main(){

	

	return 0;
}