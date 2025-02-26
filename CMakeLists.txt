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
include_directories(${CMAKE_SOURCE_DIR}/include)


# Define o padrão de compilação
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona bibliotecas
add_library(lista src/estruturas/lista.cpp)
add_library(grafo src/util/fazGrafo.cpp src/estruturas/grafo.cpp src/estruturas/lista.cpp src/algoritmos/gulosa.cpp src/algoritmos/aEstrela.cpp)
add_library(buscaLargura src/algoritmos/largura.cpp) 
add_library(backtracking src/algoritmos/backtracking.cpp)
add_library(ordenada src/algoritmos/ordenada.cpp)
add_library(profundidade src/algoritmos/profundidade.cpp)


# Cria o executável
add_executable(BuscaCidade app/main.cpp src/estruturas/grafo.cpp src/estruturas/lista.cpp)

# Cria os executáveis dos testes

add_executable(test_lista test/test_lista.cpp)
add_executable(test_vertice test/test_vertice.cpp)
add_executable(test_aresta test/test_aresta.cpp)
add_executable(test_fazerGrafoSemClasseGrafo test/test_fazerGrafoSemClasseGrafo.cpp)
add_executable(test_grafo test/test_grafo.cpp)
add_executable(test_fazGrafo test/test_fazGrafo.cpp)
add_executable(test_heapMin test/test_heapMin.cpp)
add_executable(test_buscaOrdenada test/test_buscaOrdenada.cpp)
add_executable(test_buscaGulosa test/test_buscaGulosa.cpp)
add_executable(test_buscaAEstrela test/test_buscaAEstrela.cpp)
add_executable(test_profundidade test/test_profundidade.cpp)
add_executable(test_buscaLargura test/test_buscaLargura.cpp)
add_executable(test_backtracking test/test_backtracking.cpp)

# Linka os executáveis com as bibliotecas necessárias
target_link_libraries(test_lista lista ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_vertice lista ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_fazerGrafoSemClasseGrafo lista ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_aresta lista ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_grafo grafo ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_fazGrafo grafo ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_heapMin grafo ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_buscaOrdenada grafo ordenada ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_buscaGulosa grafo ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_buscaAEstrela grafo ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_buscaLargura grafo buscaLargura ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_backtracking grafo backtracking ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_profundidade grafo profundidade ${GTEST_LIBRARIES} pthread)


# Add the test to CTest
target_link_libraries(test_profundidade grafo profundidade ${GTEST_LIBRARIES} pthread)

# Adiciona os testes ao CTest
add_test(NAME test_lista COMMAND test_lista)
add_test(NAME test_vertice COMMAND test_vertice)
add_test(NAME test_fazerGrafoSemClasseGrafo COMMAND test_fazerGrafoSemClasseGrafo)
add_test(NAME test_aresta COMMAND test_aresta)
add_test(NAME test_grafo COMMAND test_grafo)
add_test(NAME test_fazGrafo COMMAND test_fazGrafo)
add_test(NAME test_heapMin COMMAND test_heapMin)
add_test(NAME test_buscaOrdenada COMMAND test_buscaOrdenada)
add_test(NAME test_buscaGulosa COMMAND test_buscaGulosa)
add_test(NAME test_buscaAEstrela COMMAND test_buscaAEstrela)
add_test(NAME test_buscaLargura COMMAND test_buscaLargura)
add_test(NAME test_backtracking COMMAND test_backtracking)
add_test(NAME test_profundidade COMMAND test_profundidade)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)