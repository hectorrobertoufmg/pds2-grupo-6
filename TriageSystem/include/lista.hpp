#ifndef LISTA_H
#define LISTA_H

#include <list>
#include <iostream>
#include <string>
#include <cassert>
#include "paciente.hpp"

class ListaDePrioridade {
public:
    /// @brief Adiciona um paciente a lista.
    ///
    /// Adiciona um paciente a lista ordenando-o de acordo com sua
    /// prioridade e ordem de chegada.
    ///
    /// @param paciente O paciente que será adicionado.
    /// @return Retorna verdadeiro caso o paciente tenha sido adicionado.
    bool adicionar_paciente(Paciente &paciente);

    /// @brief Recupera o paciente que possui o nome dado.
    ///
    /// Retorna o paciente que possui o nome igual ao parâmetro ou o iterador
    /// do fim da lista. A lista não sofre alterações. Assume que a lista não 
    /// está vazia, caso contrário lança a exceção de lista vazia.
    ///
    /// @param nome O nome do paciente a ser buscado.
    /// @return Retorna um iterador para o paciente desejado.
    std::_List_iterator<Paciente> procurar_paciente(std::string &nome);

    /// @brief Remove um paciente da lista.
    /// @param posicao O iterador do paciente a ser removido.
    ///
    /// Remove o paciente localizado pelo iterador caso o iterador não seja o
    /// fim da lista. Assume que a lista não está vazia, caso contrário lança 
    /// a exceção de lista vazia.
    ///
    /// @return Retorna verdadeiro caso o paciente tenha sido removido.
    bool remover_paciente(std::_List_iterator<Paciente> &posicao);

    /// @brief Ordena o um paciente.
    ///
    /// Copia o paciente do iterador recebido, apaga o paciente do iterador
    /// e adiciona a cópia à lista na posição correta. Assume que a lista
    /// não está vazia, caso contrário lança a exceção de lista vazia.
    ///
    /// @param posicao O iterador do paciente a ser ordenado.
    void ordenar_paciente(std::_List_iterator<Paciente> &posicao);

    /// @brief Imprime na tela as informações completas de todos os pacientes.
    void exibir_lista() const;

    /// @brief Retorna o iterador para o fim da lista.
    /// @return O iterador para o fim da lista.
    std::_List_iterator<Paciente> fim_lista();

    /// @brief Retorna se a lista está ou não vazia.
    /// @return True se a lista está vazia, false caso contrário.
    bool lista_vazia() const;

    /// @brief Retorna se a lista está ou não ordenada.
    /// @return True se a lista está ordenada, false caso contrário.
    bool ordenado();

    /// @brief Retorna o tamanho da lista.
    /// @return O tamanho da lista.
    int tamanho();

private:
    std::list<Paciente> _pacientes;
};

#endif