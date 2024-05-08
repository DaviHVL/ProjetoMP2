#ifndef RAINHAS_H_INCLUDED
#define RAINHAS_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

/*
Fun��o Principal.
*/
int resposta_rainhas(string tabuleiro);

/*
Fun��o para verificar se todos caracteres s�o 0 ou 1.
*/
bool verificador_caracteres(string tabuleiro);

/*
Fun��o para verificar se h� 64 caracteres.
*/
bool verificador_numeros(string tabuleiro);

/*
Fun��o para verificar se h� apenas uma 1 rainha em cada linha do tabuleiro.
*/
bool verificador_umaRainha(string tabuleiro);

#endif   // RAINHAS_H_INCLUDED

