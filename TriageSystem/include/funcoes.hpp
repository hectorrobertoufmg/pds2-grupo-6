#ifndef FUNCOES_HPP
#define FUNCOES_HPP


#include <string>
#include <iostream>
#include <regex>
#include "medico.hpp"



/// @brief Tem spam de espaços.
/// Esta função não deixa o usuário utilizar mais de 4 espaços consecutivos
/// @param string uma strig que será validada
bool tem_spam_espacos(const std::string& string);

/// @brief Retorna se o nome é válido ou não.
///
/// Avalia se o nome contém spam de espaços ou números, o que o torna
/// inválido.
///
/// @param string O nome a ser avaliado.
/// @return Retorna true caso o nome atenda às condições, false caso contrário.
bool nome_invalido(std::string &string);

/// @brief Retorna se a string possui ou não números.
/// @param string String a ser avaliada.
/// @return Retorna true se a string não contém números, false caso contrário.
bool sem_numeros(std::string &string);

/// @brief Retorna se a string possui apenas números.
/// @param string String a ser avaliada.
/// @return Retorna true caso a string possua apenas números, false caso
/// contrário.
bool apenas_numeros(std::string &string);

/// @brief Limpa o buffer.
/// Limpa o buffer e modifica o parâmetro estado para true, indicando
/// que o buffer está limpo.
/// @param estado O estado do buffer, limpo ou não.
void limpar_buffer(bool &estado);

/// @brief Imprime na tela o menu do programa.
void menu();

/// @brief Validar opcao.
/// Esta funcao valida a escolha do usuário, se for algo diferente de número
/// retornará uma flag e assim o loop continuará!
/// @param flag recebe um vector do tipo Medico
/// @param entrada
void valida_opcao(bool &flag, unsigned& entrada);

/// @brief Gera banco de dados .
/// Esta função gerá um banco de dados estático, 10 médicos, com nome
/// especialidade e CRM para cada médico.
/// @param medicos recebe um vector do tipo Medico
std::vector<Medico> gerar_bd_medicos(std::vector<Medico>&medicos);

/// @brief Validar pressão .
/// Valida a pressão digitada pelo usuário
/// @param pressao recebe uma string do usuário
bool validarPressao(const std::string& pressao);

#endif