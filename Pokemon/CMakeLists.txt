cmake_minimum_required(VERSION 3.20)
project(Pokemon)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pokemon main.cpp Element.cpp Element.h PokemonBase.cpp PokemonBase.h IHelper.cpp IHelper.h GameManager.cpp GameManager.h Player.cpp Player.h)
