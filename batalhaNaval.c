#include <stdio.h>

 /*Desafio Batalha Naval - MateCheck
 Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
 Siga os comentários para implementar cada parte do desafio.*/

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAMANHO 3


int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

int tabuleiro[TAM][TAM] = {0}; // Inicializa tudo com 0 (água)
    int i, j;

    // Navio horizontal começando em (2,4)
    for (j = 0; j < TAMANHO; j++) {
        tabuleiro[2][4 + j] = NAVIO;
    }

    // Navio vertical começando em (5,7)
    for (i = 0; i < TAMANHO; i++) {
        tabuleiro[5 + i][7] = NAVIO;
    }

    //NAVIOS DIAGONAIS
    // Diagonal (linha e coluna aumentam) começando em (0,0)
    for (i = 0; i < TAMANHO; i++) {
        tabuleiro[0 + i][0 + i] = NAVIO;
    }

        // Diagonal (linha aumenta, coluna diminui) começando em (0,9)
    for (i = 0; i < TAMANHO; i++) {
        tabuleiro[0 + i][9 - i] = NAVIO;
    }

    // Exibir tabuleiro
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

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

    return 0;
}
