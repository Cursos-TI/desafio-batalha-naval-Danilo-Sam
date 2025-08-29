#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAM 10       // tamanho fixo do tabuleiro
#define NAVIO 3      // valor que representa as partes do navio
#define TAM_NAVIO 3  // tamanho fixo de cada navio

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se um navio pode ser posicionado sem sair do tabuleiro
int dentroDoTabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM;
}

// Função para verificar se há sobreposição de navios
int posicaoLivre(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int j = 0; j < TAM_NAVIO; j++) {
        if (dentroDoTabuleiro(linha, coluna + j) && posicaoLivre(tabuleiro, linha, coluna + j)) {
            tabuleiro[linha][coluna + j] = NAVIO;
        }
    }
}

// Função para posicionar navio vertical
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (dentroDoTabuleiro(linha + i, coluna) && posicaoLivre(tabuleiro, linha + i, coluna)) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para posicionar navio na diagonal principal (↘)
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        if (dentroDoTabuleiro(linha + k, coluna + k) && posicaoLivre(tabuleiro, linha + k, coluna + k)) {
            tabuleiro[linha + k][coluna + k] = NAVIO;
        }
    }
}

// Função para posicionar navio na diagonal secundária (↙)
void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        if (dentroDoTabuleiro(linha + k, coluna - k) && posicaoLivre(tabuleiro, linha + k, coluna - k)) {
            tabuleiro[linha + k][coluna - k] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    
    // Inicializa tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona navios (pré-definidos no código)
    posicionarNavioHorizontal(tabuleiro, 2, 4);       // Navio 1 - Horizontal
    posicionarNavioVertical(tabuleiro, 6, 1);         // Navio 2 - Vertical
    posicionarNavioDiagonalPrincipal(tabuleiro, 4, 1); // Navio 3 - Diagonal ↘
    posicionarNavioDiagonalSecundaria(tabuleiro, 6, 8); // Navio 4 - Diagonal ↙

    // Exibe tabuleiro final
    exibirTabuleiro(tabuleiro);

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

    return 0;
}
