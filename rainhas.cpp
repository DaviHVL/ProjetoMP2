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
Implementa��o da fun��o para verificar se h� 64 caracteres.
*/
bool verificador_numeros(string tabuleiro){
    if (tabuleiro.length() == 64){
        return true;
    }
    else{
        return false;
    }
}

/*
Implementa��o da fun��o para verificar se h� apenas uma 1 rainha em cada linha do tabuleiro.
*/
bool verificador_umaRainha(string tabuleiro){
    for (size_t i=0; i<64; i+=8){
            int contad = 0;
        for (size_t z=i; z<(i+8); z++){
            if (tabuleiro[z]=='1'){
                contad++;
            }
        }
        if (contad!=1){
            return false;
        }
    }
    return true;
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
    if (verificador_umaRainha(tabuleiro) == false) {
        return -1;
    }
    return 0;
}

