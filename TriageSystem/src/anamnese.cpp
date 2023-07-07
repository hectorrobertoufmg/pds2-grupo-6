
       
        #include <iostream>
        #include <string>
        #include "anamnese.hpp"
        #include "funcoes.hpp"

            Anamnese::Anamnese() {}
            Anamnese::Anamnese (const std::string &sintomas, float temperatura, float altura, float peso, unsigned freq_cardiaca, const std:: string &pressao){
                _sintomas = sintomas;
                _temperatura = temperatura;
                _altura = altura;
                _peso = peso;
                _freq_cardiaca=freq_cardiaca;
                _pressao = pressao;
            }
            
            std::string Anamnese::verSintomas() const {

                return _sintomas;
            }

            void Anamnese::editarSintomas(const std::string &sintomas)   {

                _sintomas = sintomas;
            }

            float Anamnese::verTemperatura() const{

                return _temperatura;
            }

            void Anamnese::editarTemperatura(float temperatura){

                _temperatura = temperatura;
            }

            float Anamnese::verAltura() const{

                return _altura;
            }

            void Anamnese::editarAltura(float altura){

                _altura = altura;
            }

            float Anamnese::verPeso() const{

                return _peso;
            }

            void Anamnese::editarPeso(float peso){

                _peso = peso;
            }

            unsigned Anamnese::verFreq_Cardiaca() const{

                return _freq_cardiaca;
            }

            void Anamnese::editarFreq_Cardiaca(unsigned freq_cardiaca){
            
                _freq_cardiaca = freq_cardiaca;
            }

            std::string Anamnese::verPressao() const {
                
                return _pressao;
            }

            void Anamnese::editarPressao(const std::string &pressao){

                _pressao = pressao;
            }

            void Anamnese::visualizarAnamnese() const{

                std::cout << "Sintomas: " << _sintomas << std::endl;
            std::cout << "Temperatura: " << _temperatura << "°C " << std::endl;
            std::cout << "Altura: " << _altura <<"m" << std::endl;
            std::cout << "Peso: " << _peso << "kg" << std::endl;
            std::cout << "Frequência Cardíaca: " <<_freq_cardiaca << "bpm" << std::endl;
            std::cout << "Pressão: " << _pressao << std::endl;
            }

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

            if (peso < 0.0f || peso > 500.0f) {
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

    } catch (const std::exception& e) {
        std::cout << "Ocorreu um erro durante a coleta de dados da anamnese: " << e.what() << std::endl;
        return Anamnese();
    }
}
