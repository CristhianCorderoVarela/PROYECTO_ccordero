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

	Movie(string aName, int aYear, float aDuration, string aCountry, string aReview, float aPrice) {
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

};

class MovieRoom {
private:
	int number;
	int seat = 120;
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
	string day;
	int hour;
	int minutes;
public:
	Schedule() {
		day = "";
		hour = 0;
		minutes = 0;
	}
	Schedule(string aDay, int aHour, int aMinutes) {
		day = aDay;
		hour = aHour;
		minutes = aMinutes;
	}

	void setDay(string newDay) {
		day = newDay;
	}

	void setHour(int newHour) {
		hour = newHour;
	}

	void setMinutes(int newMinutes) {
		minutes = newMinutes;
	}

	string getDay() {
		return day;
	}

	int getHour() {
		return hour;
	}

	int getMinutes() {
		return minutes;
	}
};

class Client {
private:
	string name;
	string lastName;
	string userId;
	string cardNumber;
	string cvcNumber;

public:
	Client() {

		userId = "";
		cardNumber = "";
		name = "";
		lastName = "";
		cvcNumber = "";
	}

	Client(string newId, string newCardNumber, string newName, string newSurnames, string newCvcNumber) {

		userId = newId;
		cardNumber = newCardNumber;
		name = newName;
		lastName = newSurnames;
		cvcNumber = newCvcNumber;
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
	void setLastname(string aLastName) {
		lastName = aLastName;
	}
	string getName() {
		return name;
	}
	string getLastName() {
		return lastName;
	}

};

class Reservation {
private:
	Movie movie;
	MovieRoom movieRoom;
	Schedule schedule;
	int consecutive;

public:
	Reservation() {
		consecutive = 0;
	}

	Reservation(int aConsecutive) {
		consecutive = aConsecutive;
	}

	int getConsecutive() {
		return consecutive;
	}
};

class MenuBase {
protected:
	int choice = 0;

	int validateChoice() {
		cout << "Seleccione una opcion: " << endl;
		if (cin >> choice) {
			return choice;
		}
		cout << "Debe ingresar un numero. " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return 0;
	}

public:
	virtual void showMenu() = 0; // Método virtual puro para mostrar el menú
};

class PrincipalMenu : public MenuBase {
public:
	void showMenu() override {
		cout << "   Menu Principal:" << endl;
		cout << "   1. Reserva" << endl;
		cout << "   2. Venta" << endl;
		cout << "   3. Mantenimiento" << endl;
		cout << "   4. Archivo " << endl;
		cout << endl;
	}

	int handleMenu() {
		showMenu();
		return validateChoice();
	}
};

class ReserveMenu : public MenuBase {
public:
	void showMenu() override {
		cout << endl << "***Aca se estableceran las funciones de Reserva***" << endl;
		cout << endl;
		cout << "1. Volver al Menu Principal" << endl;
		cout << endl;
	}

	void handleMenu() {
		while (true) {
			showMenu();
			choice = validateChoice();
			if (choice == 1) {
				return;
			}
			cout << endl << "Entrada invalida." << endl << endl;
		}
	}
};

class SalesMenu : public MenuBase {
public:
	void showMenu() override {
		cout << "1. Realizar pago " << endl;
		cout << "2. Volver al Menu Principal" << endl;
		cout << endl;
	}

	void handleMenu() {
		while (true) {
			showMenu();
			choice = validateChoice();
			if (choice == 1) {
				cout << "Pago realizado." << endl;
				continue;
			}
			if (choice == 2) {
				return;
			}
			cout << endl << "Entrada invalida." << endl << endl;
		}
	}
};

class MaintenanceMenu : public MenuBase {
	Movie movies[10];
	int movieCount = 0;

public:
	void showMenu() override {
		cout << "   Menu de Mantenimiento:" << endl;
		cout << "   1. Modificar Peliculas" << endl;
		cout << "   2. Modificar Salas" << endl;
		cout << "   3. Modificar Horarios" << endl;
		cout << "   4. Volver al Menu Principal" << endl;
		cout << endl;
	}

	void addMultipleMovies() {
		int count;
		cout << "Cuantas peliculas desea agregar? " << endl;
		cin >> count;
		cin.ignore();

		for (int i = 0; i < count; ++i) {
			if (movieCount >= 10) {
				cout << "No se pueden agregar más películas. El límite ha sido alcanzado." << endl;
				return;
			}
			cout << "Agregando pelicula " << (i + 1) << ":" << endl;
			saveMovie();
		}
	}

	void saveMovie() {
		string name, country, review;
		int year;
		float duration;

		cout << "Ingrese el nombre de la pelicula:" << endl;
		cin.ignore();
		getline(cin, name);

		cout << "Ingrese el anio de publicacion:" << endl;
		cin >> year;

		cout << "Ingrese la duracion (en minutos):" << endl;
		cin >> duration;
		cin.ignore();

		cout << "Ingrese el pais de origen:" << endl;
		getline(cin, country);

		cout << "Ingrese la sinopsis:" << endl;
		getline(cin, review);

		Movie tempMovie;
		tempMovie.setName(name);
		tempMovie.setYear(year);
		tempMovie.setDuration(duration);
		tempMovie.setCountry(country);
		tempMovie.setReview(review);

		movies[movieCount++] = tempMovie;
		cout << "Pelicula guardada con exito." << endl;
	}

	void handleMenu() {
		while (true) {
			showMenu();
			choice = validateChoice();
			if (choice == 1) {
				addMultipleMovies();
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
			cout << endl << "Entrada invalida." << endl << endl;
		}
	}
};

class FileMenu : public MenuBase {
public:
	void showMenu() override {
		cout << "   Menu de Archivo:" << endl;
		cout << "   1. Acerca de" << endl;
		cout << "   2. Volver al Menu Principal" << endl;
		cout << "   3. Salir." << endl;
		cout << endl;
	}

	void showAbout() {
		cout << endl;
		cout << "Programa: NUEVA CINEMA SA - Sistema de Venta de Tickets" << endl;
		cout << "Autor: Cristhian Cordero Varela" << endl;
		cout << "            Versiones:" << endl;
		cout << "1.0 - Version inicial con gestion de peliculas y salas" << endl;
		cout << "1.2 - Correcciones en la validacion de entradas de usuario" << endl;
		cout << "1.3 - Mejora en la gestion de horarios y ventas" << endl;
		cout << "1.5 - Correccion de errores menores" << endl;
		cout << endl;
	}

	void handleMenu(bool* leaving) {
		while (true) {
			showMenu();
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
			cout << endl << "Entrada invalida." << endl << endl;
		}
	}
};

class MenuManager {
	PrincipalMenu principalMenu;
	ReserveMenu reserveMenu;
	SalesMenu salesMenu;
	MaintenanceMenu maintenanceMenu;
	FileMenu fileMenu;

public:
	void executeMenu() {
		bool leaving = false;
		while (true) {
			int choice = principalMenu.handleMenu();
			if (choice == 1) {
				reserveMenu.handleMenu();
				continue;
			}
			if (choice == 2) {
				salesMenu.handleMenu();
				continue;
			}
			if (choice == 3) {
				maintenanceMenu.handleMenu();
				continue;
			}
			if (choice == 4) {
				fileMenu.handleMenu(&leaving);
				if (leaving) {
					break;
				}
				continue;
			}
			cout << "Entrada invalida." << endl;
		}
	}
};

int main() {
	MenuManager menuManager;
	menuManager.executeMenu();

	return 0;
}
