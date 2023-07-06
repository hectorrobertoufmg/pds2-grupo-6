#ifndef ANAMNESE_HPP
#define ANAMNESE_HPP

#include <string>
#include <regex>


class Anamnese {

private:

    std::string _sintomas;
    float _temperatura;
    float _altura;
    float _peso;
    unsigned _freq_cardiaca;
    std::string _pressao;

public:

    Anamnese();
    Anamnese(const std::string& sintomas, float temperatura, float altura, float peso, unsigned freq_cardiaca, const std::string& pressao);

    std::string verSintomas() const;
    void editarSintomas(const std::string &sintomas);

    float verTemperatura() const;
    void editarTemperatura(float temperatura);

    float verAltura() const;
    void editarAltura(float altura);

    float verPeso() const;
    void editarPeso(float peso);

    unsigned verFreq_Cardiaca() const;
    void editarFreq_Cardiaca(unsigned freq_cardiaca);

    std::string verPressao() const;
    void editarPressao(const std::string &pressao);

    void visualizarAnamnese() const;

    static Anamnese coletarDadosAnamnese();
};

#endif 
