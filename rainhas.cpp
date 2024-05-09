#include "rainhas.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>

/*
Implementação da função para retirar todos '\n' e '\r' presentes na string.
*/
string limpa_string(string str) {
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(remove(str.begin(), str.end(), '\r'), str.end());
    return str;
}

/*
Implementação da função para converter o que está no arquivo .txt em uma string.
*/
string conversor_string(const string& nomeArquivo) {
    ifstream file(nomeArquivo);
    stringstream resp;

    if (file.is_open()) {
        resp << file.rdbuf();
        file.close();
        return limpa_string(resp.str());
    } else {
        throw runtime_error("Failed to open file: " + nomeArquivo);
    }
}

/*
Implementação da função para verificar se todos caracteres são 0 ou 1.
*/
bool verificador_caracteres(const string& nomeArquivo) {
    string tabuleiro = conversor_string(nomeArquivo);
    for (size_t i = 0; i < tabuleiro.length(); i++) {
        if (tabuleiro[i] != '0' && tabuleiro[i] != '1') {
            return false;
        }
    }
    return true;
}

/*
Implementação da função para verificar se há 64 caracteres.
*/
bool verificador_numeros(const string& nomeArquivo) {
    string tabuleiro = conversor_string(nomeArquivo);
    if (tabuleiro.length() == 64) {
        return true;
    } else {
        return false;
    }
}

/*
Implementação da função para verificar se há apenas uma 1 rainha em cada linha do tabuleiro.
*/
bool verificador_umaRainha(const string& nomeArquivo) {
    string tabuleiro = conversor_string(nomeArquivo);
    for (size_t i = 0; i < 64; i += 8) {
            int contad = 0;
        for (size_t z = i; z < (i + 8); z++) {
            if (tabuleiro[z] == '1') {
                contad++;
            }
        }
        if (contad != 1) {
            return false;
        }
    }
    return true;
}

/*
Implementação da função para verificar se as rainhas interceptam uma a outra na vertical.
*/
bool verificador_vertical(const string& nomeArquivo) {
    string tabuleiro = conversor_string(nomeArquivo);
    for (size_t i = 0; i < 64; i++) {
        if (tabuleiro[i] == '1') {
            for (size_t z = (i+8); z < 64; z+=8) {
                if (tabuleiro[z] == '1') {
                    return false;
                }
            }
        }
    }
    return true;
}

/*
Função para verificar se as rainhas interceptam uma a outra na diagonal.
*/
bool verificador_diagonal(const string& nomeArquivo) {
    string tabuleiro = conversor_string(nomeArquivo);
    vector<int> colunas(8, -1);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro[i * 8 + j] == '1') {
                colunas[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            if (abs(colunas[i] - colunas[j]) == abs(i - j)) {
                return false;
            }
        }
    }
    return true;
}

/*
Implementação da função principal.
*/
int resposta_rainhas(const string& nomeArquivo) {
    if (verificador_caracteres(nomeArquivo) == false) {
        return -1;
    }

    if (verificador_numeros(nomeArquivo) == false) {
        return -1;
    }

    if (verificador_umaRainha(nomeArquivo) == false) {
        return 0;
    }

    if (verificador_vertical(nomeArquivo) == false) {
        return 0;
    }

    if (verificador_diagonal(nomeArquivo) == false) {
        return 0;
    }

    return 1;
}

