#include <iostream>
#include <string>
#include "anamnese.hpp"
#include "funcoes.hpp"

/**
 * @brief Construtor padrão da classe Anamnese.
 */
Anamnese::Anamnese() {}

/**
 * @brief Construtor da classe Anamnese.
 * @param sintomas Os sintomas informados na anamnese.
 * @param temperatura A temperatura informada na anamnese.
 * @param altura A altura informada na anamnese.
 * @param peso O peso informado na anamnese.
 * @param freq_cardiaca A frequência cardíaca informada na anamnese.
 * @param pressao A pressão informada na anamnese.
 */
Anamnese::Anamnese(const std::string &sintomas, float temperatura, float altura, float peso, unsigned freq_cardiaca, const std::string &pressao) {
    _sintomas = sintomas;
    _temperatura = temperatura;
    _altura = altura;
    _peso = peso;
    _freq_cardiaca = freq_cardiaca;
    _pressao = pressao;
}

/**
 * @brief Obtém os sintomas informados na anamnese.
 * @return Os sintomas da anamnese.
 */
std::string Anamnese::verSintomas() const {
    return _sintomas;
}

/**
 * @brief Edita os sintomas da anamnese.
 * @param sintomas Os novos sintomas a serem atribuídos.
 */
void Anamnese::editarSintomas(const std::string &sintomas) {
    _sintomas = sintomas;
}

/**
 * @brief Obtém a temperatura informada na anamnese.
 * @return A temperatura da anamnese.
 */
float Anamnese::verTemperatura() const {
    return _temperatura;
}

/**
 * @brief Edita a temperatura da anamnese.
 * @param temperatura A nova temperatura a ser atribuída.
 */
void Anamnese::editarTemperatura(float temperatura) {
    _temperatura = temperatura;
}

/**
 * @brief Obtém a altura informada na anamnese.
 * @return A altura da anamnese.
 */
float Anamnese::verAltura() const {
    return _altura;
}

/**
 * @brief Edita a altura da anamnese.
 * @param altura A nova altura a ser atribuída.
 */
void Anamnese::editarAltura(float altura) {
    _altura = altura;
}

/**
 * @brief Obtém o peso informado na anamnese.
 * @return O peso da anamnese.
 */
float Anamnese::verPeso() const {
    return _peso;
}

/**
 * @brief Edita o peso da anamnese.
 * @param peso O novo peso a ser atribuído.
 */
void Anamnese::editarPeso(float peso) {
    _peso = peso;
}

/**
 * @brief Obtém a frequência cardíaca informada na anamnese.
 * @return A frequência cardíaca da anamnese.
 */
unsigned Anamnese::verFreq_Cardiaca() const {
    return _freq_cardiaca;
}

/**
 * @brief Edita a frequência cardíaca da anamnese.
 * @param freq_cardiaca A nova frequência cardíaca a ser atribuída.
 */
void Anamnese::editarFreq_Cardiaca(unsigned freq_cardiaca) {
    _freq_cardiaca = freq_cardiaca;
}

/**
 * @brief Obtém a pressão informada na anamnese.
 * @return A pressão da anamnese.
 */
std::string Anamnese::verPressao() const {
    return _pressao;
}

/**
 * @brief Edita a pressão da anamnese.
 * @param pressao A nova pressão a ser atribuída.
 */
void Anamnese::editarPressao(const std::string &pressao) {
    _pressao = pressao;
}

/**
 * @brief Visualiza os dados da anamnese.
 */
void Anamnese::visualizarAnamnese() const {
    std::cout << "Sintomas: " << _sintomas << std::endl;
    std::cout << "Temperatura: " << _temperatura << "°C" << std::endl;
    std::cout << "Altura: " << _altura << "m" << std::endl;
    std::cout << "Peso: " << _peso << "kg" << std::endl;
    std::cout << "Frequência Cardíaca: " << _freq_cardiaca << "bpm" << std::endl;
    std::cout << "Pressão: " << _pressao << std::endl;
}

/**
 * @brief Coleta os dados da anamnese.
 * @return Uma instância de Anamnese preenchida com os dados coletados.
 */
Anamnese Anamnese::coletarDadosAnamnese() {
    std::string sintomas;
    float temperatura;
    float altura;
    float peso;
    unsigned freq_cardiaca;
    std::string pressao;
    bool limpo = true;

    try {
        std::cout << "Coleta de dados da anamnese" << std::endl;

        std::cout << "Sintomas: ";
        std::getline(std::cin, sintomas);

        while (true) {
            std::cout << "Temperatura: ";
            if (!(std::cin >> temperatura)) {
                std::cout << "Temperatura inválida. Digite um número." << std::endl;
                limpar_buffer(limpo);
                continue;
            }

            if (temperatura < 0.0f) {
                std::cout << "Temperatura inválida. O valor deve estar acima de 0°C." << std::endl;
                continue;
            }

            break;
        }

        while (true) {
            std::cout << "Altura: ";
            if (!(std::cin >> altura)) {
                std::cout << "Altura inválida. Digite um número." << std::endl;
                limpar_buffer(limpo);
                continue;
            }

            if (altura < 0.0f || altura > 3.0f) {
                std::cout << "Altura inválida. O valor deve estar entre 0m e 3m." << std::endl;
                continue;
            }

            break;
        }

        while (true) {
            std::cout << "Peso: ";
            if (!(std::cin >> peso)) {
                std::cout << "Peso inválido. Digite um número." << std::endl;
                limpar_buffer(limpo);
                continue;
            }

            if (peso < 0.0f || peso >500.0f) {
                std::cout << "Peso inválido. O valor deve estar entre 0 e 500kg." << std::endl;
                continue;
            }

            break;
        }

        while (true) {
            std::cout << "Frequência Cardíaca: ";
            if (!(std::cin >> freq_cardiaca)) {
                std::cout << "Frequência Cardíaca inválida. Digite um número." << std::endl;
                limpar_buffer(limpo);
                continue;
            }

            break;
        }

        std::cin.ignore();

        while (true) {
            std::cout << "Pressão: ";
            std::getline(std::cin, pressao);

            if (!validarPressao(pressao)) {
                std::cout << "Pressão inválida. Digite no formato 'xx/xx' ou 'xxx/xxx'." << std::endl;
                continue;
            }

            break;
        }

        return Anamnese(sintomas, temperatura, altura, peso, freq_cardiaca, pressao);

    } catch (const std::exception &e) {
        std::cout << "Ocorreu um erro durante a coleta de dados da anamnese: " << e.what() << std::endl;
        return Anamnese();
    }
}
