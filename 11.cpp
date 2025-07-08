#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <locale>

using namespace std;

struct Car {
    string ownerName;      
    string registrationDate; 
    string carBrand;        
    int yearOfManufacture;  
    string color;          
    string registrationNumber; 
};

void addCar(vector<Car>& cars) {
    Car newCar;
    cout << "Введите фамилию владельца: ";
    cin >> newCar.ownerName;
    cout << "Введите дату регистрации (DD.MM.YYYY): ";
    cin >> newCar.registrationDate;
    cout << "Введите марку машины: ";
    cin >> newCar.carBrand;
    cout << "Введите год выпуска: ";
    cin >> newCar.yearOfManufacture;
    cout << "Введите цвет машины: ";
    cin >> newCar.color;
    cout << "Введите регистрационный номер: ";
    cin >> newCar.registrationNumber;
    cars.push_back(newCar);
    cout << "Машина успешно зарегистрирована.\n";
}

void removeCar(vector<Car>& cars, const string& regNum) {
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->registrationNumber == regNum) {
            cars.erase(it);
            cout << "Машина с регистрационным номером " << regNum << " успешно удалена.\n";
            return;
        }
    }
    cout << "Машина с регистрационным номером " << regNum << " не найдена.\n";
}

void searchByBrand(const vector<Car>& cars, const string& brand) {
    bool found = false;
    for (const auto& car : cars) {
        if (car.carBrand == brand) {
            cout << "Найдена машина:\n";
            cout << "Фамилия владельца: " << car.ownerName << "\n";
            cout << "Дата регистрации: " << car.registrationDate << "\n";
            cout << "Марка машины: " << car.carBrand << "\n";
            cout << "Год выпуска: " << car.yearOfManufacture << "\n";
            cout << "Цвет: " << car.color << "\n";
            cout << "Регистрационный номер: " << car.registrationNumber << "\n\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Машины с маркой " << brand << " не найдены.\n";
    }
}

void searchByColor(const vector<Car>& cars, const string& color) {
    bool found = false;
    for (const auto& car : cars) {
        if (car.color == color) {
            cout << "Найдена машина:\n";
            cout << "Фамилия владельца: " << car.ownerName << "\n";
            cout << "Дата регистрации: " << car.registrationDate << "\n";
            cout << "Марка машины: " << car.carBrand << "\n";
            cout << "Год выпуска: " << car.yearOfManufacture << "\n";
            cout << "Цвет: " << car.color << "\n";
            cout << "Регистрационный номер: " << car.registrationNumber << "\n\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Машины с цветом " << color << " не найдены.\n";
    }
}

void searchByBrandAndColor(const vector<Car>& cars, const string& brand, const string& color) {
    bool found = false;
    for (const auto& car : cars) {
        if (car.carBrand == brand && car.color == color) {
            cout << "Найдена машина:\n";
            cout << "Фамилия владельца: " << car.ownerName << "\n";
            cout << "Дата регистрации: " << car.registrationDate << "\n";
            cout << "Марка машины: " << car.carBrand << "\n";
            cout << "Год выпуска: " << car.yearOfManufacture << "\n";
            cout << "Цвет: " << car.color << "\n";
            cout << "Регистрационный номер: " << car.registrationNumber << "\n\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Машины с маркой " << brand << " и цветом " << color << " не найдены.\n";
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    vector<Car> cars;

    int choice;
    while (true) {
        cout << "Меню:\n";
        cout << "1. Зарегистрировать новую машину\n";
        cout << "2. Удалить машину по регистрационному номеру\n";
        cout << "3. Найти машину по марке\n";
        cout << "4. Найти машину по цвету\n";
        cout << "5. Найти машину по марке и цвету\n";
        cout << "6. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCar(cars);
            break;
        case 2: {
            string regNum;
            cout << "Введите регистрационный номер для удаления: ";
            cin >> regNum;
            removeCar(cars, regNum);
            break;
        }
        case 3: {
            string brand;
            cout << "Введите марку машины для поиска: ";
            cin >> brand;
            searchByBrand(cars, brand);
            break;
        }
        case 4: {
            string color;
            cout << "Введите цвет машины для поиска: ";
            cin >> color;
            searchByColor(cars, color);
            break;
        }
        case 5: {
            string brand, color;
            cout << "Введите марку машины для поиска: ";
            cin >> brand;
            cout << "Введите цвет машины для поиска: ";
            cin >> color;
            searchByBrandAndColor(cars, brand, color);
            break;
        }
        case 6:
            cout << "Выход из программы.\n";
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}