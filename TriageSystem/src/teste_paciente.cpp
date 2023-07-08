#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "paciente.hpp"
#include "exception.hpp"

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

TEST_CASE("Teste editar_dados_paciente") {
    std::string nome = "Carlos";
    unsigned idade=45;
    std::string cpf="12345678901";
    std::string convenio="Convênio E";
    unsigned prio = 3;
    Paciente paciente(nome, idade, cpf, convenio);

    SUBCASE("Editar cor") {
        paciente.editar_dados_paciente(prio);

        CHECK(paciente.prioridade() == 3);
    }
}

TEST_CASE("Teste exceções") {
    SUBCASE("Lançar exceção NomeInvalido") {
        std::string nome = "1234";
        unsigned idade=30;
        std::string cpf="12345678901";
        std::string convenio="Convênio A";
        CHECK_THROWS_AS(Paciente(nome, idade, cpf, convenio), NomeInvalido);
    }

    SUBCASE("Lançar exceção CpfInvalido") {
        std::string nome = "Maria";
        unsigned idade=25;
        std::string cpf="1234";
        std::string convenio="Convênio B";
        CHECK_THROWS_AS(Paciente(nome,  idade, cpf, convenio), CpfInvalido&);
    }

    SUBCASE("Lançar exceção ConvenioInvalido") {
        std::string nome = "João";
        unsigned idade=40;
        std::string cpf="12345678901";
        std::string convenio="1234";
        CHECK_THROWS_AS(Paciente(nome,  idade, cpf, convenio), ConvenioInvalido&);
    }
}

TEST_CASE("Teste adicional") {
    std::string nome = "Laura";
    unsigned idade=35;
    std::string cpf="98765432109";
    std::string convenio="Convênio F";
    unsigned prio = 2;
    Paciente paciente(nome, idade, cpf, convenio);

    SUBCASE("Verificar dados do paciente") {
        CHECK(paciente.nome() == "Laura");
        CHECK(paciente.prioridade() == 5);
    }

    SUBCASE("Editar dados do paciente") {
        paciente.editar_dados_paciente(prio);

        CHECK(paciente.prioridade() == 2);
    }
}

TEST_CASE("Teste adicional 2") {
    std::string nome = "Pedro";
    unsigned idade=28;
    std::string cpf="56789012345";
    std::string convenio="Convênio G";
    unsigned prio = 4;
    Paciente paciente(nome,  idade, cpf, convenio);

    SUBCASE("Verificar dados do paciente") {
        CHECK(paciente.nome() == "Pedro");
        CHECK(paciente.prioridade() == 5);
    }

    SUBCASE("Editar dados do paciente") {
        paciente.editar_dados_paciente(prio);

        CHECK(paciente.prioridade() == 4);
    }
}


