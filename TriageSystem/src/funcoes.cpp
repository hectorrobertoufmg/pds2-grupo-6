#include "funcoes.hpp"
#include <limits>
#include <exception.hpp>

bool e_maiusculo(std::string &string)
{
    for(int c : string)
    {
        if(!(c >= 65 && c <= 90))
        {
            return false;
        }
    }
    return true;
}
bool e_minusculo(std::string &string)
{
    for(int c : string)
    {
        if(!(c >= 97 && c <= 122))
        {
            return false;
        }
    }
    return true;
}


bool detecta_espacos(const std::string& string) {
    std::regex regexPattern("\\s{4,}");  // Regex para encontrar 4 ou mais espaços consecutivos

    if (std::regex_search(string, regexPattern)) {

        return true;  // Span  de espaços encontrado na string
    }

    return false;  // Nenhum span malicioso de espaços encontrado
}

bool nome_invalido(std::string &string)
{
    if(detecta_espacos(string))
    {   // nome inválido!
        throw SequenciaInvalidaEspacos();
        return true;
    }else if((e_maiusculo(string) || e_minusculo(string)))
    {   // nome válido
        return false;
    }else
    {   //  nome inválido!
        throw NomeInvalido();
        return true;
    }

}

bool sem_numeros(std::string &string) {
    for(char c : string) {
        if(std::isdigit(c)) return false;
    }

    return true;
}

bool apenas_numeros(std::string &string) {
    for(char c : string) {
        if(!std::isdigit(c)) return false;
    }

    return true;
}

void limpar_buffer(bool &estado) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    estado = true;
}

void menu(){
    std::cout << "1: Cadastrar paciente         2: Avaliar/reavaliar paciente         3: Ver dados do Paciente" << std::endl
        << "4: Remover paciente         5: Atribuir paciente ao médico         6: Sair" << std::endl << std::endl
        << "Digite o número da operação desejada: ";
}

void valida_opcao(bool& flag, unsigned& entrada)
{
    try{
        
        std::cin >> entrada;
        if(entrada <= 0 || entrada > 6){
            throw NumeroInvalido();                    
        }
    }catch(const NumeroInvalido &err)
    {
        std::cout << "Erro capturado => " << err.what() <<"\nPressione 6 para cancelar." << std::endl;
        flag = true;
        return;
    }
    flag = false;
    
}