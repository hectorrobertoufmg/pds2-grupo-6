#ifndef MEDICO_H
#define MEDICO_H

#include <iostream>
#include <string>
#include <list>
#include "lista.hpp"

class Medico {
public:
    Medico(std::string &nome, std::string &crm, std::string &especialidade);
    void imprimir_medico() const;
    std::string nome() const;
    void atualizar_paciente(Paciente &paciente);
    void remover_paciente(std::string &nome);

    ListaDePrioridade pacientes;

private:
    std::string _nome;
    std::string _crm;
    std::string _especialidade;
};

#endif