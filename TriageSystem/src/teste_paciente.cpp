#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "paciente.hpp"

TEST_CASE("Teste construtor de Paciente") {
    SUBCASE("Paciente com nome válido") {
        std::string nome = "Maria";
        unsigned idade=30;
        std::string cpf="12345678901";
        std::string convenio="Convênio A";
        CHECK_NOTHROW(Paciente(nome, idade, cpf, convenio));
    }

    SUBCASE("Paciente com nome inválido") {
        
        std::string nome = "1234";
        unsigned idade=25;
        std::string cpf="12345678901";
        std::string convenio="Convênio B";
        CHECK_THROWS_AS(Paciente(nome, idade, cpf, convenio), NomeInvalido&);
    }

    SUBCASE("Paciente com CPF inválido") {
        std::string nome = "João";
        unsigned idade=35;
        std::string cpf="1234";
        std::string convenio="Convênio C";
        CHECK_THROWS_AS(Paciente(nome, idade, cpf, convenio), CpfInvalido&);
    }

    SUBCASE("Paciente com convênio inválido") {
        std::string nome = "Ana";
        unsigned idade=40;
        std::string cpf="12345678901";
        std::string convenio="1234";
        CHECK_THROWS_AS(Paciente(nome, idade, cpf, convenio), ConvenioInvalido&);
    }
}

TEST_CASE("Teste imprimir_paciente") {
    std::string nome = "José";
    unsigned idade=50;
    std::string cpf="12345678901";
    std::string convenio="Convênio D";
    Paciente paciente(nome, idade, cpf, convenio);

    SUBCASE("Verificar saída no console") {
        const std::string expectedOutput = "Informações do paciente José\nIdade: 50\nCPF: 12345678901\nConvênio: Convênio D\nCor: 5\n";
        CHECK(paciente.imprimir_paciente() == expectedOutput);
    }
}

TEST_CASE("Teste editar_dados_paciente") {
    std::string nome = "Carlos";
    unsigned idade=45;
    std::string cpf="12345678901";
    std::string convenio="Convênio E";
    Paciente paciente(nome, idade, cpf, convenio);

    SUBCASE("Editar cor") {
        paciente.editar_dados_paciente(3);

        CHECK(paciente.get_cor() == 3);
    }
}

TEST_CASE("Teste exceções") {
    SUBCASE("Lançar exceção NomeInvalido") {
        std::string nome = "1234";
        int idade=30;
        std::string cpf="12345678901";
        std::string convenio="Convênio A";
        CHECK_THROWS_AS(Paciente(nome,  idade, cpf, convenio), NomeInvalido&);
    }

    SUBCASE("Lançar exceção CpfInvalido") {
        std::string nome = "Maria";
        int idade=25;
        std::string cpf="1234";
        std::string convenio="Convênio B";
        CHECK_THROWS_AS(Paciente(nome,  idade, cpf, convenio), CpfInvalido&);
    }

    SUBCASE("Lançar exceção ConvenioInvalido") {
        std::string nome = "João";
        int idade=40;
        std::string cpf="12345678901";
        std::string convenio="1234";
        CHECK_THROWS_AS(Paciente(nome,  idade, cpf, convenio), ConvenioInvalido&);
    }
}

TEST_CASE("Teste adicional") {
    std::string nome = "Laura";
    int idade=35;
    std::string cpf="98765432109";
    std::string convenio="Convênio F";
    Paciente paciente(nome,  idade, cpf, convenio);

    SUBCASE("Verificar dados do paciente") {
        CHECK(paciente.get_nome() == "Laura");
        CHECK(paciente.get_idade() == 35);
        CHECK(paciente.get_cpf() == "98765432109");
        CHECK(paciente.get_convenio() == "Convênio F");
        CHECK(paciente.get_cor() == 5);
    }

    SUBCASE("Editar dados do paciente") {
        paciente.editar_dados_paciente(2);

        CHECK(paciente.get_cor() == 2);
    }
}

TEST_CASE("Teste adicional 2") {
    std::string nome = "Pedro";
    int idade=28;
    std::string cpf="56789012345";
    std::string convenio="Convênio G";
    Paciente paciente(nome,  idade, cpf, convenio);

    SUBCASE("Verificar dados do paciente") {
        CHECK(paciente.get_nome() == "Pedro");
        CHECK(paciente.get_idade() == 28);
        CHECK(paciente.get_cpf() == "56789012345");
        CHECK(paciente.get_convenio() == "Convênio G");
        CHECK(paciente.get_cor() == 5);
    }

    SUBCASE("Editar dados do paciente") {
        paciente.editar_dados_paciente(unsigned int(4));

        CHECK(paciente.get_cor() == 4);
    }
}


