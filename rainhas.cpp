#include "rainhas.hpp"

/*
Implementação da função para verificar se todos caracteres são 0 ou 1.
*/
bool verificador_caracteres(string tabuleiro){
    for (size_t i = 0; i <tabuleiro.length(); i++){
        if (tabuleiro[i] != '0' && tabuleiro[i] != '1'){
            return false;
        }
    }
    return true;
}

int resposta_rainhas(string tabuleiro){
    if (verificador_caracteres(tabuleiro) == false){
        return -1;
    }
    return 0;
}
