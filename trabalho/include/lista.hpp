#ifndef LISTA_H
#define LISTA_H

#include <list>
#include <iostream>
#include <string>
#include "paciente.hpp"

class ListaDePrioridade {
public:
    bool adicionar_paciente(Paciente &paciente);
    std::_List_iterator<Paciente> procurar_paciente(std::string &nome);
    bool remover_paciente(std::_List_iterator<Paciente> &posicao);
    void ordenar_paciente(std::_List_iterator<Paciente> &posicao);
    void exibir_lista() const;
    std::_List_iterator<Paciente> fim_lista();

private:
    std::list<Paciente> _pacientes;
};

#endif