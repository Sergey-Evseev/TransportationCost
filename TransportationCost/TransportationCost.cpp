////Lesson 11. Task 3 from Practice: Создать абстрактный базовый класс «Транспортное средство» и производные классы 
//«Автомобиль», «Велосипед», «Повозка». Подсчитать время и стоимость перевозки пассажиров и грузов каждым транспортным средством.

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
	int wheels;
	int power;
	int load;
	int passengers;

public:
	virtual int transport_cost() { return 0; };//виртуальная функция расчета стоимости

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

class Car : public Vehicle {//наследуется от Vehicle
	string brand;//марка
	double costPerKm;

public:
	Car(string b, double cost, int wheels, int power, int load, int passengers) :Vehicle(wheels, power, load, passengers) {
		brand = b;
		costPerKm = cost;
		;
	}
	string& GetBrand() {//геттер марки
		return brand;
	}
	double& GetPaidTuition() {//геттер стоимости км
		return costPerKm;
	}

	//показ на экран
	void Show() {
		cout << "--------------" << endl;
		cout << "Brand = " << brand << "\n\n";
		cout << "Cost per km = " << costPerKm << "\n\n";
		cout << "Wheels = " << wheels << "\n\n";
		cout << "Power = " << power << "\n\n";
		cout << "Load = " << load << "\n\n";
		cout << "Passengers = " << passengers << "\n\n";
		cout << "--------------\n\n";
	}
};
int main() {
	//создание объекта
	Car Volvo("Volvo XC90", 25, 4, 100, 200, 4);
	Volvo.Show();

	cout << "Brand: " << Volvo.GetBrand() << endl;
	return 0;
}
