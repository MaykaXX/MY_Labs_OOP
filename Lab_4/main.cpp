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
        std::cout << "8. Delete specific sensor\n";
        std::cout << "9. Exit\n";
        //////////////////
        std::cout << termcolor::bright_cyan << "Choose an option: " << termcolor::reset;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string type;
                std::cout << "Enter sensor ID: ";
                std::cin >> id;
                std::cout << "Enter sensor type (Temperature/Humidity/Pressure): ";
                std::cin >> type;

                if (type == "Temperature") {
                    wstation.add_temperature_sensor(id);
                } else if (type == "Humidity") {
                    wstation.add_humidity_sensor(id);
                } else if (type == "Pressure") {
                    wstation.add_pressure_sensor(id);
                } else {
                    std::cout << termcolor::bright_red << "Unknown sensor type: " << termcolor::reset << type << "\n";
                }
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
                std::string current_date;

                std::cout << termcolor::bright_green << "Enter current date for measurements --> " << termcolor::reset;
                std::cin >> current_date;

                wstation.collect_data(current_date);

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
            case 8: {
                int temp_id;
                std::cout << "Enter sensor id: ";
                std::cin >> temp_id;
                wstation - (temp_id);
            }
        }
    } while (choice != 9);
    return 0;
}
