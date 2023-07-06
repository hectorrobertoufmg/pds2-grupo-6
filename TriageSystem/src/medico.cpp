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

void Medico::atualizar_paciente(Paciente &paciente) {
    std::string nome = paciente.nome();
    auto it = pacientes.procurar_paciente(nome);
    pacientes.remover_paciente(it);
    pacientes.adicionar_paciente(paciente);
}

void Medico::remover_paciente(std::string &nome) {
    auto it = pacientes.procurar_paciente(nome);
    pacientes.remover_paciente(it);
}