#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    virtual void printInfo() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void printInfo() const override {
        cout << "Это автомобиль" << endl;
    }
    ~Car() {
        cout << "Автомобиль сломан" << endl;
    }
};

class Bike : public Vehicle {
public:
    void printInfo() const override {
        cout << "Это велосипед" << endl;
    }
    ~Bike() {
        cout << "Велосипед сломан" << endl;
    }
};

int main() {
    const int size = 5;
    Vehicle* vehicles[size];

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            vehicles[i] = new Car();
        }
        else {
            vehicles[i] = new Bike();
        }
    }

    for (int i = 0; i < size; ++i) {
        vehicles[i]->printInfo();
    }

    for (int i = 0; i < size; ++i) {
        delete vehicles[i];
    }

    return 0;
}