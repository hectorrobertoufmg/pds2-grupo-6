#ifndef SETOR_H
#define SETOR_H

#include <iostream>
#include <vector>
#include "paciente.hpp"

class Setor {
public:
    /// @brief Construtor do setor.
    /// @param nome Nome do setor.
    /// @param capacidade Capacidade do setor.
    Setor(const std::string& nome, unsigned capacidade);

    /// @brief Adiciona um paciente ao setor.
    /// @param paciente Paciente a ser adicionado.
    void adicionar_paciente(const Paciente& paciente);

    /// @brief Troca um paciente de setor.
    /// @param nome Nome do paciente a ser trocado.
    /// @param novoSetor Novo setor do paciente.
    void trocar_paciente_de_setor(const std::string& nome, const std::string& novoSetor);

    /// @brief Imprime as informações do setor na tela.
    void imprimir_setor() const;

private:
    std::string _nome;
    unsigned _capacidade;
    unsigned _disponibilidade;
    std::vector<Paciente> _pacientes;
};

#endif