#include "funcoes.hpp"

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