cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(main Lab_2/main.cpp
        Lab_2/Sensor.cpp
        Lab_2/Sensor.h
        Lab_2/Measurement.cpp
        Lab_2/Measurement.h
        Lab_2/WeatherStation.cpp
        Lab_2/WeatherStation.h
        termcolor/termcolor.hpp
)
