#ifndef RAINHAS_H_INCLUDED
#define RAINHAS_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

/*
Função Principal.
*/
int resposta_rainhas(string tabuleiro);

/*
Função para verificar se todos caracteres são 0 ou 1.
*/
bool verificador_caracteres(string tabuleiro);

/*
Função para verificar se há 64 caracteres.
*/
bool verificador_numeros(string tabuleiro);

#endif   // RAINHAS_H_INCLUDED

