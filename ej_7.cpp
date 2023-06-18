// Ejercicio 1 (25 pts) Un triatleta, preparándose para una competencia importante, ha entrenado durante varias
// semanas en el mismo circuito donde se realizará dicha competencia y registrado en cada entrenamiento sus
// tiempos para cada uno de los tres tramos (natación, ciclismo, pedestrismo). a) Escriba un programa que permita
// ingresar N grupos de 7 datos de datos conformados por la fecha (como un solo número aaaammdd) y los tres
// tiempos (cada tiempo será ingresado mediante dos números: minutos y segundos). El programa luego deberá
// informar: b) por cada disciplina, el mejor (menor) tiempo logrado y la fecha del mismo; c) el promedio de los
// tiempos totales (sumando las tres disciplinas); y d) los dos mejores tiempos totales y las fecha en que se
// realizaron.


#include<iostream>
#include<vector>
using namespace std;

struct Tramo{
	int tiempo;
	int fecha;
};

struct Competencia{
	vector<Tramo> tramos;
};


int main(){

	int n; cin >> n;

	vector<Competencia> competidores(n);

	// a. cargar ternas
	for (size_t i = 0; i < competidores.size(); i++)
	{
		competidores[i].tramos.resize(3);

		for (size_t j = 0; j < competidores[i].tramos.size(); j++)
		{
			int minutos, seg;

			cout << "Competencia " << j + 1 << endl;
			cout << "Minutos " << endl; cin >> minutos;
			cout << "Segundos " << endl; cin >> seg;
			
			cout << "Fecha: " << endl; cin >> competidores[i].tramos[j].fecha;

			competidores[i].tramos[j].tiempo = minutos * 60 + seg;
		}
	}

	// b. por cada disciplina, el mejor (menor) tiempo logrado y la fecha del mismo	
	for (size_t i = 0; i < competidores.size(); i++)
	{
	}
	

	return 0;
}