cmake_minimum_required(VERSION 3.10)
project(GraphPondere)

# Définit le standard C++ à utiliser
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajoute l'exécutable
add_executable(graph main.cpp)
