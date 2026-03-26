cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(main Lab_6/main.cpp
        Lab_6/Sensor.cpp
        Lab_6/Sensor.h
        Lab_6/Measurement.cpp
        Lab_6/Measurement.h
        Lab_6/WeatherStation.cpp
        Lab_6/WeatherStation.h
        termcolor/termcolor.hpp
        Lab_6/TemperatureSens.cpp
        Lab_6/TemperatureSens.h
        Lab_6/HumiditySens.cpp
        Lab_6/HumiditySens.h
        Lab_6/PressureSens.cpp
        Lab_6/PressureSens.h
        Lab_6/EnvironmentalSensor.cpp
        Lab_6/EnvironmentalSensor.h
        Lab_6/Roles.cpp
        Lab_6/Roles.h
        Lab_6/Human.cpp
        Lab_6/Human.h
        Lab_6/TemperatureWorker.cpp
        Lab_6/TemperatureWorker.h
        Lab_6/HumidityWorker.cpp
        Lab_6/HumidityWorker.h
        Lab_6/PressureWorker.cpp
        Lab_6/PressureWorker.h
        Lab_6/Bobby.cpp
        Lab_6/Bobby.h
)
