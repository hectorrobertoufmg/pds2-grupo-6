#include "medico.hpp"

Medico::Medico(std::string &nome, std::string &crm, std::string &especialidade) {
    if(!sem_numeros(nome)) {
        throw NomeInvalido();
    }
    if(!sem_numeros(especialidade)) {
        throw EspecialidadeInvalida();
    }
    _nome = nome;
    _crm = crm;
    _especialidade = especialidade;
}

void Medico::imprimir_medico() const {
    std::cout << "INFORMAÇÕES DO MÉDICO" << std::endl;
    std::cout << "O nome do médico é: " << _nome << std::endl;
    std::cout << "Especialidade: " << _especialidade << std::endl;
    std::cout << "CRM: " << _crm << std::endl;
}

std::string Medico::nome() const {
    return _nome;
}