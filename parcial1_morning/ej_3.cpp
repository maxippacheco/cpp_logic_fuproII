
#include<iostream>
#include "matrix"
using namespace std;

int main(){

	int n; cin >> n;

	matrix<string> materia(4, n);

	// a. cargar ternas
	int cod_alumno, nro_evaluacion;
	string docente;

	cin >> cod_alumno;
	while (cod_alumno != -1)
	{
		cin >> nro_evaluacion;
		cin.ignore();
		getline(cin, docente);

		materia[nro_evaluacion][cod_alumno] = docente;

		cin >> cod_alumno;
	}

	// cuantos alumnos rindieron cada evaluacion
	for (size_t i = 0; i < materia.size(0); i++)
	{
		int suma_por_ev = 0;
		for (size_t j = 0; j < materia.size(1); j++)
		{
			if( materia[i][j] != "No rindio"){
				++suma_por_ev;
			}
		}

		cout << "En la instancia " << i << " rindieron " << suma_por_ev << " alumnos" << endl;
	}

	int cant_alumnos = 0;
	for (size_t i = 0; i < materia.size(0); i++)
	{
		int suma_por_ev = 0;
		for (size_t j = 0; j < materia.size(1); j++)
		{
			if( materia[i][j] == "No rindio"){
				++suma_por_ev;
			}
		}

		if(suma_por_ev == 4){
			++cant_alumnos;
			cout << "El alumno " << i << " no rindio ninguna instancia." << endl;
		}
	}

	cout << cant_alumnos << " alumnos no rindieron ninguna instancia.";
	
	cin.ignore();
	
	string docente_buscar;
	getline(cin, docente_buscar);

	int cant_docente = 0;
	for (size_t i = 0; i < materia.size(0); i++)
	{
		for (size_t j = 0; j < materia.size(1); j++)
		{
			if(materia[i][j] == docente_buscar){
				++cant_docente;
			}	
		}
		
	}

	cout << "El docente " << docente_buscar << " corrigio " << cant_docente << " examenes" << endl;
	
	

	return 0;
}




// //agregar
// for (size_t i = arr.size()-1; i > pos ; i--)
// {
// 	/* code */
// }


// //eliminar
// for (size_t i = pos; i < arrr.size()-1; i++)
// {
// 	/* code */
// }
