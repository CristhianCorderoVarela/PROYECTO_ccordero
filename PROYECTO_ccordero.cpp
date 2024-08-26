#include <iostream>
using namespace std;

const int numberOfSeats = 120;
int consecutive = 0;

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

	void setEndTime(string newStartTime) {
		endTime = newStartTime;
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

	void setSaleStatus(string saleStatus) {
		saleStatus = saleStatus;
	}

	int getConsecutive() {
		return consecutive;
	}

	string getSaleStatus() {
		return saleStatus;
	}
};

void showMenu() {

	cout << "   Menu de Opciones:" << endl;
	cout << endl;
	cout << "Reserva:      " << endl;
	cout << "   1.Realizar Reserva. " << endl;
	cout << endl;
	cout << "Venta:        " << endl;
	cout << "   2.Realizar Pago.    " << endl;
	cout << endl;
	cout << "Mantenimiento:" << endl;
	cout << "   3. Peliculas. " << endl;
	cout << "   4. Salas. " << endl;
	cout << "   5. Horarios. " << endl;
	cout << endl;
	cout << "Archivo: " << endl;
	cout << "   6. Acerca de. " << endl;
	cout << "   7. Salir. " << endl;
	cout << endl;
}

int main()
{
	showMenu();
	return 0;

}

