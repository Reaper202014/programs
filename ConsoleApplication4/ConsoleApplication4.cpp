#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int weight;

protected:
    string type;

public:
    Animal(string nm, int wgt) : name(nm), weight(wgt) {}

    void print() {
        cout << "Имя: " << name << "Вес: " << weight << " кг." << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string nm, int wgt) : Animal(nm, wgt) {
        type = "Кошка";
    }

    void print() {
        Animal::print();
        cout << "Тип: " << type << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string nm, int wgt) : Animal(nm, wgt) {
        type = "Собака";
    }

    void print() {
        Animal::print();
        cout << "Тип: " << type << endl;
    }
};

int main() {
    Cat myCat("Мурка", 4);
    Dog myDog("Шарик", 10);

    myCat.print();
    myDog.print();

    return 0;
}