#include "paciente.hpp"
#include "exception.hpp"

Paciente::Paciente(std::string &nome, unsigned &idade, std::string &cpf, std::string &convenio) {
    if(!sem_numeros(nome)) {
        throw NomeInvalido();
    }
    if(!apenas_numeros(cpf) || cpf.size() != 11) {
        throw CpfInvalido();
    }
    if(!sem_numeros(convenio)) {
        throw ConvenioInvalido();
    }
    _nome = nome;
    _idade = idade;
    _cpf = cpf;
    _convenio = convenio;
}

void Paciente::imprimir_paciente() const {
        std::cout << "Informações do paciente "<< _nome << std::endl;
        std::cout << "Idade: " << _idade << std::endl;
        std::cout << "CPF: " << _cpf << std::endl;
        std::cout << "Convênio: " << _convenio << std::endl;
        std::cout << "Cor: " << _cor << std::endl;
    }

std::string Paciente::get_nome() const {
    return _nome;
}

unsigned Paciente::get_cor() const {
    return _cor;
}

void Paciente::editar_dados_paciente(unsigned &cor) {
    _cor = cor;
}

