// Ej. 1. (35 pts). Una empresa constructora lleva un registro del trabajo de sus 50 empleados. De cada empleado
// almacena nro. de empleado (1..50), nombre y apellido, CUIT y la fecha de nacimiento (AAAAMMDD). De los
// trabajos realizados durante 12 meses se desea llevar un registro del salario mensual que percibió cada empleado.
// Para esto primeramente se realiza la lectura de datos de los 50 empleados en forma desordenada. Posteriormente,
// para la carga de los salarios, se ingresa el número de empleado, el mes y el salario que percibió. Se le solicita
// que realice la lectura e implemente lo siguiente: a). Una función mejor_pago(), que retorne el nro. de empleado
// que recibió el mayor salario para un determinado mes que es leído por teclado y luego, lo muestre en pantalla
// desde el programa principal. b). Una función que reciba como argumento la fecha actual (AAAAMMDD) y
// devuelva al programa principal la cantidad de empleados mayores y menores a 50 años. c). Una función que
// retorne el mes donde se pagó menos dinero en salarios.


#include<iostream>
#include<vector>

using namespace std;

struct Salario{
	int mes, salario;
};

struct Empleado{
	string nombre, apellido;
	int cuit, fecha_nacimiento, numero_empleado;
	vector<Salario> salario;
};

Empleado mejor_pago(vector<Empleado> &arr, int mes);

int main(){

	vector<Empleado> empleados(49);

	for (size_t i = 0; i < empleados.size(); i++)
	{
		empleados[i].salario.resize(11);

		cout << "Ingrese nombre: " << endl; cin >> empleados[i].nombre;
		cout << "Ingrese apellido: " << endl; cin >> empleados[i].apellido;
		
		cout << "Ingrese CUIT: " << endl; cin >> empleados[i].cuit;
		cout << "Ingrese fehca de nacimiento (aaaammdd): " << endl; cin >> empleados[i].fecha_nacimiento;
		cout << "Ingrese numero de empleado: " << endl; cin >> empleados[i].numero_empleado;
		for (size_t j = 0; j < 12; j++)
		{
			int salario;
			cout << "Ingrese el salario de mes " << j + 1 << endl; 
			empleados[i].salario[j].mes = j + 1;
			cout << "Ingrese el salario: " << endl; cin >> salario;
			salario = empleados[i].salario[j].salario;
		}
		
	}

	return 0;
}

Empleado mejor_pago(vector<Empleado> &arr, int mes){

	int nro_empleado, mayor = 0;
	Empleado best_salario;

	for (size_t i = 0; i < arr.size(); i++)
	{
		if(arr[i].salario[mes].salario > mayor){
			mayor = arr[i].salario[mes].salario;
			best_salario = arr[i];
		}
	}
	
	return best_salario;

}