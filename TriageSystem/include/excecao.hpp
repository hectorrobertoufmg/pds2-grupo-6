#ifndef EXCECAO_H
#define EXCECAO_H

#include <exception>

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

#endif