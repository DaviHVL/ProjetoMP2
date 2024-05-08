#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE( "Tabuleiros com caracteres invalidos", "[rainhas]" ) {
    REQUIRE( resposta_rainhas("arquivo1.txt") == 0 );

    REQUIRE( resposta_rainhas("arquivo2.txt") == -1 );

    REQUIRE( resposta_rainhas("arquivo3.txt") == -1 );

    REQUIRE( resposta_rainhas("arquivo4.txt") == -1 );

    REQUIRE( resposta_rainhas("arquivo5.txt") == -1 );

}

/*
TEST_CASE( "Tabuleiros com numero inadequado de caracteres", "[rainhas]" ) {
    REQUIRE( resposta_rainhas("0000100001000000000100000000001000100000000000010000010010000000") == 0 );

    REQUIRE( resposta_rainhas("000000000000011111111111001010010101101001") == -1 );

    REQUIRE( resposta_rainhas("ligasaliuhfiaufhioahfuiehfeiauhrighiheauiheriohroieurhgrhiuaehgoe") == -1 );

    REQUIRE( resposta_rainhas("Pf7X93v2N4Ew8Gx5JQZ60Ho1aUyrIVkLcAjsbqiTBpDezMRfgYluOmFS") == -1 );

    REQUIRE( resposta_rainhas("aE2vDJ3RIGmzsLT1lF6bQ09nxWdVhYqPu7ot4Hpe8XcKSgkfBCN5iZrO") == -1 );

    REQUIRE( resposta_rainhas("SbcLVD94Nt26JRq7gXPW3nHphym1s5zIkjFeQoEKaZ8xCMTuYvr0GbAl") == -1 );

    REQUIRE( resposta_rainhas("hgkcboh11111111111ltusbirlgunkhckbgreh000000000000000000lcbeusitcneituhbvc1111100000uirscno") == -1 );

    REQUIRE( resposta_rainhas("a01111111111111111") == -1 );

    REQUIRE( resposta_rainhas("r") == -1 );

    REQUIRE( resposta_rainhas("1") == -1 );

}

TEST_CASE( "Tabuleiros com uma rainha em cada linha", "[rainhas]" ) {
    REQUIRE( resposta_rainhas("0000100001000000000100000000001000100000000000010000010010000000") == 0 );

    REQUIRE( resposta_rainhas("0010100001000000000110000000001000100010000000010000010011000000") == -1 );

    REQUIRE( resposta_rainhas("0000000000000000000000000000000000000000000000000000000000000000") == -1 );

    REQUIRE( resposta_rainhas("1111111100000000000000000000000000000000000000000000000000000000") == -1 );

    REQUIRE( resposta_rainhas("1000000000000000000000000000001000000000000000000000000000000001") == -1 );

    REQUIRE( resposta_rainhas("1111111111111111111111111111111111111111111111111111111111111111") == -1 );

    REQUIRE( resposta_rainhas("0000000000000000000000000000000000000000000000000000011111111111") == -1 );

    REQUIRE( resposta_rainhas("1010101010101001010101010100101010010101001010101010010101001010") == -1 );

    REQUIRE( resposta_rainhas("10") == -1 );

    REQUIRE( resposta_rainhas("00001") == -1 );

}
*/


