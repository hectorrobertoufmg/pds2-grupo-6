#ifndef MEDICO_HPP
#define MEDICO_HPP

#include<string>
#include"lista.hpp"
class Medico {
public:
    /// @brief Construtor do médico.
    /// @param nome O nome do médico.
    /// @param crm O CRM do médico.
    /// @param especialidade A especialidade do médico.
    Medico(std::string &nome, std::string &crm, std::string &especialidade);

    /// @brief Imprime as informações do médico na tela.
    void imprimir_medico() const;

    /// @brief Retorna o nome do médico.
    /// @return O nome do médico.
    std::string nome() const;

    /// @brief A lista de pacientes do médico.
    ListaDePrioridade pacientes;

private:
    std::string _nome;
    std::string _crm;
    std::string _especialidade;
};

#endif