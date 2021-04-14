// orientada_a_obj.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//



#include <iostream>
#include <string>
#include "Cliente.h"
	using namespace std;
	int q_estado;
	int main(){
		string nit, nombres, apellidos, direccion, fecha_nacimiento;
		int telefono=0;
		int id_aux=0;
		int id_aux2 = 0;
		cout << "ingrese nit:" << endl;
		getline(cin, nit);
		cout << "ingrese sus nombres:" << endl;
		getline(cin, nombres);
		cout << "ingrese sus apellidos:" << endl;
		getline(cin, apellidos);
		cout << "ingrese direccion:" << endl;
		getline(cin, direccion);
		cout << "ingrese telefono" << endl;
		cin >> telefono;
		cin.ignore();
		cout << "ingrese su fecha de nacimiento" << endl;
		getline(cin, fecha_nacimiento);
		

		Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
		
		c.crear();
		c.leer();
		
		cout << "ingrese el id del registro a eliminar: "; cin >> id_aux;
		c.dele(id_aux);
		cout << "ingrese id del registro a modificar: "; cin >> id_aux2; cin.ignore();

		cout << "ingrese nit:" << endl;
		getline(cin, nit);
		cout << "ingrese sus nombres:" << endl;
		getline(cin, nombres);
		cout << "ingrese sus apellidos:" << endl;
		getline(cin, apellidos);
		cout << "ingrese direccion:" << endl;
		getline(cin, direccion);
		cout << "ingrese telefono" << endl;
		cin >> telefono;
		cin.ignore();
		cout << "ingrese su fecha de nacimiento" << endl;
		getline(cin, fecha_nacimiento);
		Cliente c1 = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
		c1.updat(id_aux2);

		

		system("pause");
		return 0;
	}


	
