#include "lista.hpp"

bool ListaDePrioridade::adicionar_paciente(Paciente &paciente) {
    if(_pacientes.empty()) {
        _pacientes.push_back(paciente);
        return true;
    }

    std::_List_iterator<Paciente> it = _pacientes.begin();
    for(it; it != _pacientes.end(); ++it) {
        if(paciente.get_cor() < it->get_cor()) {
            _pacientes.insert(it, paciente);
            return true;
        }
    }

    if(it == _pacientes.end()) {
        _pacientes.push_back(paciente);
        return true;
    }

    return false;
}

std::_List_iterator<Paciente> ListaDePrioridade::procurar_paciente(std::string &nome) {
    if(_pacientes.empty()) throw ListaVazia();

    std::_List_iterator<Paciente> it = _pacientes.begin();
    for(it; it != _pacientes.end(); ++it) {
        if(it->get_nome() == nome) return it;
    }
    return it;
}

bool ListaDePrioridade::remover_paciente(std::_List_iterator<Paciente> &posicao) {
    if(_pacientes.empty()) throw ListaVazia();

    if(posicao != _pacientes.end()) {
        _pacientes.erase(posicao);
        return true;
    }
    return false;
}

void ListaDePrioridade::ordenar_paciente(std::_List_iterator<Paciente> &posicao) {
    if(_pacientes.empty()) throw ListaVazia();

    Paciente paciente = *posicao;
    _pacientes.erase(posicao);
    ListaDePrioridade::adicionar_paciente(paciente);
}

void ListaDePrioridade::exibir_lista() const {
    if(_pacientes.empty()) throw ListaVazia();
    
    for(std::_List_const_iterator<Paciente> it = _pacientes.begin(); it != _pacientes.end(); ++it) {
        it->imprimir_paciente();
    }
}

std::_List_iterator<Paciente> ListaDePrioridade::fim_lista() {
    return _pacientes.end();
}

const char *ListaVazia::what() const noexcept {
    return "A lista está vazia!";
}