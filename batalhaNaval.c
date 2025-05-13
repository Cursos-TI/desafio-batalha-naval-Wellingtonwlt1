#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5  // Tamanho fixo para exemplo, pode ser ajustado

// Função para inicializar a matriz com zeros
void inicializarMatriz(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Função para exibir a matriz no console
void exibirMatriz(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar habilidade em forma de cone
void habilidadeCone(int matriz[TAMANHO][TAMANHO], int centroX, int centroY) {
    for (int i = 0; i <= 2; i++) { // linha
        for (int j = -i; j <= i; j++) { // coluna
            int x = centroX + i;
            int y = centroY + j;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                matriz[x][y] = 1;
            }
        }
    }
}

// Função para aplicar habilidade em forma de cruz
void habilidadeCruz(int matriz[TAMANHO][TAMANHO], int centroX, int centroY) {
    for (int i = 0; i < TAMANHO; i++) {
        matriz[centroX][i] = 1;  // linha central
        matriz[i][centroY] = 1;  // coluna central
    }
}

// Função para aplicar habilidade em forma de octaedro
void habilidadeOctaedro(int matriz[TAMANHO][TAMANHO], int centroX, int centroY) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) {  // condição de octaedro
                int x = centroX + i;
                int y = centroY + j;
                if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                    matriz[x][y] = 1;
                }
            }
        }
    }
}

int main() {
    int matriz[TAMANHO][TAMANHO];

    // Exemplo: habilidade cone no centro (0,2)
    printf("Habilidade: CONE\n");
    inicializarMatriz(matriz);
    habilidadeCone(matriz, 0, 2);
    exibirMatriz(matriz);
    printf("\n");

    // Exemplo: habilidade cruz no centro (2,2)
    printf("Habilidade: CRUZ\n");
    inicializarMatriz(matriz);
    habilidadeCruz(matriz, 2, 2);
    exibirMatriz(matriz);
    printf("\n");

    // Exemplo: habilidade octaedro no centro (2,2)
    printf("Habilidade: OCTAEDRO\n");
    inicializarMatriz(matriz);
    habilidadeOctaedro(matriz, 2, 2);
    exibirMatriz(matriz);
    printf("\n");

    return 0;
}