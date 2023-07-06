#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include<exception>


class NomeInvalido : public std::exception {
public:
    const char *what() const noexcept override;
};

class CpfInvalido : public std::exception {
public:
    const char *what() const noexcept override;
};

class ConvenioInvalido : public std::exception {
public:
    const char *what() const noexcept override;
};

class NumeroInvalido : public std::exception {
public:
    const char *what() const noexcept override;
};

class SequenciaInvalidaEspacos : public std::exception {
public:
    const char *what() const noexcept override;
};

class FormatoInvalido : public std::exception {
public:
    const char *what() const noexcept override;
};

class TemperaturaInvalida : public std::exception {
public:
    const char* what() const noexcept override;
};

class AlturaInvalida : public std::exception {
public:
    const char* what() const noexcept override;
};

class PesoInvalido : public std::exception {
public:
    const char* what() const noexcept override;
};

class FreqCardiacaInvalida : public std::exception {
public:
    const char* what() const noexcept override;
};

class PressaoInvalida : public std::exception {
public:
    const char* what() const noexcept override;
};
#endif