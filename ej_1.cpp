// Un struct definido como struct Evento { string tipo; int jugador; }; representa un evento
// ocurrido en un partido de tenis. tipo puede ser “ace”, “error no forzado”, “tiro ganador”, “doble falta”, y
// ”quiebre”. jugador puede ser 1 o 2. a) Escriba una función llamada resumen_partido que reciba un
// arreglo/vector de structs de tipo Evento y un número de jugador, y retorne la cantidad de eventos de cada tipo
// para ese jugador. b) Escriba un programa cliente que permita ingresar todos los eventos de un partido durante el
// mismo (sin conocer previamente la cantidad de eventos), y luego muestre en pantalla el resumen de cada
// jugador.

#include<iostream>
#include<vector>

using namespace std;

struct Tipo{
	int cant_ace, cant_error_no_forzado, cant_tiro_ganador, cant_doble_falta, cant_quiebre;
};

struct Evento{
	string tipo;
	int jugador;
};

// vector<Tipo> resumen_partido(vector<Evento> &arr_eventos, int num_jugador);
Evento completar_evento(Evento ev);
void mostrar_eventos(vector<Evento> &arr_eventos);

int main(){

	vector<Evento> eventos;

	

	//mostrar_eventos(eventos);

	return 0;
}



Evento completar_evento(Evento ev){
	cout << "Ingrese el tipo" << endl;
	getline(cin, ev.tipo);
	
	cout << "Ingrese el jugador" << endl;
	cin >> ev.jugador;

	cin.ignore();


	return ev;

}

void mostrar_eventos(vector<Evento> &arr_eventos){
	for (Evento el : arr_eventos)
	{
		cout << "El jugador " << el.jugador << endl;
	}
	
}

// vector<Tipo> resumen_partido(vector<Evento> &arr_eventos, int num_jugador){

// }


/**
 * 
 * 
 * #include <iostream>
#include <vector>
#include <tuple>
using namespace std;
struct Evento { 
	string tipo; 
	int jugador; 
};
tuple<int,int,int,int,int>resumen_partido(vector<Evento>juego,int jug);
int main() {
	
	int N;
	cout<<"Ingrese cantidad de eventos: "; cin>>N;
	vector<Evento>juego(N);
	
	for(size_t i=0;i<juego.size();i++) { 
		cout<<"Ingrese jugador:"; cin>>juego[i].jugador;
		cout<<"Ingrese tipo de evento:"; cin>>juego[i].tipo;
	}
	
	int ace,error_no_forzado,tiro_ganador,doble_falta,quiebre,jugador;
	
	cout<<"Ingrese jugador que desea ver resumen:"; cin>>jugador;
	tie(ace,error_no_forzado,tiro_ganador,doble_falta,quiebre) = resumen_partido(juego,jugador-1);
	
	cout<<"Resumen del jugador "<<jugador<<":"<<endl;
	cout<<"ACE: "<<ace<<endl;
	cout<<"ERROR NO FORZADO: "<<error_no_forzado<<endl;
	cout<<"TIRO GANADOR: "<<tiro_ganador<<endl;
	cout<<"DOBLE FALTA: "<<doble_falta<<endl;
	cout<<"QUIEBRE: "<<quiebre<<endl;
	
	
	
	return 0;
}

tuple<int,int,int,int,int>resumen_partido(vector<Evento>juego,int jug){
	int ace =0, error =0, tiro=0, doble =0, quiebre = 0;
	for(size_t i=0;i<juego.size();i++) { 
		if(juego[jug].tipo == "ace")
			ace++;
		if(juego[jug].tipo == "error no forzado")
			error++;
		if(juego[jug].tipo == "tiro ganador")
			tiro++;
		if(juego[i].tipo == "doble falta")
			doble++;
		if(juego[i].tipo == "quiebre")
			quiebre++;
	}
	
	
	return make_tuple(ace,error,tiro,doble,quiebre);
}
*/