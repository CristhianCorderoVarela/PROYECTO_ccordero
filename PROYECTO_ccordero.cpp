#include <iostream>
#include <cstdlib> 
using namespace std;

const int numberOfSeats = 120;
int consecutive = 00000000;

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

public:
	Reservation() {
		saleStatus = " ";
	}

	Reservation(string aSaleStatus) {
		saleStatus = aSaleStatus;
	}

	void setSaleStatus(string newSaleStatus) {
		saleStatus = newSaleStatus;
	}

	string getSaleStatus() {
		return saleStatus;
	}
};

int getConsecutive() {
	return consecutive;
}

void showPrincipalMenu() {

	cout << "   Menu Principal:" << endl;
	cout << "   1. Reserva" << endl;
	cout << "   2. Venta" << endl;
	cout << "   3. Mantenimiento" << endl;
	cout << "   4. Acerca de " << endl;
	cout << "   5. Salir" << endl;
}

void showMaintenanceMenu() {
	cout << "   Menu de Mantenimiento:" << endl;
	cout << "   1. Modificar informacion de las Peliculas" << endl;
	cout << "   2. Modificar informacion de las Salas" << endl;
	cout << "   3. Modificar informacion de los Horarios" << endl;
	cout << "   4. Volver al Menu Principal" << endl;
}

void handleMaintenanceMenu() {
	int choice;
	do {
		system("cls");
		showMaintenanceMenu();
		cout << "Seleccione una opcion valida: ";
		cin >> choice;

		if (choice == 1) {
			cout << "  Peliculas" << endl;
			continue;
		}

		if (choice == 2) {
			cout << " Salas" << endl;
			continue;
		}

		if (choice == 3) {
			cout << "Horarios" << endl;
			continue;
		}

		if (choice == 4) {
			return;  
		}
		
		
	} while (true);
}

void executeMenu() {
	int choice;
	do {
		system("cls");
		showPrincipalMenu();
		cout << "Digite una opcion: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Realizar Reserva." << endl;
			return;
		}

		if (choice == 2) {
			cout << "Realizar Pago." << endl;
			return;
		}

		if (choice == 3) {
			handleMaintenanceMenu();
			continue;
		}

		if (choice == 4) {
			cout << "Acerca de." << endl;
			return;
		}

		if (choice == 5) {
			cout << "Saliendo del programa..." << endl;
			return;
		}

		cout << "Opción no válida. Intente de nuevo." << endl;
		
	} while (true);
}

int main()
{
	int choice;
	executeMenu();
	return 0;

}

