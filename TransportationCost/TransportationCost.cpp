////Lesson 11. Task 3 from Practice: ������� ����������� ������� ����� ������������� �������� � ����������� ������ 
//������������, ����������, ��������. ���������� ����� � ��������� ��������� ���������� � ������ ������ ������������ ���������.

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
	virtual double transport_cost() { return 0; };//����������� ������� ������� ���������

	Vehicle(int wheels, int power, int load, int passengers) {//����������� ���.������ � ����������� - ���������� ��� ������ ������������  ������ ����������
		this->wheels = wheels;
		this->power = power;
		this->load = load;
		this->passengers = passengers; 
	}

	int& getWheels() { return wheels; } //������ �����
	int& getPower() { return power; } //������ ��������
	int& getLoad() { return load; }//������ ����������������
	int& getPassengers() { return passengers; }//������ ��������������������
};
//�������� ������ Car//
class Car : public Vehicle {//����������� �� Vehicle
	string brand;//�����
	double fuelPerKm;

public:
	Car(string b, double fuel, int power, int load, int passengers) :Vehicle(wheels, power, load, passengers) {
		brand = b;
		fuelPerKm = 12.0;
		wheels = 4;
	}
	string& GetBrand() {//������ �����
		return brand;
	}

	double transport_cost(double fuelPer100Km)
	{
		return (fuelCost * fuelPer100Km) / 100;
	}

	//����� �� �����
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
	//����� ������ Car////

};
	//�������� ������ �������////
class Buggy : public Vehicle
{
		string brand;
		double hayCost; //��������� ���� �� ����� 100 RUB
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
			cout << "������� ���� - ��������� � ��������� ���������: " << endl;
			cout << "Brand = " << brand << "\n\n";
			cout << "Cost per km = " << transport_cost(100) << "\n\n";
			cout << "Wheels = " << wheels << "\n\n";
			cout << "Power = " << power << "\n\n";
			cout << "Load = " << load << "\n\n";
			cout << "Passengers = " << passengers << "\n\n";
		}
		//����� ������ Buggy//
};

int main() {
	setlocale(LC_ALL, "rus");
	//�������� ������� Car//
	Car Volvo("Volvo XC90", 25, 100, 200, 4);
	Volvo.Show();
	//cout << "Brand: " << Volvo.GetBrand() << endl;

	//�������� ������� �������//
	Buggy Vasya("Vasya", 1, 250, 8, 0.025);
	Vasya.Show();

	return 0;
}