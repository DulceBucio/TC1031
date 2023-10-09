cmake_minimum_required(VERSION 3.23)
project(listasTT)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(listasTT
        listas_t.h
        main.cpp Node.h List.h Direccion.h Contacto.h)
