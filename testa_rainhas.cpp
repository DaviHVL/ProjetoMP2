#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Tabuleiros com caracteres invalidos", "[rainhas]") {
    REQUIRE(resposta_rainhas("arquivo1.txt") == 1);

    REQUIRE(resposta_rainhas("arquivo2.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo3.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo4.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo5.txt") == -1);
}


TEST_CASE("Tabuleiros com numero inadequado de caracteres", "[rainhas]") {
    REQUIRE(resposta_rainhas("arquivo6.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo7.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo8.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo9.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo10.txt") == -1);
}

TEST_CASE("Tabuleiros com uma rainha em cada linha", "[rainhas]") {
    REQUIRE(resposta_rainhas("arquivo11.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo12.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo13.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo14.txt") == -1);

    REQUIRE(resposta_rainhas("arquivo15.txt") == -1);
}

TEST_CASE("Tabuleiros com rainhas na vertical", "[rainhas]") {
    REQUIRE(resposta_rainhas("arquivo16.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo17.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo18.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo19.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo20.txt") == 0);
}

TEST_CASE("Tabuleiros com rainhas na diagonal", "[rainhas]") {
    REQUIRE(resposta_rainhas("arquivo21.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo22.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo23.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo24.txt") == 0);

    REQUIRE(resposta_rainhas("arquivo25.txt") == 0);
}
