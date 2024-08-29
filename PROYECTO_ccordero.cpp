#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
	string name;
	int year;
	float duration;
	string country;
	string review;


public:
	Movie() {
		name = "";
		year = 0;
		duration = 0.0;
		country = "";
		review = "";
	}

	Movie(string aName, int aYear, float aDuration, string aCountry, string aReview) {
		name = aName;
		year = aYear;
		duration = aDuration;
		country = aCountry;
		review = aReview;
	}

	void setName(string newName) {
		name = newName;
	}

	void setYear(int newYear) {
		year = newYear;
	}

	void setDuration(float newDuration) {
		duration = newDuration;
	}

	void setCountry(string newCountry) {
		country = newCountry;
	}

	void setReview(string newReview) {
		review = newReview;
	}
	string getName() {
		return name;
	}

	int getYear() {
		return year;
	}
	float getDuration() {
		return duration;
	}

	string getCountry() {
		return country;
	}

	string getReview() {
		return review;
	}

	void getMovieData() {

		cout << "Ingrese el nombre de la pelicula:" << endl;
		getline(cin, name);
		cout << "Ingrese el anio de publicacion:" << endl;
		cin >> year;
		cout << "Ingrese la duracion (en minutos):" << endl;
		cin >> duration;
		cout << "Ingrese el pais de origen:" << endl;
		getline(cin, country);
		cout << "Ingrese la sinapsis:" << endl;
		getline(cin, review);
	}

};

class MovieRoom {
private:
	int number;
	int seats;
	float price;

public:
	MovieRoom() {
		number = 0;
		seats = 0;
		price = 0.0;
	}

	MovieRoom(int aNumber, int aSeats, float aPrice) {
		number = aNumber;
		seats = aSeats;
		price = aPrice;

	}

	void setNumber(int newNumber) {
		number = newNumber;
	}

	void setPrice(float newPrice) {
		price = newPrice;
	}

	int getNumber() {
		return number;
	}

	float getPrice() {
		return price;
	}

};

class Schedule {
private:
	string date;
	string startTime;
	string endTime;
public:
	Schedule() {
		date = " ";
		startTime = " ";
		endTime = " ";
	}
	Schedule(string aDate, string aStartTime, string aEndTime) {
		date = aDate;
		startTime = aStartTime;
		endTime = aEndTime;
	}

	void setDate(string newDate) {
		date = newDate;
	}

	void setStartTime(string newStartTime) {
		startTime = newStartTime;
	}

	void setEndTime(string newEndTime) {
		endTime = newEndTime;
	}

	string getDate() {
		return date;
	}
	string getStartTime() {
		return startTime;
	}

	string getEndTime() {
		return endTime;
	}
};

class Reservation {
private:
	Movie movie;
	MovieRoom movieRoom;
	Schedule schedule;
	string saleStatus;
	int consecutive;

public:
	Reservation() {
		saleStatus = "";
		consecutive = 0;
	}

	Reservation(string aSaleStatus, int aConsecutive) {
		saleStatus = aSaleStatus;
		consecutive = aConsecutive;
	}

	void setSaleStatus(string newSaleStatus) {
		saleStatus = newSaleStatus;
	}

	string getSaleStatus() {
		return saleStatus;
	}

	int getConsecutive() {
		return consecutive;
	}
};

class Menu {
private:
	

public:

	int validateChoice() {
		int choice;
		cout << "Seleccione una opcion: ";

		if (cin >> choice ) {
			return choice;
		}
		cout << "Debe ingresar un numero. ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void showAbout() {

		system("cls");
		cout << "Programa: NUEVA CINEMA SA - Sistema de Venta de Tickets"<<endl;
		cout << "Autor: Cristhian Cordero Varela"<<endl;
		cout << "Versiones:\n";
		cout << "1.0 - Version inicial con gestion de peliculas y salas"<<endl;
		cout << "1.2 - Correcciones en la validacion de entradas de usuario" << endl;
		cout << "1.3 - Mejora en la gestion de horarios y ventas" << endl;
		cout << "1.5 - C orrección de errores menores" << endl;
		system("pause");
		return;
	}

	void showPrincipalMenu() {

		cout << "   Menu Principal:" << endl;
		cout << "   1. Reserva" << endl;
		cout << "   2. Venta" << endl;
		cout << "   3. Mantenimiento" << endl;
		cout << "   4. Archivo " << endl;

	}

	void showReserveMenu() {

		cout << endl << "Aca se estableceran las funciones de Reserva" << endl;
		cout << endl;
		cout << "1. Volver al Menu Principal" << endl;
	}

	void showSalesMenu() {

		cout << "1. Realizar pago " << endl;
		cout << "2. Volver al Menu Principal" << endl;
	}

	void showMaintenanceMenu() {
		cout << "   Menu de Mantenimiento:" << endl;
		cout << "   1. Modificar Peliculas" << endl;
		cout << "   2. Modificar Salas" << endl;
		cout << "   3. Modificar Horarios" << endl;
		cout << "   4. Volver al Menu Principal" << endl;
	}

	void showFileMenu() {
		cout << "   Menu de Archivo:" << endl;
		cout << "   1. Acerca de" << endl;
		cout << "   2. Salir." << endl;
		cout << "   3. Volver al Menu Principal" << endl;
		cout << endl;
	}

	void handleMaintenanceMenu() {
		int choice;

		do {
			system("cls");
			showMaintenanceMenu();
			cout << "Seleccione una opcion valida: ";
			choice = validateChoice();
			if (choice == 1) {
				cout << "Se realizo GESTION de PELIS" << endl;
				system("pause");
				continue;
			}

			if (choice == 2) {
				cout << "Se realizo GESTION de SALAS" << endl;
				system("pause");
				continue;
			}

			if (choice == 3) {
				cout << "Se realizo GESTION de HORARIOS" << endl;
				system("pause");
				continue;
			}

			if (choice == 4) {
				return;
			}


		} while (true);
	}

	void handleReserveMenu() {

		int choice;

		do {
			system("cls");
			showReserveMenu();
			choice = validateChoice();


			if (choice == 1) {
				return;
			}
			cout << "Entrada invalida.";
		} while (true);


	}

	void handleSalesMenu() {
		int choice = 0;

		do {
			system("cls");
			showSalesMenu();
			choice = validateChoice();

			if (choice == 1) {
				cout << "Pago realizado." << endl;
				system("pause");
				break;
			}
			if (choice == 2) {
				return;
			}

		} while (true);
	}

	void handleFileMenu() {
		int choice = 0;

		do {
			system("cls");
			showFileMenu();
			choice = validateChoice();

			if (choice == 1) {
				showAbout();
				continue;
			}
			if (choice == 2) {
				cout << "Saliendo del programa.." << endl;
				exit(0);
				break;
			}
			if (choice == 3) {
				return;
			}

		} while (true);
	}

	void executeMenu() {

		int choice;
		do {
			system("cls");
			showPrincipalMenu();
			choice = validateChoice();
			if (choice == 1) {
				handleReserveMenu();
				continue;
			}

			if (choice == 2) {
				handleSalesMenu();
				continue;
			}

			if (choice == 3) {
				handleMaintenanceMenu();
				continue;
			}

			if (choice == 4) {
				handleFileMenu();
				continue;
			}
			cout << "Entrada invalida.";
		} while (true);
	}



};

int main()
{
	Menu menu;
	int choice;
	menu.executeMenu();
	return 0;

}

