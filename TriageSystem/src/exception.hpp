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

class OpcaoInvalida : public std::exception {
public:
    const char* what() const noexcept override; 
};
#endif