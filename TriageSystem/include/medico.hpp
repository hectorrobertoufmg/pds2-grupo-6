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
    void adicionar_paciente(Paciente &paciente);
    void editar_dados_paciente(std::string &nome, unsigned &prioridade);
    void ordenar_paciente(std::string &nome);
    void remover_paciente(std::string &nome);

private:
    std::string _nome;
    std::string _crm;
    std::string _especialidade;
    ListaDePrioridade _pacientes;
};

#endif