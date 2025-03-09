#include <iostream>
using namespace std;

class PerviKlass;

class VtoroiKlass {
private:
    int A;
    int B;

public:
    VtoroiKlass(int a, int b) : A(a), B(b) {}

    friend int addValues(VtoroiKlass a, PerviKlass b);
};

class PerviKlass {
private:
    int H;
    int Y;

public:
    PerviKlass(int c, int d) : H(c), Y(d) {}

    friend int addValues(VtoroiKlass a, PerviKlass b);
};

int addValues(VtoroiKlass a, PerviKlass b) {
    return a.A + a.B + b.H + b.Y;
}

int main() {
    VtoroiKlass Pervoe(5, 10);
    PerviKlass Vtoroe(3, 4);

    int sum = addValues(Pervoe, Vtoroe);
    cout << "Сумма всех чисел: " << sum << endl;

    return 0;
}