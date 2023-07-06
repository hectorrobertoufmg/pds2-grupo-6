#include "funcoes.hpp"
#include <limits>
#include "exception.hpp"
#include <regex>


bool tem_spam_espacos(const std::string& string) {
    std::regex regexPattern("\\s{4,}");  // Regex para encontrar 4 ou mais espaços consecutivos

    if (std::regex_search(string, regexPattern)) {

        return true;  // Span  de espaços encontrado na string
    }

    return false;  // Nenhum span malicioso de espaços encontrado
}


bool nome_invalido(std::string &string)
{
    try
    {
        if(tem_spam_espacos(string))
        {   // Nome com spam de espaços!
            throw SequenciaInvalidaEspacos();
        }
        else if(!(sem_numeros(string)))
        {
            throw NomeInvalido();
        }

    }
    catch(SequenciaInvalidaEspacos &err)
    {
        std::cout << err.what() << std::endl;
        return true;
    }
    catch(NomeInvalido &err)
    {
        std::cout << err.what() << std::endl;
        return true;
    }

    return false;



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

bool validarPressao(const std::string& pressao) {
    std::regex pressao_regex(R"(\d{2,3}/\d{2,3})");

    return std::regex_match(pressao, pressao_regex);
}
