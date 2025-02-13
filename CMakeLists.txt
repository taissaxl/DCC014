# Define o compilador C++
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

include_directories(/usr/include)

# Define a versão mínima do CMake e o nome do projeto
cmake_minimum_required(VERSION 3.5)
project(FinalWork VERSION 0.1.0 LANGUAGES CXX)

# Inclui o módulo de teste do CMake e habilita o suporte a testes
include(CTest)
enable_testing()

# Define o padrão de compilação
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Cria o executável
add_executable(BuscaCidade app/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
