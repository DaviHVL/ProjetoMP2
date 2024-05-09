#ifndef RAINHAS_H_INCLUDED
#define RAINHAS_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

/*
Função Principal.
*/
int resposta_rainhas(const string& nomeArquivo);

/*
Função para verificar se todos caracteres são 0 ou 1.
*/
bool verificador_caracteres(const string& nomeArquivo);

/*
Função para verificar se há 64 caracteres.
*/
bool verificador_numeros(const string& nomeArquivo);

/*
Função para verificar se há apenas uma 1 rainha em cada linha do tabuleiro.
*/
bool verificador_umaRainha(const string& nomeArquivo);

/*
Função para converter o que está no arquivo .txt em uma string.
*/
string conversor_string(const string& nomeArquivo);

/*
Função para retirar todos '\n' e '\r' presentes na string.
*/
string limpa_string(string str);

/*
Função para verificar se as rainhas interceptam uma a outra na vertical.
*/
bool verificador_vertical(const string& nomeArquivo);

#endif   // RAINHAS_H_INCLUDED

