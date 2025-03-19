#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Введите количество указателей: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество указателей должно быть положительным." << endl;
        return 1;
    }

    int* object = new int(42);

    int** pointers = new int* [n];

    for (int i = 0; i < n; ++i) {
        pointers[i] = object;
    }

    cout << "Адреса указателей:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Pointer " << i + 1 << ": " << pointers[i] << endl;
    }

    delete pointers;
    delete object;

    return 0;
}