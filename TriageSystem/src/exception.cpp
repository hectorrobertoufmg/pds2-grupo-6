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

const char *FormatoInvalido::what() const noexcept {
    return "Formato Inválido, tente novamente!";
}

const char* TemperaturaInvalida::what() const noexcept {
    return "Temperatura inválida. O valor deve estar acima de 0°C.";
}

const char* AlturaInvalida::what() const noexcept {
    return "Altura inválida. O valor deve estar entre 0m e 3m.";
}

const char* PesoInvalido::what() const noexcept {
    return "Peso inválido. O valor deve estar entre 0 e 500kg.";
}

const char* FreqCardiacaInvalida::what() const noexcept {
    return "Frequência Cardíaca inválida. O valor deve ser um número inteiro positivo.";
}

const char* PressaoInvalida::what() const noexcept {
    return "Pressão inválida. Digite no formato 'xx/xx' ou 'xxx/xxx'.";
}