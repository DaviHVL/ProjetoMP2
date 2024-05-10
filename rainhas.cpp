/**
 * @file main.cpp
 * @brief Arquivo fonte principal contendo a implementação das funções necessárias para a verificação das rainhas.
 * Inclui funções para manipular e verificar configurações de rainhas em um tabuleiro de xadrez.
 */

#include "rainhas.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

/**
 * @brief Remove todos os caracteres '\n' e '\r' de uma string.
 * @param str String para ser limpa.
 * @return String com todos '\n' e '\r' removidos.
 */
string limpa_string(string str) {
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(remove(str.begin(), str.end(), '\r'), str.end());
    return str;
}

/**
 * @brief Converte o conteúdo de um arquivo .txt em uma única string.
 * @param nomeArquivo Caminho do arquivo a ser lido.
 * @return Uma string contendo o conteúdo do arquivo, sem linhas novas.
 * @exception runtime_error Lançada se o arquivo não puder ser aberto.
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

/**
 * @brief Verifica se todos os caracteres em uma string são '0' ou '1'.
 * @param nomeArquivo Caminho do arquivo que contém a configuração do tabuleiro.
 * @return True se todos os caracteres forem '0' ou '1', false caso contrário.
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

/**
 * @brief Verifica se a string possui exatamente 64 caracteres.
 * @param nomeArquivo Caminho do arquivo para verificação.
 * @return True se a string tiver 64 caracteres, false caso contrário.
 */
bool verificador_numeros(const string& nomeArquivo) {
    string tabuleiro = conversor_string(nomeArquivo);
    if (tabuleiro.length() == 64) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Verifica a presença de exatamente 8 rainhas, representadas pelo '1', na string.
 * @param nomeArquivo Caminho do arquivo para verificação.
 * @return True se houver exatamente oito rainhas, false caso contrário.
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

/**
 * @brief Verifica se cada linha do tabuleiro possui exatamente uma rainha.
 * @param nomeArquivo Caminho do arquivo que contém a configuração do tabuleiro.
 * @return True se cada linha tiver exatamente uma rainha, false caso contrário.
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

/**
 * @brief Verifica se as rainhas se atacam na vertical.
 * @param nomeArquivo Caminho do arquivo que contém a configuração do tabuleiro.
 * @return True se nenhuma rainha atacar outra na vertical, false caso encontre ataques.
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

/**
 * @brief Verifica se as rainhas se atacam nas diagonais.
 * @param nomeArquivo Caminho do arquivo que contém a configuração do tabuleiro.
 * @return True se nenhuma rainha atacar outra na diagonal, false caso encontre ataques.
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

/**
 * @brief Gera um arquivo chamado ataques.txt listando pares de rainhas que se atacam.
 * @param arquivoAtaques Caminho para o arquivo de entrada com a configuração do tabuleiro.
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

        for (size_t i = 0; i < posis.size(); ++i) {
            for (size_t j = i + 1; j < posis.size(); ++j) {
                int x1 = posis[i].first, y1 = posis[i].second;
                int x2 = posis[j].first, y2 = posis[j].second;
                if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
                    outFile << x1 << "," << y1
                    << " " << x2 << "," << y2 << "\n";
                }
            }
        }
        outFile.close();
    }
}

/**
 * @brief Função principal para verificar se o arquivo possui uma configuração que satisfaz o problema.
 * @param nomeArquivo Caminho para o arquivo contendo a configuração do tabuleiro.
 * @return Código inteiro representando o resultado das verificações (-1 para entrada inválida, 0 para ataques presentes e 1 para configuração válida).
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

