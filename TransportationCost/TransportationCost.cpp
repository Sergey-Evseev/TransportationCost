////Lesson 11. Task 3 from Practice: ������� ����������� ������� ����� ������������� �������� � ����������� ������ 
//������������, ����������, ��������. ���������� ����� � ��������� ��������� ���������� � ������ ������ ������������ ���������.

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
	virtual int transport_cost() { return 0; };//����������� ������� ������� ���������

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

class Car : public Vehicle {//����������� �� Vehicle
	string brand;//�����
	double costPerKm;

public:
	Car(string b, double cost, int wheels, int power, int load, int passengers) :Vehicle(wheels, power, load, passengers) {
		brand = b;
		costPerKm = cost;
		;
	}
	string& GetBrand() {//������ �����
		return brand;
	}
	double& GetPaidTuition() {//������ ��������� ��
		return costPerKm;
	}

	//����� �� �����
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
	//�������� �������
	Car Volvo("Volvo XC90", 25, 4, 100, 200, 4);
	Volvo.Show();

	cout << "Brand: " << Volvo.GetBrand() << endl;
	return 0;
}
