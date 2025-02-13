#!/bin/bash

# Função para mostrar o menu e obter a escolha do usuário
mostrar_menu() {
    echo "Escolha uma opção:"
    echo "1. Buildar o projeto"
    echo "2. Executar o projeto"
    echo "3. Sair"
    read opcao
}

while true; do
    mostrar_menu

    case $opcao in
    1)
        rm -rf build
        mkdir -p build
        cd build
        cmake ..
        make
        cd ..
        ;;
    2)
        cd build
        ./BuscaCidade
        cd ..
        ;;
    3)
        echo "Saindo..."
        exit 0
        ;;
    *)
        echo "Opção inválida. Tente novamente."
        ;;
    esac
done
