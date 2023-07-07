#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "lista.hpp"

TEST_CASE("Lista vazia") {
    ListaDePrioridade lista;
    SUBCASE("Lista está vazia") {
        CHECK(lista.lista_vazia());
    }

    std::string nome1 = "Adrian", cpf1 = "12345678910", conv1 = "x";
    unsigned idade1 = 19;
    Paciente p1(nome1, idade1, cpf1, conv1);
    lista.adicionar_paciente(p1);

    SUBCASE("Lista não está vazia") {
        CHECK(!lista.lista_vazia());
    }
}

TEST_CASE("Ordenado") {
    ListaDePrioridade lista;
    std::string nome1 = "Adrian", cpf1 = "12345678910", conv1 = "x";
    unsigned idade1 = 19;
    Paciente p1(nome1, idade1, cpf1, conv1);
    lista.adicionar_paciente(p1);

    SUBCASE("Lista está ordenada") {
        std::string nome2 = "Hector", cpf2 = "12345678922", conv2 = "y";
        unsigned idade2 = 21, prio2 = 2;
        Paciente p2(nome2, idade2, cpf2, conv2);
        lista.adicionar_paciente(p2);
        CHECK(lista.ordenado());
    }

    SUBCASE("Lista está desordenada") {
        std::string nome2 = "Hector", cpf2 = "12345678922", conv2 = "y";
        unsigned idade2 = 21, prio2 = 2;
        Paciente p2(nome2, idade2, cpf2, conv2);
        std::string sint = "teste", pressao = "teste";
        Anamnese anam(sint, 37.0, 1.9, 100.0, 90, pressao);
        lista.adicionar_paciente(p2);
        lista.procurar_paciente(nome2)->editar_dados_paciente(anam, prio2);
        CHECK(!lista.ordenado());
    }
}

TEST_CASE("Adicionar pacientes") {
    ListaDePrioridade lista;

    std::string nome1 = "Adrian", cpf1 = "12345678910", conv1 = "x";
    unsigned idade1 = 19;
    Paciente p1(nome1, idade1, cpf1, conv1);
    lista.adicionar_paciente(p1);

    CHECK(*(std::prev(lista.fim_lista())) == p1);

    std::string nome2 = "Lith Verhen", cpf2 = "12345678922", conv2 = "y";
    unsigned idade2 = 20, prio2 = 2;
    Paciente p2(nome2, idade2, cpf2, conv2);
    std::string sint = "teste", pressao = "teste";
    Anamnese anam(sint, 37.0, 1.9, 100.0, 90, pressao);
    p2.editar_dados_paciente(anam, prio2);
    lista.adicionar_paciente(p2);

    CHECK(*(std::prev(std::prev(lista.fim_lista()))) == p2);
    CHECK(lista.ordenado());

    std::string nome3 = "Klein Moretti", cpf3 = "12345678933", conv3 = "y";
    unsigned idade3 = 21, prio3 = 0;
    Paciente p3(nome3, idade3, cpf3, conv3);
    p3.editar_dados_paciente(anam, prio3);
    lista.adicionar_paciente(p3);

    CHECK(*(std::prev(std::prev(std::prev(lista.fim_lista())))) == p2);
    CHECK(lista.ordenado());
}

TEST_CASE("Procurar paciente") {
    ListaDePrioridade lista;
    std::string nome1 = "Adrian", cpf1 = "12345678910", conv1 = "x";
    unsigned idade1 = 19;
    Paciente p1(nome1, idade1, cpf1, conv1);

    SUBCASE("Lista está vazia") {
        CHECK_THROWS_AS(lista.procurar_paciente(nome1), ListaVazia);
    }

    SUBCASE("Lista não está vazia") {
        lista.adicionar_paciente(p1);
        std::string nome2 = "Lith Verhen", cpf2 = "12345678922", conv2 = "y";
        unsigned idade2 = 20, prio2 = 2;
        Paciente p2(nome2, idade2, cpf2, conv2);
        std::string sint = "teste", pressao = "teste";
        Anamnese anam(sint, 37.0, 1.9, 100.0, 90, pressao);
        p2.editar_dados_paciente(anam, prio2);
        lista.adicionar_paciente(p2);
        std::string nome3 = "Klein Moretti", cpf3 = "12345678933", conv3 = "y";
        unsigned idade3 = 21, prio3 = 0;
        Paciente p3(nome3, idade3, cpf3, conv3);
        p3.editar_dados_paciente(anam, prio3);
        lista.adicionar_paciente(p3);

        CHECK(*(lista.procurar_paciente(nome1)) == p1);
    }
}

