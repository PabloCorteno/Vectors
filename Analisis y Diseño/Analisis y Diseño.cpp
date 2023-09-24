// Analisis y Diseño.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct programa {
	string producto;
	int piezas;
	double precio;

};

vector<programa> productos;
int cantidad;

void daralta() {
	string producto;
	double precio;
	int piezas=0;
	string opcion = "";
	do {
		cout << "Introduzca el nombre del producto" << endl;
		getline(cin, producto);
		getline(cin, producto);
		programa MyVector;
		MyVector.producto = producto;
		cout << "Introduzca el precio del producto" << endl;
		cout << "$ ";
		cin >> precio;
		MyVector.precio = precio;
		cout << "Cual es la cantidad de articulos que desea agregar en almacen?" << endl;
		cin >> piezas;
		MyVector.piezas = piezas;
		productos.push_back(MyVector);
		cout << "Se ha almacenado " << MyVector.producto << " con precio de: $" << MyVector.precio << " y cantidad de: " << MyVector.piezas << " piezas correctamente" << endl;
		cout << "Desea agregar otro producto? " << endl;
		cin >> opcion;
		system("cls");
	} while (opcion != "no");
}

void adminventario() {
	string producto;
	double precio;
	string enter;
	for (programa i : productos)
	{
		cout << "-" << "Producto: " << i.producto << ", Precio: $" << i.precio << ", cantidad en almacen: " << i.piezas << endl;

		if (i.piezas <= 5 && i.piezas > 0)
		{
			cout << "La cantidad de " << i.producto << " en almacen es baja" << endl;
		}
		else if (i.piezas == 0)
		{
			cout << "El producto ya no cuenta con piezas en el almacen" << endl;
		}
		
	}
	cout << "Presione enter para salir." << endl;
	getline(cin, enter);
	getline(cin, enter);
	system("cls");

}

void agrinventario() {
	string comparador;
	int suma;
	int indice = 0;
	bool exists = false;
	cout << "Aqui tiene una lista de sus productos registrados: " << endl;
	for (programa i : productos)
	{
		cout << "- " << i.producto << endl;

	}
	cout << "Ingrese el producto al cual desea agregar inventario en almacen: " << endl;
	getline(cin, comparador);
	getline(cin, comparador);
	for (programa i : productos)
	{
		indice++;
		if (comparador == i.producto)
		{
			cout << "Ingrese la cantidad de piezas que desea agregar: " << endl;
			cin >> suma;
			productos.at(indice - 1).piezas += suma;
			exists = true;
			cout << "Cantidad agregada con exito" << endl;
			break;
		}
	}
	if (!exists) {
		cout << "No existe el producto" << endl;
	}
}

void venta() {
	string venta;
	bool exists = false;
	int resta;
	int indice = 0;
	double multiplicacion;
	cout << "Introduzca el nombre del producto el cual va a realizar una venta " << endl;
	getline(cin, venta);
	getline(cin, venta);
	for (programa i : productos) {
		indice++;
		if (venta == i.producto) {
			
			cout << "Introduzca la cantidad que desea vender" << endl;
			cin >> resta;
			productos.at(indice - 1  ).piezas -= resta;
			multiplicacion = resta * productos.at(indice - 1 ).precio;
			cout << "Usted realizo una venta de "<< i.producto << " por la cantidad de: $"<< multiplicacion << " exitosamente!" << endl;
			exists = true;
			break;
			
		}
		
	}
	
	if (!exists) {
		cout << "El producto que ingreso no se encontro en el almacen." << endl;
	}
}



int main() {
	int opcion;
	do {
		cout << "1. Registrar Producto" << endl;
		cout << "2. Mostrar Almacen" << endl;
		cout << "3. Ingresar Articulos al Almacen" << endl;
		cout << "4. Realizar Venta" << endl;
		cout << "5. Salir" << endl;
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
			adminventario();
			
			
			break;
		case 3:
			system("cls");
			agrinventario();
			
			break;
		case 4:
			system("cls");
			venta();
			
			
			break;

		case 5:
			cout << "Hasta luego" << endl;
			break;
		default:
			cout << "Opcion incorrecta. Intente de nuevo" << endl;
			break;
		}

	} while (opcion != 5);
	
}