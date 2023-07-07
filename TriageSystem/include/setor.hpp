#ifndef SETOR_H
#define SETOR_H

#include <iostream>
#include <vector>
#include "paciente.hpp"

class Setor {
public:
    Setor(const std::string& nome, unsigned capacidade);
    void adicionar_paciente(const Paciente& paciente);
    void trocar_paciente_de_setor(const std::string& nome, const std::string& novoSetor);
    void imprimir_setor() const;

private:
    std::string _nome;
    unsigned _capacidade;
    unsigned _disponibilidade;
    std::vector<Paciente> _pacientes;
};

#endif