# Adiciona o executável de teste
add_executable(runTests test_lista.cpp)

# Linka as bibliotecas necessárias
target_link_libraries(runTests PRIVATE ${PROJECT_NAME})

# Adiciona o teste ao CTest
add_test(NAME ListaTests COMMAND runTests)
