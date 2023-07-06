#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include "anamnese.hpp"
#include "setor.hpp"
#include "exception.hpp"
#include "funcoes.hpp"

class Paciente {
public:
    Paciente(std::string &nome, unsigned &idade, std::string &cpf, std::string &convenio);
    void imprimir_paciente() const;
    std::string nome() const;
    unsigned prioridade() const;
    void editar_dados_paciente(unsigned &prioridade);
    bool operator==(const Paciente &paciente) const;

private:
    std::string _nome;
    unsigned _idade;
    std::string _cpf;
    std::string _convenio;
    Anamnese _anamnese;
    unsigned _prioridade;
};

#endif