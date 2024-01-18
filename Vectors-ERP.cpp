#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct alumno {
	string matricula;
	string nombre;
	string apellidop;
	string apellidom;
	string carrera;
	string correo;
	string telefono;
};

vector<alumno> alumnos;
int cantidad;

void daralta() {
	string matricula;
	string nombre;
	string apellidop;
	string apellidom;
	string carrera;
	string correo;
	string telefono;
	string opcion = "";
	do {
		cout << "Introduzca la matricula del alumno" << endl;
		getline(cin, matricula);
		getline(cin, matricula);
		alumno newalumno;
		newalumno.matricula = matricula;
		cout << "Introduzca el nombre del alumno" << endl;
		getline(cin, nombre);
		newalumno.nombre = nombre;
		cout << "Introduzca el apellido paterno del alumno" << endl;
		getline(cin, apellidop);
		newalumno.apellidop = apellidop;
		cout << "Introduzca el apellido materno del alumno" << endl;
		getline(cin, apellidom);
		newalumno.apellidom = apellidom;
		cout << "Introduzca la carrera del alumno" << endl;
		getline(cin, carrera);
		newalumno.carrera = carrera;
		cout << "Introduzca el correo electronico del alumno" << endl;
		getline(cin, correo);
		newalumno.correo = correo;
		cout << "Introduzca el telefono del alumno" << endl;
		getline(cin, telefono);
		newalumno.telefono = telefono;
		alumnos.push_back(newalumno);
		cout << "Se ha almacenado correctamente el alumno. \nMatricula: " << newalumno.matricula
			<< "\nNombre: " << newalumno.nombre
			<< "\nApellido Paterno: " << newalumno.apellidop
			<< "\nApellido Materno: " << newalumno.apellidom
			<< "\nCarrera: " << newalumno.carrera
			<< "\nCorreo: " << newalumno.correo
			<< "\nTelefono: " << newalumno.telefono
			<< endl;
		cout << "Desea agregar otro alumno? " << endl;
		cin >> opcion;
		system("cls");
	} while (opcion != "no");
}

void mostrarTodos() {
	string enter;
	cout << "Alumnos registrados: \n";
	for (alumno i : alumnos)
	{
		cout << "-" << i.matricula << " | " << i.nombre << " | " << i.apellidop << " | " << i.apellidom << " | " << i.carrera << " | " << i.correo << " | " << i.telefono << endl;

	}
	cout << "Presione enter para salir." << endl;
	getline(cin, enter);
	getline(cin, enter);
	system("cls");

}

void modificarAlumno() {
	string comparador;
	int suma;
	int indice = 0;
	bool exists = false;
	cout << "aqui tiene una lista de sus alumnos registrados: " << endl;
	for (alumno i : alumnos)
	{
		cout << "- " << i.matricula << " " << i.nombre << endl;

	}
	cout << "ingrese la matrícula del alumno a modificar: " << endl;
	getline(cin, comparador);
	getline(cin, comparador);
	string modificacion;
	string nuevo;
	for (alumno i : alumnos)
	{
		indice++;
		if (comparador == i.matricula)
		{
			cout << "Que es lo que desea modificar ?" << endl;
			cin >> modificacion;
			if (modificacion == "matricula") {
				cout << "Introduzca la nueva matricula: ";
				cin >> nuevo;
				alumnos.at(indice - 1).matricula = nuevo;
				cout << "Se realizo el cambio correctamente" << endl;
			}
			if (modificacion == "nombre") {
				cout << "Introduzca el nuevo nombre: ";
				cin >> nuevo;
				alumnos.at(indice - 1).nombre = nuevo;
				cout << "Se realizo el cambio correctamente" << endl;
			}
			if (modificacion == "carrera") {
				cout << "Introduzca la nueva carrera: ";
				cin >> nuevo;
				alumnos.at(indice - 1).carrera = nuevo;
				cout << "Se realizo el cambio correctamente" << endl;
			}
			if (modificacion == "correo") {
				cout << "Introduzca el nuevo correo: ";
				cin >> nuevo;
				alumnos.at(indice - 1).correo = nuevo;
				cout << "Se realizo el cambio correctamente" << endl;
			}
			if (modificacion == "telefono") {
				cout << "Introduzca el nuevo telefono: ";
				cin >> nuevo;
				alumnos.at(indice - 1).telefono = nuevo;
				cout << "Se realizo el cambio correctamente" << endl;
			}


			exists = true;
			break;
		}
	}
	if (!exists) {
		cout << "no existe la matricula" << endl;
	}
}

void bajaestudiantes() {
	string baja;
	bool exists = false;
	int indice = 0;
	cout << "Introduzca la matrícula del alumno que desea dar de baja:" << endl;
	getline(cin, baja);
	getline(cin, baja);
	for (alumno i : alumnos) {
		indice++;
		if (baja == i.matricula) {
			cout << "Se dio de baja correctamente al siguiente alumno: \n"
				<< i.matricula << "\n"
				<< i.nombre << "\n"
				<< i.apellidop << "\n"
				<< i.apellidom << "\n"
				<< i.carrera << "\n"
				<< i.correo << "\n"
				<< i.telefono << endl;
			alumnos.erase(alumnos.begin() + (indice - 1));
			exists = true;
		}

	}

	if (!exists) {
		cout << "La matrícula que ingreso no existe." << endl;
	}
}

void buscarEstudiante() {
	string busqueda;
	bool exists = false;
	cout << "Ingrese la matricula del estudiante que desea buscar: ";
	getline(cin, busqueda);
	getline(cin, busqueda);
	for (alumno i : alumnos) {
		if (busqueda == i.matricula)
		{
			cout << "Matricula: " << i.matricula
				<< "\nNombre: " << i.nombre
				<< "\nApellido Paterno: " << i.apellidop
				<< "\nApellido Materno: " << i.apellidom
				<< "\nCarrera: " << i.carrera
				<< "\nCorreo: " << i.correo
				<< "\nTelefono: " << i.telefono
				<< endl;
			exists = true;
		}


	}
	if (!exists) {
		cout << "No se encontro la matrícula" << endl;
	}
}


int main() {
	int opcion;
	do {
		cout << "1. Alta de Estudiantes" << endl;
		cout << "2. Baja de Estudiantes" << endl;
		cout << "3. Modificaciones de estudiantes" << endl;
		cout << "4. Mostrar Todos" << endl;
		cout << "5. Buscar Estudiantes" << endl;
		cout << "6. Salir" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			daralta();
			system("cls");

			break;
		case 2:
			system("cls");
			bajaestudiantes();


			break;
		case 3:
			system("cls");
			modificarAlumno();

			break;
		case 4:
			system("cls");
			mostrarTodos();

			break;

		case 5:
			system("cls");
			buscarEstudiante();
			break;

		case 6:
			cout << "Hasta luego" << endl;
			break;

		default:
			cout << "Opcion incorrecta. Intente de nuevo" << endl;
			break;
		}

	} while (opcion != 6);

}