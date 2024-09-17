#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Human {
private:
	string _name;
	string _surname;
	string _patronymic;
public:
	Human() {
		_name = "Unknown";
		_surname = "Unknown";
		_patronymic = "Unknown";
	}
	Human(string name, string surname, string patronymic) {
		_name = name;
		_surname = surname;
		_patronymic = patronymic;
	}
	Human(const Human& obj) {
		_name = obj._name;
		_surname = obj._surname;
		_patronymic = obj._patronymic;
	}
	~Human() {
	}
	void setName(string name) {
		_name = name;
	}
	void setSurname(string surname) {
		_surname = surname;
	}
	void setPatronymic(string patronymic) {
		_patronymic = patronymic;
	}
	string getName() {
		return _name;
	}
	string getSurname() {
		return _surname;
	}
	string getPatronymic() {
		return _patronymic;
	}
	void show() {
		cout << "Name: " << _name << endl;
		cout << "Surname: " << _surname << endl;
		cout << "Patronymic: " << _patronymic << endl;
	}
};

class Apartment {
private:
	Human* _human;
	int _count;
public:
	Apartment() {
		_human = new Human[1];
		_count = 1;
	}
	Apartment(int count) {
		_human = new Human[count];
		_count = count;
	}
	Apartment(const Apartment& obj) {
		_count = obj._count;
		_human = new Human[_count];
		for (int i = 0; i < _count; i++) {
			_human[i] = obj._human[i];
		}
	}
	~Apartment() {
		delete[] _human;
	}
	void setHuman(Human* human) {
		_human = human;
	}
	void setCount(int count) {
		_count = count;
	}
	Human* getHuman() {
		return _human;
	}
	int getCount() {
		return _count;
	}
	void show() {
		for (int i = 0; i < _count; i++) {
			cout << "Human " << i + 1 << endl;
			_human[i].show();
		}
	}
};

class House {
private:
	Apartment* _apartment;
	int _count;
public:
	House() {
		_apartment = new Apartment[1];
		_count = 1;
	}
	House(int count) {
		_apartment = new Apartment[count];
		_count = count;
	}
	House(const House& obj) {
		_count = obj._count;
		_apartment = new Apartment[_count];
		for (int i = 0; i < _count; i++) {
			_apartment[i] = obj._apartment[i];
		}
	}
	~House() {
		delete[] _apartment;
	}
	void setApartment(Apartment* apartment) {
		_apartment = apartment;
	}
	void setCount(int count) {
		_count = count;
	}
	Apartment* getApartment() {
		return _apartment;
	}
	int getCount() {
		return _count;
	}
	void show() {
		for (int i = 0; i < _count; i++) {
			cout << "Apartment " << i + 1 << endl;
			_apartment[i].show();
		}
	}
};

int main() {
	Human human1("Ivan", "Ivanov", "Ivanovich");
	Human human2("Petro", "Petrov", "Petrovich");
	Human human3("Stepan", "Stepanov", "Stepanovich");
	Human human4("Oleg", "Olegov", "Olegovich");
	Human human5("Vasyl", "Vasyliev", "Vasylievich");

	Human* human = new Human[5];
	human[0] = human1;
	human[1] = human2;
	human[2] = human3;
	human[3] = human4;
	human[4] = human5;

	Apartment apartment1(5);
	apartment1.setHuman(human);

	Apartment apartment2(5);
	apartment2.setHuman(human);

	Apartment apartment3(5);
	apartment3.setHuman(human);

	Apartment apartment4(5);
	apartment4.setHuman(human);

	Apartment apartment5(5);
	apartment5.setHuman(human);

	Apartment* apartment = new Apartment[5];
	apartment[0] = apartment1;
	apartment[1] = apartment2;
	apartment[2] = apartment3;
	apartment[3] = apartment4;
	apartment[4] = apartment5;

	House house(5);
	house.setApartment(apartment);

	house.show();

	delete[] human;
	delete[] apartment;

	return 0;
}