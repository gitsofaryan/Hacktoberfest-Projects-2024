#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\nTemperature Converter Menu:" << endl;
    cout << "1. Convert Celsius to Fahrenheit" << endl;
    cout << "2. Convert Fahrenheit to Celsius" << endl;
    cout << "3. Exit" << endl;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    int choice;
    double temperature;

    while (true) {
        displayMenu();
        cout << "Choose an option (1-3): ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting the temperature converter. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter temperature in Celsius: ";
                cin >> temperature;
                cout << temperature << " Celsius = " 
                     << celsiusToFahrenheit(temperature) << " Fahrenheit" << endl;
                break;
            case 2:
                cout << "Enter temperature in Fahrenheit: ";
                cin >> temperature;
                cout << temperature << " Fahrenheit = " 
                     << fahrenheitToCelsius(temperature) << " Celsius" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
