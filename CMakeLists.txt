cmake_minimum_required(VERSION 3.29)
project(CCalendar C)

set(CMAKE_C_STANDARD 11)

add_executable(CCalendar src/Main.c
        src/ATime.c
)

include_directories(include)