#include "lista.hpp"
#include <unistd.h>

int main() {
    ListaDePrioridade lista;
    bool exit = false;
    while(!exit) {
        unsigned entrada;
        std::cout << "1: Cadastrar paciente         2: Avaliar/reavaliar paciente         3: Ver dados do Paciente" << std::endl
        << "4: Remover paciente         5: Atribuir paciente ao médico         6: Sair" << std::endl << std::endl
        << "Digite o número da operação desejada: ";
        std::cin >> entrada;
        switch(entrada) {
            case 1:
            {
                std::string nome, cpf, convenio;
                unsigned idade;

                while(true) {
                    std::cout << "Nome: ";
                    std::cin >> nome;
                    if(!sem_numeros(nome)) {
                        std::cout << "Nome inválido, tente novamente." << std::endl;
                        sleep(1);
                        continue;
                    }
                    break;
                }
                std::cout << "Idade: ";
                std::cin >> idade;
                while(true) {
                    std::cout << "CPF: ";
                    std::cin >> cpf;
                    if(!apenas_numeros(cpf) || cpf.size() != 11) {
                        std::cout << "CPF inválido, tente novamente." << std::endl;
                        sleep(1);
                        continue;
                    }
                    break;
                }
                while(true) {
                    std::cout << "Convênio: ";
                    std::cin >> convenio;
                    if(!sem_numeros(convenio)) {
                        std::cout << "Convênio inválido, tente novamente." << std::endl;
                        sleep(1);
                        continue;
                    }
                    break;
                }
                Paciente paciente(nome, idade, cpf, convenio);
                lista.adicionar_paciente(paciente);
                std::cout << "Paciente cadastrado com sucesso!" << std::endl << std::endl;
                sleep(1);
                break;
            }
            case 2:
            {
                unsigned cor;
                std::string nome;
                std::_List_iterator<Paciente> paciente;
                while(true) {
                    std::cout << "Nome: ";
                    std::cin >> nome;
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
                while(true) {
                    std::cout << "Cor: ";
                    std::cin >> cor;
                    if(cor > 4) {
                        std::cout << "Cor inválida, tente novamente." << std::endl;
                        sleep(1);
                        continue;
                    }
                    paciente->editar_dados_paciente(cor);
                    break;
                }
                std::cout << "Avaliação registrada." << std::endl << std::endl;
                sleep(1);
                break;
            }
            case 3:
            {
                std::string nome;
                std::_List_iterator<Paciente> paciente;
                while(true) {
                    std::cout << "Nome: ";
                    std::cin >> nome;
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
            }
            case 4:
            {
                std::string nome;
                std::_List_iterator<Paciente> paciente;
                while(true) {
                    std::cout << "Nome: ";
                    std::cin >> nome;
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
                lista.remover_paciente(paciente);
                std::cout << "Paciente removido." << std::endl << std::endl;
                sleep(1);
                break;
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