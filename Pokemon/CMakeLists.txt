cmake_minimum_required(VERSION 3.20)
project(Pokemon)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pokemon main.cpp Element.cpp Element.h cmake-build-debug/PokemonBase.cpp cmake-build-debug/PokemonBase.h IHelper.cpp IHelper.h cmake-build-debug/GameManager.cpp cmake-build-debug/GameManager.h cmake-build-debug/Player.cpp cmake-build-debug/Player.h cmake-build-debug/NodeHelper.cpp cmake-build-debug/NodeHelper.h)
