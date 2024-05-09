#ifndef RAINHAS_H_INCLUDED
#define RAINHAS_H_INCLUDED
#include <iostream>
#include <string>

/*
Fun��o Principal.
*/
int resposta_rainhas(const std::string& nomeArquivo);

/*
Fun��o para verificar se todos caracteres s�o 0 ou 1.
*/
bool verificador_caracteres(const std::string& nomeArquivo);

/*
Fun��o para verificar se h� 64 caracteres.
*/
bool verificador_numeros(const std::string& nomeArquivo);

/*
Fun��o para verificar se h� exatamente 8 rainhas.
*/
bool verificador_numeroRainhas(const std::string& nomeArquivo);

/*
Fun��o para verificar se h� apenas uma 1 rainha em cada linha do tabuleiro.
*/
bool verificador_umaRainha(const std::string& nomeArquivo);

/*
Fun��o para converter o que est� no arquivo .txt em uma string.
*/
std::string conversor_string(const std::string& nomeArquivo);

/*
Fun��o para retirar todos '\n' e '\r' presentes na string.
*/
std::string limpa_string(std::string str);

/*
Fun��o para verificar se as rainhas interceptam uma a outra na vertical.
*/
bool verificador_vertical(const std::string& nomeArquivo);

/*
Fun��o para verificar se as rainhas interceptam uma a outra na diagonal.
*/
bool verificador_diagonal(const std::string& nomeArquivo);

#endif   // RAINHAS_H_INCLUDED

