#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 10
#define COLUMNAS 10

// ENUMERACIÓN REPRESENTATIVA DE CELDAS EXISTENTES
enum cell {
    HIDDEN,
    EMPTY,
    FLAGGED,
    MINE
};

// Tablero de juego en 2d
int board[FILAS][COLUMNAS];

// Estado del juego en 2d
enum cell state[FILAS][COLUMNAS];

// Función para generar números aleatorios
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Función para generar el tablero
void generate_board() {
    // Generador de números aleatorios
    srand(time(NULL));

    // Todas celdas al vacío
    for (int r = 0; r < FILAS; r++) {
        for (int c = 0; c < COLUMNAS; c++) {
            board[r][c] = 0;
            state[r][c] = HIDDEN;
        }
    }

    // Generar las minas
    for (int i = 0; i < 10; i++) {
        // Generar coordenadas random
        int r = rand_int(0, FILAS - 1);
        int c = rand_int(0, COLUMNAS - 1);

        // Asegurar las celulas vacías
        if (board[r][c] == 0) {
            board[r][c] = -1;
        }
    }
}

// Funcion para dibujar tablero
void print_board() {
    printf("\n");

    // dibujar numero de columnas del tablero
    printf("  ");
    for (int c = 0; c < COLUMNAS; c++) {
        printf("%d ", c);
    }
    printf("\n");

    // pintar numero de filas del tablero
    for (int r = 0; r < FILAS; r++) {
        printf("%d ", r);
        for (int c = 0; c < COLUMNAS; c++) {
            switch (state[r][c]) {
            case HIDDEN:
                printf("- ");
                break;
            case EMPTY:
                printf("%d ", board[r][c]);
                break;
            case FLAGGED:
                printf("F ");
                break;
            case MINE:
                printf("* ");
                break;
            }
        }
        printf("\n");
    }
}

// funcion para revelar la celda
void reveal_cell(int r, int c) {
    // checar si está vacía
    if (state[r][c] == HIDDEN) {
        // revelar célula
        state[r][c] = EMPTY;

        // checar si la celda tiene mina
        if (board[r][c] == -1) {
            state[r][c] = MINE;
        }
    }
}

// banderear celda
void flag_cell(int r, int c) {
    // checar si está escondida la celda
    if (state[r][c] == HIDDEN) {
        // Flag the cell
        state[r][c] = FLAGGED;
    }
}

int main() {
    // generar tablero
    generate_board();

    // pintar tablerp
    print_board();

    // saltar hasta que el juego acabe
    while (1) {
        // recibir filas y columnas del jugador
        int r, c;
        printf("Enter row and column: ");
        scanf("%d %d", &r, &c);

        // revelar la celda
        reveal_cell(r, c);

        // banderear la celda
        flag_cell(r, c);

        // imprimir tablero
        print_board();
    }

    return 0;
}