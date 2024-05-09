#ifndef RAINHAS_H_INCLUDED
#define RAINHAS_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

/*
Fun��o Principal.
*/
int resposta_rainhas(const string& nomeArquivo);

/*
Fun��o para verificar se todos caracteres s�o 0 ou 1.
*/
bool verificador_caracteres(const string& nomeArquivo);

/*
Fun��o para verificar se h� 64 caracteres.
*/
bool verificador_numeros(const string& nomeArquivo);

/*
Fun��o para verificar se h� apenas uma 1 rainha em cada linha do tabuleiro.
*/
bool verificador_umaRainha(const string& nomeArquivo);

/*
Fun��o para converter o que est� no arquivo .txt em uma string.
*/
string conversor_string(const string& nomeArquivo);

/*
Fun��o para retirar todos '\n' e '\r' presentes na string.
*/
string limpa_string(string str);

/*
Fun��o para verificar se as rainhas interceptam uma a outra na vertical.
*/
bool verificador_vertical(const string& nomeArquivo);

#endif   // RAINHAS_H_INCLUDED

