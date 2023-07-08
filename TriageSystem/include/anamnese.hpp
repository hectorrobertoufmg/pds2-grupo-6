#ifndef ANAMNESE_HPP
#define ANAMNESE_HPP

#include <string>
/**
 * @brief Construtor da classe Anamnese.
 * @param sintomas Os sintomas informados na anamnese.
 * @param temperatura A temperatura informada na anamnese.
 * @param altura A altura informada na anamnese.
 * @param peso O peso informado na anamnese.
 * @param freq_cardiaca A frequência cardíaca informada na anamnese.
 * @param pressao A pressão informada na anamnese.
 */
class Anamnese {
public:
    Anamnese();
    Anamnese(const std::string& sintomas, float temperatura, float altura, float peso, unsigned freq_cardiaca, const std::string& pressao);
    /**
     * @brief Obtém os sintomas informados na anamnese.
     * @return Os sintomas da anamnese.
     */
    std::string verSintomas() const;
    /**
     * @brief Edita os sintomas da anamnese.
     * @param sintomas Os novos sintomas a serem atribuídos.
     */
    void editarSintomas(const std::string &sintomas);

    /**
     * @brief Obtém a temperatura informada na anamnese.
     * @return A temperatura da anamnese.
     */
    float verTemperatura() const;

    /**
     * @brief Edita a temperatura da anamnese.
     * @param temperatura A nova temperatura a ser atribuída.
     */
    void editarTemperatura(float temperatura);
    /**
     * @brief Obtém a altura informada na anamnese.
     * @return A altura da anamnese.
     */
    float verAltura() const;

    /**
     * @brief Edita a altura da anamnese.
     * @param altura A nova altura a ser atribuída.
     */
    void editarAltura(float altura);

    /**
     * @brief Obtém o peso informado na anamnese.
     * @return O peso da anamnese.
     */
    float verPeso() const;

    /**
     * @brief Edita o peso da anamnese.
     * @param peso O novo peso a ser atribuído.
     */
    void editarPeso(float peso);

    /**
     * @brief Obtém a frequência cardíaca informada na anamnese.
     * @return A frequência cardíaca da anamnese.
     */
    unsigned verFreq_Cardiaca() const;

    /**
     * @brief Edita a frequência cardíaca da anamnese.
     * @param freq_cardiaca A nova frequência cardíaca a ser atribuída.
     */
    void editarFreq_Cardiaca(unsigned freq_cardiaca);

    /**
     * @brief Obtém a pressão informada na anamnese.
     * @return A pressão da anamnese.
     */
    std::string verPressao() const;

    /**
     * @brief Edita a pressão da anamnese.
     * @param pressao A nova pressão a ser atribuída.
     */
    void editarPressao(const std::string &pressao);

    /**
     * @brief Visualiza os dados da anamnese.
     */
    void visualizarAnamnese() const;
    
    /**
     * @brief Coleta os dados da anamnese.
     * @return Uma instância de Anamnese preenchida com os dados coletados.
     */
    static Anamnese coletarDadosAnamnese();

private:
    std::string _sintomas;
    float _temperatura;
    float _altura;
    float _peso;
    unsigned _freq_cardiaca;
    std::string _pressao;
};

#endif