#include "funcoes.hpp"
#include <limits>
#include "exception.hpp"
#include "medico.hpp"


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
        << "4: Remover paciente         5: Mostrar lista de pacientes completa         6: Sair" << std::endl << std::endl
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

std::vector<Medico> gerar_bd_medicos(std::vector<Medico> &medicos)
{
    std::srand (time(NULL));


    std::vector<std::string> sementes_crm = {"CRM 12345/SP", "CRM 67890/RJ", "CRM 24680/MG", 
                                            "CRM 13579/RS", "CRM 98765/BA", "CRM 10203/PR", 
                                            "CRM 45678/SC", "CRM 31415/PE", "CRM 17172/CE", 
                                            "CRM 81818/GO" };
std::vector<Medico> gerar_bd_medicos(std::vector<Medico>&medicos);

std::vector<std::string> sementes_especialidades = {"Clínica Geral", "Cardiologia", "Pediatria", 
                                                        "Ortopedia", "Ginecologia", "Neurologia", 
                                                        "Dermatologia", "Oftalmologia", "Psiquiatria", 
                                                        "Otorrinolaringologia" };

    std::vector<std::string> sementes_primeiro_nome = {"Dr. Lucas", "Dra. Isabela", "Dr. Mateus",  "Dra. Ana", 
                                                        "Dr. Metralha", "Dra. Laura", "Dr. Malucao", "Dra. Beatriz", 
                                                        "Dr. Felipe", "Dra. Mariana"};

    std::vector<std::string> sementes_sobrenome = {"Silva", "Santos", "Oliveira", "Rodrigues",
                                                       "Almeida", "Gonçalves", "Ferreira", "Sousa",
                                                       "Cardoso", "Fofão"};
    
    for(int i = 0; i < sementes_primeiro_nome.size(); ++i)
    {
       // gera um index aleatório 
       int index = rand() % sementes_primeiro_nome.size(); 
       std::string nome = sementes_primeiro_nome[index] +" "+ sementes_sobrenome[index];
       std::string crm = sementes_especialidades[i];
       std::string especialidade = sementes_especialidades[index];
       Medico temp_medico(nome, crm, especialidade);
       medicos.push_back(temp_medico);
    } 
 return medicos;
 }               
