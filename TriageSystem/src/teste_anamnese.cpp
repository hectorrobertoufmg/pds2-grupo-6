
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "anamnese.hpp"
#include "exception.hpp"

TEST_CASE("Testes de visualizar e coletar dados da Anamnese = métodos individuais") {

    Anamnese anamnese;
    anamnese.editarSintomas("Dor de cabeça");
    anamnese.editarTemperatura(37.5);
    anamnese.editarAltura(1.75);
    anamnese.editarPeso(70.0);
    anamnese.editarFreq_Cardiaca(80);
    anamnese.editarPressao("120/80");
    
    
    CHECK(anamnese.verSintomas() == "Dor de cabeça");
           
    CHECK(anamnese.verTemperatura() == 37.5);

    
    CHECK(anamnese.verAltura() == 1.75);

    
    CHECK(anamnese.verPeso() == 70.0);

    
    CHECK(anamnese.verFreq_Cardiaca() == 80);

   
    CHECK(anamnese.verPressao() == "120/80");
}

TEST_CASE("Teste VisualizarAnamnese") {
    Anamnese anamnese("Dor de cabeça", 37.5, 1.75, 70, 80, "120/80");

    std::ostringstream output;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    anamnese.visualizarAnamnese();

    std::cout.rdbuf(originalCoutBuffer);

   std::string expected = "Sintomas: Dor de cabeça\n"
                       "Temperatura: 37.5°C\n"
                       "Altura: 1.75m\n"
                       "Peso: 70kg\n"
                       "Frequência Cardíaca: 80bpm\n"
                       "Pressão: 120/80\n";

    CHECK(output.str() == expected);

}
TEST_CASE("Teste ColetarDadosAnamnese") {
    std::istringstream input("Dor de cabeça\n37.5\n1.75\n70\n80\n120/80\n");

    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());

    Anamnese anamnese = Anamnese::coletarDadosAnamnese();

    std::cin.rdbuf(orig);

    CHECK(anamnese.verSintomas() == "Dor de cabeça");
    CHECK(anamnese.verTemperatura() == 37.5);
    CHECK(anamnese.verAltura() == 1.75);
    CHECK(anamnese.verPeso() == 70);
    CHECK(anamnese.verFreq_Cardiaca() == 80);
    CHECK(anamnese.verPressao() == "120/80");
}
