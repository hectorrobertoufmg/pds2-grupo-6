#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "medico.hpp"
#include "paciente.hpp"
#include "exception.hpp"

TEST_CASE("Teste construtor de Medico") {
    SUBCASE("Médico com nome válido e especialidade válida") {
        std::string nome="João";
        std::string crm="M123";
        std::string especialidade="Oncologista";
        CHECK_NOTHROW(Medico(nome, crm, especialidade));
    }

    SUBCASE("Médico com nome inválido") {
        std::string nome="1234";
        std::string crm="M234";
        std::string especialidade="Pediatra";
        CHECK_THROWS_AS(Medico medico(nome, crm, especialidade), NomeInvalido);
    }

    SUBCASE("Médico com especialidade inválida") {
        std::string nome="Maria";
        std::string crm="M345";
        std::string especialidade="1234";
        CHECK_THROWS_AS(Medico(nome, crm, especialidade), EspecialidadeInvalida);
    }
}

TEST_CASE("Teste exceções") {
    SUBCASE("Lançar exceção NomeInvalido") {
        std::string nome="1234";
        std::string crm="M123";
        std::string especialidade="Oncologista";
        CHECK_THROWS_AS(Medico(nome, crm, especialidade), NomeInvalido);
    }

    SUBCASE("Lançar exceção EspecialidadeInvalida") {
        std::string nome="João";
        std::string crm="M234";
        std::string especialidade="1234";
        CHECK_THROWS_AS(Medico(nome, crm, especialidade), EspecialidadeInvalida);
    }
}

TEST_CASE("Teste adicionar_paciente") {
    std::string nome="Dr. João";
    std::string crm="12345";
    std::string especialidade="Cardiologia";
    Medico medico(nome, crm, especialidade);

    SUBCASE("Adicionar paciente com cor menor que os existentes") {
        std::string nome="Maria";
        unsigned idade=30;
        std::string cpf="12345678901";
        std::string convenio="Convênio A";
        unsigned cor=2;
        Paciente paciente1(nome,idade,cpf,convenio);
        medico.pacientes.adicionar_paciente(paciente1);

        CHECK(medico.pacientes.procurar_paciente(nome)->prioridade() == 2);
    }

    SUBCASE("Adicionar paciente com cor maior que os existentes") {
        std::string nome="João";
        unsigned idade=40;
        std::string cpf="98765432109";
        std::string convenio="Convênio B";
        unsigned cor=5;
        Paciente paciente2(nome,idade,cpf,convenio);
        medico.pacientes.adicionar_paciente(paciente2);

        CHECK(medico.pacientes.procurar_paciente(nome)->prioridade() == 5);
    }
}