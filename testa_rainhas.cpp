#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Tabuleiros com caracteres invalidos", "[rainhas]") {
    REQUIRE(resposta_rainhas("Possibilits/arquivo1.txt") == 1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo2.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo3.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo4.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo5.txt") == -1);
}

TEST_CASE("Tabuleiros com numero inadequado de caracteres", "[rainhas]") {
    REQUIRE(resposta_rainhas("Possibilits/arquivo6.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo7.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo8.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo9.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo10.txt") == -1);
}

TEST_CASE("Tabuleiros com uma rainha em cada linha", "[rainhas]") {
    REQUIRE(resposta_rainhas("Possibilits/arquivo11.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo12.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo13.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo14.txt") == -1);

    REQUIRE(resposta_rainhas("Possibilits/arquivo15.txt") == -1);
}

TEST_CASE("Tabuleiros com rainhas na vertical", "[rainhas]") {
    REQUIRE(resposta_rainhas("Possibilits/arquivo16.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo17.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo18.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo19.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo20.txt") == 0);
}

TEST_CASE("Tabuleiros com rainhas na diagonal", "[rainhas]") {
    REQUIRE(resposta_rainhas("Possibilits/arquivo21.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo22.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo23.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo24.txt") == 0);

    REQUIRE(resposta_rainhas("Possibilits/arquivo25.txt") == 0);
}

