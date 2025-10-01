#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAMANHO 3

int main() {
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

    // Exibir tabuleiro
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}