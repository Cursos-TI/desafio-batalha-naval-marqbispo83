#include <stdio.h>
#include <stdlib.h> 
#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAMANHO 3
#define HABILIDADE 1

// Protótipos das funções
void exibir_tabuleiro(int tabuleiro[TAM][TAM]);
void habilidade_cone(int tabuleiro[TAM][TAM], int linha_centro, int coluna_centro);
void habilidade_cruz(int tabuleiro[TAM][TAM], int linha_centro, int coluna_centro);
void habilidade_octaedro(int tabuleiro[TAM][TAM], int linha_centro, int coluna_centro);

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa tudo com 0 (água)
    int i, j;

    // Nível Novato & Aventureiro - Posicionamento dos Navios
    // Navio horizontal começando em (2,4)
    for (j = 0; j < TAMANHO; j++) {
        tabuleiro[2][4 + j] = NAVIO;
    }

    // Navio vertical começando em (5,7)
    for (i = 0; i < TAMANHO; i++) {
        tabuleiro[5 + i][7] = NAVIO;
    }

    // Navio diagonal (linha e coluna aumentam) começando em (0,0)
    for (i = 0; i < TAMANHO; i++) {
        tabuleiro[0 + i][0 + i] = NAVIO;
    }

    // Navio diagonal (linha aumenta, coluna diminui) começando em (0,9)
    for (i = 0; i < TAMANHO; i++) {
        tabuleiro[0 + i][9 - i] = NAVIO;
    }

    // Exibir tabuleiro com navios posicionados
    printf("--- Tabuleiro com navios posicionados ---\n");
    exibir_tabuleiro(tabuleiro);

    // Nível Mestre - Habilidades Especiais com Matrizes
    
    // Simular habilidade de cone no centro do tabuleiro
    printf("\n--- Tabuleiro com Habilidade em Cone (centro) ---\n");
    int tabuleiro_cone[TAM][TAM] = {0}; // Cria um novo tabuleiro para a demonstração
    habilidade_cone(tabuleiro_cone, 5, 5);
    exibir_tabuleiro(tabuleiro_cone);

    // Simular habilidade de cruz no centro do tabuleiro
    printf("\n--- Tabuleiro com Habilidade em Cruz (centro) ---\n");
    int tabuleiro_cruz[TAM][TAM] = {0}; // Cria um novo tabuleiro para a demonstração
    habilidade_cruz(tabuleiro_cruz, 5, 5);
    exibir_tabuleiro(tabuleiro_cruz);

    // Simular habilidade de octaedro no centro do tabuleiro
    printf("\n--- Tabuleiro com Habilidade em Octaedro (centro) ---\n");
    int tabuleiro_octa[TAM][TAM] = {0}; // Cria um novo tabuleiro para a demonstração
    habilidade_octaedro(tabuleiro_octa, 5, 5);
    exibir_tabuleiro(tabuleiro_octa);

    return 0;
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para a habilidade de cone
void habilidade_cone(int tabuleiro[TAM][TAM], int linha_centro, int coluna_centro) {
    int i, j;
    int tamanho_cone = 2; // Ajuste o tamanho conforme necessário

    for (i = 0; i <= tamanho_cone; i++) {
        int largura_cone = 2 * i + 1;
        int coluna_inicio = coluna_centro - i;

        for (j = 0; j < largura_cone; j++) {
            if (linha_centro + i < TAM && coluna_inicio + j >= 0 && coluna_inicio + j < TAM) {
                tabuleiro[linha_centro + i][coluna_inicio + j] = HABILIDADE;
            }
        }
    }
}

// Função para a habilidade de cruz
void habilidade_cruz(int tabuleiro[TAM][TAM], int linha_centro, int coluna_centro) {
    int i;
    // Pinta a linha vertical
    for (i = 0; i < TAM; i++) {
        tabuleiro[i][coluna_centro] = HABILIDADE;
    }
    // Pinta a linha horizontal
    for (i = 0; i < TAM; i++) {
        tabuleiro[linha_centro][i] = HABILIDADE;
    }
}

// Função para a habilidade de octaedro
void habilidade_octaedro(int tabuleiro[TAM][TAM], int linha_centro, int coluna_centro) {
    int i, j;
    int tamanho_octa = 1; // Ajuste o tamanho conforme necessário

    // Preenche o losango superior e inferior
    for (i = 0; i <= tamanho_octa; i++) {
        for (j = -i; j <= i; j++) {
            // Parte de cima
            if (linha_centro - i >= 0 && coluna_centro + j >= 0 && coluna_centro + j < TAM) {
                tabuleiro[linha_centro - i][coluna_centro + j] = HABILIDADE;
            }
            // Parte de baixo
            if (linha_centro + i < TAM && coluna_centro + j >= 0 && coluna_centro + j < TAM) {
                tabuleiro[linha_centro + i][coluna_centro + j] = HABILIDADE;
            }
        }
    }

    
}
