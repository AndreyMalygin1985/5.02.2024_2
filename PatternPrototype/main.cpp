#include <iostream>

using namespace std;

class Device {
private:
	string name;
public:
	void SetName(string dname) {
		name = dname;
	};

	string GetName() const {
		return name;
	}

	virtual Device* Clone() const {}

	void Show() const {
		cout << "\nName is\n" << GetName() << endl;
	};

	Device() :Device("Unknown device") {}

	Device(string dname) {
		SetName(dname);
	}
};

class Car : public Device {
private:
	string manufacture;
	string description;
	string color;
	int year;
public:
	Car() : Car("No information", "No discription", "No color", 0) {
		SetName("Car");
	};

	//Car(string manufacture, string description, string color, int year) {};

	string GetManufacture() const{
		return manufacture;
	};
	string GetDescription() const{
		return description;
	};
	string GetColor() const{
		return color;
	};
	int GetYear() {
		return year;
	};

	void SetManufacture(string c_manufacture) {
		this->manufacture = c_manufacture;
	};
	void SetDescription(string c_description) {
		this->description = c_description;
	};
	void SetColor(string c_color) {
		this->color = c_color;
	};
	void SetYear(int c_year) {
		this->year = c_year;
	};

	Car(string c_manufacture, string c_description, string c_color, int c_year) {
		SetName("Car");
		SetManufacture(c_manufacture);
		SetDescription(c_description);
		SetColor(c_color);
		SetYear(c_year);
	}

	Device* Clone() const {
		Car* tempCar = new Car();
		*tempCar = *this;
		return tempCar;
	}

	void Show() {
		Show();
		cout << "\nManufacture\n" << GetManufacture() << endl;
		cout << "Description\n" << GetDescription() << endl;
		cout << "Color\n" << GetColor() << endl;
		cout << "Year\n" << GetYear() << endl;
	}
};

int main()
{
	Car c("Toyota", "Good Car", "Black", 2023);
	c.Show();
	cout << "Клонирует"<<endl;

	Car* copy = (Car*)c.Clone();
	copy->Show();

	delete copy;

	return 0;
}