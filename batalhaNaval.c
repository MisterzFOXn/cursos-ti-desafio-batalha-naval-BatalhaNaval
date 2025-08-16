#include <stdio.h>

#define N 10 // tamanho do tabuleiro

void exibirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Habilidade em cone (simula ataque para baixo a partir da posição central)
void habilidadeCone(int tabuleiro[N][N], int x, int y) {
    if (x + 2 < N && y - 2 >= 0 && y + 2 < N) {
        tabuleiro[x][y] = 1;
        tabuleiro[x+1][y-1] = tabuleiro[x+1][y] = tabuleiro[x+1][y+1] = 1;
        for (int j = y-2; j <= y+2; j++) {
            tabuleiro[x+2][j] = 1;
        }
    }
}

// Habilidade em octaedro
void habilidadeOctaedro(int tabuleiro[N][N], int x, int y) {
    if (x-1 >= 0 && x+1 < N && y-1 >= 0 && y+1 < N) {
        tabuleiro[x][y] = 1;
        tabuleiro[x-1][y] = tabuleiro[x+1][y] = 1;
        tabuleiro[x][y-1] = tabuleiro[x][y+1] = 1;
    }
}

// Habilidade em cruz
void habilidadeCruz(int tabuleiro[N][N], int x, int y) {
    if (x-1 >= 0 && x+1 < N && y-2 >= 0 && y+2 < N) {
        tabuleiro[x][y] = 1;
        tabuleiro[x-1][y] = tabuleiro[x+1][y] = 1;
        for (int j = y-2; j <= y+2; j++) {
            tabuleiro[x][j] = 1;
        }
    }
}

int main() {
    int tabuleiro[N][N] = {0};

    printf("--- Tabuleiro inicial ---\n");
    exibirTabuleiro(tabuleiro);

    printf("--- Habilidade CONE ---\n");
    habilidadeCone(tabuleiro, 2, 4); // centro em (2,4)
    exibirTabuleiro(tabuleiro);

    int tabuleiro2[N][N] = {0};
    printf("--- Habilidade OCTAEDRO ---\n");
    habilidadeOctaedro(tabuleiro2, 5, 5); // centro em (5,5)
    exibirTabuleiro(tabuleiro2);

    int tabuleiro3[N][N] = {0};
    printf("--- Habilidade CRUZ ---\n");
    habilidadeCruz(tabuleiro3, 6, 4); // centro em (6,4)
    exibirTabuleiro(tabuleiro3);

    return 0;
}
