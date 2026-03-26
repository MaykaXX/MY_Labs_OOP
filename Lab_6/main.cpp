#include <iostream>
#include "WeatherStation.h"
#include "TemperatureWorker.h"
#include "HumidityWorker.h"
#include "PressureWorker.h"
#include "Bobby.h"
#include "../termcolor/termcolor.hpp"


int main() {
    srand(time(NULL));
    /*const*/
    WeatherStation wstation("Station A");

    TemperatureWorker tw;
    HumidityWorker hw;
    PressureWorker pw;

    Bobby bobby("Bobby", tw);
    Bobby lyuda("Lyuda", hw);
    Bobby valestina("Valestina", pw);


    int choice;
    int user_mode=0;

    while (true) {
        std::cout << termcolor::cyan << "\n=== Login Menu ===\n" << termcolor::reset;
        std::cout << "1. Login as Administrator\n";
        std::cout << "2. Login as User\n";
        std::cout << "3. Exit\n";
        std::cout << termcolor::bright_cyan << "Choose role: " << termcolor::reset;
        std::cin >> user_mode;

        if (user_mode == 3)
            break;

        bool is_admin = false;
        std::string current_user = "User";

        if (user_mode == 1) {
            std::string password;
            std::cout << "Enter" <<termcolor::bright_yellow << " Admin " <<termcolor::reset << "password: ";
            std::cin >> password;

            if (password == "kapysta123") {
                is_admin = true;
                current_user = "Admin";
                std::cout << termcolor::bright_green << "Welcome, Admin" << termcolor::reset<<std::endl;
                wstation.log_action("Admin logged in.");
            }else {
                std::cout <<termcolor::bright_red << "Wrong password!" << termcolor::reset<<std::endl;
                continue;
            }
        }else if (user_mode == 2) {
            std::cout << termcolor::bright_green << "Welcome, User" << termcolor::reset<<std::endl;
            wstation.log_action("User logged in.");
        }else {
            std::cout << termcolor::bright_red << "Invalid option" << termcolor::reset<<std::endl;
            continue;
        }

        do {
            try {
                ///////MENU///////
                std::cout << termcolor::magenta << "\n ***Mayka's weather station Menu***\n" << termcolor::reset;
                std::cout << "1. Add Sensor " << (is_admin ? "" : "(Admin only)") <<std::endl;
                std::cout << "2. Show Sensors\n";
                std::cout << "3. Sensor Count\n";
                std::cout << "4. Collect Data\n";
                std::cout << "5. Show History\n";
                std::cout << "6. Calculate Average by Type\n";
                std::cout << "7. Delete last Sensor " <<(is_admin ? "" : "(Admin only)") <<std::endl;;
                std::cout << "8. Delete specific sensor " <<(is_admin ? "" : "(Admin only)")<<std::endl;;
                std::cout << "9. Show workers\n";
                std::cout << "10. Exit\n";
                //////////////////
                std::cout << termcolor::bright_cyan << "Choose an option: " << termcolor::reset;
                std::cin >> choice;

                if (choice == 10) {
                    wstation.log_action(current_user + " logged out.");
                    break;
                }

                if (!is_admin && (choice == 1 || choice==7 || choice == 8)) {
                    throw "Access Denied! Only Admin can modify sensors.";
                }

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
                    case 9: {
                        Human *people[3] = {&bobby, &lyuda, &valestina};
                        for (auto p: people) {
                            p->introduce();
                        }

                        std::cout << termcolor::bright_green << "\nBobby got promoted!" << termcolor::reset << std::endl;
                        bobby.change_role(pw);
                        bobby.introduce();
                        break;
                    }
                    default:
                        std::cout << termcolor::bright_red << "Invalid choice!" << termcolor::reset<<std::endl;
                }
            }
            catch (const char *msg) {
                std::cerr <<termcolor::bright_red <<msg<<termcolor::reset<<std::endl;
                wstation.log_action(current_user + " triggered exception: " + msg);
            }
        } while (choice != 10);
        return 0;
    }
}
