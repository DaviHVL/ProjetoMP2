/**
 * @file rainhas.h
 * @brief Arquivo de cabe�alho que define fun��es relacionadas � verifica��o de coloca��o de rainhas em um tabuleiro de xadrez.
 */

#ifndef RAINHAS_H_INCLUDED
#define RAINHAS_H_INCLUDED
#include <iostream>
#include <string>

/**
 * @brief Fun��o principal que verifica se o arquivo possui uma configura��o que satisfaz o problema.
 * @param nomeArquivo Caminho para o arquivo contendo a configura��o do tabuleiro de xadrez.
 * @return Um inteiro indicando o resultado das verifica��es.
 */
int resposta_rainhas(const std::string& nomeArquivo);

/**
 * @brief Verifica se todos os caracteres no arquivo s�o '0' ou '1'.
 * @param nomeArquivo Caminho para o arquivo contendo a configura��o do tabuleiro de xadrez.
 * @return true se todos os caracteres forem '0' ou '1', false caso contr�rio.
 */
bool verificador_caracteres(const std::string& nomeArquivo);

/**
 * @brief Verifica se h� exatamente 64 caracteres representando o tabuleiro.
 * @param nomeArquivo Caminho para o arquivo contendo a configura��o do tabuleiro de xadrez.
 * @return true se houver exatamente 64 caracteres, false caso contr�rio.
 */
bool verificador_numeros(const std::string& nomeArquivo);

/**
 * @brief Verifica se h� exatamente 8 rainhas no tabuleiro.
 * @param nomeArquivo Caminho para o arquivo contendo a configura��o do tabuleiro de xadrez.
 * @return true se houver exatamente 8 rainhas, false caso contr�rio.
 */
bool verificador_numeroRainhas(const std::string& nomeArquivo);

/**
 * @brief Verifica se h� exatamente uma rainha por linha no tabuleiro.
 * @param nomeArquivo Caminho para o arquivo contendo a configura��o do tabuleiro de xadrez.
 * @return true se houver exatamente uma rainha em cada linha, false caso contr�rio.
 */
bool verificador_umaRainha(const std::string& nomeArquivo);

/**
 * @brief Converte o conte�do de um arquivo .txt em uma �nica string.
 * @param nomeArquivo Caminho para o arquivo contendo a configura��o do tabuleiro de xadrez.
 * @return Uma string contendo o conte�do do arquivo.
 */
std::string conversor_string(const std::string& nomeArquivo);

/**
 * @brief Remove todos os caracteres '\n' e '\r' de uma string.
 * @param str A string para limpar.
 * @return A string limpa.
 */
std::string limpa_string(std::string str);

/**
 * @brief Verifica se alguma das rainhas ataca outra na vertical.
 * @param nomeArquivo Caminho para o arquivo contendo a configura��o do tabuleiro de xadrez.
 * @return true se nenhuma rainha atacar outra verticalmente, false se pelo menos duas o fizerem.
 */
bool verificador_vertical(const std::string& nomeArquivo);

/**
 * @brief Verifica se alguma das rainhas ataca outra na diagonal.
 * @param nomeArquivo Caminho para o arquivo contendo a configura��o do tabuleiro de xadrez.
 * @return true se nenhuma rainha atacar outra diagonalmente, false se pelo menos duas o fizerem.
 */
bool verificador_diagonal(const std::string& nomeArquivo);

/**
 * @brief Gera um arquivo de texto listando todos os pares de rainhas que se amea�am mutuamente.
 * @param arquivoAtaques Caminho para o arquivo de entrada com a configura��o do tabuleiro.
 */
void gerador_ataques(const std::string& arquivoAtaques);

#endif   // RAINHAS_H_INCLUDED

