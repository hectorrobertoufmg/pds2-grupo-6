#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <iostream>
#include <string>
#include "anamnese.hpp"

class Paciente {
public:
    /// @brief Construtor de paciente.
    /// @param nome Nome do paciente.
    /// @param idade Idade do paciente.
    /// @param cpf CPF do paciente.
    /// @param convenio Convênio do paciente.
    Paciente(std::string &nome, unsigned &idade, std::string &cpf, std::string &convenio);

    /// @brief Imprime as informações do paciente na tela.
    void imprimir_paciente() const;

    /// @brief Retorna o nome do paciente.
    /// @return O nome do paciente.
    std::string nome() const;

    /// @brief Retorna a prioridade do paciente.
    /// @return A prioridade do paciente.
    unsigned prioridade() const;

    /// @brief Edita a prioridade e a anamnese do paciente.
    /// @param prioridade A nova prioridade do paciente.
    void editar_dados_paciente(unsigned &prioridade);

    /// @brief Comparador de pacientes
    /// Retorna true caso os dois pacientes possuam o mesmo CPF, false caso contrário.
    /// @param paciente O paciente a ser comparado com o objeto.
    /// @return True caso os dois pacientes possuam o mesmo CPF, false caso contrário.
    bool operator==(const Paciente &paciente) const;

    /// @brief Atribui o nome de um médico ao paciente.
    /// @param medico O médico a ser atribuído ao paciente.
    void atribuir_medico(std::string &medico);

    /// @brief Retorna o nome do médico associado ao paciente.
    /// @return O nome do médico associado ao paciente.
    std::string medico() const;

private:
    std::string _nome;
    unsigned _idade;
    std::string _cpf;
    std::string _convenio;
    Anamnese _anamnese;
    unsigned _prioridade;
    std::string _medico;
};

#endif