#include "lista.hpp"
#include <sstream>
#include <unistd.h>
#include "exception.hpp"


int main() {
    ListaDePrioridade lista;
    bool exit = false, limpo = true, opcao_invalida = true;
    unsigned entrada;
    while(!exit) {
        menu();
        while(true){
            valida_opcao(opcao_invalida, entrada);
            limpar_buffer(limpo);
            if(!opcao_invalida) break;
        }
        switch(entrada) {
            case 1:
            {
                std::string nome, cpf, convenio;
                unsigned idade;

                while(true) {
                    std::cout << "Nome: ";
                    if(!limpo) limpar_buffer(limpo);
                    std::getline(std::cin, nome);
                    if(nome_invalido(nome)) {
        
                        sleep(1);
                        continue;
                    }
                    break;
                }
                std::cout << "Idade: ";
                while(!(std::cin >> idade)) {
                    std::cout << "Idade inválida! Digite um número inteiro." << std::endl;
                    limpar_buffer(limpo);
                }
                limpo = false;
                while(true) {
                    std::cout << "CPF: ";
                    if(!limpo) limpar_buffer(limpo);
                    std::getline(std::cin, cpf);
                    if(!apenas_numeros(cpf) || cpf.size() != 11) {
                        std::cout << "CPF inválido, tente novamente." << std::endl;
                        sleep(1);
                        continue;
                    }
                    break;
                }
                while(true) {
                    std::cout << "Convênio: ";
                    if(!limpo) limpar_buffer(limpo);
                    std::getline(std::cin, convenio);
                    if(!sem_numeros(convenio)) {
                        std::cout << "Convênio inválido, tente novamente." << std::endl;
                        
                        sleep(1);
                        continue;
                    }
                    break;
                }
        

                Paciente paciente(nome, idade, cpf, convenio);              
                Anamnese anamnese = Anamnese::coletarDadosAnamnese();
                paciente.associarAnamnese(anamnese);
                lista.adicionar_paciente(paciente);
                std::cout << "Paciente cadastrado com sucesso!" << std::endl;

                
                std::cout << "Anamnese cadastrada com sucesso!" << std::endl;
                
                sleep(1);
                break;
            }
            case 2:
            {
                try {
                    unsigned cor;
                    std::string nome;
                    std::_List_iterator<Paciente> paciente;
                    while(true) {
                        std::cout << "Nome: ";
                        if(!limpo) limpar_buffer(limpo);
                        std::getline(std::cin, nome);
                        if(nome_invalido(nome)) {
                            sleep(1);
                            continue;
                        }
                        paciente = lista.procurar_paciente(nome);
                        break;
                    }
                    if(paciente == lista.fim_lista()) {
                        std::cout << "O paciente não está cadastrado." << std::endl << std::endl;
                        sleep(1);
                        break;
                    }
                    std::cout << "Cor: ";
                    while(!(std::cin >> cor) || cor > 4) {                       
                        std::cout << "Cor inválida, tente novamente." << std::endl;
                        limpar_buffer(limpo);
                    }
                    limpo = false;
                    paciente->editar_dados_paciente(cor);
                    std::cout << "Avaliação registrada." << std::endl << std::endl;
                    sleep(1);
                    break;
                } catch(const ListaVazia &e) {
                    std::cout << "A lista de pacientes está vazia." << std::endl << std::endl;
                    sleep(1);
                    break;
                }
            }
            case 3:
            {
                try {
                    std::string nome;
                    std::_List_iterator<Paciente> paciente;
                    while(true) {
                        std::cout << "Nome: ";
                        if(!limpo) limpar_buffer(limpo);
                        std::getline(std::cin, nome);
                        if(!sem_numeros(nome)) {
                            std::cout << "Nome inválido, tente novamente." << std::endl;
                            sleep(1);
                            continue;
                        }
                        paciente = lista.procurar_paciente(nome);
                        break;
                    }
                    if(paciente == lista.fim_lista()) {
                        std::cout << "O paciente não está cadastrado." << std::endl << std::endl;
                        sleep(1);
                        break;
                    }
                    paciente->imprimir_paciente();
                    std::cout << std::endl;
                    sleep(1);
                    break;
                } catch(const ListaVazia &e) {
                    std::cout << "A lista de pacientes está vazia." << std::endl << std::endl;
                    sleep(1);
                    break;
                }
            }
            case 4:
            {
                try {
                    std::string nome;
                    std::_List_iterator<Paciente> paciente;
                    while(true) {
                        std::cout << "Nome: ";
                        if(!limpo) limpar_buffer(limpo);
                        std::getline(std::cin, nome);
                        if(nome_invalido(nome)) {
                            sleep(1);
                            continue;
                        }
                        paciente = lista.procurar_paciente(nome);
                        break;
                    }
                    if(paciente == lista.fim_lista()) {
                        std::cout << "O paciente não está cadastrado." << std::endl << std::endl;
                        sleep(1);
                        break;
                    }
                    lista.remover_paciente(paciente);
                    std::cout << "Paciente removido." << std::endl << std::endl;
                    sleep(1);
                    break;
                } catch(const ListaVazia &e) {
                    std::cout << "A lista de pacientes está vazia." << std::endl << std::endl;
                    sleep(1);
                    break;
                }
            }
            case 5:
            {
                
                break;
            }
            case 6:
            {
                exit = true;
                std::cout << "Saindo..." << std::endl;
                sleep(2);
                break;
            }
            default:
            {
                std::cout << "Entrada inválida, tente novamente." << std::endl << std::endl;
                sleep(1);
                break;
            }
        }
    }

    return 0;
}