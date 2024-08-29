cmake_minimum_required(VERSION 3.29)
project(estruturas_de_dados C)

set(CMAKE_C_STANDARD 11)

add_executable(estruturas_de_dados main.c
        queue.c
        stack.c
        linked-list.c
        tree.c)
