#pragma once

#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;
class Cliente : public Persona{
	// atributos
private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel,string fn, string n) : Persona(nom, ape, dir, tel,fn) {
		nit = n;
	}

	// METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	

	// metodo

	void updat(int id_aux2) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string id2 = to_string(id_aux2);
			string t = to_string(telefono);
			string update;
			cout << "---------------------------------------------------" << endl;

			update = "UPDATE clientes SET nit='" + nit + "', nombres='" + nombres + "', apellidos='" + apellidos + "', direccion='" + direccion + "', telefono=" + t + ", fecha_nacimiento='" + fecha_nacimiento + "'  WHERE id_clientes =" + id2 + " ";
			string query = update.c_str();
			const char* q = query.c_str();
			q_estado = mysql_query(cn.getConectar(), q);
			if (!q_estado)
			{
				cout << "actualizado. . ." << endl;
			}
			else
			{
				cout << "error en la actualizacion. . ." << endl;
			}



		}
		else {
			cout << "error en la conexion" << endl;
		}
		cn.cerrar_conexion();


	}


	void dele(int id_aux) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
	
		cn.abrir_conexion();

		


		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;
			
			string id1 = to_string(id_aux);
			string ss;
			cout << "---------------------------------------------------" << endl;
			
				ss = "DELETE FROM clientes WHERE id_clientes= " +id1+ " ";
				string query = ss.c_str();
				const char* q = query.c_str();
				q_estado = mysql_query(cn.getConectar(), q);
				if (!q_estado)
				{
					cout << "REGISTRO ELIMINADO. . ." << endl;
				}
				else
				{
					cout << "ERROR. . ." << endl;
				}

		

		}
		else {
			cout << "error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}



	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES('"+nit+"','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				cout << "ingreso exitoso...." << endl;
			}
			else {
				cout << "error al ingresar..." << endl;
			}


		}
		else {
			cout << "error en la conexion" << endl;


		}
		cn.cerrar_conexion();


	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1]<< "," << fila[2] << "," << fila[3]<< "," << fila[4]<< "," << fila[5] << "," << fila[6] << endl;


				}
			}

			else {
				cout << " xxx Error al ingresar informacion xxxx" << endl;
			}
		
		}
		else{
			cout << "error en la conexion" << endl;


		}
		cn.cerrar_conexion();

	}
};

