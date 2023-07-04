#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include "funcoes.hpp"
#include "excecao.hpp"

class NomeInvalido : public std::exception {
public:
    const char *what() const noexcept override;
};

class CpfInvalido : public std::exception {
public:
    const char *what() const noexcept override;
};

class ConvenioInvalido : public std::exception {
public:
    const char *what() const noexcept override;
};

class Paciente {
    friend class ListaDePrioridade;
public:
    Paciente(std::string &nome, unsigned &idade, std::string &cpf, std::string &convenio);
    void imprimir_paciente() const;
    void editar_dados_paciente(unsigned &cor);

private:
    std::string _nome;
    unsigned _idade;
    std::string _cpf;
    std::string _convenio;
    unsigned _cor = 5;
};

#endif
