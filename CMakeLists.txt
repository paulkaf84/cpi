cmake_minimum_required(VERSION 3.26)
project(cpi C)

set(CMAKE_C_STANDARD 11)

add_executable(cpi main.c
        vendor/cli/src/cli.c
        src/utils.c)
