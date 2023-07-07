#include "setor.hpp"
#include "paciente.hpp"

Setor::Setor(const std::string& nome, unsigned capacidade)
    : _nome(nome), _capacidade(capacidade), _disponibilidade(capacidade) {}

void Setor::adicionar_paciente(const Paciente& paciente) {
    if (_disponibilidade > 0) {
        _pacientes.push_back(paciente);
        _disponibilidade--;
        std::cout << "Paciente adicionado ao setor " << _nome << std::endl;
    } else {
        std::cout << "O setor " << _nome << " está cheio. Não é possível adicionar mais pacientes." << std::endl;
    }
}

void Setor::trocar_paciente_de_setor(const std::string& nome, const std::string& novoSetor) {
    for (auto& paciente : _pacientes) {
        if (paciente.obter_nome() == nome) {
            std::cout << "Paciente " << nome << " movido do setor " << _nome << " para o setor " << novoSetor << std::endl;
            paciente.editar_setor(novoSetor);
            return;
        }
    }
    std::cout << "Paciente " << nome << " não encontrado no setor " << _nome << std::endl;
}

void Setor::imprimir_setor() const {
    std::cout << "Informações do setor: " << _nome << std::endl;
    std::cout << "Capacidade: " << _capacidade << std::endl;
    std::cout << "Disponibilidade: " << _disponibilidade << std::endl;
    std::cout << "Pacientes no setor: " << std::endl;
    for (const auto& paciente : _pacientes) {
        paciente.imprimir_paciente();
        std::cout << std::endl;
    }
}