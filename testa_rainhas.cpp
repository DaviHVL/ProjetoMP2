#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE( "Tabuleiros com caracteres invalidos", "[rainhas]" ) {
    REQUIRE( resposta_rainhas("0000100001000000000100000000001000100000000000010000010010000000") == 0 );

    REQUIRE( resposta_rainhas("hgkcbohltusbirlgunkhckbgrehlcbeusitcneituhbvcuirscno") == -1 );

    REQUIRE( resposta_rainhas("00000000000000000000000011111111111111111111111100000000000000000111111111111111111$") == -1 );

    REQUIRE( resposta_rainhas("01501") == -1 );

    REQUIRE( resposta_rainhas("3845267437652876549238765846952837465843729654783629832455642") == -1 );

    REQUIRE( resposta_rainhas("00001000010000000001000000%00001000100000000000010000010010000000") == -1 );

    REQUIRE( resposta_rainhas("hgkcboh11111111111ltusbirlgunkhckbgreh000000000000000000lcbeusitcneituhbvc1111100000uirscno") == -1 );

    REQUIRE( resposta_rainhas("a0000000000000000000000011111111111111111111111100000000000000000111111111111111111") == -1 );

    REQUIRE( resposta_rainhas("0000000000049587245v8j4v30") == -1 );

    REQUIRE( resposta_rainhas("1111111111111111118") == -1 );
}


