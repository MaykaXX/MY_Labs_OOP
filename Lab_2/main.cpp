#include <iostream>
#include <thread>
#include <chrono>
#include "../termcolor/termcolor.hpp"

#include "WeatherStation.h"


int Sleep(int _cpp_par_);

int main() {
    srand(time(NULL));
    WeatherStation wstation("Station A");
    int choice;

    do {
        ///////MENU///////
        std::cout << termcolor::magenta<<"\n ***Mayka's weather station Menu***\n"<<termcolor::reset;
        std::cout << "1. Add Sensor\n";
        std::cout << "2. Show Sensors\n";
        std::cout << "3. Collect Data\n";
        std::cout << "4. Show History\n";
        std::cout << "5. Calculate Average by Type\n";
        std::cout << "6. Exit\n";
        //////////////////
        std::cout << termcolor::bright_cyan <<"Choose an option: " << termcolor::reset;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string type;
                std::cout << "Enter sensor ID: ";
                std::cin >> id;
                std::cout << "Enter sensor type: ";
                std::cin >> type;
                wstation.add_Sensor(id, type);
                break;
            }
            case 2: {
                wstation.show_Sensors();
                break;
            }
            case 3: {
                wstation.collest_data();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::cout << "Data collected!\n";
                break;
            }
            case 4: {
                wstation.show_history();
                break;
            }
            case 5: {
                std::string type;
                std::cout << "Enter sensor type to calculate average: ";
                std::cin >> type;
                double average = wstation.calculate_average(type);
                std::cout << "Average for type " << type << ": " << average << "\n";
                break;
            }
        }
    } while (choice != 6);
    return 0;
}
