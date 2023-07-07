#include <string>
#include <iostream>
#include <regex>
#include "exception.hpp"


bool tem_spam_espacos(const std::string& string);

bool e_maiusculo(std::string &string);

bool e_minusculo(std::string &string);

bool nome_invalido(std::string &string);

bool sem_numeros(std::string &string);

bool apenas_numeros(std::string &string);

void limpar_buffer(bool &estado);

void menu();

void valida_opcao(bool &flag, unsigned& entrada);

bool validarPressao(const std::string &pressao);
