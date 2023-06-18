// Ejercicio 1 (25pts) Escriba un programa en C++ que simule un sistema de control de acceso por contraseña de
// la siguiente manera: a) En una primer etapa debe permitir cargar los datos de los usuarios válidos (pares de
// datos: nombre y contraseña). No se conoce la cantidad de usuarios válidos y los datos terminan con el usuario
// “ZZZ”. En esta carga inicial, debe verificar mediante un función validar_contraseña que la contraseña no sea
// "1234", "asdf", "pass" ni la cadena vacía; mostrando un mensaje de error y solicitando el reingreso de la misma
// en estos casos. (nota: proponga usted el prototipo de la función e impleméntela). b) Luego, simular el verdadero
// intento de acceso al sistema. El programa debe mostrar el mensaje "Por favor, identifíquese:" y solicitar nombre
// y contraseña. Si se ingresa un par nombre+contraseña existente (que coincida con los cargados en el apartado a)
// se debe mostrar el mensaje "Bienvenido al sistema sr X" (reemplazando X por el nombre del usuario); sino,
// luego de 5 intentos fallidos debe mostrar el mensaje "Fuera bicho!"

#include<iostream>
#include<vector>
using namespace std;

struct Usuario {
	string nombre, password;
};

bool is_valid_password( string password );

int main(){

	vector<Usuario> usuarios;
	Usuario new_user;

	cout << "Ingrese el nombre del usuario " << endl; cin >> new_user.nombre;
	
	string password_to_valid;
	while (new_user.nombre != "ZZZ")
	{
		cout << "Ingrese su password: " << endl;
		cin >> password_to_valid;

		if( is_valid_password( password_to_valid ) ){
			new_user.password = password_to_valid;
			usuarios.push_back(new_user);
		}else{
			cout << "Por favor ingresela nuevamente: " << endl; cin >>password_to_valid;
		}

		cout << "Ingrese el nombre del usuario " << endl; cin >> new_user.nombre;
	}

	Usuario user_to_validate;


	cout << "Por favor, identifiquese: " << endl;
	cout << "Nombre: " << endl; cin >> user_to_validate.nombre;
	cout << "Password: " << endl; cin >> user_to_validate.password;
	
	int intentos_fallidos = 1;

	while (intentos_fallidos < 6 )
	{
	
		for (size_t i = 0; i < usuarios.size(); i++)
		{
			if( user_to_validate.nombre == usuarios[i].nombre && user_to_validate.password == usuarios[i].password ){
				cout << "Bienvenido al sistema sr " << user_to_validate.nombre << endl;
			}else{

				
				cout << "Intentos " << intentos_fallidos << endl;
				cout << "Intente nuevamente." << endl;
				cout << "Nombre: " << endl; cin >> user_to_validate.nombre;
				cout << "Password: " << endl; cin >> user_to_validate.password;


			}
			++intentos_fallidos;
		}
	
	}

	cout << "Fuera bicho! " << endl;
	
	

	

	return 0;
}

bool is_valid_password(string password){
	if( password == "1234" || password == "asdf" || password == "pass" || password == "" ) return false;
	
	return true;
}

