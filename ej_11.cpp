// Ejercicio 2 (35 pts). Una empresa que comercializa jugos en caja, tiene 15 vendedores quienes que levantan
// pedidos de clientes durante el mes de junio (30 días). Por cada pedido, se ingresan sin orden alguno las ternas
// correspondientes al código del vendedor (1 a 15), el dia (1...30) y la cantidad de cajas de jugo encargadas,
// pudiendo haber más de un pedido diario del mismo vendedor. Los datos finalizan con el código de vendedor
// igual a 0. Luego, se desea obtener e informar:
//  a) ¿Cuál es el código de vendedor que más pedidos hizo para el día 10?
//  b) ¿Cuál es la cantidad vendida por día considerando todos los vendedores?
 
#include<iostream>
#include "matrix"
using namespace std;

int main(){

	matrix<int> pedidos(15, 30, 0);

	int cod_vendedor, dia, cant_jugos;

	cout << "Ingrese el cod del vendedor (1 al 15) " << endl; cin >> cod_vendedor;

	while (cod_vendedor != 0)
	{
		cout << "Ingrese el dia (1 al 30) " << endl; cin >> dia;
		cout << "Cantidad de cajas de jugo encargadas" << endl; cin >> cant_jugos;

		pedidos[cod_vendedor][dia] += cant_jugos;

		cout << "Ingrese el cod del vendedor (1 al 15) " << endl; cin >> cod_vendedor;
	}
	
	// a) ¿Cuál es el código de vendedor que más pedidos hizo para el día 10?
	int mayor = 0;
	for (size_t i = 0; i < pedidos.size(0); i++)
	{
		if( pedidos[i][10] > mayor ){
			mayor = i;
		}
	}

	cout << "El vendedor que mas vendio en el dia 10 fue el vendedor " << mayor << endl;
		
	// b) ¿Cuál es la cantidad vendida por día considerando todos los vendedores?
	for (size_t j = 0; j < pedidos.size(1); j++)
	{
		int suma_por_dia = 0;
		for (size_t i = 0; i < pedidos.size(0); i++)
		{
			suma_por_dia += pedidos[i][j];
		}
		
		cout << "La cantidad vendida en el dia " << j << " fueron " << suma_por_dia << endl;
	}
	

	// c) ¿Cuántas cajas vendió en total el vendedor 10?
	int cant_vendedor10;
	for (size_t i = 0; i < pedidos.size(1); i++)
	{
		cant_vendedor10 += pedidos[10][i];
	}

	cout << "El vendedor 10 vendio un total de " << cant_vendedor10 << " cajas";
	

	return 0;
}