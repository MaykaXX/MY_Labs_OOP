#include <iostream>
#include "WeatherStation.h"
#include "../termcolor/termcolor.hpp"


int main() {
    srand(time(NULL));
    /*const*/
    WeatherStation wstation("Station A");
    WeatherStation wstation2(wstation);
    WeatherStation wstation3(std::move(wstation2));

    int choice;

    do {
        ///////MENU///////
        std::cout << termcolor::magenta << "\n ***Mayka's weather station Menu***\n" << termcolor::reset;
        std::cout << "1. Add Sensor\n";
        std::cout << "2. Show Sensors\n";
        std::cout << "3. Sensor Count\n";
        std::cout << "4. Collect Data\n";
        std::cout << "5. Show History\n";
        std::cout << "6. Calculate Average by Type\n";
        std::cout << "7. Delete last Sensor\n";
        std::cout << "8. Exit\n";
        //////////////////
        std::cout << termcolor::bright_cyan << "Choose an option: " << termcolor::reset;
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
                wstation.show_sensor_count();
                break;
            }
            case 4: {
                wstation.collect_data();
                std::cout << "Data collected!\n";
                break;
            }
            case 5: {
                wstation.show_history();
                break;
            }
            case 6: {
                std::string type;
                std::cout << "Enter sensor type to calculate average: ";
                std::cin >> type;
                double average = wstation.calculate_average(type);
                std::cout << "Average for type " << type << ": " << average << "\n";
                break;
            }
            case 7: {
                --wstation;
                std::cout << termcolor::bright_green << "Sensor was deleted!1" << termcolor::reset;
                break;
            }
        }
    } while (choice != 8);
    return 0;
}
