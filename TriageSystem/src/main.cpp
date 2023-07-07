#define NDEBUG
#include "lista.hpp"
#include "medico.hpp"
#include "paciente.hpp"
#include "exception.hpp"
#include "funcoes.hpp"
#include <sstream>
#include <unistd.h>
#include <vector>

int main() {
    
    std::vector<Medico> medicos;

    gerar_bd_medicos(medicos);

    ListaDePrioridade lista;
    
    bool exit = false, limpo = true;
    unsigned entrada;
    while(!exit) {
        bool opcao_invalida = true;
        menu();
        while(true) {
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
                if(medicos[0].pacientes.tamanho() <= medicos[1].pacientes.tamanho()) {
                    std::string medico = medicos[0].nome();
                    paciente.atribuir_medico(medico);
                    medicos[0].pacientes.adicionar_paciente(paciente);
                    std::cout << "->" << medicos[0].nome() << std::endl;
                } else {
                    std::string medico = medicos[1].nome();
                    paciente.atribuir_medico(medico);
                    medicos[1].pacientes.adicionar_paciente(paciente);
                    std::cout << "->" << medicos[1].nome() << std::endl;
                }
                lista.adicionar_paciente(paciente);
                std::cout << "Paciente cadastrado com sucesso!" << std::endl << std::endl;
                sleep(1);
                break;
            }
            case 2:
            {
                try {
                    unsigned prioridade;
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
                    std::cout << "Prioridade: ";
                    while(!(std::cin >> prioridade) || prioridade > 4) {                       
                        std::cout << "Prioridade inválida, tente novamente." << std::endl;
                        limpar_buffer(limpo);
                    }
                    limpo = false;
                    limpar_buffer(limpo);

                    paciente->editar_dados_paciente(prioridade);
                    lista.ordenar_paciente(paciente);
                    
                    if(paciente->medico() != medicos[0].nome() && paciente->medico() != medicos[1].nome()) {
                        for(int i = 2; i < 5; ++i) {
                            if(paciente->medico() == medicos[i].nome()) {
                                auto it = medicos[i].pacientes.procurar_paciente(nome);
                                medicos[i].atualizar_paciente(*paciente);
                                break;
                            }
                        }
                    } else {
                        for(int i = 0; i < 2; ++i) {
                            if(paciente->medico() == medicos[i].nome()) {
                                medicos[i].remover_paciente(nome);
                                int menor = 2;
                                for(int i = 3; i < 5; ++i) {
                                    if(medicos[menor].pacientes.tamanho() > medicos[i].pacientes.tamanho()) menor = i;
                                }
                                medicos[menor].pacientes.adicionar_paciente(*paciente);
                                std::cout << "->" << medicos[menor].nome() << std::endl;
                            }
                        }
                    }
                    
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
                    for(int i = 0; i < 5; ++i) {
                        if(paciente->medico() == medicos[i].nome()) {
                            medicos[i].remover_paciente(nome);
                        }
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
                if(lista.lista_vazia()) {
                    std::cout << "A lista está vazia." << std::endl << std::endl;
                    sleep(1);
                    break;
                }
                for(int i = 0; i < 5; ++i) {
                    if(!medicos[i].pacientes.lista_vazia()) {
                        std::cout << "Médico:" << medicos[i].nome() << std::endl;
                        medicos[i].pacientes.exibir_lista();
                    }
                }
                std::cout << std::endl << std::endl;
                sleep(1);
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