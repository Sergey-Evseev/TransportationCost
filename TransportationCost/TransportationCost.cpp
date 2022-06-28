////Lesson 11. Task 3 from Practice: Создать абстрактный базовый класс «Транспортное средство» и производные классы 
//«Автомобиль», «Велосипед», «Повозка». Подсчитать время и стоимость перевозки пассажиров и грузов каждым транспортным средством.

#include <iostream>
#include <string>
#include <string>
using namespace std;

class Vehicle {
protected:
	const double fuelCost = 50.0;
	int wheels;
	int power;
	int load;
	int passengers;

public:
	virtual double transport_cost() { return 0; };//виртуальная функция расчета стоимости

	Vehicle(int wheels, int power, int load, int passengers) {//конструктор род.класса с параметрами - вызывается при вызове конструктора  класса наследника
		this->wheels = wheels;
		this->power = power;
		this->load = load;
		this->passengers = passengers; 
	}

	int& getWheels() { return wheels; } //геттер колес
	int& getPower() { return power; } //геттер мощности
	int& getLoad() { return load; }//геттер грузоподъемности
	int& getPassengers() { return passengers; }//геттер пассажировместимости
};
//описание класса Car//
class Car : public Vehicle {//наследуется от Vehicle
	string brand;//марка
	double fuelPerKm;

public:
	Car(string b, double fuel, int power, int load, int passengers) :Vehicle(wheels, power, load, passengers) {
		brand = b;
		fuelPerKm = 12.0;
		wheels = 4;
	}
	string& GetBrand() {//геттер марки
		return brand;
	}

	double transport_cost(double fuelPer100Km)
	{
		return (fuelCost * fuelPer100Km) / 100;
	}

	//показ на экран
	void Show() {
		cout << "--------------" << endl;
		cout << "Brand = " << brand << "\n\n";
		cout << "Cost per km = " << transport_cost(25) << "\n\n";
		cout << "Wheels = " << wheels << "\n\n";
		cout << "Power = " << power << "\n\n";
		cout << "Load = " << load << "\n\n";
		cout << "Passengers = " << passengers << "\n\n";
		cout << "--------------\n\n";
	}
	//конец класса Car////

};
	//описание класса Повозка////
class Buggy : public Vehicle
{
		string brand;
		double hayCost; //стоимость сена за тонну 100 RUB
		double hayPerKm;

	public:
		Buggy(string b, int power, int load, int passengers, double hayPerKm) :Vehicle(wheels, power, load, passengers) {
			brand = b;
			wheels = 4;
			this->hayPerKm = hayPerKm;
		}

		double transport_cost(double hayCost)
		{
			return (hayCost * hayPerKm);
		}
		void Show() {
			cout << "Повозка Вася - параметры и стоимость перевозки: " << endl;
			cout << "Brand = " << brand << "\n\n";
			cout << "Cost per km = " << transport_cost(100) << "\n\n";
			cout << "Wheels = " << wheels << "\n\n";
			cout << "Power = " << power << "\n\n";
			cout << "Load = " << load << "\n\n";
			cout << "Passengers = " << passengers << "\n\n";
		}
		//конец класса Buggy//
};

int main() {
	setlocale(LC_ALL, "rus");
	//создание объекта Car//
	Car Volvo("Volvo XC90", 25, 100, 200, 4);
	Volvo.Show();
	//cout << "Brand: " << Volvo.GetBrand() << endl;

	//создание объекта Повозка//
	Buggy Vasya("Vasya", 1, 250, 8, 0.025);
	Vasya.Show();

	return 0;
}