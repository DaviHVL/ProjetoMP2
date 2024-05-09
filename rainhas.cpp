#include "rainhas.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

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
        return -1;
    }
    return 0;
}

