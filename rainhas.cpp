#include "rainhas.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

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
Implementação da função para verificar se há exatamente 8 rainhas.
*/
bool verificador_numeroRainhas(const string& nomeArquivo) {
    string tabuleiro = conversor_string(nomeArquivo);
    int contad = 0;
    for (size_t i = 0; i < 64; i ++) {
        if (tabuleiro[i] == '1') {
            contad++;
        }
    }
    if (contad != 8) {
        return false;
    } else {
        return true;
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
Função para gerar o arquivo ataques.txt.
*/
void gerador_ataques(const string& arquivoAtaques) {
    string tabuleiro = conversor_string(arquivoAtaques);
    vector<vector<int>> matriz(8, vector<int>(8, 0));

    for (int i = 0; i < 64; ++i) {
        matriz[i / 8][i % 8] = tabuleiro[i] - '0';
    }

    ofstream outFile("ataques.txt");

    if (outFile.is_open()) {
        vector<pair<int, int>> posis;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (matriz[i][j] == 1) {
                    posis.push_back({i, j});
                }
            }
        }
    }

        for (size_t i = 0; i < posis.size(); ++i) {
            for (size_t j = i + 1; j < posis.size(); ++j) {
                int x1 = posis[i].first, y1 = posis[i].second;
                int x2 = posis[j].first, y2 = posis[j].second;
                if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
                    outFile << x1 << ", " << y1
                    << " " << x2 << ", " << y2 << "\n";
                }
            }
        }
        outFile.close();
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

    if (verificador_numeroRainhas(nomeArquivo) == false) {
        return -1;
    }

    if (verificador_umaRainha(nomeArquivo) == false) {
        gerador_ataques(nomeArquivo);
        return 0;
    }

    if (verificador_vertical(nomeArquivo) == false) {
        gerador_ataques(nomeArquivo);
        return 0;
    }

    if (verificador_diagonal(nomeArquivo) == false) {
        gerador_ataques(nomeArquivo);
        return 0;
    }

    return 1;
}

