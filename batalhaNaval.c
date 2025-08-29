#include <stdio.h>
#include <stdlib.h>

    // Desafio Batalha Naval - MateCheck
    // Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
    // Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

#include <stdio.h>

#define TAM 10
#define NAVIO 3

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função que posiciona navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int j = 0; j < tamanho; j++) {
        tabuleiro[linha][coluna + j] = NAVIO;
    }
}

// Função que posiciona navio vertical
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Função que posiciona navio diagonal (↘)
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
}

// Função que posiciona navio diagonal (↙)
void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

// Função para aplicar uma habilidade sem sobrescrever navios
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[3][5], int origemLinha, int origemColuna) {
    int tamHab = 5;
    int offset = tamHab / 2;

    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + (i - offset);
                int coluna = origemColuna + (j - offset);

                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == 0) { // só aplica se for água
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // ---- POSICIONA 4 NAVIOS ----
    posicionarNavioHorizontal(tabuleiro, 0, 0, 3);   // Navio horizontal
    posicionarNavioVertical(tabuleiro, 2, 2, 3);     // Navio vertical
    posicionarNavioDiagonalPrincipal(tabuleiro, 4, 0, 3); // Diagonal ↘
    posicionarNavioDiagonalSecundaria(tabuleiro, 7, 9, 3); // Diagonal ↙

    printf("===Tabuleiro inicial com navios=== \n\n");
    imprimirTabuleiro(tabuleiro);

    // ---- MATRIZES DE HABILIDADE ----
    int cone[3][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[4][5] = {0};

    // Cone apontando para cima
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            if (j >= 0 && j < 5) {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 5/2 || j == 5/2) // Linha e coluna central
                cruz[i][j] += 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Octaedro (losango)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (abs(i - 3/2) + abs(j - 3/2) <= 3/2) // Fórmula da distância Manhattan
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ---- APLICA HABILIDADES ----
    aplicarHabilidade(tabuleiro, cone, 2, 6);     // Posicionando a habilidade de Cone
    aplicarHabilidade(tabuleiro, cruz, 6, 7);     // Posicionando a habilidade de Cruz
    aplicarHabilidade(tabuleiro, octaedro, 9, 4); // Posicionando a habilidade de Octaedro

    printf("===Tabuleiro com habilidades aplicadas=== \n\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}

