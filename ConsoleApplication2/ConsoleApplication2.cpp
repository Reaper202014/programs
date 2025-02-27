#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Address {
private:
    string country;
    string city;
    string street;
    int house;
    int flat;
public:
    Address() {
        country = "default";
        city = "default";
        street = "default";
        house = 1;
        flat = 1;
    }

    Address(string country, string city, string street, int house, int flat)
        : country(country), city(city), street(street), house(house), flat(flat) {
    }

    string get_country() const {
        return country;
    }

    string get_city() const {
        return city;
    }

    string get_street() const {
        return street;
    }

    int get_house() const {
        return house;
    }

    int get_flat() const {
        return flat;
    }

    void set_city(const string& c) {
        city = c;
    }

    void set_street(const string& s) {
        street = s;
    }
};

void print_menu() {
    cout << "1. Добавление \'пустого\' адреса" << endl;
    cout << "2. Добавления адреса с собственными данными" << endl;
    cout << "3. Редактирование адреса" << endl;
    cout << "4. Вывод адресов" << endl;
    cout << "5. Сортиировка адресов" << endl;
    cout << "0. Выход" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Выбор: ";
}

void print_address(const Address& a) {
    cout << "Страна: " << a.get_country() << endl;
    cout << "Город: " << a.get_city() << endl;
    cout << "Улица: " << a.get_street() << endl;
    cout << "Номер дома: " << a.get_house() << endl;
    cout << "Квартира: " << a.get_flat() << endl;
    cout << "----------------------------" << endl;
}

void print_addresses(const vector<Address>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << i + 1 << ")" << endl;
        print_address(v[i]);
    }
}

Address get_data() {
    string country;
    string city;
    string street;
    int house;
    int flat;

    do {
        cout << "Введите название страны:";
        getline(cin, country);
        if (country.empty()) {
            cout << "Пустая строка! Попробуйте ещё раз" << endl;
        }
    } while (country.empty());

    do {
        cout << "Введите название города:";
        getline(cin, city);
        if (city.empty()) {
            cout << "Пустая строка! Попробуйте ещё раз" << endl;
        }
    } while (city.empty());

    do {
        cout << "Введите название улицы:";
        getline(cin, street);
        if (street.empty()) {
            cout << "Пустая строка! Попробуйте ещё раз" << endl;
        }
    } while (street.empty());

    cout << "Введите номер дома:";
    cin >> house;

    cout << "Введите номер квартиры:";
    cin >> flat;

    return { country, city, street, house, flat };
}

void add_address(vector<Address>& addresses) {
    addresses.push_back(get_data());
}

void change_address(Address& a) {
    a = get_data();
}

bool sort_addresses(const Address& a, const Address& b) {
    if (a.get_country() < b.get_country()) {
        return true;
    }
    else if (a.get_country() > b.get_country()) {
        return false;
    }
    else {
        if (a.get_city() < b.get_city()) {
            return true;
        }
        else if (a.get_city() > b.get_city()) {
            return false;
        }
        else {
            if (a.get_street() < b.get_street()) {
                return true;
            }
            else if (a.get_street() > b.get_street()) {
                return false;
            }
            else {
                if (a.get_house() < b.get_house()) {
                    return true;
                }
                else if (a.get_house() > b.get_house()) {
                    return false;
                }
                else {
                    if (a.get_flat() < b.get_flat()) {
                        return true;
                    }
                    else if (a.get_flat() > b.get_flat()) {
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
        }
    }
}

int main() {
    system("chcp 1251");
    system("cls");


    vector<Address> addresses;
    int choice;
    do {
        system("cls");
        print_menu();
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 0:
            cout << "До свидания!" << endl;
            break;
        case 1:
            addresses.push_back({});
            cout << "Пустой адрес добавлен!" << endl;
            break;
        case 2:
            system("cls");
            cout << "Добавление нового адреса" << endl;
            cout << "----------------------------" << endl;

            add_address(addresses);
            cout << "Адрес добавлен!" << endl;

            break;
        case 3:
            system("cls");
            cout << "Адреса:" << endl;
            cout << "----------------------------" << endl;
            print_addresses(addresses);

            cout << "Выбор адреса для замены: ";
            int c;
            cin >> c;
            cin.ignore();

            change_address(addresses[c - 1]);

            cout << "Адрес изменён!" << endl;

            break;
        case 4:
            system("cls");
            cout << "Адреса:" << endl;
            cout << "----------------------------" << endl;
            print_addresses(addresses);
            break;
        case 5:
            sort(addresses.begin(), addresses.end(), sort_addresses);

            cout << "Адреса отсортированы!" << endl;

            break;
        default:
            cout << "Некорректный ввод!" << endl;
        }
        system("pause");
    } while (choice != 0);
}
