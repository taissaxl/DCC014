# Define o compilador C++
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

include_directories(include)

# Define a versão mínima do CMake e o nome do projeto
cmake_minimum_required(VERSION 3.5)
project(FinalWork VERSION 0.1.0 LANGUAGES CXX)

# Inclui o módulo de teste do CMake e habilita o suporte a testes
include(CTest)
enable_testing()

# Adicione o Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Define o padrão de compilação
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona bibliotecas

add_library(lista src/lista.cpp)
add_library (grafo src/grafo.cpp)


# Cria o executável
add_executable(BuscaCidade app/main.cpp)


# Create a test executable
add_executable(test_lista test/test_lista.cpp)
add_executable(test_vertice test/test_vertice.cpp)
add_executable(test_aresta test/test_aresta.cpp)
add_executable(test_fazerGrafoSemClasseGrafo test/test_fazerGrafoSemClasseGrafo.cpp)
add_executable(test_grafo test/test_grafo.cpp)

# Link the test executable to the lista library
target_link_libraries(test_lista lista ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_vertice lista ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_fazerGrafoSemClasseGrafo lista ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_aresta lista ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_grafo lista grafo ${GTEST_LIBRARIES} pthread)


# Add the test to CTest
add_test(NAME test_lista COMMAND test_lista)
add_test(NAME test_vertice COMMAND test_vertice)
add_test(NAME test_fazerGrafoSemClasseGrafo COMMAND test_fazerGrafoSemClasseGrafo)
add_test(NAME test_aresta COMMAND test_aresta)
add_test(NAME test_grafo COMMAND test_grafo)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
