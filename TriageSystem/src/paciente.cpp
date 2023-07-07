#include "paciente.hpp"
#include "exception.hpp"
#include "funcoes.hpp"

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
    _prioridade = 5;
}

void Paciente::imprimir_paciente() const {
        std::cout << "Informações do paciente "<< _nome << std::endl;
        std::cout << "Idade: " << _idade << std::endl;
        std::cout << "CPF: " << _cpf << std::endl;
        std::cout << "Convênio: " << _convenio << std::endl;
        std::cout << "Prioridade: " << _prioridade << std::endl;
        _anamnese.visualizarAnamnese();
    }

std::string Paciente::nome() const {
    return _nome;
}

unsigned Paciente::prioridade() const {
    return _prioridade;
}

void Paciente::editar_dados_paciente(unsigned &prioridade) {
    _anamnese.coletarDadosAnamnese();
    _prioridade = prioridade;
}

bool Paciente::operator==(const Paciente &paciente) const {
    if(this->_cpf == paciente._cpf) return true;
    return false;
}

void Paciente::atribuir_medico(std::string &medico) {
    _medico = medico;
}

std::string Paciente::medico() const {
    return _medico;
}
