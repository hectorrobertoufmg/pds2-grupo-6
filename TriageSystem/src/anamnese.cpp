
       
        #include <iostream>
        #include <string>
        #include "anamnese.hpp"

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

            std::cout << "Coleta de dados da anamnese" << std::endl;

            std::cout << "Sintomas: ";
            std::getline(std::cin, sintomas);

            std::cout << "Temperatura: ";
            std::cin >> temperatura;

            std::cout << "Altura: ";
            std::cin >> altura;

            std::cout << "Peso: ";
            std::cin >> peso;

            std::cout << "Frequência Cardíaca: ";
            std::cin >> freq_cardiaca;

            std::cout << "Pressão: ";
            std::cin.ignore();
            std::getline(std::cin, pressao);

            return Anamnese(sintomas, temperatura, altura, peso, freq_cardiaca, pressao);

            }