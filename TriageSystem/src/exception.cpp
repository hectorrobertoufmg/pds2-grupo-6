#include "exception.hpp"

const char *NomeInvalido::what() const noexcept {
    return "Nome inválido, tente novamente!";
}

const char *CpfInvalido::what() const noexcept {
    return "CPF inválido!";
}

const char *ConvenioInvalido::what() const noexcept {
    return "Convênio inválido!";
}

const char *NumeroInvalido::what() const noexcept {
    return "Número inválido, tente novamente!";
}

const char *SequenciaInvalidaEspacos::what() const noexcept {
    return "Número muito grande de espaços ( >4 consecutivos ), tente novamente!";
}