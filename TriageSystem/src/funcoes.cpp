#include "funcoes.hpp"
#include <limits>

bool sem_numeros(std::string &string) {
    for(char c : string) {
        if(std::isdigit(c)) return false;
    }

    return true;
}

bool apenas_numeros(std::string &string) {
    for(char c : string) {
        if(!std::isdigit(c)) return false;
    }

    return true;
}

void limpar_buffer(bool &estado) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    estado = true;
}

void menu(){
    std::cout << "1: Cadastrar paciente         2: Avaliar/reavaliar paciente         3: Ver dados do Paciente" << std::endl
        << "4: Remover paciente         5: Atribuir paciente ao médico         6: Sair" << std::endl << std::endl
        << "Digite o número da operação desejada: ";
}