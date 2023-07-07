#ifndef MEDICO_HPP
#define MEDICO_HPP

#include<string>
#include"lista.hpp"
class Medico {
public:
    Medico(std::string &nome, std::string &crm, std::string &especialidade);
    void imprimir_medico() const;
    std::string nome() const;

    ListaDePrioridade pacientes;

private:
    std::string _nome;
    std::string _crm;
    std::string _especialidade;
};

#endif