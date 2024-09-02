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

	void getMovieData(Movie*& movie) {

		int size = 1;

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

		Movie* temp = new Movie[size];

		for (int i = 0; i < size; i++) {
			temp[i] = movie[i];
		}

	}


};

class MovieRoom {
private:
	int number;
	int seat;
	float price;

public:
	MovieRoom() {
		number = 0;
		seat = 0;
		price = 0.0;
	}

	MovieRoom(int aNumber, int aSeats, float aPrice) {
		number = aNumber;
		seat = aSeats;
		price = aPrice;

	}

	void setNumber(int newNumber) {
		number = newNumber;
	}
	void setSeat(int newSeat) {
		seat = newSeat;
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

	int getSeat() {
		return seat;
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

class Client {
private:
	string name;
	string surnames;
	string userId;
	string cardNumber;

public:
	Client() {

		userId = " ";
		cardNumber = " ";
		name = " ";
		surnames = " ";
	}

	Client(string newId, string newCardNumber, string newName, string newSurnames) {

		userId = newId;
		cardNumber = newCardNumber;
		name = newName;
		surnames = newSurnames;
	}
	void setUserId(string anId) {
		userId = anId;
	}

	void setCardNumber(string aCardNumber) {
		cardNumber = aCardNumber;
	}
	void setName(string aName) {
		name = aName;
	}
	void setSurnames(string theSurnames) {
		surnames = theSurnames;
	}

	string getUserId() {
		return userId;
	}

	string getCardNumber() {
		return cardNumber;
	}
	string getName() {
		return name;
	}
	string setSurnames() {
		return surnames;
	}

};

class Menu {
	int choice;

public:

	int validateChoice() {

		cout << "Seleccione una opcion: ";
		cout << endl;

		if (cin >> choice) {
			return choice;
		}
		cout << "Debe ingresar un numero. " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void showAbout() {

		cout << "Programa: NUEVA CINEMA SA - Sistema de Venta de Tickets" << endl;
		cout << "Autor: Cristhian Cordero Varela" << endl;
		cout << "            Versiones:" << endl;
		cout << "1.0 - Version inicial con gestion de peliculas y salas" << endl;
		cout << "1.2 - Correcciones en la validacion de entradas de usuario" << endl;
		cout << "1.3 - Mejora en la gestion de horarios y ventas" << endl;
		cout << "1.5 - Correccion de errores menores" << endl;
		cout << endl;

	}

	void showPrincipalMenu() {
		cout << "   Menu Principal:" << endl;
		cout << "   1. Reserva" << endl;
		cout << "   2. Venta" << endl;
		cout << "   3. Mantenimiento" << endl;
		cout << "   4. Archivo " << endl;
		cout << endl;

	}

	void showReserveMenu() {
		cout << endl << "***Aca se estableceran las funciones de Reserva***" << endl;
		cout << endl;
		cout << "1. Volver al Menu Principal" << endl;
		cout << endl;
	}

	void showSalesMenu() {
		cout << "1. Realizar pago " << endl;
		cout << "2. Volver al Menu Principal" << endl;
		cout << endl;
	}

	void showMaintenanceMenu() {
		cout << "   Menu de Mantenimiento:" << endl;
		cout << "   1. Modificar Peliculas" << endl;
		cout << "   2. Modificar Salas" << endl;
		cout << "   3. Modificar Horarios" << endl;
		cout << "   4. Volver al Menu Principal" << endl;
		cout << endl;
	}

	void showFileMenu() {
		cout << "   Menu de Archivo:" << endl;
		cout << "   1. Acerca de" << endl;
		cout << "   2. Volver al Menu Principal" << endl;
		cout << "   3. Salir." << endl;
		cout << endl;
	}

	void handleMaintenanceMenu() {

		do {
			showMaintenanceMenu();
			choice = validateChoice();
			if (choice == 1) {
				cout << "Se realizo GESTION de PELICULAS" << endl;
				continue;
			}
			if (choice == 2) {
				cout << "Se realizo GESTION de SALAS" << endl;
				cout << endl;
				continue;
			}
			if (choice == 3) {
				cout << "Se realizo GESTION de HORARIOS" << endl;
				cout << endl;
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

			showReserveMenu();
			choice = validateChoice();

			if (choice == 1) {
				return;
			}
			cout << "Entrada invalida.";
		} while (true);


	}

	void handleSalesMenu() {

		do {
			showSalesMenu();
			choice = validateChoice();

			if (choice == 1) {
				cout << "Pago realizado." << endl;
				continue;
			}
			if (choice == 2) {
				return;
			}

		} while (true);
	}

	void handleFileMenu(bool* leaving) {

		do {
			showFileMenu();
			choice = validateChoice();

			if (choice == 1) {
				showAbout();
				continue;
			}
			if (choice == 2) {
				return;
			}
			if (choice == 3) {
				cout << "Saliendo del programa.." << endl;
				*leaving = true;
				break;
			}
		} while (true);
	}

	void executeMenu() {
		bool leaving = false;
		do {

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
				handleFileMenu(&leaving);
				if (leaving) {
					break;
				}
				continue;
			}
			cout << "Entrada invalida.";
		} while (true);
	}

};

int main()
{
	Menu menu;
	menu.executeMenu();
	return 0;

}

