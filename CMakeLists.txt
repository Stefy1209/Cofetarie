cmake_minimum_required(VERSION 3.27)
project(cofetarie C)

set(CMAKE_C_STANDARD 23)

add_executable(cofetarie main.c
        "materie prima.c"
        "materie prima.h"
        repo.c
        repo.h
        service.c
        service.h
        ui.c
        ui.h
        test.c
        test.h)

target_compile_options(cofetarie PRIVATE -Wall -Wextra -Wpedantic)
