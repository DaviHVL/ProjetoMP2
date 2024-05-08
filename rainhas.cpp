#include "rainhas.hpp"

/*
Implementa��o da fun��o para verificar se todos caracteres s�o 0 ou 1.
*/
bool verificador_caracteres(string tabuleiro) {
    for (size_t i = 0; i < tabuleiro.length(); i++) {
        if (tabuleiro[i] != '0' && tabuleiro[i] != '1') {
            return false;
        }
    }
    return true;
}

/*
Fun��o para verificar se h� 64 caracteres.
*/
bool verificador_numeros(string tabuleiro){
    if (tabuleiros.length() == 64){
        return true;
    }
    else{
        return false;
    }
}

/*
Implementa��o da fun��o principal.
*/
int resposta_rainhas(string tabuleiro) {
    if (verificador_caracteres(tabuleiro) == false) {
        return -1;
    }
    if (verificador_numeros(tabuleiro) == false) {
        return -1;
    }
    return 0;
}

