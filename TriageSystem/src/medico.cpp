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

void Medico::adicionar_paciente(Paciente &paciente) {
    _pacientes.adicionar_paciente(paciente);
}

void Medico::editar_dados_paciente(std::string &nome, unsigned &prioridade) {
    std::_List_iterator<Paciente> it = _pacientes.procurar_paciente(nome);
    it->editar_dados_paciente(prioridade);
}

void Medico::ordenar_paciente(std::string &nome) {
    std::_List_iterator<Paciente> it = _pacientes.procurar_paciente(nome);
    _pacientes.ordenar_paciente(it);
}

void Medico::remover_paciente(std::string &nome) {
    std::_List_iterator<Paciente> it = _pacientes.procurar_paciente(nome);
    _pacientes.remover_paciente(it);
}