TEST_CASE("Remover paciente") {
    ListaDePrioridade lista;
    std::string nome1 = "Adrian", cpf1 = "12345678910", conv1 = "x";
    unsigned idade1 = 19;
    Paciente p1(nome1, idade1, cpf1, conv1);

    SUBCASE("Lista está vazia") {
        auto it = lista.fim_lista();
        CHECK_THROWS_AS(lista.remover_paciente(it), ListaVazia);
        CHECK_THROWS_AS(lista.remover_paciente(nome1), ListaVazia);
    }

    SUBCASE("Lista não está vazia") {
        lista.adicionar_paciente(p1);
        std::string nome2 = "Lith Verhen", cpf2 = "12345678922", conv2 = "y";
        unsigned idade2 = 20, prio2 = 2;
        Paciente p2(nome2, idade2, cpf2, conv2);
        std::string sint = "teste", pressao = "teste";
        Anamnese anam(sint, 37.0, 1.9, 100.0, 90, pressao);
        p2.editar_dados_paciente(anam, prio2);
        lista.adicionar_paciente(p2);

        std::string nome3 = "Klein Moretti", cpf3 = "12345678933", conv3 = "y";
        unsigned idade3 = 21, prio3 = 0;
        Paciente p3(nome3, idade3, cpf3, conv3);
        p3.editar_dados_paciente(anam, prio3);
        lista.adicionar_paciente(p3);
        auto it = lista.procurar_paciente(nome1);

        CHECK(lista.remover_paciente(it));

        CHECK(lista.procurar_paciente(nome1) == lista.fim_lista());

        CHECK(lista.remover_paciente(nome2));

        CHECK(lista.procurar_paciente(nome2) == lista.fim_lista());        
    }
}

TEST_CASE("Ordenar paciente") {
    ListaDePrioridade lista;
    std::string nome1 = "Adrian", cpf1 = "12345678910", conv1 = "x";
    unsigned idade1 = 19;
    Paciente p1(nome1, idade1, cpf1, conv1);

    SUBCASE("Lista está vazia") {
        auto it = lista.fim_lista();
        CHECK_THROWS_AS(lista.ordenar_paciente(it), ListaVazia);
    }

    SUBCASE("Lista não está vazia") {
        lista.adicionar_paciente(p1);
        std::string nome2 = "Lith Verhen", cpf2 = "12345678922", conv2 = "y";
        unsigned idade2 = 20, prio2 = 2;
        Paciente p2(nome2, idade2, cpf2, conv2);
        std::string sint = "teste", pressao = "teste";
        Anamnese anam(sint, 37.0, 1.9, 100.0, 90, pressao);
        p2.editar_dados_paciente(anam, prio2);
        lista.adicionar_paciente(p2);

        std::string nome3 = "Klein Moretti", cpf3 = "12345678933", conv3 = "y";
        unsigned idade3 = 21, prio3 = 0;
        Paciente p3(nome3, idade3, cpf3, conv3);
        p3.editar_dados_paciente(anam, prio3);
        lista.adicionar_paciente(p3);

        auto it = lista.procurar_paciente(nome1);
        it->editar_dados_paciente(anam, prio3);
        lista.ordenar_paciente(it);

        CHECK(lista.ordenado());
    }
}
