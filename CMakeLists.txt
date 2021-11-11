cmake_minimum_required(VERSION 3.17)
project(projeto_lp1_aed1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(projeto_lp1_aed1
        main.c
        projetolp1_aed1.c
        projetolp1_aed1.h)
