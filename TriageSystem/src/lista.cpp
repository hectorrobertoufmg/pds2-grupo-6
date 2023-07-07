#include "lista.hpp"

bool ListaDePrioridade::adicionar_paciente(Paciente &paciente) {
    if(_pacientes.empty()) {
        _pacientes.push_back(paciente);
        assert(*(_pacientes.begin()) == paciente);
        return true;
    }

    std::_List_iterator<Paciente> it = _pacientes.begin();
    for(it; it != _pacientes.end(); ++it) {
        if(paciente.prioridade() < it->prioridade()) {
            _pacientes.insert(it, paciente);
            assert((*(std::prev(it)) == paciente) && ordenado());
            return true;
        }
    }

    if(it == _pacientes.end()) {
        _pacientes.push_back(paciente);
        assert((*(_pacientes.rbegin()) == paciente) && ordenado());
        return true;
    }

    return false;
}

std::_List_iterator<Paciente> ListaDePrioridade::procurar_paciente(std::string &nome) {
    if(_pacientes.empty()) throw ListaVazia();

    std::_List_iterator<Paciente> it = _pacientes.begin();
    for(it; it != _pacientes.end(); ++it) {
        if(it->nome() == nome) return it;
    }
    return it;
}

bool ListaDePrioridade::remover_paciente(std::_List_iterator<Paciente> &posicao) {
    if(_pacientes.empty()) throw ListaVazia();

    if(posicao != _pacientes.end()) {
        _pacientes.erase(posicao);
        assert(ordenado());
        return true;
    }
    assert(ordenado());
    return false;
}

bool ListaDePrioridade::remover_paciente(std::string &nome) {
    if(_pacientes.empty()) throw ListaVazia();

    std::_List_iterator<Paciente> it = procurar_paciente(nome);
    if(it == _pacientes.end()) return false;
    if(remover_paciente(it)) {
        assert(ordenado());
        return true;
    }
    assert(ordenado());
    return false;
}

void ListaDePrioridade::ordenar_paciente(std::_List_iterator<Paciente> &posicao) {
    if(_pacientes.empty()) throw ListaVazia();

    Paciente paciente = *posicao;
    _pacientes.erase(posicao);
    ListaDePrioridade::adicionar_paciente(paciente);
    assert(ordenado());
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

bool ListaDePrioridade::lista_vazia() const {
    return _pacientes.empty();
}

bool ListaDePrioridade::ordenado() {
    for(std::_List_iterator<Paciente> it = _pacientes.begin(); it != std::prev(_pacientes.end()); ++it) {
        if(it->prioridade() > std::next(it)->prioridade()) return false;
    }
    return true;
}

int ListaDePrioridade::tamanho() {
    return _pacientes.size();
}