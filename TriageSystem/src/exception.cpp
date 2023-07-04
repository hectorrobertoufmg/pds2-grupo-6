#include "exception.hpp"

const char *NomeInvalido::what() const noexcept {
    return "Nome inválido!";
}

const char *CpfInvalido::what() const noexcept {
    return "CPF inválido!";
}

const char *ConvenioInvalido::what() const noexcept {
    return "Convênio inválido!";
}