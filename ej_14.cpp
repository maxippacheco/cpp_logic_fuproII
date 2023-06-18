//  	Ejercicio 3 [30 pts] Se desea seleccionar dos alumnos de una lista de 30 candidatos para una pasantía. Escriba
//    un programa que permita ingresar los datos de los 30 alumnos, los guarde en un vector de structs, y obtenga
//    mediante una función los los apellidos y nombres de los dos mejores. Por cada alumno se ingresa apellido y
//    nombre, promedio, cantidad de materias aprobadas, y cantidad de aplazos. Defina un struct para agrupar estos
//    datos. Para esta pasantía se considera a un alumno mejor que otro si tiene mayor cantidad de materias aprobadas.
//    En caso de empate, se considera mejor a quien tenga menor cantidad de aplazos. Si nuevamente hay empate
//    (igual cantidad de materias aprobadas y de aplazos), a quien tenga mejor promedio.


#include<iostream>
#include<vector>

using namespace std;

struct Candidatos{
	string apellido, nombre;
	float promedio;
	int cantidad_aprobadas, cantidad_aplazos;
};

int main(){

	int n = 2;
	vector<Candidatos> pasantia(n);

	// cargar ternas
	for (size_t i = 0; i < pasantia.size(); i++)
	{
		cout << "Ingrese el nombre: " << endl;
		cin >> pasantia[i].nombre;
		cout << "Ingrese el apellido: " << endl;
		cin >> pasantia[i].apellido;
		cout << "Ingrese el promedio: " << endl;
		cin >> pasantia[i].promedio;
		cout << "Ingrese el c aprobadas: " << endl;
		cin >> pasantia[i].cantidad_aprobadas;
		cout << "Ingrese el c aplazos: " << endl;
		cin >> pasantia[i].cantidad_aplazos;
	}

	Candidatos mejor_candidato = pasantia[pasantia.size() - 1];

	int i = 0;
	while ( pasantia.size() > i )
	{
		if(pasantia[i].cantidad_aprobadas > mejor_candidato.cantidad_aprobadas){
			mejor_candidato = pasantia[i];
		}else if( pasantia[i].cantidad_aprobadas == mejor_candidato.cantidad_aprobadas ){
			
			if(mejor_candidato.cantidad_aplazos > pasantia[i].cantidad_aplazos){
				mejor_candidato = pasantia[i];	
			}else if( pasantia[i].cantidad_aplazos == mejor_candidato.cantidad_aplazos && pasantia[i].promedio > mejor_candidato.promedio ){
				mejor_candidato = pasantia[i];
			}
		}

		i++;
	}
	
	cout << "El mejor candidato es: " << mejor_candidato.nombre << " " << mejor_candidato.apellido << endl;
	cout << "Con un promedio de: " << mejor_candidato.promedio << endl;
	cout << "Un total de " << mejor_candidato.cantidad_aprobadas << " materias aprobadas." << endl;
	cout << "Y un total de " << mejor_candidato.cantidad_aplazos << " materias aplazadas." << endl;

	return 0;
}